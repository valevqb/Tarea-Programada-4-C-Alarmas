#include "pch.h"
#include "SistemaAlarma.h"
#include <string>

void SistemaAlarma::insertar(int pNumZona, string pDescripcion, string pDispositivo)
{
	if (raiz == nullptr) {
		raiz = new Sensor(pNumZona, pDescripcion, pDispositivo);
	}
	else {
		if (raiz->numZona < pNumZona) {
			if (raiz->HD != nullptr) {
				insertar(pNumZona, pDescripcion, pDispositivo, raiz->HD);
			}
			else {
				raiz->HD = new Sensor(pNumZona, pDescripcion, pDispositivo);
				raiz->HD->padre = raiz;
			}
		}
		else {
			if (raiz->HI != nullptr) {
				insertar(pNumZona, pDescripcion, pDispositivo, raiz->HI);
			}
			else {
				raiz->HI = new Sensor(pNumZona,pDescripcion,pDispositivo);
				raiz->HI->padre = raiz;
			}
		}
	}
	raiz->color = false;
}

void SistemaAlarma::insertar(int pNumZona, string pDescripcion, string pDispositivo, Sensor* pRaiz)
{
	if (pNumZona > pRaiz->numZona) {
		if (pRaiz->HD != nullptr) {
			insertar(pNumZona, pDescripcion, pDispositivo, pRaiz->HD);
		}
		else {
			pRaiz->HD = new Sensor(pNumZona, pDescripcion, pDispositivo);
			pRaiz->HD->padre = pRaiz;
			if (pRaiz->color) {
				reglaDelTio(pRaiz->HD);
			}
			else {
				return;
			}
		}
	}
	else {
		if (pRaiz->HI != nullptr) {
			insertar(pNumZona, pDescripcion, pDispositivo, pRaiz->HI);
		}
		else {
			pRaiz->HI = new Sensor(pNumZona, pDescripcion, pDispositivo);
			pRaiz->HI->padre = pRaiz;
			if (pRaiz->color) {
				reglaDelTio(pRaiz->HI);
			}
			else {
				return;
			}
		}
	}
}

void SistemaAlarma::reglaDelTio(Sensor* sensor)
{
	Sensor* t = tio(sensor);
	if ((t != nullptr) && (t->color)) {
		sensor->padre->color = false;
		t->color = false;
		Sensor* a = abuelo(sensor);
		a->color = true;
		if ((a->padre != nullptr) && (a->padre->color)) {
			reglaDelTio(a);
		}
	}
	else {
		rotar(sensor);
	}
}

Sensor* SistemaAlarma::abuelo(Sensor* sensor)
{
	if ((sensor != nullptr) && (sensor->padre != nullptr)) {
		return sensor->padre->padre;
	}
	else {
		return nullptr;
	}
}

Sensor* SistemaAlarma::tio(Sensor* sensor)
{
	Sensor* a = abuelo(sensor);
	if (sensor->padre == a->HI) {
		return a->HD;
	}
	else {
		return a->HI;
	}
}

void SistemaAlarma::rotar(Sensor* sensor)
{
	Sensor* a = abuelo(sensor);
	if ((sensor == sensor->padre->HD) && (sensor->padre == a->HD)) {
		rotacionIzquierda(sensor);

	}
	else if ((sensor == sensor->padre->HI) && (sensor->padre == a->HI)) {
		rotacionDerecha(sensor);
	}
	else {
		if ((a->HI != nullptr) && (a->HI->HD != nullptr)) {
			rotacionDobleIzquierda(sensor);
		}
		else if ((a->HD != nullptr) && (a->HD->HI != nullptr)) {
			rotacionDobleDerecha(sensor);
		}
	}
}

