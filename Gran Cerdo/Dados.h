#ifndef FUNCIONES_DADOS_H_INCLUDED
#define FUNCIONES_DADOS_H_INCLUDED

void lanzarDados(int v[], int cant) {
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

#endif FUNCIONES_DADOS_H_INCLUDED