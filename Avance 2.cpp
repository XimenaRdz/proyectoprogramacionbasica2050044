#include<iostream>
#include <math.h>
#include<string>
#include<string.h>
#include<conio.h>
#include<wchar.h>
#include<stdio.h>
using namespace std;

struct Tienda
{
	int  item;
	char nomart[2500], desc[1000], genero[1500], clas[1500], consola[1000];
	float precioun, tot;
};

Tienda info[3];

int main()
{

	
	int opc, des;

	do
	{


		printf("Bienvenido al menu de opciones,Que opcion desea seleccionar \n");
		printf("1 - Alta de articulos \n 2 - Modificacion de articulos \n 3 - Baja de articulos \n 4 - Lista de articulos \n 5 - Limpiar pantalla\n 6- Salir \n");
		scanf_s("%d", &opc);

		switch (opc)
		{
		case 1: //Alta de articulos
			for (int i = 0; i < 3; i++)
			{
				printf(" \n Ingrese el numero de item: ");
				scanf_s("%d", &info[i].item);
				cin.ignore();
				printf("\n Ingrese el nombre del articulo:");
				gets_s(info[i].nomart);

				printf("\n Ingrese una breve descripcion del juego:");
				gets_s(info[i].desc);

				printf("\n Ingrese el genero del juego:");
				gets_s(info[i].genero);

				printf("\n Ingrese la clasificacion del juego:");
				gets_s(info[i].clas);

				printf("\n Ingrese a que consola pertenece el juego:");
				gets_s(info[i].consola);

				printf("\n Ingrese el precio unitario del juego:");
				scanf_s("%f", &info[i].precioun);
			}

			

			break;




		case 2:
			/*return al inicio
			printf("Desea volver al inicio \n 1-Si \n 2-No \n");
			scanf_s("%d", &des);
			if (des == 1)
			{
				return main();
			}*/
			return main();
			break;


		case 3:
				return main();
			
			break;


		case 4:
			for (int i = 0; i < 3; i++)
			{
				printf("El numero del item es: %d \n", info[i].item);
				printf("El nombre del articulo es: %s \n", info[i].nomart);
				printf("La descripcion es: %s \n", info[i].desc);
				printf("El genero del juego es: %s \n", info[i].genero);
				printf("La clasificacion del juego: %s \n", info[i].clas);
				printf("La consola es: %s \n", info[i].consola);
				printf("El precio unitario es: %f \n", info[i].precioun);
				info[i].tot = info[i].precioun * 1.16;     //operacion del precioun *el impuesto+ precioun
				printf("El total del precio por el juego junto con el IVA es de: %f \n", info[i].tot);
			}
			break;


		case 5: //limpiar pantalla
			system("cls");
			return main();
			break; //return main() break


		case 6://aqui hago la opcion de salir 
			exit(1);
			break;
		}
	} while (opc != 6);

}
