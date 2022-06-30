#include "NuevoJuego.h"
#include "Rondas.h"
#include "Dados.h"
#include "Struct.h"

void NuevoJuego(jugador *j1, jugador *j2){ 
    pedirNombres(j1, j2);
    int comienza = quienComienza(j1, j2);
    comenzarJuego(j1, j2, comienza);

    system("pause");
}
