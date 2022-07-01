#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

struct jugador {
    std::string nombre;
    int puntosTotales = 0;
    int puntosRonda = 0;
    int cantidadLanzamientos = 0;
    int oink = 0;
    int pdv = 0;
};

#endif