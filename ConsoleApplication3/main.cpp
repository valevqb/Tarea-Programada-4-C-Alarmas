#include "pch.h"
#include <iostream>
#include "SistemaAlarma.h"

int main()
{
	bool ciclo = true;
	char opcion = ' ';


	while (ciclo) 
	{
		system("cls");
		cout << "1 - Armar sistema" << endl;
		cout << "2 - Desarmar sistema" << endl;
		cout << "3 - Desactivar sistema" << endl;
		cout << "4 - Programar Zonas" << endl;
		cout << "5 - Lista de Zonas" << endl;
		cout << "6 - Bitacora" << endl;
		cout << "7 - Borrar Bitacora" << endl;
		cout << "8 - Establecer codigo de acceso principal" << endl;
		cout << "9 - Establecer codigos de acceso secundarios" << endl;
		cout << "0 - Fin" << endl;
		cout << "F - Fuego" << endl;
		cout << "A - Ayuda" << endl;
		cout << "P - Panico" << endl;
		cin >> opcion;
		switch (opcion) {
			case '1':
				//Aca insertamos las instrucciones de la opcion 1
				break;
			case '2':
				//Aca insertamos las instrucciones de la opcion 2
				break;
			case '3': 
				//Aca insertamos las instrucciones de la opcion 3
				break;
			case '4': 
				//Aca insertamos las instrucciones de la opcion 4
				break;
			case '5':
				//Aca insertamos las instrucciones de la opcion 5
				break;
			case '6':
				//Aca insertamos las instrucciones de la opcion 6
				break;
			case '7':
				//Aca insertamos las instrucciones de la opcion 7
				break;
			case '8':
				//Aca insertamos las instrucciones de la opcion 8
				break;
			case '9':
				//Aca insertamos las instrucciones de la opcion 9
				break;
			case '0':
				//Aca insertamos las instrucciones de la opcion 0
				break;
			case 'F':
				//Aca insertamos las instrucciones de la opcion F
				break;
			case 'A':
				//Aca insertamos las instrucciones de la opcion A
				break;
			case 'P':
				//Aca insertamos las instrucciones de la opcion P
				break;
			default:
				//Aca insertamos las instrucciones en caso de no haber colocado una opción válida
				break;
		}
	}
	//Esto de abajo son ejemplos de funcionamiento, pueden borrarse
	SistemaAlarma cliente1 = SistemaAlarma(901160160,"0987654321");
	cliente1.insertar(1, "Patio", "movimiento");
	cliente1.insertar(2, "Sala", "movimiento");
	cliente1.insertar(3, "Patio Trasero", "perro");
	cliente1.insertar(4, "Cocina", "humo");
	cliente1.insertar(2, "Patio", "humo");

	cliente1.inorden();
	cliente1.insertarCodigoSecundario(1234, 1, "Javier", 22345213);
	cliente1.insertarCodigoSecundario(1432, 2, "Javiera", 2865213);
	cliente1.insertarCodigoSecundario(1643, 3, "Jason", 22345242);
	cliente1.insertarCodigoSecundario(1954, 4, "Joseth", 22348613);
}
