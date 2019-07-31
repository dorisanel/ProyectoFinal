#ifndef libreria_proyecto
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define LETRA 62 // asigno el simbolo > para poder digirar comando
char *leer();
void corregir_espacios(char*);
void corregir_mayus(char*);
void corregir_acentos(char*);
void m_antes_pb(char*);
void c_antes_ei(char*);
void h_a_inicio(char*);
void aje(char*);
void doble_l(char*);
void gergir(char*);
void aba(char*);
void sangria(char*);
int contador_palabras(char*);
int contador_oraciones(char*);
int contador_parrafos(char*);
void buscar_remplazar(char*,char*,char*);
void insertar(char*);
void borrar_linea(char*);
void borrar_despues_linea(char*);
void eliminar_caracter(char*);
int vim(char*);
void imprimir_cantidad(char*);
#endif // libreria_proyecto
