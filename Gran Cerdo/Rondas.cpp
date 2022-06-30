#include <iostream>
using namespace std;
#include "Rondas.h"
#include "Dados.h"
#include "Struct.h"

void pedirNombres(jugador *j1, jugador *j2){
    std::string nombre;
    cout << "Introduce el nombre del jugador 1: ";
    cin >> j1->nombre;
    // j1.nombre = &nombre;
    cout << "Introduce el nombre del jugador 2: ";
    cin >> j2->nombre;
    // j2.nombre = &nombre;
    cout << "El jugador 1 es: " << j1->nombre << endl;
    cout << "El jugador 2 es: " << j2->nombre << endl;
}

void quienComienza(jugador *j1, jugador *j2){
    int dados[2];
    int lanzamientoJ1[2];
    int lanzamientoJ2[2];
    for(int i=0; i<2; i++){     
        lanzarDados(dados, 2);
        mostrarDados(dados, 2);
        lanzamientoJ1[i] = dados[i];
        system("pause");
    }
    int sumaJ1 = sumarVector(lanzamientoJ1, 2);
    int sumaJ2 = sumarVector(lanzamientoJ2, 2);
    cout << "dados l1 " << lanzamientoJ1[0] << endl;
    cout << "dados l1 " << lanzamientoJ1[1] << endl;
}

void comenzarJuego(){
    
}