void SistemaAlarma::rotacionIzquierda(Sensor* sensor)
{
	Sensor* a = abuelo(sensor);
	Sensor* pPadre = sensor->padre;
	pPadre->padre = a->padre;
	if (a->padre == nullptr) {
		raiz = pPadre;
	}
	a->padre = pPadre;
	a->HD = pPadre->HI;
	if (a->HD != nullptr) {
		a->HD->padre = a;
	}
	pPadre->HI = a;
	pPadre->color = !(pPadre->color);
	a->color = !(a->color);
	if ((pPadre->padre != nullptr) && (pPadre->padre->HD == a)) {
		pPadre->padre->HD = pPadre;
	}
	else {
		if ((pPadre->padre != nullptr) && (pPadre->padre->HI == a)) {
			pPadre->padre->HI = pPadre;
		}
	}
	if ((a->HD != nullptr) && (a->HD->color) && (a->color)) {
		reglaDelTio(a->HD);
	}
	else {
		if ((a->HI != nullptr) && (a->HI->color) && (a->color)) {
			reglaDelTio(a->HI);
		}
	}
	if ((pPadre->padre != nullptr) && (pPadre->padre->color) && (pPadre->color)) {
		reglaDelTio(pPadre);
	}
}

void SistemaAlarma::rotacionDerecha(Sensor* sensor)
{
	Sensor* a = abuelo(sensor);
	Sensor* pPadre = sensor->padre;
	pPadre->padre = a->padre;
	if (a->padre == nullptr) {
		raiz = pPadre;
	}
	a->padre = pPadre;
	a->HI = pPadre->HD;
	if (a->HI != nullptr) {
		a->HI->padre = a;
	}
	pPadre->HD = a;
	pPadre->color = !(pPadre->color);
	a->color = !(a->color);
	if ((pPadre->padre != nullptr) && (pPadre->padre->HD == a)) {
		pPadre->padre->HD = pPadre;
	}
	else {
		if ((pPadre->padre != nullptr) && (pPadre->padre->HI == a)) {
			pPadre->padre->HI = pPadre;
		}
	}
	if ((a->HD != nullptr) && (a->HD->color) && (a->color)) {
		reglaDelTio(a->HD);
	}
	else {
		if ((a->HI != nullptr) && (a->HI->color) && (a->color)) {
			reglaDelTio(a->HI);
		}
	}
	if ((pPadre->padre != nullptr) && (pPadre->padre->color) && (pPadre->color)) {
		reglaDelTio(pPadre);
	}
}

void SistemaAlarma::rotacionDobleIzquierda(Sensor* sensor)
{
	Sensor* a = abuelo(sensor);
	Sensor* pPadre = sensor->padre;
	sensor->padre = a->padre;
	if (a->padre == nullptr) {
		raiz = sensor;
	}
	pPadre->HD = sensor->HI;
	a->HI = sensor->HD;
	sensor->HI = pPadre;
	sensor->HD = a;
	a->padre = sensor;
	pPadre->padre = sensor;
	sensor->color = !(sensor->color);
	a->color = !(a->color);
	if ((sensor->padre != nullptr) && (sensor->padre->HD == a)) {
		sensor->padre->HD = sensor;
	}
	else {
		if ((sensor->padre != nullptr) && (sensor->padre->HI == a)) {
			sensor->padre->HI = sensor;
		}
	}
	if ((a->HD != nullptr) && (a->HD->color) && (a->color)) {
		reglaDelTio(a->HD);
	}
	else {
		if ((a->HI != nullptr) && (a->HI->color) && (a->color)) {
			reglaDelTio(a->HI);
		}
	}
	if ((pPadre->HD != nullptr) && (pPadre->HD->color) && (pPadre->color)) {
		reglaDelTio(pPadre->HD);
	}
	else {
		if ((pPadre->HI != nullptr) && (pPadre->HI->color) && (pPadre->color)) {
			reglaDelTio(pPadre->HI);
		}
	}
	if ((sensor->padre != nullptr) && (sensor->padre->color) && (sensor->color)) {
		reglaDelTio(sensor);
	}
}

void SistemaAlarma::rotacionDobleDerecha(Sensor* sensor)
{
	Sensor* a = abuelo(sensor);
	Sensor* pPadre = sensor->padre;
	sensor->padre = a->padre;
	if (a->padre == nullptr) {
		raiz = sensor;
	}
	pPadre->HI = sensor->HD;
	a->HD = sensor->HI;
	sensor->HD = pPadre;
	sensor->HI = a;
	a->padre = sensor;
	pPadre->padre = sensor;
	sensor->color = !(sensor->color);
	a->color = !(a->color);
	if ((sensor->padre != nullptr) && (sensor->padre->HD == a)) {
		sensor->padre->HD = sensor;
	}
	else {
		if ((sensor->padre != nullptr) && (sensor->padre->HI == a)) {
			sensor->padre->HI = sensor;
		}
	}
	if ((a->HD != nullptr) && (a->HD->color) && (a->color)) {
		reglaDelTio(a->HD);
	}
	else {
		if ((a->HI != nullptr) && (a->HI->color) && (a->color)) {
			reglaDelTio(a->HI);
		}
	}
	if ((pPadre->HD != nullptr) && (pPadre->HD->color) && (pPadre->color)) {
		reglaDelTio(pPadre->HD);
	}
	else {
		if ((pPadre->HI != nullptr) && (pPadre->HI->color) && (pPadre->color)) {
			reglaDelTio(pPadre->HI);
		}
	}
	if ((sensor->padre != nullptr) && (sensor->padre->color) && (sensor->color)) {
		reglaDelTio(sensor);
	}
}

