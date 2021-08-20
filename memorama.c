#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "memorama.h"


void bienvenida ( )
{

   printf ( "\n\n\n\t\t\t\t MEMORAMA\n\n\n" );
   printf ("INSTRUCCIONES\n\n\n");
   printf ("Selecciona 2 cartas con n%cmeros diferentes.\n",163 );
   printf ("Si las 2 cartas que seleccionaste son iguales estas desaparecer%cn.\n",160);
   printf ("Si no son iguales volver%cn a su lugar original.\n",160);
   printf ("Repita el proceso hasta que todas las cartas desaparezcan.\n");
   printf ("\n\n");

   system("color 0A");
   system ( "pause" );
   Beep(350,200);
}
void despedida()
{
  char pantalla[20][80],dorso[12][78];
   llena_des(pantalla,dorso);
   muestra_pantalla(pantalla);
   system("color 0A");
   Beep(300,300);
   system("pause");
}
void llena_dorso(char pantalla[20][80],char dorso_1[6][11],char dorso_2[6][11],char dorso_3[6][11],char dorso_4[6][11],char dorso_5[6][11],char dorso_6[6][11],char dorso_7[7][11],char dorso_8[6][11])//recuadro del memorama
{
    int fila,columna;
    pantalla[0][0]= 201;
    pantalla[19][0]=200;
    pantalla[0][79]=187;
    pantalla[19][79]=188;

    for (columna=1;columna<=78;columna++)
        {
           pantalla[0][columna]=205;
           pantalla[19][columna]=205;
        }

    for (fila=1;fila<=18;fila++)
    {
        pantalla[fila][0]=186;

         for(columna=1;columna<=78;columna++)
            pantalla[fila][columna]=' ';

       pantalla[fila][79]=186;
    }

    carta(pantalla,dorso_1,2,8,"num1.txt");
    carta(pantalla,dorso_2,2,25,"num2.txt");
    carta(pantalla,dorso_3,2,42,"num3.txt");
    carta(pantalla,dorso_4,2,60,"num4.txt");
    carta(pantalla,dorso_5,10,8,"num5.txt");
    carta(pantalla,dorso_6,10,25,"num6.txt");
    carta(pantalla,dorso_7,10,42,"num7.txt");
    carta(pantalla,dorso_8,10,60,"num8.txt");
     system("color 0B");

}
void muestra_pantalla(char pantalla[20][80])
{
        int fila, columna;
        for(fila=0;fila<=19;fila++)
    {
        for (columna=0;columna<=79;columna++)
            printf("%c",pantalla[fila][columna]);
        printf("\n");
    }
}
void figuras (char dorso [6][11], char nom_arch[20])//llenar la matriz con la imagen
{
    FILE *figura;

    int fila,columna;


    if ((figura = fopen( nom_arch,"rt")) == NULL)
   {
        fprintf(stderr, "No abrio archivo de entrada.\n");
        getch();
   }

    for (fila=0;fila<=6;fila++)
        for (columna=0;columna<=11;columna++)
    {
        fscanf(figura,"%c",& dorso[fila][columna]);
        //printf("%c",dorso[fila][columna]);   //imprimir la imagen

    }
   // printf("\n");

    fclose(figura);



}
void figuras_2 (char imagen [12][78], char nom_arch[20])//llenar la matriz con la imagen
{
    FILE *figura;

    int fila,columna;
    char letra;


    if ((figura = fopen( nom_arch,"rt")) == NULL)
   {
        fprintf(stderr, "No abrio archivo de entrada.\n");
        getch();
   }

    for (fila=0;fila<=11;fila++)
        for (columna=0;columna<=78;columna++)
    {
        fscanf(figura,"%c",& imagen[fila][columna]);
        //printf("%c",imagen[fila][columna]);   //imprimir la imagen

    }
    //printf("\n");

    fclose(figura);



}
void carta(char pantalla[20][80],char dorso[6][11],int x, int y, char nom_arch[20])//acomodar la imagen en la matriz principal
{
    int fila,columna;
    figuras(dorso, nom_arch);



    for (fila=x;fila<=x+5;fila++)
        for (columna=y;columna<=y+10;columna++)
            pantalla[fila][columna]=dorso[fila-x][columna-y];

}
void aleatorios(int posiciones[8])
{
    int num_aleatorio;
    int band;
    int cont;
    srand(time(NULL));
    for(cont=0;cont<8;cont++)
    {
        do{
            num_aleatorio=1+rand()%8;
            band=buscarNumero(num_aleatorio,posiciones);
        }while(band);
        posiciones[cont]=num_aleatorio;
        //printf("%d",posiciones[cont]);
    }
    return(EXIT_SUCCESS);
}
int buscarNumero(int numero,int arreglo[8])
{
    int i, band=0;
    for (i=0;(i<8 && band==0);i++)
    {
        if (arreglo[i]==numero)
            band=1;
    }
    return band;
}
void llena_des (char pantalla[20][80],char dorso[12][78])//recuadro del memorama
{
    int fila,columna;
    pantalla[0][0]= 201;
    pantalla[19][0]=200;
    pantalla[0][79]=187;
    pantalla[19][79]=188;

    for (columna=1;columna<=78;columna++)
        {
           pantalla[0][columna]=205;
           pantalla[19][columna]=205;
        }

    for (fila=1;fila<=18;fila++)
    {
        pantalla[fila][0]=186;

         for(columna=1;columna<=78;columna++)
            pantalla[fila][columna]=' ';

       pantalla[fila][79]=186;
    }
    carta_1(pantalla,dorso,6,1,"despedida.txt");

}
void carta_1(char pantalla[20][80],char dorso[12][78],int x, int y, char nom_arch[20])//acomodar la imagen en la matriz principal
{
    int fila,columna;
    figuras_2(dorso, nom_arch);



    for (fila=x;fila<=x+11;fila++)
        for (columna=y;columna<=y+77;columna++)
            pantalla[fila][columna]=dorso[fila-x][columna-y];

}
int da_posicion(int numero,int arreglo[8])
{
    int i=0;
    int band=0;
     while(i<8 && band==0)
    {
        if (arreglo[i]==numero)
            band=1;
        i++;
    }
    i=i-1;
    return i;
}
void Figura_de_carta(char figura_seleccion [6][11],char pantalla[20][80], char taza[6][11],char rombo[6][11],char circulo[6][11],char mal[6][11],int pos)
{
    int fila,columna;
    if (pos==0||pos==1)
    {
        for (fila=0;fila<7;fila++)
            for (columna=0;columna<11;columna++)
                figura_seleccion[fila][columna]=taza[fila][columna];
    }

    if (pos==2||pos==3)
    {
        for (fila=0;fila<7;fila++)
            for (columna=0;columna<11;columna++)
                figura_seleccion[fila][columna]=rombo[fila][columna];
    }
    if (pos==4||pos==5)
    {
        for (fila=0;fila<7;fila++)
            for (columna=0;columna<11;columna++)
                figura_seleccion[fila][columna]=circulo[fila][columna];
    }
    if (pos==6||pos==7)
    {
        for (fila=0;fila<7;fila++)
            for (columna=0;columna<11;columna++)
                figura_seleccion[fila][columna]=mal[fila][columna];
    }

}
void vuelta(char pantalla[20][80],char figura_seleccion [6][11],int carta_elejida)
{
    int fila,columna;
    switch (carta_elejida)
    {


    case 1:
            for (fila=2;fila<=2+5;fila++)
                for (columna=8;columna<=8+10;columna++)
                    pantalla[fila][columna]=figura_seleccion[fila-2][columna-8];
            break;

    case 2:
            for (fila=2;fila<=2+5;fila++)
                for (columna=25;columna<=25+10;columna++)
                    pantalla[fila][columna]=figura_seleccion[fila-2][columna-25];
            break;

    case 3:
        for (fila=2;fila<=2+5;fila++)
            for (columna=42;columna<=42+10;columna++)
                pantalla[fila][columna]=figura_seleccion[fila-2][columna-42];
            break;

    case 4:
            for (fila=2;fila<=2+5;fila++)
                for (columna=60;columna<=60+10;columna++)
                    pantalla[fila][columna]=figura_seleccion[fila-2][columna-60];
            break;

    case 5:
            for (fila=10;fila<=10+5;fila++)
            for (columna=8;columna<=8+10;columna++)
                pantalla[fila][columna]=figura_seleccion[fila-10][columna-8];

            break;

    case 6:
            for (fila=10;fila<=10+5;fila++)
                for (columna=25;columna<=25+10;columna++)
                    pantalla[fila][columna]=figura_seleccion[fila-10][columna-25];
            break;

    case 7:
            for (fila=10;fila<=10+5;fila++)
                for (columna=42;columna<=42+10;columna++)
                    pantalla[fila][columna]=figura_seleccion[fila-10][columna-42];
            break;
    case 8:
            for (fila=10;fila<=10+5;fila++)
                for (columna=60;columna<=60+10;columna++)
                    pantalla[fila][columna]=figura_seleccion[fila-10][columna-60];
            break;
    }
}
void regresar(char pantalla[20][80],char dorso[6][11],int carta_elejida)
{
    if (carta_elejida==1)
        carta(pantalla,dorso,2,8,"num1.txt");
    if (carta_elejida==2)
        carta(pantalla,dorso,2,25,"num2.txt");
    if (carta_elejida==3)
        carta(pantalla,dorso,2,42,"num3.txt");
    if (carta_elejida==4)
        carta(pantalla,dorso,2,60,"num4.txt");
    if (carta_elejida==5)
        carta(pantalla,dorso,10,8,"num5.txt");
    if (carta_elejida==6)
        carta(pantalla,dorso,10,25,"num6.txt");
    if (carta_elejida==7)
        carta(pantalla,dorso,10,42,"num7.txt");
    if (carta_elejida==8)
        carta(pantalla,dorso,10,60,"num8.txt");
}
void quitar_carta(char pantalla[20][80],char espacios[6][11],int carta_elejida)
{
    if (carta_elejida==1)
        carta(pantalla,espacios,2,8,"blanco.txt");
    if (carta_elejida==2)
        carta(pantalla,espacios,2,25,"blanco.txt");
    if (carta_elejida==3)
        carta(pantalla,espacios,2,42,"blanco.txt");
    if (carta_elejida==4)
        carta(pantalla,espacios,2,60,"blanco.txt");
    if (carta_elejida==5)
        carta(pantalla,espacios,10,8,"blanco.txt");
    if (carta_elejida==6)
        carta(pantalla,espacios,10,25,"blanco.txt");
    if (carta_elejida==7)
        carta(pantalla,espacios,10,42,"blanco.txt");
    if (carta_elejida==8)
        carta(pantalla,espacios,10,60,"blanco.txt");
}

