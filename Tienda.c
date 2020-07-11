#include <stdio.h>
#include <windows.h>
#include "libraries/Articulos.h"

void menu();

void main()
{
    SetConsoleTitle("Bienvenido al sistema de tienda tienda de Eimy Corcino 2018-6245");
    menu();
}

void menu()
{
    int option;
    printf("\n\t\tBienvenido a mi tienda de libros\n\n");
    printf("1-) Agregar un articulo\n 2-) Ver articulos\n\n");

    printf("Favor en elegir una opcion:\t");

    scanf("%d",&option);

    switch (option)
    {
        case 1:
            {
                printf("1");
            }
        break;

        case 2:
            {
                printf("2");
            }
        break;
        
        default:
            system("cls");
            menu();
        break;
    }
}