#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int Menu(void);
void EscribeNombres(char [1][50]);
int Empieza(char [1][50]);
int Cargar_Tablero(int [8][8]);
int IniciaTablero(char [1][50],int,int [8][8]);
int MenuJuego(void);
void DibujaTablero(void);
void EscribeOrigen(int*,int*);
void EscribeDestino(int*,int*);
void Redibuja_Tablero(int [8][8]);
int ConfirmaOrigen(int,int,int,int [8][8]);
int Guardar_Partida(int,int[8][8],char [1][50],char[*]);
int Reanudar_Partida(int,int[8][8],char [1][50]);
void Jugar(int Matriz_Tablero[8][8], int opcion, int color, int rehazMenu, int turno, int sino, char nombre[1][50]);

void Jugar(int Matriz_Tablero[8][8], int opcion, int color, int rehazMenu, int turno, int sino, char nombre[1][50])
{
        rehazMenu=0;
        system("cls");
        opcion=Menu();

        switch(opcion)   //con break salgo del switch
        {

            case 1:
            {
                EscribeNombres(nombre);

                if(Empieza(nombre))
                {
                    printf("\n\tEmpieza el Jugador 1 = %s\n\t", nombre[0]);
                    turno=1;   //blancas
                    if(Cargar_Tablero(Matriz_Tablero))
                        printf("\n\n\tTablero cargado satisfactoriamente.");
                    else
                    {
                        printf("\t\nPartida anulada\n\t");
                        rehazMenu=1;
                        break;
                    }

                }
                else
                {
                    printf("\n\tEmpieza el Jugador 2 = %s\n\t", nombre[1]);
                    turno=2;  //negras
                }

                getch();
                IniciaTablero(nombre,turno,Matriz_Tablero);
                rehazMenu=1;
                break;
            }
            case 2:
            {
                printf("\n\tLas normas y procedimientos del videojuego\n\tson las aplicadas al ajedrez basico. \n\tNo se permite el enroque largo ni corto.\n\tUna vez elegida la pieza no se podra retroceder y elegir otra,\n\tdado que el ajedrez profesional si se toca \n\tuna pieza se debe mover esa obligatoriamente.\n\tLas piezas Negras se nombran en mayusculas \n\ty las Blancas en minusculas. \n\tLas Negras se colocan en la parte superior y \n\tlas Blancas en la parte inferior.\n\tHay que tener cuidado al introducir las columnas dado que al escribir un caracter,\n\tla maquina no verifica si ese caracter es cierto. \n\n\t1 = Peon\n\t2 = Torre\n\t3 = Alfil\n\t6 = Rey\n\t5 = Reina\n\t4 = Caballo\n\n\t");
                getch();
                rehazMenu=1;
                break;
            }
            case 3:
            {
                printf("\n\tDesarrollado por Eimy Yaily Corcino Nolasco\n\n\tMatricula 2018-6245\n\n");
                getch();
                rehazMenu=1;
                break;
            }
            case 4:
            {
                printf("\n\tCONTROLES DE TECLADO:\n\n\tEl origen y destino de las piezas se escogera mediante\n\tel teclado numerico.\n\tLas opciones de los diversos menus \n\ttambien se escogeran mediante el teclado numerico.\n\n\tCONTROLES DE RATON\n\n\tNinguno.\n\n\t");
                getch();
                rehazMenu=1;
                break;
            }
            case 5:
            {
            int repite;
            do
            {
                system("cls");
                printf("\n\n\t�Estas seguro de que quieres reanudar partida?:\n\n\t1-Si:\n\t2-No:");
                scanf("%d", &sino);

                if(sino==2)
                {
                    break;
                }
                else
                {

                    if(Reanudar_Partida(turno,Matriz_Tablero,nombre))
                    {
                        printf("\n\n\tPartida cargada satisfactoriamente\n\t");
                        getch();
                        IniciaTablero(nombre,turno,Matriz_Tablero);
                        repite=0;
                    }
                    else
                    {
                        printf("\n\tPartida no posible de cargar, nombre de la partida incorrecto...");
                        getch();
                        repite=1;
                    }
                }
                }while(repite==1);
            }
            case 6:
            {
                printf("\n\n\tPresione una tecla para salir del juego: \n\n\n");
                break;
            }
            default:
                printf("\n\tOpcion elegida no existente: \n\n\n");
        }        
}

int Menu()
{
    int menu;
    do
    {
        printf("\n\n\tAJEDREZ VIRTUAL MANFREDI");
        printf("\n\n\tMenu:\n\t1-Nuevo Juego\n\t2-Reglas del juego\n\t3-Creditos\n\t4-Controles\n\t\5-Reanudar Partida Guardada\n\t6-Salir\n\t");
        scanf("%d", &menu);

        if (menu<=0 || menu>=7)
        {
            system("cls");
            printf("\n\tOpcion no valida, pulsa una tecla para volver al menu");
            getch();
            system("cls");
        }
    }
    while (menu<=0 || menu>=7);
    system("cls");
    return(menu);
}

