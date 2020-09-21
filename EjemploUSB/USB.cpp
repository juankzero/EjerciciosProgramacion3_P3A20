
#include "USB.h"
#include <fstream>
#include <iostream>

using namespace std;


USB::USB() 
{}

void USB::initUSB() 
{
	fstream usbFile("usb.bin", ios::out | ios::binary);

	if (!usbFile)
	{
		cout << "Imposible cargar dispositivo USB\n";
		return;
	}

	metadata meta;
	cout << "*** C R E A C I O N  D E  D I S P O S I T I V O ***\n\n";

	cout << "Indique nombre de dispositivo: ";
	cin >> meta.nombreUSB;

	cout << "Indique creador de dispositivo: ";
	cin >> meta.creadorUSB;

	meta.cantidadFileEntry = 10;
	meta.cantidadBloquesDatos = 100;
	meta.primerBloqueLibre = 0;

	//me posiciono al inicio del archivo para escribir
	usbFile.seekp(0, ios::beg);

	usbFile.write(reinterpret_cast<const char*>(&meta), sizeof(metadata));

	//Creacion de FileEntries

	fileEntry file;
	strcpy_s(file.nombreArchivo, 3, "ND");
	file.tamanioArchivo = 0;
	file.primerBloqueDatos = 0;
	file.ultimoBloqueDatos = 0;
	file.estadoArchivo = 0; // false

	for (int i = 0; i < meta.cantidadFileEntry; i++) 
		usbFile.write(reinterpret_cast<const char*>(&file), sizeof(fileEntry));

	//Creacion de bloques de datos

	dataBLock  bloque;
	for (int i = 0; i < 1020; i++) 
		bloque.data[i] = 'a';

	bloque.siguienteBloque = -1;

	for (int i = 0; i < meta.cantidadBloquesDatos; i++)
	{
		usbFile.write(reinterpret_cast<const char*>(&bloque), sizeof(dataBLock));
		
		if (i == meta.cantidadBloquesDatos - 1)
			bloque.siguienteBloque = -1;
		else
			bloque.siguienteBloque = i + 1;
	}
	//Confirmar la creacion del dispositivo

	cout << "Dispositivo USB creado correctamente!\n\n";

}

void USB::addFile() 
{
	cout << "*** I M P O R T A R  A R C H I V O ***\n\n";

	cout << "Indique el nombre de archivo a importar: ";
	char archivoAdd[30];
	cin >> archivoAdd;

	ifstream archivoImp(archivoAdd, ios::in | ios::binary);

	if (!archivoImp)
	{
		cout << "Archivo a importar no existe!\n";
		return;
	}

	fstream usbFile("usb.bin", ios::in | ios::out | ios::binary);

	if (!usbFile)
	{
		cout << "Imposible cargar dispositivo USB\n";
		return;
	}

	//lectura de metadata
	metadata meta;
	usbFile.read(reinterpret_cast<char*>(&meta), sizeof(metadata));

	fileEntry file;
	int posicionFileEntry = 0;
	//lectura de FAT FileEntries
	for (int i = 0; i < meta.cantidadFileEntry; i++) 
	{
		usbFile.read(reinterpret_cast<char*>(&file), sizeof(fileEntry));
		//si esta libre
		if (!file.estadoArchivo) //1 = true | 0 = false
		{
			posicionFileEntry = i;
			break;
		}
	}

	//escribir la informacion del archivo a ingresar
	strcpy_s(file.nombreArchivo, strlen(archivoAdd) + 1, archivoAdd);
	
	//me posiciono al final del archivo para conocer la cantidad de bytes que tiene
	archivoImp.seekg(0, ios::end);
	file.tamanioArchivo = archivoImp.tellg();
	file.primerBloqueDatos = meta.primerBloqueLibre;
	file.estadoArchivo = 1;

	//escribir bloques de Datos
	//posicion actual del archivo a importar
	archivoImp.seekg(0, ios::beg);
	int posActArchivoImp = 0;

	dataBLock bloqueDisponible;
	int siguienteBloqueDatos = file.primerBloqueDatos;

	int cantidadBloques = file.tamanioArchivo / 1020;
	int residuoBytes = file.tamanioArchivo % 1020;

	if (cantidadBloques == 0 && residuoBytes > 0)
	{
		int mt = sizeof(metadata);
		int fe = sizeof(fileEntry);
		int db = sizeof(dataBLock);
		int cantidad = mt + fe * 10  + siguienteBloqueDatos * db;
		usbFile.seekg(cantidad, ios::beg);
		usbFile.read(reinterpret_cast<char*>(&bloqueDisponible), sizeof(dataBLock));
		int posicion = usbFile.tellg();

		archivoImp.read(reinterpret_cast<char*>(bloqueDisponible.data), residuoBytes);
		meta.primerBloqueLibre = bloqueDisponible.siguienteBloque;

		usbFile.seekp(sizeof(metadata) + (sizeof(fileEntry) * meta.cantidadFileEntry) + siguienteBloqueDatos * sizeof(dataBLock), ios::beg);
		usbFile.write(reinterpret_cast<const char*>(&bloqueDisponible), sizeof(dataBLock));
	}
	else if (cantidadBloques > 0)
	{
		for (int i = 0; i < cantidadBloques; i++) 
		{
			usbFile.seekg(sizeof(metadata) + sizeof(fileEntry) * 10 + siguienteBloqueDatos * sizeof(dataBLock), ios::beg);
			usbFile.read(reinterpret_cast<char*>(&bloqueDisponible), sizeof(dataBLock));

			archivoImp.read(reinterpret_cast<char*>(bloqueDisponible.data), 1020);

			usbFile.seekp(sizeof(metadata) + (sizeof(fileEntry) * meta.cantidadFileEntry) + siguienteBloqueDatos * sizeof(dataBLock), ios::beg);
			usbFile.write(reinterpret_cast<const char*>(&bloqueDisponible), sizeof(dataBLock));
			siguienteBloqueDatos = bloqueDisponible.siguienteBloque;
		}

		if (residuoBytes > 0)
		{
			usbFile.seekg(sizeof(metadata) + sizeof(fileEntry) * 10 + siguienteBloqueDatos * sizeof(dataBLock), ios::beg);
			usbFile.read(reinterpret_cast<char*>(&bloqueDisponible), sizeof(dataBLock));

			archivoImp.read(reinterpret_cast<char*>(bloqueDisponible.data), residuoBytes);
			meta.primerBloqueLibre = bloqueDisponible.siguienteBloque;

			usbFile.seekp(sizeof(metadata) + (sizeof(fileEntry) * meta.cantidadFileEntry) + siguienteBloqueDatos * sizeof(dataBLock), ios::beg);
			usbFile.write(reinterpret_cast<const char*>(&bloqueDisponible), sizeof(dataBLock));
		}

	}

	usbFile.seekp(0, ios::beg);
	usbFile.write(reinterpret_cast<char*>(&meta), sizeof(metadata));
	usbFile.seekp(sizeof(metadata) + posicionFileEntry * sizeof(fileEntry), ios::beg);
	usbFile.write(reinterpret_cast<char*>(&file), sizeof(fileEntry));

	usbFile.close();

}
