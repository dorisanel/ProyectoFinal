#include "libreria_proyecto.h"
int main()
{
    char *texto, letra;
    int cont=0;

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

        if(letra==LETRA)
        {
            cont--;
            if(vim(texto)==-1)
            {
                printf("ERROR!! El comando digitado no existe!\n");
            }
        }
        cont++;
    }
    while((letra!=EOF));

    m_antes_pb(texto);
    c_antes_ei(texto);
    aje(texto);
    gergir(texto);
    aba(texto);
    corregir_espacios(texto);
    corregir_mayus(texto);
    corregir_acentos(texto);
    sangria(texto);

    puts(texto);

    printf("\n\nCantidad de palabras: %d",contador_palabras(texto));
    printf("\nCantidad de oraciones: %d",contador_oraciones(texto));
    printf("\nCantidad de parrafos: %d",contador_parrafos(texto));

    if(vim(texto)==-1)
    {
        printf("ERROR!! El comando digitado no existe!\n");
    }

    /*implementar aqui que pregunte si desea continuar, aparte agregar un menu que permita abrir un archivo ya existente para modificar
     o crear uno nuevo*/

    free(texto);

    return 0;
}
