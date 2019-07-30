#include "libreria_proyecto.h"
int main()
{
    char *texto;

    printf("Digite texto: \n");

    texto=leer();

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
    imprimir_cantidad(texto);

    if(vim(texto)==-1)
    {
        printf("ERROR!! El comando digitado no existe!\n");
    }

    free(texto);

    return 0;
}
