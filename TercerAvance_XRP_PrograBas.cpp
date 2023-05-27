#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>// funcion new y delete
#include <vector>

using namespace std;

//definir la funcion
void Alta();
void listas();
void archivos();
void eliminar();
void modificar();
//punteros
int alta, * item, contador; //los punteros son los operadores para reservar y liberar dinamicamente memoria.
float* precioun, * total;
string* nomart, * desc, * genero, * clasif, * consola, * stock;
int main()
{
	int opc;
	char a = 1, b = 2, c = 3, d = 4, p = 168, e = 130, z = 161, o = 162, u = 163;
	//1- Carita feliz blanca, 2- Carita feliz negra, 3- Corazon, 4- Rombo, 168- Signo de pregunta, 130- é, 161= í, 162- ó
	printf("%c %c %c Bienvenido al men%c de opciones, %cQu%c opci%cn desea seleccionar? %c %c %c\n", d, d, d, u, p, e, o, d, d, c);
	printf("\n 1-Alta de art%cculos %c\n 2-Mostrar %c\n 3-Limpiar pantalla %c\n 4-Modificar %c\n 5-Eliminar %c\n 6-Crear archivo %c\n 7-Salir %c \n", z, a, b, c, d, a, b, c);
	scanf_s("%d", &opc);

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		listas();
		return main();
		break;

	case 3:
		system("cls"); //system("clear");
		return main();
		break;

	case 4:
		modificar();
		return main();
		break;

	case 5:
		eliminar();
		return main();
		break;

	case 6:
		archivos();
		return main();
		break;

	case 7:  //opción de salir
		exit(1);
		break;
	}
}

void Alta()
{
	//acentos
	char c = 3, u = 163, z = 161, o = 162, e = 130, a = 160;//163=ú

	printf("Digite el n%cmero de registros que desea dar de alta \n", u);
	scanf_s("%d", &alta);
	//arreglos
	/*el new intenta asignar e inicializar un objeto o matriz de objetos de un tipo especificado o de
	un marcador de posición, y devuelve un puntero con tipo adecuado y distinto de cero al objeto (o al objeto inicial de la matriz)*/
	item = new int[alta];
	nomart = new string[alta];
	desc = new string[alta];
	genero = new string[alta];
	clasif = new string[alta];
	consola = new string[alta];
	precioun = new float[alta];
	total = new float[alta];
	stock = new string[alta];

	for (int i = 0; i < alta; i++)
	{

		printf("Ingrese el n%cmero de item %c\n", u, c);
		scanf_s("%d", &item[i]);

		while (getchar() != '\n'); //se vacia el buffer o el espacio o cin.ignore
		printf("Ingrese nombre del articulo %c\n", c);
		getline(cin, nomart[i]); //el getline es una función que lee una línea entera, almacenando el texto (incluyendo el espaciado)
		printf("Ingrese la descripci%cn del juego %c\n", o, c);
		getline(cin, desc[i]);
		printf("Ingrese el g%cnero del juego %c\n", e, c);
		getline(cin, genero[i]);
		printf("Ingrese la clasificaci%cn del juego %c\n", o, c);
		getline(cin, clasif[i]);
		printf("Ingrese la consola del juego %c\n", c);
		getline(cin, consola[i]);
		printf("Ingrese el precio unitario %c\n", c);
		scanf_s("%f", &precioun[i]);
		while (getchar() != '\n');
		printf("Disponibilidad de stock %c (Disponible o No disponible) %c\n", c, c); //lo agregue para que tuviera sentido con el if del listas
		getline(cin, stock[i]);
		


		//* subtotal, * iva, * total

	}
}

void listas()
{
	char c = 3, u = 163, z = 161, o = 162, e = 130;

	for (int i = 0; i < alta; i++)
	{
		//if (item[i] == 0)
		if (stock[i] == "NO DISPONIBLE")
		{
			printf("REGISTRO %d NO DISPONIBLE :( \n", i + 1);
		}
		else
		{
			printf("\n %c %c %c REGISTRO %d %c %c %c\n", c, c, c, i + 1, c, c, c);
			printf("El n%cmero del item es: %d \n", u, item[i]);
			printf("El nombre del articulo es: %s \n", nomart[i].c_str());
			printf("La descripci%cn del juego es: %s \n", o, desc[i].c_str());
			printf("El g%cnero del juego es: %s \n", e, genero[i].c_str());
			printf("La clasificaci%cn es: %s \n", o, clasif[i].c_str());
			printf("LA consola es: %s \n", consola[i].c_str());
			printf("EL precio unitario es: %f \n", precioun[i]);
			total[i] = precioun[i] * 1.16 + precioun[i];//cálculo del pecio unitario con el IVA
			printf("El precio total con IVA incluido es: %f \n", total[i]);
			printf("Stock %s \n", stock[i].c_str());
		}
	}
}

