#ifndef BALAS_H_INCLUDED
#define BALAS_H_INCLUDED

//Importando librerías
#include "pantalla.h"
#include "Constantes.h"


//Borrando las balas
void balaBorrar(struct Bala *balasA)
{
  gotoxy((*balasA).x,(*balasA).y); printf(" ");
}

//Dibujando las balas
void balaDibujar(struct Bala *balasA)
{
  gotoxy((*balasA).x,(*balasA).y); printf("*");
}

//Obteniendo todas las balas
int cajaBalasLLena()
{
  int llena=1,i;
  for(i=0;i<cantBalas;i++)
    if(cajaBalas[i]==0)
      {
        llena=0; break;
      }
  return llena;
}

#endif // BALAS_H_INCLUDED