#include <stdio.h>
#include "libraries/Tablero.h"

void main()
{
    int Matriz_Tablero[8][8];  //el tama�o correcto seria 7x7 (el 0 cuenta), pero el compilador necesita un exceso de una fila y una columna para que no entre en conflicto con Windows
    int opcion,color,rehazMenu,turno,sino;
    char nombre[1][50];
    do
    {
        Jugar(Matriz_Tablero, opcion,color,rehazMenu,turno,sino,nombre);
    }
    while(rehazMenu==1);
}