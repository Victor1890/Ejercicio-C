//Definiendo la jugabilidad
#ifndef JUGABILIDAD_H_INCLUDED
#define JUGABILIDAD_H_INCLUDED

//Importando la librería del sistema
#include <dos.h>

//Importando las librerías
#include "Nave.h"
#include "Constantes.h"
#include "balas.h"

//Creando el médoto de poder manejar la pequeña nave
void naveMover(struct Bala *balasA)
{
    //Tratando de implementar métodos modernos como los booleanos
    //Si kbhit es mayor que 1, entonces es verdadero
    if(kbhit())
    {
        //Obteniendo los comandos del teclado
        char tecla = getch(); //Obtiene tecla
        naveBorrar(); //Borrar nave


        if(tecla == IZQUIERDA && NaveUno.x>posXMinima)
            NaveUno.x = NaveUno.x - 1;
        if(tecla == DERECHA && NaveUno.x+5<posXMaxima)
            NaveUno.x = NaveUno.x + 1;
        if(tecla == ARRIBA && NaveUno.y>posYMinima)
            NaveUno.y = NaveUno.y - 1;
        if(tecla == ABAJO && NaveUno.y+2<posYMaxima)
            NaveUno.y = NaveUno.y + 1;

        if(tecla == 'r')
        {
            NaveUno.vidas =vidas;
            NaveUno.corazones=corazones;
            copiaCantBalas = cantBalas;
        }

        //Poner Pausa al juego
        if(tecla == 'p')
        {
            gotoxy(ANCHO/2-3,ALTO/2);
            printf("PAUSA...");
            getch();
            gotoxy(ANCHO/2-3,ALTO/2);
            printf("        ");
        }

        //Ingresando nuevas propiedades
        if(tecla == 'e')
        {
            char nota[100];
            system("cls");
            system("color 0b");
            gotoxy(posXMinima,posYMinima);
            printf("Ingrese nota");
            gotoxy(posXMinima,posYMinima+2);
            gets(nota);
            system("cls");
            system("color 0f");
            pintarLimites();

        }

        //Mi parte favorita, la música del juego
        if(tecla == 'g')
        {
            Beep(300,100); ///sonido y delay
        }

        //Actualización de la pantalla
        if(tecla == 'h')
        {
            Beep(220,300);
            Beep(294,300);
            Beep(294,300);
            Beep(370,300);
            Beep(494,300);
            Beep(370,300);
            Beep(440,800);
            /* */
            Beep(440,300);
            Beep(494,300);
            Beep(440,300);
            Beep(370,300);
            Beep(392,300);
            Beep(370,300);
            Beep(330,800);
            /* */
            Beep(247,300);
            Beep(330,300);
            Beep(330,300);
            Beep(370,300);
            Beep(555,300);
            Beep(555,300);
            Beep(494,300);
            Beep(440,300);
            Beep(392,800);
            Beep(392,300);
            Beep(370,300);
            Beep(247,800);
            Beep(278,300);
            Beep(294,300);
            Beep(330,2600);
            /* */
            Beep(220,300);
            Beep(294,300);
            Beep(294,300);
            Beep(370,300);
            Beep(494,300);
            Beep(370,300);
            Beep(440,800);
            /* */
            Beep(440,300);
            Beep(494,300);
            Beep(440,300);
            Beep(370,300);
            Beep(392,300);
            Beep(370,300);
            Beep(330,800);
            /* */
            Beep(247,300);
            Beep(330,300);
            Beep(330,300);
            Beep(370,300);
            Beep(555,300);
            Beep(555,300);
            Beep(494,300);
            Beep(440,300);
            Beep(392,800);
            Beep(392,300);
            Beep(370,300);
            Beep(278,600);
            Beep(330,600);
            Beep(294,2600);
            /*Reff : */
            Beep(494,300);
            Beep(494,300);
            Beep(494,300);
            Beep(440,300);
            Beep(392,200);
            Beep(440,200);
            Beep(494,200);
            Beep(440,800);
            Beep(330,300);
            Beep(370,300);
            Beep(416,300);
            Beep(330,300);
            Beep(440,2000);
            /* */
            Beep(494,800);
            Beep(440,800);
            Beep(392,1600);
            /* */
            Beep(555,300);
            Beep(555,300);
            Beep(555,300);
            Beep(494,300);
            Beep(440,300);
            Beep(494,300);
            Beep(440,300);
            Beep(392,1400);
            /* */
            Beep(440,300);
            Beep(494,300);
            Beep(370,1100);
            Beep(330,300);
            Beep(294,1800);
            /* */
            Beep(494,800);
            Beep(440,800);
            Beep(392,1600);
            /* */
            Beep(555,300);
            Beep(555,300);
            Beep(555,300);
            Beep(494,300);
            Beep(440,300);
            Beep(494,300);
            Beep(440,300);
            Beep(392,1400);
            /* */
            Beep(440,300);
            Beep(494,300);
            Beep(370,1100);
            Beep(330,300);
            Beep(294,1800);

        }

        //Lo mismo, pero con la J
        if(tecla == 'j')
        {
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


        //Disparar con la tecla A
        if(tecla == 'a')
        {

            if(copiaCantBalas>0)
            {
                copiaCantBalas--;
                cajaBalas[num]=0;

                naveCajaBalasDibujar();

                (*balasA).x = NaveUno.x+2;
                (*balasA).y = NaveUno.y-1;
                balaDibujar(balasA);
                num++;
                if(num>=cantBalas) num=0;

            }


        }

        //Actualización del juego y de la vida del jugador
        navePintar();
        naveCorazonesPintar();
    }



}

#endif // JUGABILIDAD_H_INCLUDED