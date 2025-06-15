#include "Aeropuerto.h"
#include <iostream>

using namespace std;

Aeropuerto::Aeropuerto() {}

void Aeropuerto::crearPilaPasajeros() {
    cout << "Creando pila de pasajeros..." << endl;
    // Se agregan pasajeros manualmente aquí, respetando el formato del enunciado.
}

void Aeropuerto::mostrarPilaPasajeros() {
    cout << "Mostrando pasajeros que llegarán al aeropuerto:" << endl;
    pilaPasajeros.mostrar();
}

void Aeropuerto::simularPasoTiempo(int N) {
    cout << "Simulando el paso de " << N << " minutos..." << endl;
    // Implementar la lógica según la simulación en el enunciado.
}

void Aeropuerto::mostrarListaBoxes() {
    cout << "Lista de boxes en funcionamiento:" << endl;
    listaBoxes.mostrar();
}

int Aeropuerto::obtenerBoxMenosOcupado() {
    // Implementación para encontrar el box con menos pasajeros en espera.
    cout << "Buscando el box con menos pasajeros en espera..." << endl;
    return 0; // Retorna el ID del box con menos ocupación.
}

void Aeropuerto::buscarPasajeroEnBoxes(int id) {
    cout << "Buscando pasajero en boxes con ID " << id << "..." << endl;
    // Implementación para buscar en la lista de boxes.
}

void Aeropuerto::simularControlCompleto() {
    cout << "Simulando el control hasta que no haya pasajeros pendientes..." << endl;
    // Implementación para procesar todos los pasajeros del sistema.
}

void Aeropuerto::agregarPasajeroABB() {
    abbPasajeros.agregarPasajeroManual();
}

void Aeropuerto::mostrarABBOrdenado() {
    cout << "Mostrando datos del ABB ordenados por país..." << endl;
    abbPasajeros.verInOrden();
}

void Aeropuerto::mostrarPasajerosPorPais(string pais) {
    abbPasajeros.mostrarPasajerosPorPais(pais);
}

void Aeropuerto::buscarPasajeroABB(int id) {
    abbPasajeros.buscarPasajero(id);
}

void Aeropuerto::calcularTiempoMedioPorPais() {
    abbPasajeros.calcularTiempoMedioPorPais();
}

void Aeropuerto::mostrarMenu() {
    int opcion = 0;
    while (opcion != 13) {
        cout << "\n===== MENÚ DEL AEROPUERTO =====" << endl;
        cout << "1. Crear pila de pasajeros" << endl;
        cout << "2. Mostrar pasajeros en pila" << endl;
        cout << "3. Simular paso del tiempo" << endl;
        cout << "4. Mostrar lista de boxes" << endl;
        cout << "5. Mostrar box con menos pasajeros en espera" << endl;
        cout << "6. Buscar pasajero en boxes" << endl;
        cout << "7. Simular todo el control de aduanas" << endl;
        cout << "8. Añadir pasajero al ABB manualmente" << endl;
        cout << "9. Mostrar ABB ordenado" << endl;
        cout << "10. Mostrar pasajeros por país" << endl;
        cout << "11. Buscar pasajero en ABB" << endl;
        cout << "12. Calcular tiempo medio por país" << endl;
        cout << "13. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearPilaPasajeros();
                break;
            case 2:
                mostrarPilaPasajeros();
                break;
            case 3: {
                int N;
                cout << "Ingrese N minutos a simular: ";
                cin >> N;
                simularPasoTiempo(N);
                break;
            }
            case 4:
                mostrarListaBoxes();
                break;
            case 5:
                obtenerBoxMenosOcupado();
                break;
            case 6: {
                int id;
                cout << "Ingrese ID del pasajero: ";
                cin >> id;
                buscarPasajeroEnBoxes(id);
                break;
            }
            case 7:
                simularControlCompleto();
                break;
            case 8:
                agregarPasajeroABB();
                break;
            case 9:
                mostrarABBOrdenado();
                break;
            case 10: {
                string pais;
                cout << "Ingrese el país: ";
                cin >> pais;
                mostrarPasajerosPorPais(pais);
                break;
            }
            case 11: {
                int id;
                cout << "Ingrese ID del pasajero: ";
                cin >> id;
                buscarPasajeroABB(id);
                break;
            }
            case 12:
                calcularTiempoMedioPorPais();
                break;
            case 13:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
}
