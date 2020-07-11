//Invocando las librerías del sistema
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

//Invocando las librerías creadas
#include "libraries/Naves/Inicializacion.h"
#include "libraries/Naves/pantalla.h"
#include "libraries/Naves/jugabilidad.h"
#include "libraries/Naves/Nave.h"
#include "libraries/Naves/Asteroides.h"
#include "libraries/Naves/Constantes.h"
#include "libraries/Naves/balas.h"

//Referencia para así crear el videojuego de la nave
//https://github.com/wesbdss/C137-The-Nave-Game/blob/master/C137(Final)(Finalizado).c Aquí teniendo una idea en como hacerla
//https://www.lawebdelprogramador.com/codigo/C-Visual-C/4494-Juego-de-naves.html Aquí otra referencia


//Variable global
int enJuego = 1;

void main()
{
    int i;

    inicio();
    while(enJuego)
    {
        ///funciones atentas al teclado y juego
        naveMover(&balasA[num]);
        naveMuerte(&enJuego);

        for(i=0;i<nAst;i++)
            AsteroideColisionNave(&Ast[i]);

        if(!cajaBalasLLena())
        {
            for(i=0;i<cantBalas;i++)
            {
                if(!cajaBalas[i])
                    naveBalaMovimiento(&balasA[i],i);
            }
        }

        colisionBalaAsteroide();

        ///generar primeros asteroides
        for(i=0;i<nAst;i++)
            AsteroideMovimiento(&Ast[i]);

        //Receso por 30 segundo
        Sleep(30);
    }

    //Fin del juego y actualización de la pantalla
    gotoxy(ANCHO/2-4,ALTO/2); printf("GameOver");
    Beep(450, 110);
    Beep(500, 110);
    Beep(550, 110);
    Beep(450, 110);
    Beep(675, 200);
    Beep(675, 200);
    Beep(600, 300);
    Beep(450, 110);
    Beep(500, 110);
    Beep(550, 110);
    Beep(450, 110);
    Beep(600, 200);
    Beep(600, 200);
    Beep(550, 300);
    Beep(525, 110);
    Beep(450, 300);
    Beep(450, 110);
    Beep(500, 110);
    Beep(550, 110);
    Beep(450, 110);
    Beep(500, 400);
    Beep(600, 300);
    Beep(500, 400);
    Beep(475, 200);
    Beep(450, 200);
    Beep(400, 200);
    Beep(600, 500);
    Beep(525, 500);
    Beep(450, 110);
    Beep(500, 110);
    Beep(550, 110);
    Beep(450, 110);
    Beep(675, 200);
    Beep(675, 200);
    Beep(600, 300);
    Beep(450, 110);
    Beep(500, 110);
    Beep(550, 110);
    Beep(450, 110);
    Beep(800, 200);
    Beep(500, 200);
    Beep(550, 300);
    Beep(525, 110);
    Beep(450, 300);
    Beep(450, 110);
    Beep(500, 110);
    Beep(550, 110);
    Beep(450, 110);
    Beep(500, 400);
    Beep(600, 300);
    Beep(500, 400);
    Beep(475, 200);
    Beep(450, 200);
    Beep(400, 200);
    Beep(600, 500);
    Beep(525, 500);
}