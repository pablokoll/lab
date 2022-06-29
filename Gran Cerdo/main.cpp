#include <iostream>
#include <ctime>
#include <cstdlib>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

#include "NuevoJuego.h"
#include "Estadisticas.h"
#include "Cerditos.h"
#include "Dados.h"

int main(){
    int opcion;
    int vDados[2];
    // setBackgroundColor(0);
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
            NuevoJuego();
            break;
        case 2:
            Estadisticas();
            break;
        case 3:
            Cerditos();
            break;
        default:
            break;
    }
    } while(opcion !=0);

    return 0;
}
