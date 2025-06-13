#ifndef NODOABB_H
#define NODOABB_H
#include <iostream>
#include <stdio.h>
//#include "ListaPasajeros.h"


using namespace std;
class NodoABB
{
    friend class ABB;
    public:
        NodoABB(string nom, NodoABB *izq=NULL, NodoABB *der=NULL);
        virtual ~NodoABB();
        void verNombre();
        void agregarPasajero(const Pasajero& p);


    private:
        string nombre;
        ListaPasajeros listaPasajerosDestino; // lista de pasajeros con este destino
        NodoABB *hi, *hd;
};

#endif // NODOABB_H



