#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria_proyecto.h"

int main()
{
    char *texto, letra;
    int cont=0;
    fflush(stdin);
    printf("Digite texto: ");
    do
    {
        letra=getchar();
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

    puts(texto);

    printf("\n\nCantidad de palabras: %d",contador_palabras(texto));

    free(texto);

    return 0;
}

