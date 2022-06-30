#include <iostream>
#include <ctime>
#include <cstdlib>
#include "rlutil.h"
using namespace std;
using namespace rlutil;

#include "NuevoJuego.cpp"
#include "Estadisticas.cpp"
#include "Cerditos.cpp"
#include "Dados.cpp"
#include "Rondas.cpp"
#include "Struct.h"   

int main(){

jugador *j1 = new jugador;
jugador *j2 = new jugador;

    int opcion;
    do{
        cls();
        cout << "GRAN CERDO" << endl;
        cout << "---------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADÍSTICAS" << endl;
        cout << "3 - CERDITOS" << endl;
        cout << "---------------------" << endl;
        cout << "0 - SALIR" << endl;
        cin >> opcion;
        cls();

     switch(opcion){
        case 1:
            NuevoJuego(j1, j2);
            break;
        case 2:
            Estadisticas(j1, j2);
            break;
        case 3:
            Cerditos(j1, j2);
            break;
        default:
            break;
    }
    } while(opcion !=0);

    return 0;
}
