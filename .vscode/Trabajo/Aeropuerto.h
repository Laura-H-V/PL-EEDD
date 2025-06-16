#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include "ABB.h"
#include "Pila.h"
#include "Lista.h"

class Aeropuerto {
public:
    Aeropuerto(); // Constructor

    void mostrarMenu(); // Menú principal

    void crearPilaPasajeros(); // Opción 1: Crear la pila de pasajeros
    void mostrarPilaPasajeros(); // Opción 2: Mostrar la pila de pasajeros
    void simularPasoTiempo(int N); // Opción 3: Simular N minutos
    void mostrarListaBoxes(); // Opción 4: Mostrar lista de boxes
    int obtenerBoxMenosOcupado(); // Opción 5: Mostrar box con menos pasajeros en espera
    void buscarPasajeroEnBoxes(int id); // Opción 6: Buscar pasajero en lista de boxes
    void simularControlCompleto(); // Opción 7: Simular todo el control hasta que no haya pasajeros pendientes
    void agregarPasajeroABB(); // Opción 8: Añadir pasajero al ABB manualmente
    void mostrarABBOrdenado(); // Opción 9: Mostrar ABB ordenado por país
    void mostrarPasajerosPorPais(string pais); // Opción 10: Mostrar pasajeros por país
    void buscarPasajeroABB(int id); // Opción 11: Buscar pasajero en el ABB
    void calcularTiempoMedioPorPais(); // Opción 12: Calcular tiempo medio por país

private:
    ABB abbPasajeros; // ABB para pasajeros almacenados
    Pila pilaPasajeros; // Pila de pasajeros que llegan al aeropuerto
    Lista listaBoxes; // Lista de boxes en funcionamiento
};

#endif // AEROPUERTO_H
