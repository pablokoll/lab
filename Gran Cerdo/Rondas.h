#ifndef RONDAS_H_INCLUDED
#define RONDAS_H_INCLUDED
#include "Struct.h"

void pedirNombres(jugador *j1, jugador *j2);
int quienComienza(jugador *j1, jugador *j2);
void comenzarJuego(jugador *j1, jugador *j2, int comienza);

#endif