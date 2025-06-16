    #include <iostream>
    #include "Box.h"
    #include "Pasajero.h"

    int main() {
        // Crear boxes
        Box box1(1);
        Box box2(2);

        // Crear pasajeros
        Pasajero p1(101, 10, 5, "Mexico", 1);
        Pasajero p2(102, 12, 3, "USA", 2);
        Pasajero p3(103, 15, 4, "Canada", 1);

        // Agregar pasajeros a la cola de espera de box1
        box1.agregarPasajeroAEspera(p1);
        box1.agregarPasajeroAEspera(p2);

        // Agregar pasajero a la cola de espera de box2
        box2.agregarPasajeroAEspera(p3);

        // Mostrar estado inicial
        box1.mostrarInfo();
        box2.mostrarInfo();

        
        // Asignar pasajeros del inicio de la cola a boxes (si están libres)
        if (box1.estaLibre() && !box1.colaEsperaVacia()) {
            Pasajero siguiente = box1.obtenerPrimerPasajeroEnEspera();
            box1.asignarPasajero(&siguiente);
            // Remover de cola (necesitarías un método para desencolar o similar)
        }

        if (box2.estaLibre() && !box2.colaEsperaVacia()) {
            Pasajero siguiente = box2.obtenerPrimerPasajeroEnEspera();
            box2.asignarPasajero(&siguiente);
        }

        // Mostrar estado después de asignar pasajeros
        std::cout << "\nDespués de asignar pasajeros:\n";
        box1.mostrarInfo();
        box2.mostrarInfo();

        // Simular paso de tiempo
        box1.actualizarTiempo(3);
        box2.actualizarTiempo(3);

        std::cout << "\nDespués de actualizar tiempo 3 minutos:\n";
        box1.mostrarInfo();
        box2.mostrarInfo();

        // Actualizar tiempo para terminar la atención
        box1.actualizarTiempo(3);
        box2.actualizarTiempo(3);

        std::cout << "\nDespués de actualizar tiempo otros 3 minutos:\n";
        box1.mostrarInfo();
        box2.mostrarInfo();

        return 0;
    }
