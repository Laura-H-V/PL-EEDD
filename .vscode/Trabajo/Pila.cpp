#include "Pila.h"

Pila::Pila() : cima(nullptr) {}

Pila::~Pila() {
    while (!esVacia()) {
        desapilar();
    }
}

void Pila::apilar(Pasajero v) {
    pNodoPila nuevo = new NodoPila(v, nullptr);

    if (esVacia() || cima->valor.getMinLlegada() >= v.getMinLlegada()) {
        nuevo->siguiente = cima;
        cima = nuevo;
    } else {
        pNodoPila actual = cima;
        while (actual->siguiente != nullptr && actual->siguiente->valor.getMinLlegada() < v.getMinLlegada()) {
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }

}

void Pila::desapilar() {
    if (cima != nullptr) {
        pNodoPila aux = cima;
        cima = cima->siguiente;
        delete aux;
    }
    return;
}



bool Pila::esVacia() {
    return cima == nullptr;
}

Pasajero* Pila::mostrar() {
    if (esVacia()) {
        std::cout << "La pila está vacía." << std::endl;
        return nullptr; // Retornar nullptr si la pila está vacía
    } else {
        return &cima->valor; // Retornar un puntero al proceso en la cima
    }
}

int Pila::longitud() {
    int contador = 0;
    pNodoPila aux = cima;
    while (aux != nullptr) {
        contador++;
        aux = aux->siguiente;
    }
    return contador;
}
