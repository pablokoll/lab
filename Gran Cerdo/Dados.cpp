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

int analizarDados(int dados[], int cant, int puntosRonda){
    string expression;
    
    if(cant == 2){
        //Caras distintas entre si y ningun AS
        
    }else if(cant == 3){
        //Dos Caras iguales y una distinta sin AS

    }

    switch (expression)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
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

