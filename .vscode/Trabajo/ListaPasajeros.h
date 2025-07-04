#ifndef LISTAPASAJEROS_H
#define LISTAPASAJEROS_H
#include <string>
#include "Pasajero.h"  

class ListaPasajeros {
private:
    Pasajero* listaPasajeros; // Arreglo dinámico de pasajeros
    int capacidad;  // Capacidad actual del arreglo
    int cantidad;   // Número de pasajeros almacenados

    void redimensionar(int nuevaCapacidad); // Expande o reduce el tamaño del arreglo

public:
    // Constructor y destructor
    ListaPasajeros(int capacidadInicial = 10);
    ~ListaPasajeros();

    // Métodos de gestión
    void insertarPasajero(const Pasajero& p);
    void eliminarPasajero(int id);
    Pasajero* buscarPasajeroPorID(int id);
    Pasajero* buscarPasajeroPorIndice(int index);
    bool esVacia() const;
    int contarPasajeros() const;

    // Métodos auxiliares
    void mostrarLista();
};

#endif // LISTAPASAJEROS_H
