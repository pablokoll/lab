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
        cout << " " << v[i] << "   ";
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

char seguirTirando(){
    char seguir;
    cout << endl << " Continuar? (S/N)";
    cin >> seguir;
    if(seguir == 'S' || seguir == 's' || seguir == 'N' || seguir == 'n'){
        return seguir;
    } else{
        seguirTirando();
    }
}

int analizarDados(int dados[], int cant, jugador *jugadorActual, bool &barro, jugador *j1, jugador *j2){
    int puntosLanzamiento = 0;

    // DOS DADOS:
    if(cant == 2){
        //Dados distintos entre si y ningun as
        if(dados[0] != dados[1] && dados[0] != 1 && dados[1] != 1){
            puntosLanzamiento += sumarVector(dados, cant);
            cout << endl << endl << " Sumaste " << puntosLanzamiento << " trufas!" << endl << endl;
            return puntosLanzamiento;
        }
        //Dados iguales y no son ases -> OINK
        if(dados[0] == dados[1] && dados[0] != 1){
            puntosLanzamiento += sumarVector(dados, cant) * 2;
            cout << endl << endl << " Sumaste " << puntosLanzamiento << " trufas y obtuviste un OINK!" << endl << endl;
            jugadorActual->oink++;
            return puntosLanzamiento;
        }
        //Dados iguales y son ases -> HUNDE EN EL BARRO
        if(dados[0] == 1 && dados[1] == 1){
            puntosLanzamiento = 0;
            jugadorActual->puntosTotales = 0;
            cout << endl << " Sacaste doble as te hundiste en el barro y termina tu turno" << endl << endl;
            jugadorActual->barro = true;
            return puntosLanzamiento;
        }
        //Dados distintos y hay 1 as
         if(dados[0] == 1 || dados[1] == 1){
            puntosLanzamiento = 0;
            cout << endl << " Sacaste un as no acumulas trufas esta ronda y termina tu turno" << endl << endl;
            return puntosLanzamiento;
        }
        // TRES DADOS:
    } else {
        // Tres dados distintos y uno es un AS CHECK
        if (dados[0] != dados[1] && dados[1] != dados[2] && dados[0] != dados[2] && (dados[0] == 1 || dados[1] == 1 || dados[2] == 1)){
            puntosLanzamiento = 0;
            cout << endl << " Sacaste un as no acumulas trufas esta ronda y termina tu turno" << endl << endl;
            return puntosLanzamiento;
        }
        // Tres dados iguales y no son ases -> OINK
        if (dados[0] == dados[1] && dados[1] == dados[2] && dados[2] != 1){
            puntosLanzamiento += sumarVector(dados, cant) * 2;
            cout << endl << endl << " Sumaste " << puntosLanzamiento << " trufas y obtuviste un OINK!" << endl << endl;
            jugadorActual->oink++;
            return puntosLanzamiento;
        }
        // Tres dados iguales y son ases -> HUNDE EN EL BARRO Y PASA PUNTOS AL OTRO
        if (dados[0] == dados[1] && dados[1] == dados[2] && dados[2] == 1){
            if (jugadorActual != j1){
                j1->puntosTotales += puntosLanzamiento;
                j1->puntosTotales += j2->puntosTotales;
            } else {
                j2->puntosTotales += puntosLanzamiento;
                j2->puntosTotales += j1->puntosTotales;
            }
            puntosLanzamiento = 0;
            jugadorActual->puntosTotales = 0;
            cout << endl << " Sacaste triple as te hundiste en el barro y termina tu turno" << endl << endl;
            jugadorActual->barro = true;
            return puntosLanzamiento;
        }
        // Dos dados son AS y el otro no -> HUNDE EN EL BARRO
        if ((dados[0] == dados[1] || dados[1] == dados[2] || dados[0] == dados[2]) && (dados[0] == 1 && dados[1] == 1 || dados[1] == 1 && dados[2] == 1 || dados[0] == 1 && dados[2] == 1)){
            puntosLanzamiento = 0;
            jugadorActual->puntosTotales = 0;
            cout << endl << " Sacaste doble as te hundiste en el barro, perdiste todas tus trufas acumuladas y termina tu turno" << endl << endl;
            jugadorActual->barro = true;
            return puntosLanzamiento;
        }
        // Dos dados iguales y uno distino (ninguna es un AS) CHECK
        if (dados[0] == dados[1] || dados[1] == dados[2] || dados[0] == dados[2] && dados[0] != 1 && dados[1] != 1 && dados[2] != 1){
            puntosLanzamiento += sumarVector(dados, cant);
            cout << endl << endl << " Sumaste " << puntosLanzamiento << " trufas!" << endl << endl;
            cout << endl << " Queres continuar y acumular las trufas? Sino termina tu turno y no acumulas las trufas" << endl << endl;
            char seguirTurno = seguirTirando();
            if (seguirTurno == 'n' || seguirTurno == 'N'){
                puntosLanzamiento = 0;
                cout << endl << " No sumaste ninguna trufa y termina tu turno" << endl << endl;
                return puntosLanzamiento;
            } else {
                return puntosLanzamiento;
            }
        }
        // Tres dados distintos y ninguno AS CHECK
        if (dados[0] != dados[1] && dados[1] != dados[2] && dados[0] != dados[2] && dados[0] != 1 && dados[1] != 1 && dados[2] != 1){
            puntosLanzamiento += sumarVector(dados, cant);
            cout << endl << endl << " Sumaste " << puntosLanzamiento << " trufas!" << endl;
            return puntosLanzamiento;
        }
        
    }
}

