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

char* quienComienza(jugador *j1, jugador *j2){
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
        return "J1";
    }else if(sumaJ1 < sumaJ2){
        cout << "El jugador 2 comienza" << endl;
        return "J2";
    }else{
        cout << "Empate!" << endl;
        int maxJ1 = max(lanzamientoJ1[0], lanzamientoJ1[1]);
        int maxJ2 = max(lanzamientoJ2[0], lanzamientoJ2[1]);
        if(maxJ1 > maxJ2){
            cout << "El jugador 1 comienza" << endl;
            return "J1";
        }else if(maxJ1 < maxJ2){
            cout << "El jugador 2 comienza" << endl;
            return "J2";
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

//Esta funcion tiene que ejecutar el juego, arrancando el que haya ganado el "quienComienza".
//El jugador va a arrancar a tirar los dados y se tiene que analizar cada tirada para ir contando los puntos o ver que sucede
//Despues de que tira el jugador, se tiene que ver si quiere seguir tirando o no, para esto esta la funcion seguirTirando().
//Ver como hacer el switch para cunado el jugador quiera dejar de tirar o caiga en el barro.

void comenzarJuego(jugador *j1, jugador *j2, char comienza[2]){
    int rondas = 0;
    int dadosCant = 2;
    int dados[dadosCant];
    do{
        cout << "Ronda " << rondas << endl;
        cout << "El jugador " << comienza << " comienza" << endl;
    if(comienza == "J1"){
        cout << "arranco con un tiki con un par de lobas";
    }else if(comienza == "J2"){
        cout << "tu wacha baja al piso cuando escucha al noba";
    }

    
    char decision = seguirTirando();
    system("pause");
    if(decision == 'N' || decision == 'n'){
        //Switchear el jugador
        //Cuando termina el segundo turno cambiar devuelta y sumar una ronda
        rondas++;
    }else if(decision == 'S' || decision == 's'){
        // Sigo jugando
    }
    }while(rondas < 5);

}
