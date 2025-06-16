#include "ListaPasajeros.h"
#include <iostream>
#include "Pasajero.h"
#include "ABB.h"
using namespace std;

// Constructor
ListaPasajeros::ListaPasajeros(int capacidadInicial) : capacidad(capacidadInicial), cantidad(0) {
    listaPasajeros = new Pasajero[capacidad]; // Reservar memoria dinámica
}

// Destructor
ListaPasajeros::~ListaPasajeros() {
    delete[] listaPasajeros; // Liberar memoria al destruir el objeto
}

// Redimensionar el arreglo dinámico cuando sea necesario
void ListaPasajeros::redimensionar(int nuevaCapacidad) {
    Pasajero* nuevaLista = new Pasajero[nuevaCapacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevaLista[i] = listaPasajeros[i]; // Copiar elementos
    }
    delete[] listaPasajeros; // Liberar memoria antigua
    listaPasajeros = nuevaLista;
    capacidad = nuevaCapacidad;
}

// Insertar pasajero en la lista
void ListaPasajeros::insertarPasajero(const Pasajero& p) {
    if (cantidad == capacidad) {
        redimensionar(capacidad * 2); // Expandir si está llena
    }
    listaPasajeros[cantidad] = p;
    cantidad++;
    agregarAlABB(p);
}

// Eliminar pasajero por ID
void ListaPasajeros::eliminarPasajero(int id) {
    int indice = -1;
    for (int i = 0; i < cantidad; i++) {
        if (listaPasajeros[i].getID() == id) {
            indice = i;
            break;
        }
    }
    if (indice == -1) return;

    // Mover elementos para compactar la lista
    for (int i = indice; i < cantidad - 1; i++) {
        listaPasajeros[i] = listaPasajeros[i + 1];
    }
    cantidad--;

    // Reducir tamaño si es necesario
    if (cantidad < capacidad / 2) {
        redimensionar(capacidad / 2);
    }
}

// Buscar pasajero por ID
Pasajero* ListaPasajeros::buscarPasajero(int id) {
    for (int i = 0; i < cantidad; i++) {
        if (listaPasajeros[i].getID() == id) {
            return &listaPasajeros[i];
        }
    }
    return nullptr;
}

// Verificar si la lista está vacía
bool ListaPasajeros::esVacia() const {
    return cantidad == 0;
}

// Contar pasajeros almacenados
int ListaPasajeros::contarPasajeros() const {
    return cantidad;
}

// Agregar pasajero al ABB por país de destino
void ListaPasajeros::agregarAlABB(const Pasajero& p) {
    arbolDestinos.insertar(p.getPais());
}

// Mostrar pasajeros con destino a un país específico
void ListaPasajeros::mostrarPorPais(const string& pais) {
    cout << "Pasajeros con destino a " << pais << ":" << endl;
    // Recorrer ABB para mostrar pasajeros según país
}

// Calcular tiempo medio de estancia por país
void ListaPasajeros::calcularTiempoMedioPorPais() {
    // Recorrer ABB en preorden y calcular promedio
}

// Mostrar todos los pasajeros de la lista
void ListaPasajeros::mostrarLista() {
    for (int i = 0; i < cantidad; i++) {
        cout << "ID: " << listaPasajeros[i].getID() << ", Destino: " << listaPasajeros[i].getPais() << endl;
    }
}

Pasajero* ListaPasajeros::buscarPasajeroPorIndice(int index) {
    if (index < 0 || index >= cantidad) {
        return nullptr; // Verifica que el índice sea válido
    }
    return &listaPasajeros[index]; // Retorna la dirección del pasajero en la posición deseada
}

Pasajero* ListaPasajeros::buscarPasajeroPorID(int id) {
    for (int i = 0; i < contarPasajeros(); i++) {
        if (listaPasajeros[i].getID() == id) {
            return &listaPasajeros[i];
        }
    }
    return nullptr; // Si no se encuentra el pasajero, retorna nullptr.
}

