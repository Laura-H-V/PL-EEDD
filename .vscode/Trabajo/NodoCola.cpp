#include "NodoCola.h"

NodoCola::NodoCola(){
    prioridad = 0;
    elemento = Pasajero();
    siguiente = NULL;
    //constructor por defecto
    }
    NodoCola::NodoCola(Pasajero e, int prioridad, NodoCola*sig )
    {
    elemento = e;
    siguiente = sig;
    this->prioridad = prioridad;
    }
    NodoCola::~NodoCola(){
    //Nothing to do here (destructor)
}