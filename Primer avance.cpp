#include<iostream>
using namespace std;

int main()
{
	int opc, item, des;
	char nomart[25], desc[100], genero[15], clas[15], consola[10];
	float precioun, tot;

	cout << "Bienvenido al menu de opciones,Que opcion desea seleccionar?" << endl;
	cout << "1- Alta de articulos" << endl << "2- Modificacion de articulos" << endl << "3- Baja de articulos" << endl << "4- Lista de articulos" << endl << "5- Limpiar pantalla" << endl;
	cout << "6- Salir" << endl;
	cin >> opc;

	switch (opc)
	{
	case 1: //Alta de articulos
		cout << "Ingrese el numero de item:" << endl;
		cin >> item;

		cout << "Ingrese el nombre del articulo:" << endl;
		cin >> nomart;

		cout << "Ingrese una breve descripcion del juego:" << endl;
		cin >> desc;

		cout << "Ingrese el genero del juego:" << endl;
		cin >> genero;

		cout << "Ingrese la clasificacion del juego:" << endl;
		cin >> clas;

		cout << "Ingrese a que consola pertenece el juego:" << endl;
		cin >> consola;

		cout << "Ingrese el precio unitario del juego:" << endl;
		cin >> precioun;

		tot = precioun * 1.16;     //operacion del precioun *el impuesto+ precioun

		cout << "El total del precio por el juego es de:" << endl << tot << endl;

		//return al inicio
		cout << "Desea volver al inicio del menu?" << endl << "1-Si" << endl << "2-No" << endl;
		cin >> des;
		if (des == 1)
		{
			return main();
		}

		break;



	case 2:
		break;


	case 3:

		break;


	case 4:

		break;


	case 5: //limpiar pantalla
		system("cls");
		return main();
		break; //return main() break


	case 6://aqui hago la opcion de salir 
		exit(1);
		break;
	}

}


