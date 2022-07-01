#include <iostream>

using namespace std;

#include "Dados.h"
#include "Struct.h"

void lanzarDados(int dados[], int cant){
    srand(time(NULL));
    for (int i = 0; i < cant; i++){
        dados[i] = rand() % 6 + 1;
    }
}

void mostrarDados(int v[], int cant){
    for (int i = 0; i < cant; i++){
        cout << v[i] << "   ";
    }
}

int sumarVector(int v[], int tam){
    int i, suma = 0;
    for(i=0; i<tam; i++)
    {
        suma += v[i];
    }
    return suma;
}

int analizarDados(int dados[], int cant, jugador *jugador, bool &barro){
    int puntosLanzamiento = 0;
    if(cant == 2){
        //Caras distintas entre si y ningun as
        if(dados[0] != dados[1] && dados[0] != 1 && dados[1] != 1){
            puntosLanzamiento += sumarVector(dados, cant);
            cout << endl << endl << "¡Sumaste " << puntosLanzamiento << " trufas!" << endl;
            return puntosLanzamiento;
        }
        //Caras iguales y no son ases OINK
        if(dados[0] == dados[1] && dados[0] != 1){
            puntosLanzamiento += sumarVector(dados, cant) * 2;
            cout << endl << endl << "¡Sumaste " << puntosLanzamiento << " trufas y obtuviste un OINK!" << endl;
            jugador->oink++;
            return puntosLanzamiento;
        }
        //Caras iguales y son ases BARRO
        if(dados[0] == 1 && dados[1] == 1){
            puntosLanzamiento = 0;
            jugador->puntosTotales = 0;
            cout << endl << "Sacaste doble as te hundiste en el barro y termina tu turno" << endl;
            barro = true;
            return puntosLanzamiento;
        }
        //Caras distintas y hay 1 as
         if(dados[0] == 1 || dados[1] == 1){
            puntosLanzamiento = 0;
            cout << endl << "Sacaste un as no acumulas trufas esta ronda y termina tu turno" << endl << endl;
            return puntosLanzamiento;
        }
    } else {
        cout << "FUNCIONA REY" << endl << endl << endl;
        
    }
}

