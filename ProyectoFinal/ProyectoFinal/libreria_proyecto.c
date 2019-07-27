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
        if(texto[i]=='o' && texto[i+1]=='n' && (texto[i+2]=='.' || texto[i+2]==32 || texto[i+2]=='\n') && cl>2)
        {
            texto[i]=162;
        }
        if(texto[i]=='u' && texto[i+1]=='n' && (texto[i+2]=='.' || texto[i+2]==32 || texto[i+2]=='\n') && cl>2)
        {
            texto[i]=163;
        }
        /*Para acento en las palabras terminadas en ia*/
         if(texto[i]=='i' && texto[i+1]=='a' && (texto[i+2]=='s' || texto[i+2]=='.' || texto[i+2]==' ' || texto[i+2]=='\n'))
        {
            texto[i]=161;
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
    int cont=0;
    char aux[50], tab[50]={'\t'};

    strcpy(aux,tab);

    for(int i=0; texto[i]!='\0';i++)
    {
        //texto= (char*)realloc(texto,((strlen(texto)+2+cont)*sizeof(char)));
        if(i==0)
        {
            strcat(tab,texto);

            //Aca a la cadena tab se le agrega el texto.
            //Esto para la sangria a inicio de parrafo

            strcpy(texto, tab);

            //Texto pasa a tener el valor de tab que es el \t a inicio
            //con el texto luego
        }
        if(texto[i-1]=='\n')//Si hay cambio de linea se introducira un \t
        {
            strcat(tab, &texto[i]); //A tab se le añade el texto a partir de la posicion del \n

            strcpy(&texto[i],tab); //texto a partir de la posicion luego del \n se le agrega tab
            cont++;
        }
        strcpy(tab,aux);
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
        if(*(texto+i)=='.' && (*(texto+(i+1))!='.' || *(texto+(i+1))!='\n'))
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
void buscar_remplazar(char *texto, char *palabra, char *palabrapor)
{
    int c_letras=strlen(palabra);
    char aux[50];

    strcpy(aux,palabrapor);

    /*Cuenta la cantidad de letras de la palabra que se buscara*/
    for(int i=0; texto[i]!='\0'; i++)
    {
        if(strnicmp(palabra,&texto[i],c_letras)==0)
            /*texto en la posicion i se compara con palabra pero solo la cantidad de caracteres de palabra
            si son iguales retornara 0*/
        {
            strcat(palabrapor,&texto[i+c_letras]);
            /*a la palabra por la que se va a sustituir se le agrega el texto luego de la palabra que se
            busco*/
            strcpy(&texto[i],palabrapor);
            /*texto pasa a tener la palabra por la que se va a sustituir mas el resto del texto luego de la
            posicion donde estaba la palabra que se busco*/
        }
        strcpy(palabrapor,aux);
    }
}
