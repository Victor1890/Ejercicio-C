#include <stdio.h>
#include <windows.h>
#include "libraries/_Complejos.h"

void menu();

void main()
{
	SetConsoleTitle("Bienvenido al Software de Eimy Corcino 2018-6245");
	menu();
}

void menu()
{
	int option;
	printf("1-) Suma de numeros complejos\n\n 2-) Resta de numeros complejos\n\n 3-) Multiplicacion de numeros complejos\n\n 4-) Division de numeros complejos\n\n 5-) Conjuntos de numeros complejos\n\n Favor en elegir una opcion:\t");

	scanf("%d", &option);
	
	switch (option)
	{
		case 1:
			{
				double a1,a2;
				system("cls");
				printf("Escribir el primer numero:\t"); scanf("%lf",&a1);
				printf("Escribir el segundo numero:\t"); scanf("%lf",&a2);
				SumarComplejos(a1,a2);
			}
		break;
		
		case 2:
			{
				double a1,a2;
				system("cls");
				printf("Escribir el primer numero:\t"); scanf("%lf",&a1);
				printf("Escribir el segundo numero:\t"); scanf("%lf",&a2);
				RestaComplejos(a1,a2);
			}
		break;

		case 3:
			{
				double a1,a2;
				system("cls");
				printf("Escribir el primer numero:\t"); scanf("%lf",&a1);
				printf("Escribir el segundo numero:\t"); scanf("%lf",&a2);
				MultiComplejos(a1,a2);
			}
		break;

		case 4:
			{
				double a1,a2;
				system("cls");
				printf("Escribir el primer numero:\t"); scanf("%lf",&a1);
				printf("Escribir el segundo numero:\t"); scanf("%lf",&a2);
				DivisionComplejos(a1,a2);
			}
		break;

		case 5:
			{
				double a1,a2;
				system("cls");
				printf("Escribir el primer numero:\t"); scanf("%lf",&a1);
				printf("Escribir el segundo numero:\t"); scanf("%lf",&a2);
				ConjugadoComplejos(a1,a2);
			}
		break;

		default:
			{
				system("cls");
				menu();
			}
		break;
	}
}