#include "Box.h"
#include <iostream>

using namespace std;

// Constructor por defecto
Box::Box() : IDBox(-1), pasajeroActual(), tiempoRestante(0) {}

// Constructor con ID específico
Box::Box(int id) : IDBox(id), pasajeroActual(), tiempoRestante(0) {}

// Métodos de acceso
int Box::getIDBox() const {
    return IDBox;
}

Pasajero Box::getPasajeroActual() const {
    return pasajeroActual;
}

int Box::getTiempoRestante() const {
    return tiempoRestante;
}

bool Box::colaEsperaVacia() const  {
    return colaEsperaBox.es_vacia();
}

Cola Box::getCopiaColaEsperaBox() {
    return colaEsperaBox;
}

Cola& Box::getColaEsperaBox() {
    return colaEsperaBox;
}

// Asigna un pasajero al box y establece su tiempo de control
void Box::asignarPasajero(const Pasajero& p) {
    if (!estaLibre()) {
        cout << "El box está ocupado. No se puede asignar otro pasajero." << endl;
        return;
    }
    pasajeroActual = p;
    tiempoRestante = p.getDuracionControl();    
    ocupado = true;
}

// Libera el box cuando el pasajero termina su proceso
void Box::liberarBox() {
    if (!estaLibre()) {
        cout << "Pasajero " << pasajeroActual.getID() << " ha salido del box " << IDBox << "." << endl;
        tiempoRestante = 0;
        ocupado = false;

        // Si hay pasajeros en espera, asignar el siguiente
        if (!colaEsperaVacia()) {
            Pasajero siguiente = obtenerPrimerPasajeroEnEspera();
            asignarPasajero(siguiente);
        }
    }
}

// Actualiza el tiempo restante de atención
void Box::actualizarTiempo(int minutos) {
    if (!estaLibre()) {
        tiempoRestante -= minutos;
        if (tiempoRestante <= 0) {
            liberarBox();
        }
    }
}

// Verifica si el box está libre
bool Box::estaLibre() const {
    return !ocupado;
}

// Agrega un pasajero a la cola de espera ordenado por prioridad
void Box::agregarPasajeroAEspera(Pasajero p) {
    colaEsperaBox.encolar(p, p.getPrioridad());
}

// Obtiene el primer pasajero en espera
Pasajero Box::obtenerPrimerPasajeroEnEspera() {
    if (!colaEsperaVacia()) {
        return colaEsperaBox.inicio();
    }
    return Pasajero(); // Retorna un pasajero vacío si la cola está vacía
}

// Muestra la información del box
void Box::mostrarInfo() const {
    cout << "Box ID: " << IDBox << endl;
    if (!estaLibre()) {
        cout << "Atendiendo a pasajero ID " << pasajeroActual.getID()
             << " - Tiempo restante: " << tiempoRestante << " minutos" << endl;
    } else {
        cout << "Box libre." << endl;
    }

    if (!colaEsperaVacia()) {
        cout << "Pasajeros en espera: " << colaEsperaBox.get_longitud() << endl;
    } else {
        cout << "No hay pasajeros en espera." << endl;
    }
}

// Destructor
Box::~Box() {
}
