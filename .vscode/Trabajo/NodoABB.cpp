#include "NodoABB.h"

NodoABB::NodoABB(string nom, NodoABB *izq, NodoABB *der)
// : nombre(nom), hi(izq), hd(der), listaPasajerosDestino(10)
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
