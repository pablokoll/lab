#include "NuevoJuego.h"
#include "Rondas.h"
#include "Dados.h"
#include "Struct.h"

void reiniciarJuego(jugador *j1, jugador *j2){
    j1->cantidadLanzamientos = 0;
    j2->cantidadLanzamientos = 0;
    j1->puntosRonda = 0;
    j2->puntosRonda = 0;
    j1->puntosTotales = 0;
    j2->puntosTotales = 0;
    j1->oink = 0;
    j2->oink = 0;
}

void nuevoJuego(jugador *j1, jugador *j2){
    reinciarJuego(j1, j2);
    pedirNombres(j1, j2);
    int comienza = quienComienza(j1, j2);
    comenzarJuego(j1, j2, comienza);
    finDelJuego(j1, j2);

    system("pause");
}
