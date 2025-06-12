#ifndef NODOPILA_H
#define NODOPILA_H

#include "Pasajero.h"

class NodoPila {
private:
    Pasajero valor;
    NodoPila *siguiente; // Next
    friend class Pila; // Friend class

public:
    NodoPila(); // Constructor vacío
    NodoPila(Pasajero p, NodoPila* sig = nullptr);
    ~NodoPila(); // Destructor
};

typedef NodoPila* pNodoPila; // Pointer to NodoPila

#endif // NODOPILA_H
