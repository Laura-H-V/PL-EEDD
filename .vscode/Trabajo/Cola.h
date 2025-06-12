#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"

class Cola{

    private:
        NodoCola * primero;
        NodoCola * ultimo;
        int longitud;
    public:
        Cola(); ~Cola();
        void encolar(Pasajero elemento, int prioridad);
        Pasajero inicio() const;
        Pasajero fin() const;
        Pasajero desencolar();
        int get_longitud() const; 
        bool es_vacia() const;
        void mostrarCola(); //No es correcto, se implementa para ver que está creada correctamente
        
};
#endif // COLA_H