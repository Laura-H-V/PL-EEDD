#ifndef NODOABB_H
#define NODOABB_H
#include <iostream>
#include <stdio.h>


using namespace std;
class NodoABB
{
    friend class ABB;
    public:
        NodoABB(string nom, NodoABB *izq=NULL, NodoABB *der=NULL);
        virtual ~NodoABB();
        void verNombre();



    private:
        string nombre;
        NodoABB *hi, *hd;
};

#endif // NODOABB_H