void SistemaAlarma::inorden()
{
	system("cls");
	cout << "Numero de zona:\t\tDescripcion:\tDispositivo:" << endl;
	if (raiz != nullptr) {
		if (raiz->HI != nullptr) {
			inorden(raiz->HI);
		}
		cout << "\t" << raiz->numZona << "\t\t" << raiz->descripcion << "\t\t" << raiz->dispositivo <<endl;
		if (raiz->HD != nullptr) {
			inorden(raiz->HD);
		}
	}
}

void SistemaAlarma::inorden(Sensor*pRaiz)
{
	if (pRaiz->HI != nullptr) {
		inorden(pRaiz->HI);
	}
	cout << "\t" << pRaiz->numZona << "\t\t" << pRaiz->descripcion << "\t\t" << pRaiz->dispositivo << endl;
	if (pRaiz->HD != nullptr) {
		inorden(pRaiz->HD);
	}
}

void SistemaAlarma::borrar(int pNumZona)
{
	borrar(pNumZona, raiz);
}

void SistemaAlarma::borrar(int pNumZona, Sensor*pRaiz)
{
	if (pRaiz != nullptr) {
		if (pRaiz->numZona > pNumZona) {
			borrar(pNumZona, pRaiz->HI);
		}
		if (pRaiz->numZona < pNumZona) {
			borrar(pNumZona, pRaiz->HD);
		}
		if (pRaiz->numZona == pNumZona) {
			if ((pRaiz->HD == nullptr) && (pRaiz->HI == nullptr)) {
				if (pRaiz->padre == nullptr) {
					delete raiz;
					raiz = nullptr;
				}
				else {
					if (pRaiz->padre->HI == pRaiz) {
						pRaiz->padre->HI = nullptr;
						delete pRaiz;
					}
					else{
						pRaiz->padre->HD = nullptr;
						delete pRaiz;
					}
				}
			}
			else {
				if (pRaiz->HD != nullptr) {
					Sensor*menorMayores = pRaiz->HD;
					while (menorMayores->HI != nullptr) {
						menorMayores = menorMayores->HI;
					}
					if (pRaiz->padre == nullptr) {
						raiz = menorMayores;
						raiz->padre->HI = raiz->HD;
						if (raiz->padre->HI != nullptr) {
							raiz->padre->HI->padre = raiz->padre;
						}
						raiz->padre = nullptr;
						if (pRaiz->HD != raiz) {
							raiz->HD = pRaiz->HD;
						}
						raiz->HI = pRaiz->HI;
						if (raiz->HD != nullptr) {
							raiz->HD->padre = raiz;
						}
						if (raiz->HI != nullptr) {
							raiz->HI->padre = raiz;
						}
						delete pRaiz;
					}
					else {
						menorMayores->padre->HI = menorMayores->HD;
						if (menorMayores->padre->HI != nullptr) {
							menorMayores->padre->HI->padre = menorMayores->padre;
						}
						menorMayores->padre = pRaiz->padre;
						if (menorMayores->padre->HI == pRaiz) {
							menorMayores->padre->HI = menorMayores;
						}
						if (menorMayores->padre->HD == pRaiz) {
							menorMayores->padre->HD = menorMayores;
						}
						if (pRaiz->HD != menorMayores) {
							menorMayores->HD = pRaiz->HD;
						}
						menorMayores->HI = pRaiz->HI;
						if (menorMayores->HD != nullptr) {
							menorMayores->HD->padre = menorMayores;
						}
						if (menorMayores->HI != nullptr) {
							menorMayores->HI->padre = menorMayores;
						}
						delete pRaiz;
					}
				}
				else {
					Sensor*mayorMenores = pRaiz->HI;
					while (mayorMenores->HD != nullptr) {
						mayorMenores = mayorMenores->HD;
					}
					if (pRaiz->padre == nullptr) {
						raiz = mayorMenores;
						raiz->padre->HD = raiz->HI;
						if (raiz->padre->HD != nullptr) {
							raiz->padre->HD->padre = raiz->padre;
						}
						raiz->padre = nullptr;
						raiz->HD = pRaiz->HD;
						if (pRaiz->HI != raiz) {
							raiz->HI = pRaiz->HI;
						}
						if (raiz->HD != nullptr) {
							raiz->HD->padre = raiz;
						}
						if (raiz->HI != nullptr) {
							raiz->HI->padre = raiz;
						}
						delete pRaiz;
					}
					else {
						mayorMenores->padre->HD = raiz->HI;
						if (mayorMenores->padre->HD != nullptr) {
							mayorMenores->padre->HD->padre = mayorMenores->padre;
						}
						mayorMenores->padre = pRaiz->padre;
						if (mayorMenores->padre->HI == pRaiz) {
							mayorMenores->padre->HI = mayorMenores;
						}
						if (mayorMenores->padre->HD == pRaiz) {
							mayorMenores->padre->HD = mayorMenores;
						}
						mayorMenores->HD = pRaiz->HD;
						if (pRaiz->HI != mayorMenores) {
							mayorMenores->HI = pRaiz->HI;
						}
						if (mayorMenores->HD != nullptr) {
							mayorMenores->HD->padre = mayorMenores;
						}
						if (mayorMenores->HI != nullptr) {
							mayorMenores->HI->padre = mayorMenores;
						}
						delete pRaiz;
					}
				}
			}
		}
	}
}

