#include <stdio.h>
#include <stdlib.h>
#include "libreria_proyecto.h"

#define LETRA 62 // asigno el simbolo > para poder digirar comando

int main()
{
    char *texto, letra,comando,guardar_texto[50];
    FILE *guardad_nuevo;
    int cont=0,vim;

    printf("Digite el nombre donde se guardar%c el archivo de texto: ",160);
    gets(guardar_texto);
    guardad_nuevo=fopen(guardar_texto,"rt");

    printf("Digite texto: ");

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
    }
    while((letra!=EOF));

    corregir_mayus(texto);
    corregir_acentos(texto);
    sangria(texto);

    puts(texto);
    printf("\b");/*Para borrar el ctrl Z*/

    printf("\n\nCantidad de palabras: %d",contador_palabras(texto));

    comando=getchar(); // espera a que digite un caracter que es el >

    if(comando== LETRA) // Para poder digitar comandos a lo vim
    {
        printf("\ndigite un comando");
        scanf("%d",&vim);

        if(vim==1)     //Prueba de usar comando
        {

            printf("\nEl archivo no existia, por tanto se ha creado!\n");
            guardad_nuevo=fopen(guardar_texto,"w");
            fclose(guardad_nuevo);
        }
    }

    guardad_nuevo=fopen(guardar_texto,"a+t");
    if(!(guardad_nuevo==NULL))
    {
        fwrite(texto,sizeof(texto),10,guardad_nuevo);
        printf("Funciono\n");

    }

    free(texto);

    return 0;
}