void EscribeNombres(char nombre [1][50])
{
    int i=0;

    for(i=0; i<=1; i++)
    {
        printf("\n\n\tEscribe el nombre del Jugador %d: ",i+1);
        scanf("%s", &nombre[i]);
    }
    //GuardaPartida(turno);
    system("cls");
}

int Empieza(char nombre [1][50])
{
    int num,begin;

    do
    {
        system("cls");
        printf("\n\tEmpieza el jugador 1(%s) o el 2(%s): \n\t",nombre[0],nombre[1]);
        scanf("%d", &begin);
        printf("\n\tJugador %d es BLANCAS\n\t",begin);
    }
    while(begin<1 || begin>2);

    if(begin==1)
        return(1);
    else
        return(0);
}

int Cargar_Tablero(int Matriz_Tablero[8][8])
{
    int i,j;
    FILE *fp;
    fp=fopen("Tablero.txt","r");
    if(fp!=NULL)
    {
        for (i=0;i<8;i++)
        {
            for (j=0;j<8;j++)
            {
             fscanf(fp,"%d ", &Matriz_Tablero[i][j]);
            }
             fscanf(fp,"\n");
        }

    return(1);
             fclose(fp);
    }
    else
    {
         fprintf(stdout,"\n\tNo se pudo abrir el fichero que contine las posiciones de las fichas");
         return(0);
         fclose(fp);
    }

}

int IniciaTablero(char nombre [1][50],int turno, int Matriz_Tablero[8][8])
{
    int opcion,of,oc,df,dc,rendicion=0,od;
    int origenf,origenc,destinof,destinoc;
    do
    {
        system("cls"); //borro la pantalla
        if(turno==1)   //escribo el nombre del que mueve ahora
        {
            printf("\n\n\tMueve %s\n\n", nombre[0]);
        }
        if(turno==2)
        {
            printf("\n\n\tMueve %s\n\n", nombre[1]);
        }

        getch();
        system("cls");
        Redibuja_Tablero(Matriz_Tablero);   //redibujo tablero
        opcion=MenuJuego();     //le doy a legir mover, rendirse o guardar partida

        switch(opcion)
        {
        case 1:
        {
            do
            {
                EscribeOrigen(&of,&oc); //pido origen
                origenf=of;
                origenc=oc;
                if(ConfirmaOrigen(of,oc,turno,Matriz_Tablero)) //confirmo origen
                {
                 printf("\n\tOrigen valido\n");
                 od=1;
                }
                else
                {
                 printf("\n\tOrigen no valido:");
                 getch();
                }
            }while (od!=1);

            EscribeDestino(&df,&dc); //pido destino
            destinof=df;
            destinoc=dc;

            Matriz_Tablero[destinof][destinoc] = Matriz_Tablero[origenf][origenc]; // cambio  de sitio la pieza
            Matriz_Tablero[origenf][origenc] = 88; // en el hueco ahora no hay nada => 0

            if(turno==1) //cambio de turno
                turno=2;
            else
                turno=1;

            system("cls");   //borro todo

            Redibuja_Tablero(Matriz_Tablero);   //redibujo tablero con las piezas movidas
            getch();

            break;  //salgo de switch y recomienzo el loop siguiendo el turno
        }
        case 2:
        {
            if(turno==1)
            {
                system("cls");
                printf("\n\t%s se rinde, EL GANADOR ES: %s", nombre[0], nombre[1]);
                rendicion=1;
                getch();
            }
            else
            {
                system("cls");
                printf("\n\t%s se rinde, EL GANADOR ES: %s", nombre[1], nombre[0]);
                rendicion=1;
                getch();

            }
            break;
        }
        case 3:
            {
               int guardar;
                do
                {
                    system("cls");
                    printf("\n\n\t�Seguro que quire guardar partida?\n\n\t1-Si\n\t2-No\n\n\t");
                    scanf("%d",&guardar);
                }while(guardar<1 || guardar>2);

                    if(guardar==1)
                    {
                        if(Guardar_Partida(turno,Matriz_Tablero,nombre,"Partida.txt"))
                        {
                            printf("\n\n\tPartida guardada correctamente:\n\n");
                            getch();
                            break;
                        }
                        else
                        {
                         getch();
                         break;
                        }
                    }
                    if(guardar==2)
                        break;
            }
        }
    }
    while(rendicion==0);
}


