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
void sangria(char *texto)
{
    //IGNORAR: TRABAJANDO EN ESTA FUNCION
    int cont=0, M=(strlen(texto)+2);
    char aux[2]={'\t'}, tab[100]={'\t'};

    for(int i=0; texto[i]!='\0';i++)
    {
        //strcpy(tab,aux);

        texto= (char*)realloc(texto,(M+cont)*sizeof(char));
        if(i==0)
        {
            //tab=(char*)malloc(M*sizeof(char));
            strcat(tab, texto);
            /*Aca a la cadena tab se le agrega el texto.
            Esto para la sangria a inicio de parrafo*/
        }

        /*if(texto[i]=='\n')//Si hay cambio de linea se introducira un \t
        {
            //Asignando memoria para tratar de corregir errores
            texto= (char*)realloc(texto,(strlen(texto)+cont+2)*sizeof(char));
            strcat(tab, texto);
            cont++;
        }*/
        strcpy(texto,tab);
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
int contador_oraciones(char *texto)
{
    int cont=0;
    /*Cuenta una oracion después de cada punto, siempre que depués de
    punto no haya otro punto. También cuenta como oracion luego de salto de línea*/
    for (int i=0; texto[i]!='\0'; i++)
    {
        if(*(texto+i)=='.' && *(texto+(i+1))!='.')
        {
            cont++;
        }
        if(texto[i]=='\n' && (texto[i+1]!='\n'))
        {
            cont++;
        }
    }

    return cont;
}
int contador_parrafos(char *texto)
{
    int cont=0;
    /*Cuenta un parrafo después de cada salto de linea, siempre que depués de
     salto de línea no haya otro*/
    for (int i=0; texto[i]!='\0'; i++)
    {
        if(texto[i]=='\n' && (texto[i+1]!='\n'))
        {
            cont++;
        }
    }

    return cont;
}
