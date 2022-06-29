#ifndef NUEVOJUEGO_H_INCLUDED
#define NUEVOJUEGO_H_INCLUDED

void NuevoJuego(char jugador1[], char jugador2[]){
    int vDados[2];
    cout << "Introduce el nombre del jugador 1: ";
    cin >> jugador1;
    cout << "Introduce el nombre del jugador 2: ";
    cin >> jugador2;
    cout << "El jugador 1 es: " << jugador1 << endl;
    cout << "El jugador 2 es: " << jugador2 << endl;   

    // lanzarDados(vDados[2], 2);
    system("pause");
}

#endif NUEVOJUEGO_H_INCLUDED