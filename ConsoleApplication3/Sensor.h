#pragma once
#include <iostream>

using namespace std;

class Sensor
{
public:
	Sensor(int pNumZona,string pDescripcion,string pDispositivo)
	{
		numZona = pNumZona;
		descripcion = pDescripcion;
		dispositivo = pDispositivo;
		color = true;
		HD = nullptr;
		HI = nullptr;
		padre = nullptr;
	}
private:
	int numZona;
	string descripcion;
	string dispositivo;
	bool color;
	Sensor*HD;
	Sensor*HI;
	Sensor*padre;
friend class SistemaAlarma;
};

