#include "libreria_proyecto.h"
int main()
{
    system("color b0");
    char *texto;

    printf("\t\t\t\t COMANDOS\n\n");
    printf("\t\t '>'->entrar al modo comando\n");
    printf("\t\t %%s->reemplazar letra o palabra\n");
    printf("\t\t a->insertar texto en un archivo ya creado\n");
    printf("\t\t i->insertar texto\n");
    printf("\t\t d->borrar todas las lineas debajo de la digitada\n");
    printf("\t\t dd->borrar una linea dicha por el usuario\n");
    printf("\t\t x->borra un caracter o una palabra dicha por el usuario\n");
    printf("\t\t q!->sale del modo comando\n\n\n");

    system("PAUSE");
    system("CLS");

    printf("Digite texto: \n");

    texto=leer();

    m_antes_pb(texto);
    c_antes_ei(texto);
    h_a_inicio(texto);
    doble_l(texto);
    corregir_x(texto);
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
