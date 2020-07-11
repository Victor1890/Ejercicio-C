#include <stdio.h>
#include <string.h>

enum genero { historica, intriga, rosa, viaje, autoayuda, aventuras, ensayo };

struct libro
{
    char cod_art[10];
    char titulo[20];
    char autores[30];
    char editorial[10];
    enum genero migenero;
};

struct DVD
{
    char cod_art[10];
    char titulo[20];
    char director[10];
    char actores[30];
    int ano;
};

enum tipo { libro, DVD };

union descripcion {
    struct libro milibro;
    struct DVD miDVD;
};

struct articulo
{
    enum tipo mitipo;
    union descripcion midescripcion;
    float precio;
    unsigned int existencias;
};

// struct articulo
// {
//     char cod_art[10];
//     float precio;
//     unsigned int existencias;
// };

float Vender(struct articulo *ar, int cantidad );
struct articulo Alta(long int codigo, float dolar, unsigned int cantidad );
void Visualizar(struct articulo *ar );
void Reponer(struct articulo *ar, int cantidad );


struct articulo Alta(char *codigo, float dolar, unsigned int cantidad )
{
    struct articulo ar;
    ar.cod_art[1] = codigo;
    ar.precio = dolar;
    ar.existencias = cantidad;
    return ar;
}

void Visualizar(struct articulo *ar )
{
    printf("Código del artículo: %s\n", ar->cod_art);
    printf("Precio del artículo: %f\n", ar->precio);
    printf("Existencias del artículo: %d\n", ar->existencias);
}

float Vender(struct articulo *ar, int cantidad )
{
    ar->existencias= ar->existencias-cantidad;
    return (cantidad*ar->precio);
}

void Reponer(struct articulo *ar, int cantidad )
{
    ar->existencias= ar->existencias+cantidad;
}

int Valida(struct articulo *ar1, struct articulo *ar2)
{
    if(!strcmp( ar1->cod_art, ar2->cod_art )) return 0;
    else return 1;
}