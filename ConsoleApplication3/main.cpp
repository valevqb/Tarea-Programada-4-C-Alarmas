#include "pch.h"
#include <iostream>
#include "SistemaAlarma.h"

int main()
{
	SistemaAlarma sis1(1249,"248");
	sis1.insertar(1,"No c","No c 0x01");
	sis1.insertar(5, "No c", "No c 0x05");
	sis1.insertar(3, "No c", "No c 0x03");
	sis1.insertar(8, "No c", "No c 0x08");
	sis1.insertar(17, "No c", "No c 0x03");
	sis1.insertar(2, "No c", "No c 0x03");
	sis1.inorden();
	sis1.~SistemaAlarma();
	cout << (sis1.validar("Guayaboscr1?")) << endl;
}
