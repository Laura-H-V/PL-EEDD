// main.cpp
#include <iostream>
#include "Box.h"
#include "Pasajero.h"
#include "Aeropuerto.h"

int main() {
    Aeropuerto airport;

    // Creamos dos boxes con algunos pasajeros en cola
    Box b1(1), b2(2);
    Pasajero p1(101,0,5,"Mexico",1),
             p2(102,0,7,"USA",2),
             p3(103,0,4,"Canada",1);

    b1.agregarPasajeroAEspera(p1);
    b1.agregarPasajeroAEspera(p2);
    b2.agregarPasajeroAEspera(p3);

    // Mostramos su estado
    std::cout << "Estado inicial:\n";
    b1.mostrarInfo();
    b2.mostrarInfo();

    // Los añadimos al aeropuerto y comprobamos
    airport.agregarBox(b1);
    airport.agregarBox(b2);

    int elegido = airport.obtenerBoxMenosOcupado();
    if (elegido >= 0) {
        std::cout << "==> El box elegido es ID " << elegido << "\n";
    } else {
        std::cout << "==> No hay boxes.\n";
    }
    return 0;
}
