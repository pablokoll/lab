#include <iostream>

using namespace std;

#include "Dados.h"

void lanzarDados(int dados[], int cant){
    srand(time(NULL));
    for (int i = 0; i < cant; i++){
        dados[i] = rand() % 6 + 1;
    }
}

void mostrarDados(int v[], int cant){
    for (int i = 0; i < cant; i++){
        cout << v[i] << endl;
    }
}

void analizarDados(int dados[], int cant){
    
}

int sumarVector(int v[], int tam){
    int i, suma = 0;
    for(i=0; i<tam; i++)
    {
        suma += v[i];
    }
    return suma;
}

