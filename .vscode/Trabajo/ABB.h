#ifndef ABB_H
#define ABB_H
using namespace std;
#include "NodoABB.h"
#include "NodoABB.h"
#include "Pasajero.h"
#include "ListaPasajeros.h"


class ABB
{
    public:
        ABB();
        ABB(NodoABB *r);
        ABB(string nom, NodoABB *hIz=NULL, NodoABB *hDer=NULL);
        virtual ~ABB();
        void verInOrden();
        void verInOrden(NodoABB *arb);

        
        NodoABB* buscar(string pais);
        NodoABB* buscar(string pais, NodoABB* nodo);

        void mostrarPasajerosPorPais(string pais);
        void calcularTiempoMedioPorPais();
        void calcularTiempoMedioPorPais(NodoABB* nodo);
        void agregarPasajeroManual();

        Pasajero* buscarPasajero(int id);
        Pasajero* buscarPasajero(int id, NodoABB* nodo);


       // void verInOrdenABB();
        void insertar(string nom);
        void insertar(string nom, NodoABB *nodo);


    protected:

    private:
        NodoABB *raiz;
};

#endif // ABB_H

