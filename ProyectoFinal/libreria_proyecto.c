#include "libreria_proyecto.h"
#define MAX 100000
void corregir_mayus(char *texto)
{
    /*Para convertir la primera letra del texto a mayúscula*/
    if (texto[0]>='a' && texto[0]<='z')
    {
        texto[0]-=32;
    }
    for (int i=0; texto[i]!='\0'; i++)
    {
        /*Para convertir las letras después de punto a mayúscula*/
        if (texto[i]=='.' && texto[i+2]>='a' && texto[i+2]<='z')
        {
            texto[i+2]-=32;
        }
    }
}
void corregir_acentos(char *texto)
{
    /*Corrige el acento a las vocales antes de una letra n al final de una palabra*/
    //PROXIMAMENTE: PERFECCIONAR PARA PALABRAS QUE LLEVAN EXCEPCIONES
    for(int i=0; texto[i]!='\0'; i++)
    {
        if(texto[i]=='a' && texto[i+1]=='n' && texto[i+2]==32)
        {
            texto[i]=160;
        }
        if(texto[i]=='e' && texto[i+1]=='n' && texto[i+2]==32)
        {
            texto[i]=130;
        }
        if(texto[i]=='i' && texto[i+1]=='n' && texto[i+2]==32)
        {
            texto[i]=161;
        }
        if(texto[i]=='o' && texto[i+1]=='n' && texto[i+2]==32)
        {
            texto[i]=162;
        }
        if(texto[i]=='u' && texto[i+1]=='n' && texto[i+2]==32)
        {
            texto[i]=163;
        }
    }
}
int contador_palabras(char *texto)
{
    int cont=1;
    /*Cuenta una palabra después de cada espacio.
      Inica en 1 para contar la primera palabra*/
    for (int i=0; texto[i]!='\0'; i++)
    {
        if(texto[i]==32)
        {
            cont++;
        }
    }

    return cont;
}
