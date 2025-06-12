#ifndef NODOPILA_H
#define NODOPILA_H

#include "Persona.h"

class NodoPila {
private:
    Persona valor;
    NodoPila *siguiente; // Next
    friend class Pila; // Friend class

public:
    NodoPila(); // Constructor vacío
    NodoPila(Persona p, NodoPila* sig = nullptr);
    ~NodoPila(); // Destructor
};

typedef NodoPila* pNodoPila; // Pointer to NodoPila

#endif // NODOPILA_H
