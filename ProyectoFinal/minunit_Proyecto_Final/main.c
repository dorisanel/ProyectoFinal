#include "minunit.h"
#include "../libreria_proyecto.h"
char texto[]={"Hola como estas. Yo muy bien gracias.\n"};
char texto2[]={"Hola     como    estas.\n\t\n\t\n\tYo muy bien  gracias.\n"};
char texto3[]={"Me encantaria pasar esta materia,\nOjala el profe se apiade de mi.\nSi es con A mucho mejor,\nSe lo agradeceria de corazon.\n"};
MU_TEST(test_contador_palabras)
{
    mu_assert_int_eq(7,contador_palabras(texto));
    mu_assert_int_eq(7,contador_palabras(texto2));
    mu_assert_int_eq(23,contador_palabras(texto3));
}
MU_TEST(test_contador_parrafos)
{
    mu_assert_int_eq(1,contador_parrafos(texto));
    mu_assert_int_eq(2,contador_parrafos(texto2));
    mu_assert_int_eq(4,contador_parrafos(texto3));
}
MU_TEST(test_contador_oraciones)
{
    mu_assert_int_eq(2,contador_oraciones(texto));
    mu_assert_int_eq(2,contador_oraciones(texto2));
    mu_assert_int_eq(4,contador_oraciones(texto3));
}
MU_TEST(test_vim_ninguncomando)
{
    mu_assert_int_eq(-1,vim(texto3));
}
int main(int argc, char *argv[])
{
    MU_RUN_TEST(test_contador_palabras);
    MU_RUN_TEST(test_contador_oraciones);
    MU_RUN_TEST(test_contador_parrafos);
    MU_RUN_TEST(test_vim_ninguncomando);
    MU_REPORT();
    return 0;
}
