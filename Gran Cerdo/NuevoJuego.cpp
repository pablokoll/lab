#include "NuevoJuego.h"
#include "Rondas.h"
#include "Dados.h"
#include "Struct.h"

void pedirNombres(jugador *j1, jugador *j2){
    cout << " Introduce el nombre del jugador 1: ";
    cin >> j1->nombre;
    cout << " Introduce el nombre del jugador 2: ";
    cin >> j2->nombre;
    cls();

    cout << " El jugador 1 es: " << j1->nombre << endl;
    cout << " El jugador 2 es: " << j2->nombre << endl;
}

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
    reiniciarJuego(j1, j2);
    
    pedirNombres(j1, j2);

    int comienza = quienComienza(j1, j2);
    comenzarJuego(j1, j2, comienza);

    finDelJuego(j1, j2);

    system("pause");
}
