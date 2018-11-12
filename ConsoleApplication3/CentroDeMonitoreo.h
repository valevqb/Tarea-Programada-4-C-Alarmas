#pragma once
#include "SistemaAlarma.h"


class CentroDeMonitoreo
{
public:
	CentroDeMonitoreo(int pIdentificacion, string pCodigo)
	{
		raiz = nullptr;
	}
	~CentroDeMonitoreo()
	{
		while (raiz != nullptr) {
			borrar(raiz->identificacion);
		}
	}
	SistemaAlarma*abuelo(SistemaAlarma*sistemaAlarma);
	SistemaAlarma*tio(SistemaAlarma*sistemaAlarma);
	void reglaDelTio(SistemaAlarma*sistemaAlarma);
	void rotacionIzquierda(SistemaAlarma*sistemaAlarma);
	void rotacionDerecha(SistemaAlarma*sistemaAlarma);
	void rotacionDobleIzquierda(SistemaAlarma*sistemaAlarma);
	void rotacionDobleDerecha(SistemaAlarma*sistemaAlarma);
	void insertar(int pIdentificacion, string pCodigo);
	void insertar(int pIdentificacion, string pCodigo,SistemaAlarma*pRaiz);
	SistemaAlarma*buscar(int pNumZona);
	SistemaAlarma*buscar(int pNumZona, SistemaAlarma*pRaiz);
	void rotar(SistemaAlarma*sistemaAlarma);
	void inorden();
	void inorden(SistemaAlarma*pRaiz);
	void borrar(int pIdentificacion);
	void borrar(int pIdentificacion, SistemaAlarma*pRaiz);
private:
	SistemaAlarma*raiz;
};



