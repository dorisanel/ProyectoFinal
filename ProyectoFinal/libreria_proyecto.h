#ifndef libreria_proyecto
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define LETRA 62 // asigno el simbolo > para poder digirar comando
void corregir_espacios(char*);
void corregir_mayus(char*);
void corregir_acentos(char*);
void m_antes_pb(char*);
void sangria(char*);
int contador_palabras(char*);
int contador_oraciones(char*);
int contador_parrafos(char*);
void buscar_remplazar(char*,char*,char*);
void vim(char *,FILE *,char[]);
#endif // libreria_proyecto