int MenuJuego(void)
{
    int repite;
    do
    {
        //DibujaTablero();  //Solo el tablero Inicial

        printf("\n\tAbajo aprecen la blancas, los dobles 8 son espacios libres");
        printf("\n\t1-Mover\n\t2-Rendirse\n\t3-Guardar Partida\n\n\t");
        scanf("%d",&repite);

    }
    while(repite<=0 || repite>4);
    return(repite);
}

void DibujaTablero()
{
    int fil=0,col=0,numerofil=0;
    for(fil=0; fil<18; fil++) //filas
    {
        if(fil==0 && col==0)     // primera fila
        {
            printf("\n\t    COL    0   1   2   3   4   5   6   7");
        }
        if(fil==1 && col==0)     // segunda fila
        {
            printf("\n\tFIL      |---|---|---|---|---|---|---|---|");
        }
        if(fil%2!=0 && fil>=3)  // filas impares dibuja separador
        {
            printf("\n\t         |---|---|---|---|---|---|---|---|");
        }
        if(fil%2==0 && fil>1)               //filas pares
        {
            if(fil==2)
            {
                printf("\n\t %d       | T | C | A | rn| Rn| A | C | T |", numerofil);
                numerofil=numerofil+1;
            }
            else if(fil==4)
            {
                printf("\n\t %d       | P | P | P | P | P | P | P | P |", numerofil);
                numerofil=numerofil+1;
            }
            else if(fil==14)
            {
                printf("\n\t %d       | p | p | p | p | p | p | p | p |", numerofil);
                numerofil=numerofil+1;
            }
            else if(fil==16)
            {
                printf("\n\t %d       | t | c | a | rb| Rb| a | c | t |", numerofil);
                numerofil=numerofil+1;
            }
            else
            {
                printf("\n\t %d       |   |   |   |   |   |   |   |   |", numerofil);
                numerofil=numerofil+1;
            }
        }
    }
}

void EscribeOrigen(int *of,int *oc)
{
    printf("\n\n\tOrigen\n");
    printf("\n\tEscoge la pieza:");
    do
    {
        printf("\n\n\tFila: ");   // elige fila
        scanf("%d",of);
    }
    while(*of<0 || *of>7);

    do
    {
        printf("\n\tColumna: ");   // elige columna
        scanf("%d",oc);
    }
    while(*oc<0 || *oc>7);
}

void EscribeDestino(int *df,int *dc)
{
    printf("\n\n\tDestino\n");
    do
    {
        printf("\n\tEscoge el destino:\n\n\tFila: ");   // elige fila
        scanf("%d",df);
    }
    while(*df<0 || *df>7);

    do
    {
        printf("\n\n\tColumna: ");   // elige Columna
        scanf("%d",dc);
    }
    while(*dc<0 || *dc>7);
}

int ConfirmaOrigen(int origenf,int origenc,int turno,int Matriz_Tablero[8][8])
{
    int repite,x,y;
    char A,P,T,C,rn,Rn,a,p,t,c,rb,Rb;

    x=origenf;
    y=origenc;
    do
    {
        if(turno==2)  //blancas
        {
            if(Matriz_Tablero[x][y]!=0 && Matriz_Tablero[x][y]!=10 && Matriz_Tablero[x][y]!=20 && Matriz_Tablero[x][y]!=30 && Matriz_Tablero[x][y]!=40 && Matriz_Tablero[x][y]!=50 && Matriz_Tablero[x][y]!=60)
              {
                repite=0;
              }
              else
              {
                printf("\n\tNo hay pieza en esa posicion o es una pieza negra\n\t");
                repite=1;
                system("cls");
                getch();
              }
        }
        if(turno==1)  //blancas
        {
            if(Matriz_Tablero[x][y]!=0 && Matriz_Tablero[x][y]!=1 && Matriz_Tablero[x][y]!=2 && Matriz_Tablero[x][y]!=3 && Matriz_Tablero[x][y]!=4 && Matriz_Tablero[x][y]!=5 && Matriz_Tablero[x][y]!=6)
             repite=0;
        else
         {
            printf("\n\tNo hay pieza en esa posicion o es una pieza blanca\n\t");
            repite=1;
            system("cls");
            getch();
         }
        }

    }while(repite==1);

    return(1);

}

