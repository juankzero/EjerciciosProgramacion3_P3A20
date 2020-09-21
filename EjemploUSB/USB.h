#pragma once
#ifndef USB_H
#define USB_H

struct metadata 
{
	char nombreUSB[10];
	char creadorUSB[10];
	unsigned int cantidadFileEntry;
	unsigned int cantidadBloquesDatos;
	unsigned int primerBloqueLibre;
}; //bytes = 32

struct fileEntry 
{
	char nombreArchivo[30];
	unsigned int tamanioArchivo;
	unsigned int primerBloqueDatos;
	unsigned int ultimoBloqueDatos;
	bool estadoArchivo; //1 Ocupado, 0 Disponible
}; //bytes = 43 x 10

struct fileEntry2
{
	
	int tamanioArchivo;
	char nombreArchivo[12];
	//unsigned int primerBloqueDatos;
	//unsigned int ultimoBloqueDatos;
	//bool estadoArchivo; //1 Ocupado, 0 Disponible
}; //by

struct dataBLock 
{
	char data[1020];
	int siguienteBloque;
}; // bytes 1024 x 100

class USB 
{
private:
	int getFreeDataBlock();

public:
	USB();

	//Inicializar dispositivo
	void initUSB();
	void addFile(); // importacion de archivos a USB
	void removeFile();

};


#endif // !USB_H
