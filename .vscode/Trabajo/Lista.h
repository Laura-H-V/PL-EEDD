#ifndef LISTA_H
#define LISTA_H

#include "NodoLista.h"
#include "Box.h"
#include "Pasajero.h"
#include <iostream>

class Lista {
private:
    Box valor;
    pNodoLista cabeza; // Puntero al primer nodo de la lista
    pNodoLista cola;   // Puntero al último nodo de la lista

public:

    Lista(); // Constructor
    ~Lista(); // Destructor
    void insertarInicio(Box v); // Inserta al inicio de la lista
    void insertarFinal(Box v); // Inserta al final de la lista
    void insertarEnPosicion(Box v, int pos); // Inserta en una posición específica
    void eliminar(Box v); // Elimina un nodo con un valor específico
    bool esVacia(); // Verifica si la lista está vacía
    Box* buscar(int id); // Busca un proceso en la lista y devuelve un puntero a él
    void mostrar(); // Muestra todos los elementos de la lista
    int longitud(); // Retorna la longitud de la lista
    Box inicio();
    Box fin();
    pNodoLista obtenerCabeza() const; 
    
};

#endif // LISTA_H