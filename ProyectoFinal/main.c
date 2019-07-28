#include "libreria_proyecto.h"
int main()
{
    char *texto, letra,guardar_texto[50];
    FILE *guardar_nuevo;
    int cont=0;

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

    corregir_espacios(texto);
    corregir_mayus(texto);
    corregir_acentos(texto);
    m_antes_pb(texto);
    sangria(texto);

    puts(texto);

    printf("\n\nCantidad de palabras: %d",contador_palabras(texto));
    printf("\nCantidad de oraciones: %d",contador_oraciones(texto));
    printf("\nCantidad de parrafos: %d",contador_parrafos(texto));

    vim(texto,guardar_nuevo,guardar_texto);

    /*implementar aqui que pregunte si desea continuar, aparte agregar un menu que permita abrir un archivo ya existente para modificar
     o crear uno nuevo*/

    free(texto);

    return 0;
}
