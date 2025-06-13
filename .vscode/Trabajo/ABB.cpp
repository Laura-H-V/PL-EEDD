#include "ABB.h"
#include "NodoABB.h"
#include "Pasajero.h"
#include "ListaPasajeros.h"


ABB::ABB() //crea arbol vacio
{
    //ctor
    raiz=NULL;
}
ABB::ABB(NodoABB *r)
{
    raiz=r;

}
ABB::ABB(string nom, NodoABB *hIz, NodoABB *hDer)//constructor que crea �rbolBin con dato y dos sub�rboles
{
    raiz= new NodoABB(nom, hIz, hDer);//llamamos al constructor del Nodo y raiz es un puntero al Nodo creado

}

ABB::~ABB()
{
    //dtor
}


void ABB::verInOrden() { verInOrden(raiz);}
void ABB::verInOrden(NodoABB *arb)// M�todo para ver Arbol empezando por su izquirda, despu�s pasamos por la raiz y por ultimo por la rama derecha
{
    if (arb) {
       verInOrden(arb->hi);//Recursion para la rama izquierda
       cout<< arb->nombre<<endl;//Mostrar nombre
        verInOrden(arb->hd);// Recursion para la rama derecha
    }
}
/*void ABB::verInOrdenABB()// M�todo para ver Arbol en inorden sin tener que pasar puntero, resulta farragoso crear objetos cada vez...
{
    if (raiz) {
            ABB hijoIz(raiz->hi);hijoIz.verInOrden();//Recursion para la rama izquierda
        raiz->cliente.verDatos();//Mostrar datos del cliente
        ABB hijoDer(raiz->hd);hijoDer.verInOrden();// Recursion para la rama derecha
    }
}*/


void ABB::insertar(string nombre)
{
    insertar(nombre, raiz);
}
void ABB::insertar(string nombre, NodoABB *nodo)//En este m�todo insertamos un nombre en el ABB para que siga ordenado
{


    if ((nodo->nombre>nombre) || (nodo->nombre ==nombre))
        //((nombre.compare(nodo->nombre)==0) ||  (nombre.compare(nodo->nombre)<0)) usando funcion de string


         { //Si el nombre del cliente es menor o igual al del nodo  ra�z entoces comprobamos...


        if (nodo->hi == NULL)//Si el nodo izquierdo est� vacio entoces
        {
            //creo un objeto NodoABB para insertarlo en el ABB
        NodoABB *nuevo=new NodoABB(nombre);
        nodo->hi= nuevo;
        }
            //Creamos un nuevo nodo e incluimos el cliente y el pedido en la lista (se crea vsc�a)

        else//En caso de que el nodo no estuviera vacio
        {
            insertar(nombre, nodo->hi);//insertamos al pasajero en el nodo izquierdo
        }
    }
    else// Si el nombre es > que el nodo
    {
        cout<<"es menor "<<nodo->nombre<<"que  "<< nombre<<endl;
        if (nodo->hd == NULL)//Comprobamos si el derecho no existe
        {

            //creo un objeto NodoABB para insertarlo en el ABB
        NodoABB *nuevo=new NodoABB(nombre);
            nodo->hd=nuevo;
            }// Creamos un nuevo nodo en la rama derecha

        else//si existe
        {
            insertar(nombre, nodo->hd);// insertamos el pasajero al nodo derecho
        }
    }
}


NodoABB* ABB::buscar(string pais) {
    return buscar(pais, raiz);
}

NodoABB* ABB::buscar(string pais, NodoABB* nodo) {
    if (nodo == nullptr || nodo->nombre == pais) {
        return nodo; // Si el nodo es nulo o encontramos el país, lo devolvemos
    }
    if (pais < nodo->nombre) {
        return buscar(pais, nodo->hi);
    }
    return buscar(pais, nodo->hd);
}

void ABB::mostrarPasajerosPorPais(string pais) {
    NodoABB* nodoDestino = buscar(pais); // Buscamos el nodo del país en el ABB
    if (nodoDestino == nullptr) {
        cout << "No hay pasajeros con destino a " << pais << "." << endl;
        return;
    }

    cout << "Pasajeros con destino a " << pais << ":" << endl;
    nodoDestino->listaPasajerosDestino.mostrarLista(); // Mostrar la lista de pasajeros del nodo
}




void ABB::calcularTiempoMedioPorPais() {
    calcularTiempoMedioPorPais(raiz);
}

void ABB::calcularTiempoMedioPorPais(NodoABB* nodo) {
    if (nodo == nullptr) {
        return;
    }

    // Obtener la lista de pasajeros del país
    ListaPasajeros& lista = nodo->listaPasajerosDestino;
    int totalTiempo = 0;
    int cantidadPasajeros = lista.contarPasajeros();

    if (cantidadPasajeros > 0) {
        for (int i = 0; i < cantidadPasajeros; i++) {
            totalTiempo += lista.buscarPasajeroPorIndice(i)->calcularTiempoEstancia();
        }
        double tiempoMedio = static_cast<double>(totalTiempo) / cantidadPasajeros;
        cout << "País: " << nodo->nombre << " | Tiempo medio de estancia: " << tiempoMedio << " minutos" << endl;
    }

    // Recorrer en preorden: primero izquierda, luego derecha
    calcularTiempoMedioPorPais(nodo->hi);
    calcularTiempoMedioPorPais(nodo->hd);
}

Pasajero* ABB::buscarPasajero(int id) {
    return buscarPasajero(id, raiz);
}

Pasajero* ABB::buscarPasajero(int id, NodoABB* nodo) {
    if (nodo == nullptr) {
        return nullptr; // Si el nodo es nulo, el pasajero no está en el árbol.
    }

    // Buscar en la lista de pasajeros de este nodo
    Pasajero* encontrado = nodo->listaPasajerosDestino.buscarPasajeroPorID(id);
    if (encontrado != nullptr) {
        cout << "Pasajero encontrado: ID " << encontrado->getID()
             << ", País: " << nodo->nombre
             << ", Tiempo de estancia: " << encontrado->calcularTiempoEstancia() << " minutos." << endl;
        return encontrado;
    }

    // Recorrer el árbol en búsqueda del pasajero en otros nodos
    Pasajero* izq = buscarPasajero(id, nodo->hi);
    if (izq != nullptr) return izq;

    return buscarPasajero(id, nodo->hd);
}








