/*Agregando Librerías para facilitarme la vida*/
#include <stdio.h>
#include <complex.h>

#ifndef _COMPLEJOS_H_
#define _COMPLEJOS_H_

typedef struct Datos{
    double complex z1;
    double complex z2;
}Datos;

/*Creo yo, registrando las funciones*/
void DatosPrueba(double a1, double a2);
void SumarComplejos(double a1, double a2);
void RestaComplejos(double a1, double a2);
void MultiComplejos(double a1, double a2);
void DivisionComplejos(double a1, double a2);
void ConjugadoComplejos(double a1, double a2);

/*Funciones con sus */
void ConjugadoComplejos(double a1, double a2)
{
    struct Datos *instancia;
    instancia->z1 = a1 + a2 * I;

    double complex conjugate = conj(instancia->z1);
    printf("La conjugación de Z1 = %.2f %+.2fi\n", creal(conjugate), cimag(conjugate));
}

void DivisionComplejos(double a1, double a2)
{
    struct Datos *instancia;
    instancia->z1 = a1 + a2 * I;
    instancia->z2 = a1 - a2 * I;

    double complex quotient = instancia->z1 / instancia->z2;
    printf("La división es: Z1 / Z2 = %.2f %+.2fi\n", creal(quotient), cimag(quotient));
}

void MultiComplejos(double a1, double a2)
{
    struct Datos *instancia;
    instancia->z1 = a1 + a2 * I;
    instancia->z2 = a1 - a2 * I;

    double complex product = instancia->z1 * instancia->z2;
    printf("la multiplicación es: Z1 x Z2 = %.2f %+.2fi\n", creal(product), cimag(product));
}

void RestaComplejos(double a1, double a2)
{
    struct Datos *instancia;
    instancia->z1 = a1 + a2 * I;
    instancia->z2 = a1 - a2 * I;

    double complex difference = instancia->z1 - instancia->z2;
    printf("La resta es: Z1 - Z2 = %.2f %+.2fi\n", creal(difference), cimag(difference));
}

void SumarComplejos(double a1, double a2)
{
    struct Datos *instancia;
    instancia->z1 = a1 + a2 * I;
    instancia->z2 = a1 - a2 * I;

    double complex sum = instancia->z1 + instancia->z2;
    printf("La suma es : Z1 + Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));
}

void DatosPrueba(double a1, double a2)
{   
    struct Datos *instancia;
    
    instancia->z1 = a1 + a2 * I;
    instancia->z2 = a1 - a2 * I;

    printf("Inicializamos los valores: Z1 = %.2f + %.2fi\t Z2 = %.2f %+.2fi\n", creal(instancia->z1), cimag(instancia->z1), creal(instancia->z2), cimag(instancia->z2));
    //printf("Inicializamos los valores: Z1 = %.2f + %.2fi\t Z2 = %.2f %+.2fi\n", creal(z1), cimag(z1), creal(z2), cimag(z2));
    getchar();
}

#endif