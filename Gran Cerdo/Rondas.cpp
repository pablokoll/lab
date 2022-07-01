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
    cls();

    cout << "El jugador 1 es: " << j1->nombre << endl;
    cout << "El jugador 2 es: " << j2->nombre << endl;
}

int quienComienza(jugador *j1, jugador *j2){
    cls();
    int dados[2];
    int lanzamientoJ1[2];
    int lanzamientoJ2[2];  
    cout << "LANZA " << j1->nombre << endl;
    lanzarDados(dados, 2);
    mostrarDados(dados, 2);
    cout << endl;
    lanzamientoJ1[0] = dados[0];
    lanzamientoJ1[1] = dados[1];
    int sumaJ1 = sumarVector(lanzamientoJ1, 2);
    system("pause");

    cout << "LANZA " << j2->nombre << endl;
    lanzarDados(dados, 2);
    mostrarDados(dados, 2);
    cout << endl;
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
    cout << endl << "Continuar? (S/N)";
    cin >> seguir;
    if(seguir == 'S' || seguir == 's' || seguir == 'N' || seguir == 'n'){
        return seguir;
    } else{
        seguirTirando();
    }
}

int realizarLanzamiento(jugador *jugadorActual, int dados[], int dadosCant, int lanzamientos, jugador *j1, jugador *j2, int rondas){
    bool barro = false;
    cls();
    if(barro || j1->puntosTotales > 10 && j2->puntosTotales > 10) dadosCant = 3;
    cout << "GRAN CERDO" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << j1->nombre << ": " << j1->puntosTotales << " trufas acumuladas" << "      " << j2->nombre << ": " << j2->puntosTotales << " trufas acumuladas" << endl << endl;
    cout << "TURNO DE " << jugadorActual->nombre << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "RONDAS #" << rondas << endl;
    cout << "TRUFAS DE LA RONDA: " << jugadorActual->puntosRonda << endl;
    cout << "LANZAMIENTOS DE LA RONDA: " << lanzamientos << endl;
    cout << "-----------------------------------------------------" << endl << endl;
    lanzamientos++;
    cout << "LANZAMIENTO: " << lanzamientos << endl << endl;
    if(lanzamientos > jugadorActual->cantidadLanzamientos){
        jugadorActual->cantidadLanzamientos = lanzamientos;
    }
    
    lanzarDados(dados, dadosCant);
    mostrarDados(dados, dadosCant);
    jugadorActual->puntosRonda += analizarDados(dados, dadosCant, jugadorActual, barro);
    // SI NO SALE AS QUE EL jugadorActual ELIJA SI TIRAR O NO
    if(dados[0] != 1 && dados[1] != 1 && dados[2] != 1){
        // SI SALE OINK QUE TIRE SI O SI
        if(dados[0] == dados[1] && dados[0] != 1 || dados[1] == dados[2] && dados[0] != 1){
            system("pause");
            realizarLanzamiento(jugadorActual, dados, dadosCant, lanzamientos, j1, j2, rondas);
        } else {
            char decision = seguirTirando();
            if(decision == 'N' || decision == 'n'){
                return jugadorActual->puntosRonda;
            }else if(decision == 'S' || decision == 's'){
                realizarLanzamiento(jugadorActual, dados, dadosCant, lanzamientos, j1, j2, rondas);
            }
        }
    }
}

void comenzarJuego(jugador *j1, jugador *j2, int comienza){
    int rondas = 1;
    int puntosRondaJ1, puntosRondaJ2, lanzamientos = 0;
    int dadosCant = 2;
    int dados[dadosCant];
    do{
        cls();
        if(comienza == 1){ 
            puntosRondaJ1 = realizarLanzamiento(j1, dados, dadosCant, lanzamientos, j1, j2, rondas);
            if (puntosRondaJ1 == 1){
                puntosRondaJ1 = 0;
            }
            j1->puntosTotales += puntosRondaJ1;
            j1->puntosRonda = 0;
            system("pause");
            puntosRondaJ2 = realizarLanzamiento(j2, dados, dadosCant, lanzamientos, j1, j2, rondas);
            if (puntosRondaJ2 == 1){
                puntosRondaJ2 = 0;
            }
            j2->puntosTotales += puntosRondaJ2;
            j2->puntosRonda = 0;
            rondas++;
            system("pause");
        } else if(comienza == 2){
            puntosRondaJ2 = realizarLanzamiento(j2, dados, dadosCant, lanzamientos, j1, j2, rondas);
            if (puntosRondaJ2 == 1){
                puntosRondaJ2 = 0;
            }
            j2->puntosTotales += puntosRondaJ2;
            j2->puntosRonda = 0;
            system("pause");
            puntosRondaJ1 = realizarLanzamiento(j1, dados, dadosCant, lanzamientos, j1, j2, rondas);
            if (puntosRondaJ1 == 1){
                puntosRondaJ1 = 0;
            }
            j1->puntosTotales += puntosRondaJ1;
            j1->puntosRonda = 0;
            rondas++;
            system("pause");
        }
    } while(rondas < 6);
}

void finDelJuego(jugador *j1, jugador *j2){
    cls();
    string Oink;
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
    cin >> Oink;
    if(Oink != "Oink"){
        cout << "Ingrese Oink para continuar:" << endl;
        cin >> Oink;
    }
}