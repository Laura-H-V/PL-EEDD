#include "Cola.h"
#include "Pila.h"
#include <iostream>

Cola::Cola()
{   primero = NULL; 
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola() { } //desencolar () cuando hay elementos

    void Cola::encolar(Persona elemento, int prioridad)
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

Persona Cola::desencolar()
{   if(!es_vacia()){ 
        Persona elemento = primero->elemento;
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
    return Persona();
}

Persona Cola::inicio(){ 
    if(!es_vacia()){ 
        return primero->elemento;
    }
    return Persona();
}

Persona Cola::fin(){ 
    if(!es_vacia())
    { return ultimo->elemento;
    }
    return Persona();
}

int Cola::get_longitud(){ 
    return longitud;
    }

bool Cola::es_vacia(){ 
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
            std::cout << aux->elemento.getPID()<<std::endl;
            aux = aux->siguiente;
        }
    }
}


