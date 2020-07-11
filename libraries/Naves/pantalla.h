#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

//Importando las librerías
#include "Asteroides.h"
#include "Constantes.h"

//Para resumir todo, esto es la interfaz del juego.


void gotoxy(int x,int y)
{
    HANDLE hConsola; //Nombre que tiene cada ventana
    hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    //Toma el control de la salida

    COORD pos;
    pos.X = x; pos.Y = y;

    SetConsoleCursorPosition(hConsola,pos);
}


void ocultarCursor()
{
    HANDLE hConsola;
    hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 50; //Tamanio del parpadeo
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(hConsola,&cursor);
}

void naveCajaBalasDibujar()
{
    int i;
    gotoxy(posXMinima,2); printf("Balas:");

    for(i=1;i<=cantBalas;i++)
    {
        gotoxy(posXMinima+6+i,2);
        printf(" ");
    }

    for(i=1;i<=copiaCantBalas;i++)
    {
        gotoxy(posXMinima+6+i,2);
        printf("|");
    }

    gotoxy(posXMinima+8+cantBalas,2); printf("Caja: ");

    ///Caja
    for(i=0;i<cantBalas;i++)
    {
        gotoxy(posXMinima+13+cantBalas+i,2);
        printf(" ");
    }


    for(i=0;i<cantBalas;i++)
    {
       gotoxy(posXMinima+14+cantBalas+i,2);
       printf("%d",cajaBalas[i]);
    }
}

void naveCorazonesPintar()
{
    int i;

    gotoxy(posXMaxima-20-corazones-1,2); printf("Vidas: %d",NaveUno.vidas);

    gotoxy(posXMaxima-7-corazones,2); printf("Salud:");

    for(i=0;i<corazones;i++)
    {
        gotoxy(posXMaxima-corazones+i,2);
        printf(" ");
    }//Para borrar rastros de corazones


    for(i=0;i<NaveUno.corazones;i++)
    {
        gotoxy(posXMaxima-corazones+i,2);
        printf("%c",3);
    }
}

void colisionBalaAsteroide()
{
    int i,j;
    gotoxy(posXMinima+19+cantBalas,2);
    printf("Score: %d",score);

    for(i=0;i<cantBalas;i++)
    {
        for(j=0;j<nAst;j++)
        {
           if((Ast[j].y==balasA[i].y||
               Ast[j].y-1==balasA[i].y||
               Ast[j].y+1==balasA[i].y) &&
              (Ast[j].x==balasA[i].x))
            {
                gotoxy(Ast[j].x,Ast[j].y); printf(" ");
                gotoxy(Ast[j].x,Ast[j].y+1); printf(" ");
                gotoxy(Ast[j].x,Ast[j].y-1); printf(" ");
                balasA[i].y=-2;

                Ast[j].x=rand()%(posXMaxima-posXMinima)+posXMinima;
                Ast[j].y=posYMinima;
                AsteroidePintar(&Ast[j]);
                score += 20;
                Beep(600,50);
            }
        }
    }
}

#endif // PANTALLA_H_INCLUDED