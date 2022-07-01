#include "Estadisticas.h"
#include "Struct.h"
#include "NuevoJuego.h"

void Estadisticas(jugador *j1, jugador *j2){
    string nombreGanador;
    int pdvGanador = 0;
    string tituloGanador = " GANADOR: ";
    cout << "    GRAN CERDO" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << " Jugadores:    JUGADOR 1: " << j1->nombre << " con " << j1->pdv << " PDV" << "   JUGADOR 2: " << j2->nombre << " con " << j2->pdv << " PDV" << endl;
    cout << endl << endl;
    if(j1->pdv > j2->pdv){
        nombreGanador = j1->nombre;
        pdvGanador = j1->pdv;
    } else if(j1->pdv < j2->pdv){
        nombreGanador = j2->nombre;
        pdvGanador = j2->pdv;
    } else{
        nombreGanador = "Empate";
        tituloGanador = "";
        pdvGanador = j1->pdv;
    }
    cout << tituloGanador << nombreGanador << " con " << pdvGanador << " Puntos de Victoria!" << endl << endl;
    system("pause");
}
