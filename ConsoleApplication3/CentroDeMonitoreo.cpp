#include "pch.h"
#include "CentroDeMonitoreo.h"
#include <string>

void CentroDeMonitoreo::insertar(int pIdentificacion, string pCodigo)
{
	if (raiz == nullptr) {
		raiz = new SistemaAlarma(pIdentificacion, pCodigo);
	}
	else {
		if (raiz->identificacion < pIdentificacion) {
			if (raiz->HD != nullptr) {
				insertar(pIdentificacion, pCodigo, raiz->HD);
			}
			else {
				raiz->HD = new SistemaAlarma(pIdentificacion, pCodigo);
				raiz->HD->padre = raiz;
			}
		}
		else {
			if (raiz->HI != nullptr) {
				insertar(pIdentificacion, pCodigo, raiz->HI);
			}
			else {
				raiz->HI = new SistemaAlarma(pIdentificacion, pCodigo);
				raiz->HI->padre = raiz;
			}
		}
	}
	raiz->color = false;
}

void CentroDeMonitoreo::insertar(int pIdentificacion, string pCodigo, SistemaAlarma* pRaiz)
{
	if (pIdentificacion > pRaiz->identificacion) {
		if (pRaiz->HD != nullptr) {
			insertar(pIdentificacion, pCodigo, pRaiz->HD);
		}
		else {
			pRaiz->HD = new SistemaAlarma(pIdentificacion, pCodigo);
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
			insertar(pIdentificacion, pCodigo, pRaiz->HI);
		}
		else {
			pRaiz->HI = new SistemaAlarma(pIdentificacion, pCodigo);
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

void CentroDeMonitoreo::reglaDelTio(SistemaAlarma* sistemaAlarma)
{
	SistemaAlarma* t = tio(sistemaAlarma);
	if ((t != nullptr) && (t->color)) {
		sistemaAlarma->padre->color = false;
		t->color = false;
		SistemaAlarma* a = abuelo(sistemaAlarma);
		a->color = true;
		if ((a->padre != nullptr) && (a->padre->color)) {
			reglaDelTio(a);
		}
	}
	else {
		rotar(sistemaAlarma);
	}
}

SistemaAlarma* CentroDeMonitoreo::abuelo(SistemaAlarma* sistemaAlarma)
{
	if ((sistemaAlarma != nullptr) && (sistemaAlarma->padre != nullptr)) {
		return sistemaAlarma->padre->padre;
	}
	else {
		return nullptr;
	}
}

SistemaAlarma* CentroDeMonitoreo::tio(SistemaAlarma* sistemaAlarma)
{
	SistemaAlarma* a = abuelo(sistemaAlarma);
	if (sistemaAlarma->padre == a->HI) {
		return a->HD;
	}
	else {
		return a->HI;
	}
}

void CentroDeMonitoreo::rotar(SistemaAlarma* sistemaAlarma)
{
	SistemaAlarma* a = abuelo(sistemaAlarma);
	if ((sistemaAlarma == sistemaAlarma->padre->HD) && (sistemaAlarma->padre == a->HD)) {
		rotacionIzquierda(sistemaAlarma);

	}
	else if ((sistemaAlarma == sistemaAlarma->padre->HI) && (sistemaAlarma->padre == a->HI)) {
		rotacionDerecha(sistemaAlarma);
	}
	else {
		if ((a->HI != nullptr) && (a->HI->HD != nullptr)) {
			rotacionDobleIzquierda(sistemaAlarma);
		}
		else if ((a->HD != nullptr) && (a->HD->HI != nullptr)) {
			rotacionDobleDerecha(sistemaAlarma);
		}
	}
}

void CentroDeMonitoreo::rotacionIzquierda(SistemaAlarma* sistemaAlarma)
{
	SistemaAlarma* a = abuelo(sistemaAlarma);
	SistemaAlarma* pPadre = sistemaAlarma->padre;
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

void CentroDeMonitoreo::rotacionDerecha(SistemaAlarma* sistemaAlarma)
{
	SistemaAlarma* a = abuelo(sistemaAlarma);
	SistemaAlarma* pPadre = sistemaAlarma->padre;
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

void CentroDeMonitoreo::rotacionDobleIzquierda(SistemaAlarma* sistemaAlarma)
{
	SistemaAlarma* a = abuelo(sistemaAlarma);
	SistemaAlarma* pPadre = sistemaAlarma->padre;
	sistemaAlarma->padre = a->padre;
	if (a->padre == nullptr) {
		raiz = sistemaAlarma;
	}
	pPadre->HD = sistemaAlarma->HI;
	a->HI = sistemaAlarma->HD;
	sistemaAlarma->HI = pPadre;
	sistemaAlarma->HD = a;
	a->padre = sistemaAlarma;
	pPadre->padre = sistemaAlarma;
	sistemaAlarma->color = !(sistemaAlarma->color);
	a->color = !(a->color);
	if ((sistemaAlarma->padre != nullptr) && (sistemaAlarma->padre->HD == a)) {
		sistemaAlarma->padre->HD = sistemaAlarma;
	}
	else {
		if ((sistemaAlarma->padre != nullptr) && (sistemaAlarma->padre->HI == a)) {
			sistemaAlarma->padre->HI = sistemaAlarma;
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
	if ((sistemaAlarma->padre != nullptr) && (sistemaAlarma->padre->color) && (sistemaAlarma->color)) {
		reglaDelTio(sistemaAlarma);
	}
}

void CentroDeMonitoreo::rotacionDobleDerecha(SistemaAlarma* sistemaAlarma)
{
	SistemaAlarma* a = abuelo(sistemaAlarma);
	SistemaAlarma* pPadre = sistemaAlarma->padre;
	sistemaAlarma->padre = a->padre;
	if (a->padre == nullptr) {
		raiz = sistemaAlarma;
	}
	pPadre->HI = sistemaAlarma->HD;
	a->HD = sistemaAlarma->HI;
	sistemaAlarma->HD = pPadre;
	sistemaAlarma->HI = a;
	a->padre = sistemaAlarma;
	pPadre->padre = sistemaAlarma;
	sistemaAlarma->color = !(sistemaAlarma->color);
	a->color = !(a->color);
	if ((sistemaAlarma->padre != nullptr) && (sistemaAlarma->padre->HD == a)) {
		sistemaAlarma->padre->HD = sistemaAlarma;
	}
	else {
		if ((sistemaAlarma->padre != nullptr) && (sistemaAlarma->padre->HI == a)) {
			sistemaAlarma->padre->HI = sistemaAlarma;
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
	if ((sistemaAlarma->padre != nullptr) && (sistemaAlarma->padre->color) && (sistemaAlarma->color)) {
		reglaDelTio(sistemaAlarma);
	}
}

void CentroDeMonitoreo::inorden()
{
	cout << "Identificacion:"<< endl;
	if (raiz != nullptr) {
		if (raiz->HI != nullptr) {
			inorden(raiz->HI);
		}
		cout << "\t" << raiz->identificacion << endl;
		if (raiz->HD != nullptr) {
			inorden(raiz->HD);
		}
	}
}

void CentroDeMonitoreo::inorden(SistemaAlarma*pRaiz)
{
	if (pRaiz->HI != nullptr) {
		inorden(pRaiz->HI);
	}
	cout << "\t" << pRaiz->identificacion << endl;
	if (pRaiz->HD != nullptr) {
		inorden(pRaiz->HD);
	}
}

void CentroDeMonitoreo::borrar(int pIdentificacion)
{
	borrar(pIdentificacion, raiz);
}

void CentroDeMonitoreo::borrar(int pIdentificacion, SistemaAlarma*pRaiz)
{
	if (pRaiz != nullptr) {
		if (pRaiz->identificacion > pIdentificacion) {
			borrar(pIdentificacion, pRaiz->HI);
		}
		if (pRaiz->identificacion < pIdentificacion) {
			borrar(pIdentificacion, pRaiz->HD);
		}
		if (pRaiz->identificacion == pIdentificacion) {
			if ((pRaiz->HD == nullptr) && (pRaiz->HI == nullptr)) {
				if (pRaiz->padre == nullptr) {
					raiz->~SistemaAlarma();
					delete raiz;
					raiz = nullptr;
				}
				else {
					if (pRaiz->padre->HI == pRaiz) {
						pRaiz->padre->HI = nullptr;
						pRaiz->~SistemaAlarma();
						delete pRaiz;
					}
					else {
						pRaiz->padre->HD = nullptr;
						pRaiz->~SistemaAlarma();
						delete pRaiz;
					}
				}
			}
			else {
				if (pRaiz->HD != nullptr) {
					SistemaAlarma*menorMayores = pRaiz->HD;
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
						pRaiz->~SistemaAlarma();
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
						pRaiz->~SistemaAlarma();
						delete pRaiz;
					}
				}
				else {
					SistemaAlarma*mayorMenores = pRaiz->HI;
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
						pRaiz->~SistemaAlarma();
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
						pRaiz->~SistemaAlarma();
						delete pRaiz;
					}
				}
			}
		}
	}
}

SistemaAlarma*CentroDeMonitoreo::buscar(int pIdentificacion)
{
	return buscar(pIdentificacion, raiz);
}

SistemaAlarma*CentroDeMonitoreo::buscar(int pIdentificacion, SistemaAlarma*pRaiz)
{
	if (pRaiz != nullptr) {
		if (pRaiz->identificacion == pIdentificacion) {
			return pRaiz;
		}
		if (pRaiz->identificacion < pIdentificacion) {
			buscar(pIdentificacion, pRaiz->HD);
		}
		if (pRaiz->identificacion > pIdentificacion) {
			buscar(pIdentificacion, pRaiz->HI);
		}
	}
}