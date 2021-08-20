#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "memorama.h"



int main()

{
    int posiciones [8],cartaE1,cartaE2,cont_pos,pos1,pos2,contador_aciertos,band1,band2,band3,doble1,doble2,doble3,doble4,doble5,doble6,doble7,doble8,bandc1,bandc2;
    contador_aciertos =0;
    band1=0;
    band2=0;
    band3=0;
    doble1=0;
    doble2=0;
    doble3=0;
    doble4=0;
    doble5=0;
    doble6=0;
    doble7=0;
    doble8=0;
    char contra[6][11], figura_seleccion [7][11],pantalla[20][80],dorso_1[6][11],dorso_2[6][11],dorso_3[6][11],dorso_4[6][11],dorso_5[6][11],dorso_6[6][11],dorso_7[6][11],dorso_8[6][11],circulo[6][11],rombo[6][11],reloj[6][11],mal[6][11];
    bienvenida();
    system("cls");

    aleatorios(posiciones);
    /*for (cont_pos=0;cont_pos<6;cont_pos++)
    {
        printf("%d",posiciones[cont_pos]);
    } */
    printf("\n");
    llena_dorso(pantalla,dorso_1,dorso_2,dorso_3,dorso_4,dorso_5,dorso_6,dorso_7,dorso_8);

    figuras(reloj,"circulo.txt");

    figuras(circulo,"taza.txt");

    figuras(rombo,"rombo.txt");

    figuras(mal,"mal.txt");

    printf("\n\n");
        do{
         muestra_pantalla(pantalla);
        do{
            printf("Introduce el n%cmero de la primera carta:  ",163);
            scanf("%d",&cartaE1);
            Beep(250,200);
        }while((!(cartaE1>0 && cartaE1<9)) || cartaE1==doble1||cartaE1==doble2 || cartaE1==doble3 || cartaE1==doble4 || cartaE1==doble5 ||cartaE1==doble6 || cartaE1==doble7 || cartaE1==doble8);
        pos1=da_posicion(cartaE1,posiciones);//busca el número en el arreglo y da la posición
        //printf("%d \n",pos1); PRUEBA
        Figura_de_carta(figura_seleccion,pantalla,circulo,rombo,reloj,mal,pos1);
        vuelta(pantalla, figura_seleccion, cartaE1);
        system("cls");
        muestra_pantalla(pantalla);
        //printf("%d \n",pos1); prueba
        do{
            bandc2=0;
            printf("Introduce el n%cmero de la segunda carta :   ",163);
            scanf("%d",&cartaE2);
             Beep(250,200);

        }while (((cartaE1==cartaE2) || !(cartaE2>0 && cartaE2<9))|| cartaE2==doble1||cartaE2==doble2 || cartaE2==doble3 || cartaE2==doble4 || cartaE2==doble5 ||cartaE2==doble6 || cartaE2==doble7 || cartaE2==doble8);
        pos2=da_posicion(cartaE2,posiciones);
        Figura_de_carta(figura_seleccion,pantalla,circulo,rombo,reloj,mal,pos2);
        vuelta(pantalla, figura_seleccion, cartaE2);
        system("cls");
        muestra_pantalla(pantalla);
        Sleep(1200);
        system("cls");

        if ((posiciones[0]==cartaE1||posiciones[0]==cartaE2)&&(posiciones[1]==cartaE1||posiciones[1]==cartaE2)&&band1==0)
            {
                contador_aciertos=contador_aciertos+1;
                quitar_carta(pantalla, contra,cartaE1);
                quitar_carta(pantalla, contra,cartaE2);
                doble1=cartaE1;
                doble2=cartaE2;
                band1=1;
            }
        else if ((posiciones[2]==cartaE1||posiciones[2]==cartaE2)&&(posiciones[3]==cartaE1||posiciones[3]==cartaE2)&&band2==0)
            {
                contador_aciertos=contador_aciertos+1;
                quitar_carta(pantalla, contra,cartaE1);
                quitar_carta(pantalla, contra,cartaE2);
                doble3=cartaE1;
                doble4=cartaE2;
                band2=1;
            }
        else if ((posiciones[4]==cartaE1||posiciones[4]==cartaE2)&&(posiciones[5]==cartaE1||posiciones[5]==cartaE2)&&band3==0)
            {
                contador_aciertos=contador_aciertos+1;
                quitar_carta(pantalla, contra,cartaE1);
                quitar_carta(pantalla, contra,cartaE2);
                doble5=cartaE1;
                doble6=cartaE2;
                band3=1;
            }
        else if ((posiciones[6]==cartaE1||posiciones[6]==cartaE2)&&(posiciones[7]==cartaE1||posiciones[7]==cartaE2))
            {
                contador_aciertos=contador_aciertos+1;
                quitar_carta(pantalla, contra,cartaE1);
                quitar_carta(pantalla, contra,cartaE2);
                doble7=cartaE1;
                doble8=cartaE2;

            }

        else
        {
            regresar(pantalla, contra,cartaE1);
            regresar(pantalla, contra,cartaE2);

        }
       // printf("%d %d %d %d %d %d %d %d %d",band1,band2,band3,doble1,doble2,doble3,doble4,doble5,doble6);
        }while(contador_aciertos!=4);
        muestra_pantalla(pantalla);


        //printf("%d \n",pos2); prueba

    system("pause");
    system("cls");

    despedida();

    return 0;
}

