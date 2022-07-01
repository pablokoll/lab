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

int quienComienza(jugador *j1, jugador *j2){
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
        return 1;
    }else if(sumaJ1 < sumaJ2){
        cout << "El jugador 2 comienza" << endl;
        return 2;
    }else{
        cout << "Empate!" << endl;
        int maxJ1 = max(lanzamientoJ1[0], lanzamientoJ1[1]);
        int maxJ2 = max(lanzamientoJ2[0], lanzamientoJ2[1]);
        if(maxJ1 > maxJ2){
            cout << "El jugador 1 comienza" << endl;
            return 1;
        }else if(maxJ1 < maxJ2){
            cout << "El jugador 2 comienza" << endl;
            return 2;
        }else{
            cout << "Empate!" << endl;
            quienComienza(j1, j2);
        }
    }
}

char seguirTirando(){
    char seguir;
    cout << "Desea seguir tirando? (S/N): ";
    cin >> seguir;
    if(seguir == 'S' || seguir == 's' || seguir == 'N' || seguir == 'n'){
        return seguir;
    }
    else{
        cout << "Ingrese una opcion valida" << endl;
        seguirTirando();
    }
}

int jugarRonda(jugador *jugador, int dados[], int dadosCant){
    int puntosRonda = 0;
    int lanzamientos = 0;
    lanzarDados(dados, dadosCant);
    mostrarDados(dados, dadosCant);
    puntosRonda = analizarDados(dados, dadosCant, puntosRonda);
    
    lanzamientos++;
    if(lanzamientos > jugador->cantidadLanzamientos){
        jugador->cantidadLanzamientos = lanzamientos;
    }
    char decision = seguirTirando();
    if(decision == 'N' || decision == 'n'){
        return puntosRonda;
    }else if(decision == 'S' || decision == 's'){
        jugarRonda(jugador, dados, dadosCant);
    }
    
}
//Esta funcion tiene que ejecutar el juego, arrancando el que haya ganado el "quienComienza".
//El jugador va a arrancar a tirar los dados y se tiene que analizar cada tirada para ir contando los puntos o ver que sucede
//Despues de que tira el jugador, se tiene que ver si quiere seguir tirando o no, para esto esta la funcion seguirTirando().
//Ver como hacer el switch para cunado el jugador quiera dejar de tirar o caiga en el barro.

void comenzarJuego(jugador *j1, jugador *j2, int comienza){
    int rondas = 1;
    int dadosCant = 2;
    int dados[dadosCant];
    int puntosTotalesJ1 = 0;
    int puntosTotalesJ2 = 0;
    do{
        if(comienza == 1){
        cout << "Ronda: " << rondas << " - Jugador: " << j1->nombre << endl;
        puntosTotalesJ1 =+ jugarRonda(j1, dados, dadosCant);
        system("pause");
        cout << "Ronda: " << rondas << " - Jugador: " << j2->nombre << endl;
        puntosTotalesJ2 =+ jugarRonda(j2, dados, dadosCant);
        rondas++;
        system("pause");
        }else if(comienza == 2){
        cout << "Ronda: " << rondas << " - Jugador: " << j2->nombre << endl;
        puntosTotalesJ2 =+ jugarRonda(j2, dados, dadosCant);
        system("pause");
        cout << "Ronda: " << rondas << " - Jugador: " << j1->nombre << endl;
        puntosTotalesJ1 =+ jugarRonda(j1, dados, dadosCant);
        rondas++;
        system("pause");
        }
    }while(rondas < 6);
    cout << "El jugador 1 tiene: " << puntosTotalesJ1 << " puntos" << endl;
    cout << "El jugador 1 lanzo: " << j1->cantidadLanzamientos << " puntos" << endl;
}

