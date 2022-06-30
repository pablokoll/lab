#include "NuevoJuego.h"
#include "Rondas.h"
#include "Dados.h"
#include "Struct.h"

void NuevoJuego(jugador *j1, jugador *j2){
    int dados[2];
    pedirNombres(j1, j2);
    quienComienza(j1, j2);

    system("pause");
}
