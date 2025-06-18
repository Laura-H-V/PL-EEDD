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
    void apilar(Pasajero v);
    void desapilar();
    bool esVacia();
    Pasajero* mostrar(); // Muestra el pasajero en la cima
    int longitud(); // Devuelve la longitud de la pila
    void mostrarTodos();
};

#endif // PILA_H
