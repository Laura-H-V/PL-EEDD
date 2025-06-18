#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Box.h"

class NodoLista {
private:
    Box valor;
    NodoLista* siguiente; // Puntero al siguiente nodo
    NodoLista* anterior; // Puntero al nodo anterior
    friend class Lista; // La clase Lista puede acceder a los datos privados de NodoLista

public:
    NodoLista(); 
    NodoLista(Box p, NodoLista* sig = nullptr, NodoLista* ant = nullptr);
    Box& obtenerValor(); // Obtener el valor del nodo
    NodoLista* obtenerSiguiente();
    NodoLista* getSiguiente() const;
    NodoLista* getAnterior() const;
    ~NodoLista(); // Destructor
};

typedef NodoLista* pNodoLista; // Definimos un puntero a NodoLista para facilitar la lectura del código

#endif // NODOLISTA_H