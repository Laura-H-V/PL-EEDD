#ifndef NODOCOLA_H 
#define NODOCOLA_H
#include <iostream>
#include "Pasajero.h"

class NodoCola
{   
    friend class Cola;
    private:
        NodoCola *siguiente; //puntero
        Pasajero elemento;
        int prioridad;
    public:
        NodoCola(); //Constructor
        NodoCola(Pasajero e, int prioridad, NodoCola*sig = NULL);
        ~NodoCola();
};
#endif // NODOCOLA_H