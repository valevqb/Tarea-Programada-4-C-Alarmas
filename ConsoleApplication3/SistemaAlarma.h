#pragma once
#include "Sensor.h"
#include "CodigoSecundario.h"
class SistemaAlarma
{
public:
	SistemaAlarma(int pIdentificacion,string pCodigo)
	{
		raiz = nullptr;
		identificacion = pIdentificacion;
		color = true;
		codigo = pCodigo;
		HD = nullptr;
		HI = nullptr;
		padre = nullptr;
		estado = 0;
		codsSecundarios = nullptr;
	}
	~SistemaAlarma()
	{
		while (raiz != nullptr) {
			borrar(raiz->numZona);
		}
	}
	Sensor*abuelo(Sensor*sensor);
	Sensor*tio(Sensor*sensor);
	void reglaDelTio(Sensor*sensor);
	void rotacionIzquierda(Sensor*sensor);
	void rotacionDerecha(Sensor*sensor);
	void rotacionDobleIzquierda(Sensor*sensor);
	void rotacionDobleDerecha(Sensor*sensor);
	void insertar(int pNumZona, string pDescripcion, string pDispositivo);
	void insertar(int pNumZona, string pDescripcion, string pDispositivo, Sensor*pRaiz);
	Sensor*buscar(int pNumZona);
	Sensor*buscar(int pNumZona, Sensor*pRaiz);
	void rotar(Sensor*sensor);
	void inorden();
	void inorden(Sensor*pRaiz);
	void borrar(int pNumZona);
	void borrar(int pNumZona, Sensor*pRaiz);
	bool validar(string contra);
	CodigoSecundario* buscarCodSecundario(int numZona);
	void mostrarCod_secundario();
	void insertarCodigoSecundario(int pNumCodigo, int pCodigo, string pNombre, int pTelefono);
private:
	Sensor*raiz;
	int estado;
	int identificacion;
	string codigo;
	SistemaAlarma* HD;
	SistemaAlarma* HI;
	SistemaAlarma* padre;
	CodigoSecundario*codsSecundarios;
	bool color;
friend class CentroDeMonitoreo;
};

