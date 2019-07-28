
#include <stdio.h>
#include <stdlib.h>
#include "libreria_proyecto.h"


// Cambiar > por 'i' de insert.

int main()
{
    char *texto, letra,guardar_texto[50];
    int cont=0;// busc_remp;
 FILE *guardar_nuevo;

    printf("Digite el nombre donde se guardar%c el archivo de texto: ",160);
    gets(guardar_texto);
    guardar_nuevo=fopen(guardar_texto,"rt");

    printf("Digite texto: \n");


    do
    {
        letra=fgetc(stdin);
        if(cont==0)
            texto = (char*)malloc(1*sizeof(char));

        else
            texto = (char*)realloc(texto,(cont+1)*sizeof(char));

        *(texto+cont) = letra;

        if(letra==EOF)
            *(texto+cont) ='\0';

        cont++;
    }while((letra!=EOF));

    corregir_mayus(texto);
    corregir_acentos(texto);
    sangria(texto);

    puts(texto);
    printf("\b");/*Para borrar el ctrl Z*/

    printf("\n\nCantidad de palabras: %d",contador_palabras(texto));
    printf("\nCantidad de oraciones: %d",contador_oraciones(texto));
    printf("\nCantidad de parrafos: %d",contador_parrafos(texto));



    vim(texto,guardar_nuevo,guardar_texto);



    /*implementar aqui que pregunte si desea continuar, aparte agregar un menu que permita abrir un archivo ya existente para modificar
     o crear uno nuevo*/

    /*  printf("\n\nDesea remplazar alguna palabra? \n1.Si \n2.No\n");
      scanf("%d",&busc_remp);

      if(busc_remp==1)
      {
          fflush(stdin);
          printf("Digite la palabra que desea reemplazar: ");
          gets(palabra);

          printf("\nPor cual palabra desea reemplazarla: ");
          gets(palabrapor);

          buscar_remplazar(texto,palabra,palabrapor);
          puts(texto);
      }*/

    free(texto);

    return 0;
}


