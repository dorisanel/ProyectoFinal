#include "libreria_proyecto.h"

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
        /*Para convertir las letras luego de salto de línea*/
        if (texto[i-1]=='\n' && texto[i]>='a' && texto[i]<='z')
        {
            texto[i]-=32;
        }
    }
}
void corregir_acentos(char *texto)
{
    /*Corrige el acento a las vocales antes de una letra n al final de una palabra*/

    int cl=1;
    /*Se encarga de ir contando las letras de cada palabra para no agregar
               acento a palabras monosílabas*/
    //PROXIMAMENTE: PERFECCIONAR PARA PALABRAS QUE LLEVAN EXCEPCIONES
    for(int i=0; texto[i]!='\0'; i++)
    {
        if(texto[i]=='a' && texto[i+1]=='n' && (texto[i+2]=='.' || texto[i+2]==32 || texto[i+2]=='\n') && cl>2)
        {
            texto[i]=160;
        }
        if(texto[i]=='e' && texto[i+1]=='n' && (texto[i+2]=='.' || texto[i+2]==32 || texto[i+2]=='\n') && cl>2)
        {
            texto[i]=130;
        }
        if(texto[i]=='i' && texto[i+1]=='n' && (texto[i+2]=='.' || texto[i+2]==32 || texto[i+2]=='\n') && cl>2)
        {
            texto[i]=161;
        }
        /*if(texto[i]=='o' && texto[i+1]=='n' && (texto[i+2]=='.' || texto[i+2]==32 || texto[i+2]=='\n') && cl>2)
        {
            texto[i]=162;
        }*/
        if(texto[i]=='u' && texto[i+1]=='n' && (texto[i+2]=='.' || texto[i+2]==32 || texto[i+2]=='\n') && cl>2)
        {
            texto[i]=163;
        }
        if(texto[i]==32 || texto[i]=='\n')
        {
            cl=0;
        }
        cl++;
    }
}
int contador_palabras(char *texto)
{
    int cont=0;
    /*Cuenta una palabra después de cada espacio, siempre que depués de
    espacio no haya otro espacio. También cuenta como palabra luego de salto de línea*/
    for (int i=0; texto[i]!='\0'; i++)
    {
        if(*(texto+i)==' ' && *(texto+(i+1))!=' ')
        {
            cont++;
        }
        if(texto[i]=='\n' && (texto[i+1]!='\n' || texto[i+1]!=' '))
        {
            cont++;
        }
    }

    return cont;
}
void sangria(char *texto)
{
    //IGNORAR: TRABAJANDO EN ESTA FUNCION
    char tab[2]={'\t','a'};/*Esto es para ver si se agrega el \t*/
    int cont=0;

    texto= (char*)realloc(texto,(strlen(texto)+2)*sizeof(char));

    for(int i=0; texto[i]!='\0';i++)
    {
        if(i==0)
        {
            strcat(tab, texto);
            /*Aca a la cadena tab se le agrega el texto.
            Esto para la sangria a inicio de parrafo*/
        }
        if(texto[i]=='\n')//Si hay cambio de linea se introducira un \t
        {
            /*Asignando memoria para tratar de corregir errores*/
            texto= (char*)realloc(texto,(strlen(texto)+cont+2)*sizeof(char));
            strcat(tab, texto);
            cont++;
        }
    }

    /*Trabajando en como lograr que texto tenga el valor de tab, actualmente me da error*/

    //puts(tab);

    //strcpy(texto,tab);
}
