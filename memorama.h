#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void llena_dorso(char pantalla[20][80],char dorso_1[6][11],char dorso_2[6][11],char dorso_3[6][11],char dorso_4[6][11],char dorso_5[6][11],char dorso_6[6][11],char dorso_7[6][11],char dorso_8[6][11]);
void carta(char pantalla[20][80],char dorso[7][11],int x, int y, char nom_arch[20]);
void figuras (char dorso [6][11],char nom_arch[20]);
void figuras_2 (char imagen [12][78],char nom_arch[20]);
void bienvenida();
void despedida();
void muestra_pantalla(char pantalla[20][80]);
int buscarNumero(int numero,int arreglo[8]);
void aleatorios(int posiciones[8]);
void carta_1(char pantalla[20][80],char dorso[12][78],int x, int y, char nom_arch[20]);
int da_posicion(int numero,int arreglo[8]);
void vuelta(char pantalla[20][80],char figura_seleccion [6][11],int carta_elejida);
void Figura_de_carta(char figura_seleccion [6][11],char pantalla[20][80], char taza[6][11],char rombo[6][11],char circulo[6][11],char mal[6][11],int pos);
void regresar(char pantalla[20][80],char dorso[6][11],int carta_elejida);
void quitar_carta(char pantalla[20][80],char espacios[6][11],int carta_elejida);



