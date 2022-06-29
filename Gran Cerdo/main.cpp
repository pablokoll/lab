#include <iostream>
#include <ctime>
#include <cstdlib>
#include "rlutil.h"

using namespace std;
using namespace rlutil;


void lanzarDado(int v[], int cant) {
    srand(time(NULL));
    for (int i = 0; i < cant; i++){
        v[i] = rand() % 6 + 1;
    }
}
void mostrarDados(int v[], int cant){
    for (int i = 0; i < cant; i++){
        cout << " " << v[i];
    }

}

int main()
{
    int opcion;
    int vDados[2];
    setBackgroundColor(5);
    cls();
    do{
        cout << "GRAN CERDO" << endl;
        cout << "---------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTAD�STICAS" << endl;
        cout << "3 - CERDITOS" << endl;
        cout << "---------------------" << endl;
        cout << "0 - SALIR" << endl;
    } while(opcion !=0);

    switch(opcion){
        case 1:
            anykey();
            break;
        case 2:
            anykey();
            break;
        case 3:
            anykey();
            break;
        case 0:
            anykey();
            break;
    }


    string jugador1, jugador2;
    cout << "Introduce el nombre del jugador 1: ";
    cin >> jugador1;
    cout << "Introduce el nombre del jugador 2: ";
    cin >> jugador2;
    cout << "El jugador 1 es: " << jugador1 << endl;
    cout << "El jugador 2 es: " << jugador2 << endl;

    lanzarDados(vDados, 2); // lanza 2 dados
    mostrarDados(vDados, 2);

    return 0;
}
