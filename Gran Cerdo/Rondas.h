#ifndef RONDAS_H_INCLUDED
#define RONDAS_H_INCLUDED
#include "Struct.h"

int quienComienza(jugador *j1, jugador *j2);
void comenzarJuego(jugador *j1, jugador *j2, int comienza);
int realizarLanzamiento(jugador *jugadorActual, int dados[], int dadosCant, int lanzamientos, jugador *j1, jugador *j2, int rondas);
void finDelJuego(jugador *j1, jugador *j2);

#endif