#include "Cola.h"
#include "Pila.h"
#include <iostream>

Cola::Cola()
{   primero = NULL; 
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola() { while (!es_vacia()) {  //Cambiado!!!!!!!
        desencolar();
    } 
} //desencolar () cuando hay elementos

    void Cola::encolar(Pasajero elemento, int prioridad)
{   NodoCola *nuevo_nodo = new NodoCola(elemento, prioridad);
    if (es_vacia()) {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    } else if (prioridad < primero->prioridad) {
        // Si el nuevo nodo tiene mayor prioridad (menor valor numérico) que el primero, inserta al inicio
        nuevo_nodo->siguiente = primero;
        primero = nuevo_nodo;
    } else {
        // Insertar el nuevo nodo en la posición adecuada según su prioridad
        NodoCola *actual = primero;
        while (actual->siguiente != nullptr && actual->siguiente->prioridad <= prioridad) {
            actual = actual->siguiente;
        }
        // Insertar el nodo en la posición encontrada
        nuevo_nodo->siguiente = actual->siguiente;
        actual->siguiente = nuevo_nodo;

        // Si el nuevo nodo se convierte en el último, actualiza `ultimo`
        if (nuevo_nodo->siguiente == nullptr) {
            ultimo = nuevo_nodo;
        }
    }

    longitud++;
}

Pasajero Cola::desencolar()
{   if(!es_vacia()){ 
        Pasajero elemento = primero->elemento;
        NodoCola *aux = primero;
        if((primero == ultimo) && (primero->siguiente == NULL)){
             primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else
        {   primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
        longitud--;
        return elemento;
    }
    return Pasajero();
}

Pasajero Cola::inicio() const { 
    if (!es_vacia()) {
        return primero->elemento;
    }
    return Pasajero(); // Retorna un pasajero vacío si la cola está vacía
}

Pasajero Cola::fin() const{ 
    if(!es_vacia())
    { return ultimo->elemento;
    }
    return Pasajero();
}

int Cola::get_longitud() const { 
        // Devuelve la longitud de la cola
        // No es necesario recorrer la cola, ya que se mantiene un contador de longitud
    return longitud;
}

bool Cola::es_vacia() const{ 
    return ((primero == NULL) && (ultimo == NULL));
}

void Cola::mostrarCola()
//No es correcto, la cola solo puede verse mostrando el primero 
//y desencolando, se implementa para comprobar código facilmente.
{
    NodoCola *aux = primero;
    if (es_vacia()) {
        std::cout<<"Cola Vacía: "<<std::endl;
    }
    else {
        std::cout<<"Datos de la Cola: "<<std::endl;
        while (aux){
            std::cout << aux->elemento.getID()<<std::endl;
            aux = aux->siguiente;
        }
    }
}