Sensor*SistemaAlarma::buscar(int pNumZona)
{
	return buscar(pNumZona, raiz);
}

Sensor*SistemaAlarma::buscar(int pNumZona, Sensor*pRaiz)
{
	if (pRaiz != nullptr) {
		if (pRaiz->numZona == pNumZona) {
			return pRaiz;
		}
		if (pRaiz->numZona < pNumZona) {
			buscar(pNumZona, pRaiz->HD);
		}
		if (pRaiz->numZona > pNumZona) {
			buscar(pNumZona, pRaiz->HI);
		}
	}
}

void SistemaAlarma::mostrarCod_secundario()
{
	CodigoSecundario*aux = codsSecundarios;
	system("cls");
	cout << "Codigo:\t\t\t" << "Nombre:\t\t\t" << "Telefono:" << endl;
	while (aux != nullptr) {
		cout << aux->codigo << "\t\t\t" << aux->nombre << "\t\t\t" << aux->telefono << endl;
		aux = aux->siguiente;
	}
}

void SistemaAlarma::insertarCodigoSecundario(int pNumCodigo, int pCodigo, string pNombre, int pTelefono)
{
	if (codsSecundarios == nullptr) {
		codsSecundarios = new CodigoSecundario(pNumCodigo, pCodigo, pNombre, pTelefono);
		return;
	}
	CodigoSecundario*aux = codsSecundarios;
	while (aux->siguiente != nullptr) {
		aux = aux->siguiente;
	}
	aux->siguiente = new CodigoSecundario(pNumCodigo, pCodigo, pNombre, pTelefono);
	cout << aux->siguiente << endl;
}

bool SistemaAlarma::validar(string pcontra)
{
	bool mayus = false;
	bool minus = false;
	bool digi = false;
	bool simbol = false;
	if (pcontra.length() >= 8) {
		for (unsigned i = 0; i < pcontra.length(); ++i) {
			if (pcontra.at(i) >= 65 && pcontra.at(i) < 91) {
				mayus = true;
			}
			else {
				if (pcontra.at(i) >= 95 && pcontra.at(i) < 123) {
					minus = true;
				}
				else {
					if (pcontra.at(i) >= 48 && pcontra.at(i) < 58) {
						digi = true;
					}
					else {
						simbol = true;
					}
				}
			}
		}
	} else {
		return false;
	}
	if (mayus && minus && digi && simbol) {
		return true;
	}
	return false;
}
