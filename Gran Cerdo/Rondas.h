#ifndef RONDAS_H_INCLUDED
#define RONDAS_H_INCLUDED
#include "Struct.h"

void pedirNombres(jugador *j1, jugador *j2);
char* quienComienza(jugador *j1, jugador *j2);
void comenzarJuego(jugador *j1, jugador *j2, char comienza[2]);

#endif