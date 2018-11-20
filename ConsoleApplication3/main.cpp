#include "pch.h"
#include <iostream>
#include "SistemaAlarma.h"

int main()
{
	bool ciclo = true;
	char opcion = ' ';
	SistemaAlarma cliente1 = SistemaAlarma(901160160, "0987654321");
	while (ciclo) 
	{
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
				//Aca insertamos las instrucciones de la opcion 1 Mine
				system("cls");
				cliente1.armarSistema();
				break;
			case '2':
				//Aca insertamos las instrucciones de la opcion 2 Mine
				system("cls");
				cliente1.desarmarSistema();
				break;
			case '3': 
				//Aca insertamos las instrucciones de la opcion 3
				system("cls");

				break;
			case '4': 
				//Aca insertamos las instrucciones de la opcion 4
				system("cls");

				break;
			case '5':
				//Aca insertamos las instrucciones de la opcion 5
				system("cls");

				break;
			case '6':
				//Aca insertamos las instrucciones de la opcion 6 Mine
				system("cls");
				cliente1.mostrarBitacora();
				break;
			case '7':
				//Aca insertamos las instrucciones de la opcion 7 Mine
				system("cls");
				cliente1.borrarBitacora();
				break;
			case '8':
				//Aca insertamos las instrucciones de la opcion 8
				system("cls");

				break;
			case '9':
				//Aca insertamos las instrucciones de la opcion 9 Mine
				system("cls");
				cliente1.insertarCodigoSecundario(1234, 12345, "12431", 1341);
				break;
			case '0':
				//Aca insertamos las instrucciones de la opcion 0
				system("cls");
				ciclo = false;
				break;
			case 'F':
				//Aca insertamos las instrucciones de la opcion F
				system("cls");

				break;
			case 'A':
				//Aca insertamos las instrucciones de la opcion A
				system("cls");

				break;
			case 'P':
				//Aca insertamos las instrucciones de la opcion P
				system("cls");

				break;
			default:
				//Aca insertamos las instrucciones en caso de no haber colocado una opción válida
				system("cls");
				cout << "Opcion invalida, ingrese nuevamente" << endl;

				break;
		}
	}
	//Esto de abajo son ejemplos de funcionamiento, pueden borrarse
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
