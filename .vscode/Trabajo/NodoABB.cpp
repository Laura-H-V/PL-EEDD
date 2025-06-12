#include "NodoABB.h"

NodoABB::NodoABB(string nom, NodoABB *izq, NodoABB *der)
{
    //ctor
    nombre=nom;
    hi=izq;
    hd=der;

}

NodoABB::~NodoABB()
{
    //dtor
}

void NodoABB::verNombre(){cout<<nombre<<endl;}
