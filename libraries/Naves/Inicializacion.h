#ifndef INICIALIZACION_H_INCLUDED
#define INICIALIZACION_H_INCLUDED

//Importando las librerías
#include "pantalla.h"
#include "jugabilidad.h"
#include "Nave.h"
#include "Asteroides.h"
#include "Constantes.h"
#include "balas.h"

//En caracteres, no pixeles,etc
void pintarLimites()
{
    int i;
    //Lo que pinta X
    for(i=posXMinima-1;i<posXMaxima+1;i++)
    {
        gotoxy(i,posYMinima-1); printf("%c",205);
        gotoxy(i,posYMaxima+1);printf("%c",205);
    }

    //Lo que pinta y
    for(i=posYMinima-1;i<posYMaxima+1;i++)
    {
        gotoxy(posXMinima-1,i); printf("%c",186);
        gotoxy(posXMaxima+1,i); printf("%c",186);
    }

    gotoxy(posXMaxima,ALTO/2); printf("X");
    gotoxy(posXMinima,ALTO/2); printf("X");
    gotoxy(ANCHO/2,posYMaxima); printf("Y");
    gotoxy(ANCHO/2,posYMinima); printf("Y");

    ///arriba a abajo
    gotoxy(posXMinima-1,posYMinima-1); printf("%c",201);
    gotoxy(posXMinima-1,posYMaxima+1); printf("%c",200);

    gotoxy(posXMaxima+1,posYMinima-1); printf("%c",187);
    gotoxy(posXMaxima+1,posYMaxima+1); printf("%c",188);

}

//Iniciando el sistema
void inicio()
{
    system("title Jueguito de Naves :v");

    //Función graciasl al reloj del sistema
    srand(clock());

    //Oculando el cursos para así poder jugar
    ocultarCursor();

    //Limpiando la pantalla
    pintarLimites();


    NaveUno.x = ANCHO/2-3; NaveUno.y = ALTO-6;
    NaveUno.corazones = corazones; NaveUno.vidas = vidas;

    //Pintando la vida del jugador
    naveCorazonesPintar();

    //Pindando la nave
    navePintar();

    //Pindando las ballas
    naveCajaBalasDibujar();

    int i;
    for(i=0;i<nAst;i++)
    {
        Ast[i].x=rand()%(posXMaxima-posXMinima)+posXMinima;
        Ast[i].y=rand()%10+posYMinima;
    }
}

#endif // INICIALIZACION_H_INCLUDED