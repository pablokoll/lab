#include <iostream>
#include <math.h>
using namespace std;
#include "Rondas.h"
#include "Dados.h"
#include "Struct.h"

int quienComienza(jugador *j1, jugador *j2){
    cls();
    int dados[2];
    int lanzamientoJ1[2];
    int lanzamientoJ2[2];  
    cout << " LANZA " << j1->nombre << endl;
    lanzarDados(dados, 2);
    mostrarDados(dados, 2);
    cout << endl;
    lanzamientoJ1[0] = dados[0];
    lanzamientoJ1[1] = dados[1];
    int sumaJ1 = sumarVector(lanzamientoJ1, 2);
    system("pause");

    cout << " LANZA " << j2->nombre << endl;
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


int realizarLanzamiento(jugador *jugadorActual, int dados[], int dadosCant, int lanzamientos, jugador *j1, jugador *j2, int rondas){
    bool barro = false;
    cls();
    // CONDICION PARA QUE CAMBIE A TIRAR CON 3 DADOS
    if(barro || j1->puntosTotales > 50 && j2->puntosTotales > 50) dadosCant = 3;
    cout << " GRAN CERDO" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << " " << j1->nombre << ": " << j1->puntosTotales << " trufas acumuladas" << "      " << j2->nombre << ": " << j2->puntosTotales << " trufas acumuladas" << endl << endl;
    cout << " TURNO DE " << jugadorActual->nombre << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << " RONDAS #" << rondas << endl;
    cout << " TRUFAS DE LA RONDA: " << jugadorActual->puntosRonda << endl;
    cout << " LANZAMIENTOS DE LA RONDA: " << lanzamientos << endl;
    cout << "-----------------------------------------------------" << endl << endl;
    lanzamientos++;
    cout << " LANZAMIENTO: " << lanzamientos << endl << endl;
    if(lanzamientos > jugadorActual->cantidadLanzamientos){
        jugadorActual->cantidadLanzamientos = lanzamientos;
    }
    
    lanzarDados(dados, dadosCant);
    mostrarDados(dados, dadosCant);
    jugadorActual->puntosRonda += analizarDados(dados, dadosCant, jugadorActual, barro, j1, j2);

    // SI NO SALE AS QUE EL JUGADOR ACTUAL ELIJA SI TIRAR O NO
    if(dados[0] != 1 && dados[1] != 1 && dados[2] != 1){
        // SI SALE OINK QUE TIRE SI O SI
        if((dados[0] == dados[1] && dados[0] != 1 || dados[1] == dados[2] && dados[0] != 1) || dados[0] == dados[1] || dados[1] == dados[2] || dados[0] == dados[2] && dados[0] != 1 && dados[1] != 1 && dados[2] != 1){
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
        // COMIENZA JUGADOR 1
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
            // COMIENZA JUGADOR 2
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
    // CALCULO SUMAR 5 PDV A QUIEN TUVO MAS TRUFAS TOTALES
    int masTrufasTotalJ1, masTrufasTotalJ2 = 0;
    if(j1->puntosTotales > j2->puntosTotales){
        masTrufasTotalJ1 = 5;
        masTrufasTotalJ2 = 0;
    } else if (j1->puntosTotales < j2->puntosTotales) {
        masTrufasTotalJ2 = 5;
        masTrufasTotalJ1 = 0;
    } else {
        masTrufasTotalJ1 = 5;
        masTrufasTotalJ2 = 5;
    }
    // CALCULO SUMAR 1 PDV POR CADA 50 TRUFAS
    int cincuentaTrufasJ1 = j1->puntosTotales / 50;
    int cincuentaTrufasJ2 = j2->puntosTotales / 50;
    
    // CALCULO OINKS
    int oinksJ1 = j1->oink * 2;
    int oinksJ2 = j2->oink * 2;
    
    // CALCULO CERDO CODICIOSO
    int cerdoCodiciosoJ1, cerdoCodiciosoJ2 = 0;
    if(j1->cantidadLanzamientos > j2->cantidadLanzamientos){
        cerdoCodiciosoJ1 = 3;
        cerdoCodiciosoJ2 = 0;
    } else if (j1->cantidadLanzamientos < j2->cantidadLanzamientos) {
        cerdoCodiciosoJ2 = 3;
        cerdoCodiciosoJ1 = 0;
    } else {
        cerdoCodiciosoJ1 = 3;
        cerdoCodiciosoJ2 = 3;
    }
    
    //CALCULO PDV TOTAL
    int pdvTotalJ1, pdvTotalJ2 = 0;
    pdvTotalJ1 = masTrufasTotalJ1 + cincuentaTrufasJ1 + oinksJ1 + cerdoCodiciosoJ1;
    pdvTotalJ2 = masTrufasTotalJ2 + cincuentaTrufasJ2 + oinksJ2 + cerdoCodiciosoJ2;

    //LE GUARDO AL JUGADOR SUS PDV TOTALES
    j1->pdv = pdvTotalJ1;
    j2->pdv = pdvTotalJ2;
    // CALCULAR QUIEN ES EL GANADOR
    string nombreGanador;
    int pdvGanador = 0;
    if(pdvTotalJ1 > pdvTotalJ2){
        nombreGanador = j1->nombre;
        pdvGanador = pdvTotalJ1;
    } else if (pdvTotalJ1 < pdvTotalJ2){
        nombreGanador = j2->nombre;
        pdvGanador = pdvTotalJ2;
    } else {
        nombreGanador = "EMPATE";
        pdvGanador = pdvTotalJ1;
    }

    
    cls();
    string Oink;
    
    cout << "                                                         GRAN CERDO" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << " HITO" << "                                 " << j1->nombre << "                        " << j2->nombre << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << " Mas trufas en total           "  <<  masTrufasTotalJ1   <<    " PDV (" << j1->puntosTotales << " trufas)              " <<    masTrufasTotalJ2   <<   " PDV (" << j2->puntosTotales << " trufas)" << endl;
    cout << " Cada 50 trufas                "  <<    cincuentaTrufasJ1     << " PDV (" << j1->puntosTotales << " trufas)              "   << cincuentaTrufasJ2   << " PDV (" << j2->puntosTotales << " trufas)" << endl;
    cout << " Oinks                         " << oinksJ1 << " PDV (" << j1->oink << " Oinks)               "<< oinksJ2 <<" PDV (" << j2->oink << " Oinks)" << endl;
    cout << " Cerdo codicioso               " << cerdoCodiciosoJ1 << " PDV (" << j1->cantidadLanzamientos << " lanzamientos)        " << cerdoCodiciosoJ2 << " PDV (" << j2->cantidadLanzamientos << " lanzamientos)" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << " TOTAL                             "<< pdvTotalJ1 << " PDV                            " << pdvTotalJ2 << " PDV" << endl << endl;
    cout << " GANADOR: " << nombreGanador << " con " << pdvGanador << " puntos de victoria." << endl << endl;
    cout << " Ingrese Oink para continuar:" << endl;
    cin >> Oink;
    if(Oink != "Oink"){
        cout << " Ingrese Oink para continuar:" << endl;
        cin >> Oink;
    }
}