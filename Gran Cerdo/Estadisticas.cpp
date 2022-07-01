#include "Estadisticas.h"
#include "Struct.h"
#include "NuevoJuego.h"

void Estadisticas(jugador *j1, jugador *j2){

    cout << "    GRAN CERDO" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "HITO" << j1->nombre << j2->nombre << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Mas trufas en total" << " PDV (" << j2->puntosTotales << " trufas)" << " PDV (" << j2->puntosTotales << " trufas)" << endl;
    cout << "Cada 50 trufas 6 PDV (300 trufas) 5 PDV (250 trufas)" << endl;
    cout << "Oinks " << j1->oink * 2 << " PDV (" << j1->oink << " Oinks) "<< j2->oink * 2 <<" PDV (" << j2->oink << " Oinks)" << endl;
    cout << "Cerdo codicioso " << " PDV (" << j1->cantidadLanzamientos << " lanzamientos) " << " PDV (" << j2->cantidadLanzamientos << " lanzamientos)" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "TOTAL 18 PDV 16 PDV" << endl;
    cout << "GANADOR: PEPPA con 18 puntos de victoria." << endl;
    cout << "Ingrese Oink para continuar:" << endl;

    system("pause");
}
