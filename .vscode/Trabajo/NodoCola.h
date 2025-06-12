#ifndef NODOCOLA_H 
#define NODOCOLA_H
#include <iostream>
#include "Persona.h"

class NodoCola
{   
    friend class Cola;
    private:
        NodoCola *siguiente; //puntero
        Persona elemento;
        int prioridad;
    public:
        NodoCola(); //Constructor
        NodoCola(Persona e, int prioridad, NodoCola*sig = NULL);
        ~NodoCola();
};
#endif // NODOCOLA_H