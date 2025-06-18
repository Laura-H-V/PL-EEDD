#ifndef NODOPILA_H
#define NODOPILA_H

#include "Pasajero.h"

class NodoPila {
private:
    Pasajero valor;
    NodoPila *siguiente; 
    friend class Pila;

public:
    NodoPila(); 
    NodoPila(Pasajero p, NodoPila* sig = nullptr);
    ~NodoPila();
};

typedef NodoPila* pNodoPila; // Pointer to NodoPila

#endif // NODOPILA_H
