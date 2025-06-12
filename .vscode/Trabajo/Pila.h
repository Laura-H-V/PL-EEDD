#ifndef PILA_H
#define PILA_H

#include "NodoPila.h"
#include <iostream>

class Pila {
private:
    pNodoPila cima; // Top of the stack

public:
    Pila(); // Constructor
    ~Pila(); // Destructor
    void apilar(Persona v);
    void desapilar();
    bool esVacia();
    Persona* mostrar(); // Muestra el proceso en la cima
    int longitud(); // Devuelve la longitud de la pila
};

#endif // PILA_H
