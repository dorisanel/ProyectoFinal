
#include <stdio.h>
#include <stdlib.h>
#include "libreria_proyecto.h"

#define LETRA 62 // asigno el simbolo > para poder digirar comando

int main()
{
    char *texto, letra, palabra[50], palabrapor[50],comando,guardar_texto[50];
    FILE *guardad_nuevo;
    int cont=0;// busc_remp;
    char vim [10];

    printf("Digite el nombre donde se guardar%c el archivo de texto: ",160);
    gets(guardar_texto);
    guardad_nuevo=fopen(guardar_texto,"rt");

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

    printf("\n");
    comando=getchar(); // espera a que digite un caracter que es el >

    if(comando== LETRA) // Para poder digitar comandos a lo vim
    {
        fflush(stdin);
        printf("\nDigite un comando\n");
        gets(vim);

        for(int k=0; vim[k]!='\0'; k++)
        {

            if(vim[k]=='w' && vim[k+1]=='q')     //Prueba de usar comando
            {

                printf("\nEl archivo no existia, por tanto se ha creado!\n");
                guardad_nuevo=fopen(guardar_texto,"w");
                fclose(guardad_nuevo);

                guardad_nuevo=fopen(guardar_texto,"a+t");

            }
            else if(!(guardad_nuevo==NULL))
            {
                fwrite(texto,sizeof(texto),10,guardad_nuevo); // preguntar a damaris sobre que debe de ir donde esta el 10
                printf("Texto guardado con exito!\n");

            }



            if(vim[k]=='r')
            {
                fflush(stdin);
                printf("Digite la palabra que desea reemplazar: ");
                gets(palabra);

                printf("\nPor cual palabra desea reemplazarla: ");
                gets(palabrapor);

                buscar_remplazar(texto,palabra,palabrapor);
                puts(texto);
            }
        }
    }


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