void archivos()
{
	ofstream archivo; //clase ifstream para leer archivos
	string nombrearchivo;
	int texto;
	string texto2;
	char d = 4;

	while (getchar() != '\n');
	printf("Ingrese el nombre del archivo:");//tner en cuenta que el nombre del archivo tiene que ir seguido de .txt
	getline(cin, nombrearchivo); //El usuario nombra el archivo creado

	//nombrearchivo = "altasitem.txt";

	archivo.open(nombrearchivo.c_str(), ios::out); //abriendo el archivo

	if (archivo.fail())
	{
		printf("\n %c ERROR NO SE PUDO CREAR EL ARCHIVO %c \n", d, d);
		exit(1);
	}

	archivo << "ITEM" << "\t";
	archivo << "NOMBRE DEL ARTICULO" << "\t";
	archivo << "DESCRIPCION" << "\t";
	archivo << "GENERO" << "\t";
	archivo << "CLASIFICACION" << "\t";
	archivo << "CONSOLA" << "\t";
	archivo << "STOCK" << "\t" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (stock[i] == "NO DISPONIBLE")
		{
			texto2 = "NO DISPONIBLE ";
			texto = i + 1;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			texto = item[i];
			archivo << texto << "\t" << "\t";
			texto2 = nomart[i];
			archivo << texto2 << "\t" << "\t";
			texto2 = desc[i];
			archivo << texto2 << "\t " << "\t";
			texto2 = genero[i];
			archivo << texto2 << "\t " << "\t";
			texto2 = clasif[i];
			archivo << texto2 << "\t " << "\t";
			texto2 = consola[i];
			archivo << texto2 << "\t " << "\t";
			texto2 = "disponible";
			archivo << texto2 << "\t" << "\n ";

		}
	}

	archivo.close();
}

void eliminar()
{
	int j;
	char a = 1, z = 248;//248=°
	printf("%c Ingrese el  registro a eliminar:\n", a);
	scanf_s("%d", &j);
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("%c Eliminando registro %c \n", z, z, j + 1);
		stock[i] = "NO DISPONIBLE";
		/*
		item[i] = 0;
		nombre[i] = " ";
		calf[i] = 0;
		calflab[i] = 0;
		*/
	}
}

void modificar()
{
	char c = 3, u = 163, z = 161, o = 162, e = 130, a = 160, b = 2;//160=á
	int j, opcion, op2;
	do
	{
		printf("Ingrese el n%cmero del articulo a modificar: \n", u);
		scanf_s("%d", &j);
		j = j - 1; // esto debido a que i inicia en 0

		for (int i = j; i == j; i++)
		{
			if ((stock[i] == "NO DISPONIBLE"))
			{
				printf("ARTICULO NO DISPONIBLE \n", i + 1);
				printf("Ingrese un n%cmero de articulo v%clido \n \n", u, a);
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);
	printf("Ingrese que desea modificar: \n 1-Item %c\n 2-Nombre del articulo %c\n 3-Descripci%cn %c\n 4-G%cnero %c\n", b, b, o, b, e, b);
	printf(" 5-Clasificaci%cn %c\n 6-Consola %c\n 7-Precio unitario %c\n 8-Stock %c\n", o, b, b, b, b);
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese item \n ", i);
			scanf_s("%d", &item[i]);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese nombre del articulo:\n");
			getline(cin, nomart[i]);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese descripci%cn\n", o);
			getline(cin, desc[i]);
		}
		break;

	case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese el g%cnero\n", e);
			getline(cin, genero[i]);
		}
		break;

	case 5:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese clasificaci%cn \n", o);
			getline(cin, clasif[i]);
		}
		break;

	case 6:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese la consola: \n");
			getline(cin, consola[i]);
		}
		break;
	case 7:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese el precio unitario: \n");
			scanf_s("%f", &precioun[i]);
		}
		break;
	case 8:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese el stock: \n");
			getline(cin, stock[i]);
		}
		break;
	}
}