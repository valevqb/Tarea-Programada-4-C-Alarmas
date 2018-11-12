#pragma once
#include <iostream>
#include <string>

using namespace std;

class CodigoSecundario
{
public:
	CodigoSecundario(int pNumCodigo,int pCodigo,string pNombre,int pTelefono)
	{
		numCodigo = pNumCodigo;
		codigo = pCodigo;
		nombre = pNombre;
		telefono = pTelefono;
	}
private:
	int numCodigo;
	int codigo;
	string nombre;
	int telefono;
	CodigoSecundario*siguiente;
friend class SistemaAlarma;
};

