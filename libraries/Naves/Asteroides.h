//Definiendo los objetos del juego
#ifndef ASTEROIDES_H_INCLUDED
#define ASTEROIDES_H_INCLUDED

//Importando librerías
#include "Nave.h"
#include "Constantes.h"


//Creando el método de los asteroides
void AsteroidePintar(struct Asteroide *Ast)
{
    gotoxy((*Ast).x,(*Ast).y); printf("%c",figuraAsteroide);
}

//Creando movimientos de los asteroides
void AsteroideMovimiento(struct Asteroide *Ast)
{
    gotoxy((*Ast).x,(*Ast).y); printf(" ");
    (*Ast).y = (*Ast).y + 1 ;

    //Si la posición Y del asteroide es mayor a la posición del escenario
    if((*Ast).y>posYMaxima)
    {
        //Entonces vamos a renderizar los objetos a la pantalla
        (*Ast).x=rand()%(posXMaxima-posXMinima)+posXMinima;
        (*Ast).y=posYMinima+1;
    }
    //Pintamos los asteroides
    AsteroidePintar(Ast);
}

//Creando daño a la nave del jugador
void AsteroideColisionNave(struct Asteroide *Ast)
{

    if((*Ast).x >= NaveUno.x && (*Ast).x<NaveUno.x+5
    && (*Ast).y>=NaveUno.y && (*Ast).y<=NaveUno.y+3)
    {
        if(
           ((*Ast).x==NaveUno.x+2 && (*Ast).y==NaveUno.y) ||
           ((*Ast).x==NaveUno.x+1 && (*Ast).y==NaveUno.y+1) ||
           ((*Ast).y==NaveUno.y+2) ||
           ((*Ast).x==NaveUno.x+3 && (*Ast).y==NaveUno.y+1)
          )
        {
            //Actualiza la pantalla
            Beep(100,30);
            
            //Renderizando los objetos
            gotoxy((*Ast).x,(*Ast).y); printf(" ");
            (*Ast).x=rand()%(posXMaxima-posXMinima)+posXMinima;
            (*Ast).y=posYMinima;
            AsteroidePintar(Ast);

            //Quitando vida por cada objeto colisiona con la nave
            NaveUno.corazones--;
            naveCorazonesPintar();

            //Actualiza la nave
            navePintar();
        }
    }
}

#endif // ASTEROIDES_H_INCLUDED
