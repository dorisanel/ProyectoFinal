#include "libreria_proyecto.h"
void corregir_espacios(char *texto)
{
    for(int i=0; texto[i]!='\0';i++)
    {
        if(texto[i]==' ' && texto[i+1]==' ')
        {
            strcpy(&texto[i],&texto[i+1]);
            i--;
        }
    }
}
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

    for(int i=0; texto[i]!='\0'; i++)
    {
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
        /*Para acento en las palabras terminadas en ia e ias*/
         if(texto[i]=='i' && texto[i+1]=='a' && (texto[i+2]=='n' || texto[i+2]=='s' || texto[i+2]=='.' || texto[i+2]==' ' || texto[i+2]=='\n'))
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
void m_antes_pb(char *texto)
{
    for(int i=0; texto[i]!='\0';i++)
    {
        if(texto[i]=='n' && (texto[i+1]=='b' || texto[i+1]=='p'))
        {
            texto[i]='m';
        }
    }
}
void c_antes_ei(char *texto)
{
    for(int i=0; texto[i]!='\0'; i++)
    {
        if(texto[i]=='z' && (texto[i+1]=='e' || texto[i+1]=='i'))
        {
            texto[i]='c';
        }
    }
}
void aje(char *texto)
{
    for(int i=0; texto[i]!='\0';i++)
    {
        if((texto[i]=='a' || texto[i]=='e') && texto[i+1]=='g'  && texto[i+2]=='e')
            texto[i+1]='j';
    }
}
void gergir(char *texto)
{
    for(int i=0; texto[i]!='\0';i++)
    {
        if(texto[i]=='j' && (texto[i+1]=='e' || texto[i+1]=='i') && texto[i+2]=='r')
            texto[i]='g';
    }
}
void aba(char *texto)
{
    for(int i=0;texto[i]!='\0';i++)
    {
        if(texto[i]=='a' && texto[i+1]=='v' && texto[i+2]=='a')
        {
            texto[i+1]='b';
        }
    }
}
void sangria(char *texto)
{
    int cont=0;
    char aux[1000], tab[1000]={'\t'};

    strcpy(aux,tab);

    for(int i=0; texto[i]!='\0';i++)
    {
        texto= (char*)realloc(texto,((strlen(texto)+2+cont)*sizeof(char)));
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
        strcpy(tab,aux);//tab vuelve a tener su valor inicial
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
void buscar_remplazar(char *texto, char *palabra, char *palabrapor)
{
    int c_letras=strlen(palabra);/*Cuenta la cantidad de letras de la palabra que se buscara*/
    char aux[1000];

    strcpy(aux,palabrapor);

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
void insertar(char *texto)
{
    char palabra[100];

    printf("Digite lo que desea insertar: ");
    gets(palabra);

    strcat(texto,palabra);
}
void borrar_linea(char *texto)
{
   printf("say sike right now");
}
int vim (char *texto,FILE *guardar_nuevo,char guardar_texto[50])
{
    printf("\n");
    char palabra[50], palabrapor[50];
    char vim [10];

    fflush(stdin);
    printf("\n\t\t\t\t MODO COMANDO \n");
    gets(vim);

    if(strcmp(vim,"wq")==0)     //Prueba de usar comando
    {
        printf("\nEl archivo no existia, por tanto se ha creado!\n");
        guardar_nuevo=fopen(guardar_texto,"r");
        fclose(guardar_nuevo);

        if(!(guardar_nuevo==NULL))
        {
            fclose(guardar_nuevo);
            guardar_nuevo=fopen(guardar_texto,"w+t");
            fputs(texto,guardar_nuevo);
            printf("Texto guardado con exito!\n");
            fclose(guardar_nuevo);
        }
        else
        {
            fclose(guardar_nuevo);
            guardar_nuevo=fopen(guardar_texto,"a+t");
            fputs(texto,guardar_nuevo);
            printf("Texto guardado con exito!\n");
            fclose(guardar_nuevo);
        }

        return 0;
    }

    else if(strcmp(vim,"i")==0)

    {
        insertar(texto);
        return 0;
    }

    else if(strcmp(vim,"q!")==0)
    {
        return 0;
    }

    else if(strcmp(vim,"%s")==0)
    {
        fflush(stdin);
        printf("Digite la palabra que desea reemplazar: ");
        gets(palabra);

        printf("\nPor cual palabra desea reemplazarla: ");
        gets(palabrapor);

        buscar_remplazar(texto,palabra,palabrapor);
        puts(texto);

        return 0;
    }
    else if(strcmp(vim,"dd")==0)
    {
        borrar_linea(texto);
        return 0;
    }

    return -1;/*Si llega a retornar -1 se digito un comando no existente*/
}
