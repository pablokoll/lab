#include <iostream>
#include <math.h>
using namespace std;
#include "Rondas.h"
#include "Dados.h"
#include "Struct.h"

void pedirNombres(jugador *j1, jugador *j2){
    cout << "Introduce el nombre del jugador 1: ";
    cin >> j1->nombre;
    cout << "Introduce el nombre del jugador 2: ";
    cin >> j2->nombre;
    cout << "El jugador 1 es: " << j1->nombre << endl;
    cout << "El jugador 2 es: " << j2->nombre << endl;
}

char* quienComienza(jugador *j1, jugador *j2){
    int dados[2];
    int lanzamientoJ1[2];
    int lanzamientoJ2[2];  
    lanzarDados(dados, 2);
    mostrarDados(dados, 2);
    lanzamientoJ1[0] = dados[0];
    lanzamientoJ1[1] = dados[1];
    int sumaJ1 = sumarVector(lanzamientoJ1, 2);
    system("pause");
    lanzarDados(dados, 2);
    mostrarDados(dados, 2);
    lanzamientoJ2[0] = dados[0];
    lanzamientoJ2[1] = dados[1];
    int sumaJ2 = sumarVector(lanzamientoJ2, 2);
    system("pause");
    if(sumaJ1 > sumaJ2){
        cout << "El jugador 1 comienza" << endl;
        return "J1";
    }else if(sumaJ1 < sumaJ2){
        cout << "El jugador 2 comienza" << endl;
        return "J2";
    }else{
        cout << "Empate!" << endl;
        int maxJ1 = max(lanzamientoJ1[0], lanzamientoJ1[1]);
        int maxJ2 = max(lanzamientoJ2[0], lanzamientoJ2[1]);
        if(maxJ1 > maxJ2){
            cout << "El jugador 1 comienza" << endl;
            return "J1";
        }else if(maxJ1 < maxJ2){
            cout << "El jugador 2 comienza" << endl;
            return "J2";
        }else{
            cout << "Empate!" << endl;
            quienComienza(j1, j2);
        }
    }
}

void comenzarJuego(jugador *j1, jugador *j2, char comienza[2]){
    cout << "EMPIEZA: " << comienza << endl;
}