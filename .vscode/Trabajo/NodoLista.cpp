#include "NodoLista.h"

// Constructor por defecto
NodoLista::NodoLista() : valor(), siguiente(nullptr), anterior(nullptr) {}

// Constructor con parámetros
NodoLista::NodoLista(Box p, NodoLista* sig, NodoLista* ant) 
    : valor(p), siguiente(sig), anterior(ant) {}

Box& NodoLista::obtenerValor() {
    return valor;  // Devuelve una referencia al atributo valor
}
NodoLista* NodoLista::obtenerSiguiente() {
    return siguiente;  // Devuelve el puntero al siguiente nodo
}

NodoLista* NodoLista::getSiguiente() const {
    return siguiente;
}

NodoLista* NodoLista::getAnterior() const {
    return anterior;
}

// Destructor
NodoLista::~NodoLista() {
    siguiente = nullptr;
    anterior = nullptr;
}