void Redibuja_Tablero(int Matriz_Tablero[8][8])
{

        printf("\n\t    COL    0     1    2    3    4    5    6   7");
        printf("\n\tFIL      |----|----|----|----|----|----|----|----|");
        printf("\n\t 0       | %d | %d | %d | %d | %d | %d | %d | %d |",Matriz_Tablero[0][0],Matriz_Tablero[0][1],Matriz_Tablero[0][2],Matriz_Tablero[0][3],Matriz_Tablero[0][4],Matriz_Tablero[0][5],Matriz_Tablero[0][6],Matriz_Tablero[0][7]);
        printf("\n\t         |----|----|----|----|----|----|----|----|");
        printf("\n\t 1       | %d | %d | %d | %d | %d | %d | %d | %d |",Matriz_Tablero[1][0],Matriz_Tablero[1][1],Matriz_Tablero[1][2],Matriz_Tablero[1][3],Matriz_Tablero[1][4],Matriz_Tablero[1][5],Matriz_Tablero[1][6],Matriz_Tablero[1][7]);
        printf("\n\t         |----|----|----|----|----|----|----|----|");
        printf("\n\t 2       | %d | %d | %d | %d | %d | %d | %d | %d |",Matriz_Tablero[2][0],Matriz_Tablero[2][1],Matriz_Tablero[2][2],Matriz_Tablero[2][3],Matriz_Tablero[2][4],Matriz_Tablero[2][5],Matriz_Tablero[2][6],Matriz_Tablero[2][7]);
        printf("\n\t         |----|----|----|----|----|----|----|----|");
        printf("\n\t 3       | %d | %d | %d | %d | %d | %d | %d | %d |",Matriz_Tablero[3][0],Matriz_Tablero[3][1],Matriz_Tablero[3][2],Matriz_Tablero[3][3],Matriz_Tablero[3][4],Matriz_Tablero[3][5],Matriz_Tablero[3][6],Matriz_Tablero[3][7]);
        printf("\n\t         |----|----|----|----|----|----|----|----|");
        printf("\n\t 4       | %d | %d | %d | %d | %d | %d | %d | %d |",Matriz_Tablero[4][0],Matriz_Tablero[4][1],Matriz_Tablero[4][2],Matriz_Tablero[4][3],Matriz_Tablero[4][4],Matriz_Tablero[4][5],Matriz_Tablero[4][6],Matriz_Tablero[4][7]);
        printf("\n\t         |----|----|----|----|----|----|----|----|");
        printf("\n\t 5       | %d | %d | %d | %d | %d | %d | %d | %d |",Matriz_Tablero[5][0],Matriz_Tablero[5][1],Matriz_Tablero[5][2],Matriz_Tablero[5][3],Matriz_Tablero[5][4],Matriz_Tablero[5][5],Matriz_Tablero[5][6],Matriz_Tablero[5][7]);
        printf("\n\t         |----|----|----|----|----|----|----|----|");
        printf("\n\t 6       | %d | %d | %d | %d | %d | %d | %d | %d |",Matriz_Tablero[6][0],Matriz_Tablero[6][1],Matriz_Tablero[6][2],Matriz_Tablero[6][3],Matriz_Tablero[6][4],Matriz_Tablero[6][5],Matriz_Tablero[6][6],Matriz_Tablero[6][7]);
        printf("\n\t         |----|----|----|----|----|----|----|----|");
        printf("\n\t 7       | %d | %d | %d | %d | %d | %d | %d | %d |",Matriz_Tablero[7][0],Matriz_Tablero[7][1],Matriz_Tablero[7][2],Matriz_Tablero[7][3],Matriz_Tablero[7][4],Matriz_Tablero[7][5],Matriz_Tablero[7][6],Matriz_Tablero[7][7]);
        printf("\n\t         |----|----|----|----|----|----|----|----|\n\n");

}

int Reanudar_Partida(int turno,int Matriz_Tablero[8][8],char nombre[1][50])
 {
    int i,j;

    FILE *fp;
    fp=fopen("Partida.txt","r");
    if(fp!=NULL)
    {
        for (i=0;i<8;i++)
        {
            for (j=0;j<8;j++)
            {
             fscanf(fp,"%d ", &Matriz_Tablero[i][j]);
            }
             fscanf(fp,"\n");
        }
        fscanf(fp,"\n%d ", &turno);
        fscanf(fp,"\n%s ", &nombre[0]);
        fscanf(fp,"\n%s ", &nombre[1]);
        return(1);
    }
    else
    {
         fprintf(stdout,"\n\tNo se pudo abrir el fichero que contine las posiciones de las fichas");
         return(0);
    }
    fclose(fp);
 }

int Guardar_Partida(int turno,int Matriz_Tablero[8][8],char nombre[1][50],char nom[80])
{
    FILE *fp;
    int i,j;

    system("cls");

    fp=fopen(nom,"w");
    if(fp!=NULL)
    {
        for (i=0;i<8;i++)
        {
            for (j=0;j<8;j++)
            {
             fprintf(fp,"%d ", Matriz_Tablero[i][j]);
            }
            fprintf(fp,"\n");
        }
        fprintf(fp,"\n%d ", turno);
        fprintf(fp,"\n%s ", nombre[0]);
        fprintf(fp,"\n%s ", nombre[1]);

        return(1);
    }
    else
    {
         fprintf(stdout,"\n\tNo se pudo guardar la partida");
         return(0);
    }
    fclose(fp);
}