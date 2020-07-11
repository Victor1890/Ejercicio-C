#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED

//Importando las librerías
#include "pantalla.h"
#include "balas.h"
#include "Constantes.h"

//Pintar nave
void navePintar()
{
    gotoxy(NaveUno.x,NaveUno.y);    printf("  %c",30);
    gotoxy(NaveUno.x,NaveUno.y+1); printf(" %c%c%c",40,207,41);
    gotoxy(NaveUno.x,NaveUno.y+2); printf("%c%c %c%c",30,190,190,30);
}

//Borrando la nave
void naveBorrar()
{
    gotoxy(NaveUno.x,NaveUno.y);   printf("     ");
    gotoxy(NaveUno.x,NaveUno.y+1); printf("     ");
    gotoxy(NaveUno.x,NaveUno.y+2); printf("     ");
}

//Muerte del jugador
void naveMuerte(int *enJuego)
{
    int delay = 150;
    if(NaveUno.corazones == 0)
    {
        Beep(200,100);
        naveBorrar();
        gotoxy(NaveUno.x,NaveUno.y);   printf("  *  ");
        gotoxy(NaveUno.x,NaveUno.y+1); printf(" *** ");
        gotoxy(NaveUno.x,NaveUno.y+2); printf("  *  ");
        Sleep(delay);

        naveBorrar();
        gotoxy(NaveUno.x,NaveUno.y);   printf("* * *");
        gotoxy(NaveUno.x,NaveUno.y+1); printf(" *** ");
        gotoxy(NaveUno.x,NaveUno.y+2); printf("* * *");
        Sleep(delay);

        naveBorrar();
        gotoxy(NaveUno.x,NaveUno.y);   printf("*   *");
        gotoxy(NaveUno.x,NaveUno.y+1); printf(" * * ");
        gotoxy(NaveUno.x,NaveUno.y+2); printf("* * *");
        Sleep(delay);

        naveBorrar();

        NaveUno.vidas--;

        if(NaveUno.vidas==0)
            *enJuego=0;
        else
        {
            NaveUno.corazones=corazones;
            navePintar();
        }
        naveCorazonesPintar();
    }
}

//Movimiento de la nave
void naveBalaMovimiento(struct Bala *balasA,int pos)
{
    balaBorrar(balasA);
    if((*balasA).y>posYMinima)
    {
        (*balasA).y = (*balasA).y -1 ;
        balaDibujar(balasA);
    }

    else
    {
        cajaBalas[pos]=1; copiaCantBalas++;
        naveCajaBalasDibujar();
    }
}

#endif // NAVE_H_INCLUDED
