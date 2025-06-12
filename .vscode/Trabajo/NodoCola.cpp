#include "NodoCola.h"

NodoCola::NodoCola(){
    prioridad = 0;
    elemento = Persona();
    siguiente = NULL;
    //constructor por defecto
    }
    NodoCola::NodoCola(Persona e, int prioridad, NodoCola*sig )
    {
    elemento = e;
    siguiente = sig;
    this->prioridad = prioridad;
    }
    NodoCola::~NodoCola(){
    //Nothing to do here (destructor)
}