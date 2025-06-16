#include "Aeropuerto.h"
#include <iostream>

using namespace std;

Aeropuerto::Aeropuerto() {
    int minuto_actual = 0;
    int intervalo_llegadas = 2;
}

void Aeropuerto::crearPilaPasajeros() {
    cout << "\nCreando pila de pasajeros..." << endl;

    int cantidad;
    cout << "Ingrese la cantidad de pasajeros a agregar: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        int id, duracion, prioridad;
        string pais;

        cout << "\nPasajero " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Duración del control en minutos: ";
        cin >> duracion;
        cout << "País de destino: ";
        cin >> pais;
        cout << "Prioridad del país de destino (1-30): ";
        cin >> prioridad;

        // Crear pasajero y apilarlo en la Pila
        Pasajero nuevoPasajero(id, 0, duracion, pais, prioridad);
        pilaPasajeros.apilar(nuevoPasajero);
    }

    cout << "\nPila creada correctamente con " << cantidad << " pasajeros.\n";
}


void Aeropuerto::mostrarPilaPasajeros() {
    cout << "Mostrando pasajeros que llegarán al aeropuerto:" << endl;
    pilaPasajeros.mostrar();
}

void Aeropuerto::simularPasoTiempo(int N) {
    int intervalo_llegadas = 2; //Establecemos el tiempo que tarda en salir de la pila y añadirse al box
    cout << "Simulando el paso de " << N << " minutos..." << endl;
    std::cout << "Intervalo de llegada de pasajeros: cada " << intervalo_llegadas << " minutos.\n";
    // Implementar la lógica según la simulación en el enunciado.
    
}

void Aeropuerto::mostrarListaBoxes() {
    cout << "Lista de boxes en funcionamiento:" << endl;
    listaBoxes.mostrar();
}

int Aeropuerto::obtenerBoxMenosOcupado() {
    /*

    cout << "Buscando el box con menos pasajeros en espera..." << endl;
    if (listaBoxes.esVacia()) {
        std::cout << "No hay boxes en funcionamiento." << std::endl;
        return -1;
    }

    pNodoLista actual = listaBoxes.obtenerCabeza();
    Box* boxMenor = nullptr;
    int minEnEspera = INT_MAX;

    while (actual != nullptr) {
        Box& box = actual->obtenerValor(); // Obtener referencia al Box en el nodo
        int enEspera = box.getColaEsperaBox().get_longitud();

        if (enEspera < minEnEspera) {
            minEnEspera = enEspera;
            boxMenor = &box; // Apuntamos al box con menos espera
        }

        actual = actual->getSiguiente();
    }

    if (boxMenor != nullptr) {
        std::cout << "Box con menos pasajeros en espera: ID " << boxMenor->getIDBox()
                  << " con " << minEnEspera << " en espera." << std::endl;
        return  boxMenor->getIDBox();
    } else {
        std::cout << "No se pudo determinar el box con menos espera." << std::endl;
          return -1;
    }
*/
    Box min = listaBoxes.obtenerEnPosicion(0);
    for (int i = 0; i < listaBoxes.longitud() - 1; i++){

        min = listaBoxes.obtenerEnPosicion(i);

        if (GetLongitudColaBox(min) > GetLongitudColaBox(listaBoxes.obtenerEnPosicion(i + 1))){
            min = listaBoxes.obtenerEnPosicion(i + 1);
        }

    }
    return min.getIDBox();
}

int Aeropuerto::GetLongitudColaBox(Box box){
    Cola c = box.getColaEsperaBox();
    return c.get_longitud();
}

void Aeropuerto::buscarPasajeroEnBoxes(int id) {
    cout << "Buscando pasajero en boxes con ID " << id << "..." << endl;
    // Implementación para buscar en la lista de boxes.
    for (int i = 0; i < listaBoxes.longitud(); i++) {
        Box box = listaBoxes.obtenerEnPosicion(i);

        // 1. Revisar si el pasajero está siendo atendido
        Pasajero* actual = box.getPasajeroActual();
        if (actual != nullptr && actual->getID() == id) {
            cout << "Pasajero " << id << " está siendo atendido en el box " << box.getIDBox() << endl;
            cout << "Tiempo restante para salir: " << box.getTiempoRestante() << " minutos" << endl;
            cout << "Destino: " << actual->getPais() << endl;
            return;
        }

        // 2. Revisar la cola de espera
        Cola cola = box.getCopiaColaEsperaBox();
        bool encontrado = false;
        while (!cola.es_vacia()) {
            Pasajero p = cola.desencolar();
            if (p.getID() == id) {
                cout << "Pasajero " << id << " está esperando en el box " << box.getIDBox() << endl;
                cout << "Destino: " << p.getPais() << endl;
                encontrado = true;
                break;
            }
        }

        if (encontrado) return;
    }

    cout << "Pasajero " << id << " no se encuentra en ningún box." << endl;
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





