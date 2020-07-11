#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#define nAst 7

//Para resumir todas las cosas sobre este archivo llamado Constantes.h, lo diré de manera muy rápida

//Clase Asteroide
struct Asteroide
{
    int x,y;
}Ast[nAst];

//Clase Nave
struct Nave
{
    int x,y;
    int corazones;
    int vidas;
}NaveUno;

//Clase Balas
struct Bala
{
    int x,y;
}balasA[10];


///para el movimiento de las flechas
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

///tamanio en caracteres de la pantalla
#define ANCHO 82
#define ALTO 37


///figuras , atributos
#define figuraAsteroide 184

int corazones=3,vidas=3;


//Posiciones dentro de los escenarios
int posYMinima=4,posYMaxima=ALTO-3,
posXMinima=3,posXMaxima=ANCHO-5;


int cajaBalas[] = {1,1,1};
int num = 0;
int const cantBalas = sizeof(cajaBalas)/sizeof(int);
int copiaCantBalas = sizeof(cajaBalas)/sizeof(int);

int score=0;
#endif // CONSTANTES_H_INCLUDED