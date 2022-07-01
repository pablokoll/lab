#ifndef FUNCIONES_DADOS_H_INCLUDED
#define FUNCIONES_DADOS_H_INCLUDED
#include "Struct.h"

void lanzarDados(int dados[], int cant);
void mostrarDados(int dados[], int cant);
int analizarDados(int dados[], int can, jugador *jugadorActual, jugador *j1, jugador *j2);
char seguirTirando();

#endif

