#include "Aeropuerto.h"
#include <iostream>

using namespace std;

Aeropuerto::Aeropuerto() : minuto_actual(0), intervalo_llegadas(2) {}

//Crea la pila de pasajeros 
void Aeropuerto::crearPilaPasajeros() {
    cout << "\nCreando pila de pasajeros..." << endl;
    //Pasajero(ID, minLlegada, duracionControl, pais, prioridad) 
    Pasajero p1(1, 0, 10, "Indonesia", 6);
    Pasajero p2(2, 0, 15, "Portugal", 1);
    Pasajero p3(3, 5, 29, "Australia", 7);
    Pasajero p4(4, 7, 8, "Sudafrica", 5);
    Pasajero p5(5, 9, 16, "Indonesia", 7);
    Pasajero p6(6, 9, 13, "Noruega", 6);
    Pasajero p7(7, 10, 10, "Australia", 6);
    Pasajero p8(8, 10, 15, "Italia", 1);
    Pasajero p9(9, 15, 29, "Alemania", 7);
    Pasajero p10(10, 17, 8,"Australia", 5);
    Pasajero p11(11, 19, 16, "Italia", 7);
    Pasajero p12(12, 19, 13, "Alemania", 6);

    Pasajero p13(13, 20, 12, "Francia", 4);
    Pasajero p14(14, 22, 18, "Indonesia", 5);
    Pasajero p15(15, 25, 22, "Portugal", 8);
    Pasajero p16(16, 27, 11, "Australia", 2);
    Pasajero p17(17, 30, 19, "Sudafrica", 3);
    Pasajero p18(18, 32, 14, "Noruega", 6);
    Pasajero p19(19, 35, 20, "Alemania", 7);
    Pasajero p20(20, 37, 25, "Italia", 9);

    // Apilar todos los pasajeros
    pilaPasajeros.apilar(p1);
    pilaPasajeros.apilar(p2);
    pilaPasajeros.apilar(p3);
    pilaPasajeros.apilar(p4);
    pilaPasajeros.apilar(p5);
    pilaPasajeros.apilar(p6);
    pilaPasajeros.apilar(p7);
    pilaPasajeros.apilar(p8);
    pilaPasajeros.apilar(p9);
    pilaPasajeros.apilar(p10);
    pilaPasajeros.apilar(p11);
    pilaPasajeros.apilar(p12);
    pilaPasajeros.apilar(p13);
    pilaPasajeros.apilar(p14);
    pilaPasajeros.apilar(p15);
    pilaPasajeros.apilar(p16);
    pilaPasajeros.apilar(p17);
    pilaPasajeros.apilar(p18);
    pilaPasajeros.apilar(p19);
    pilaPasajeros.apilar(p20);

    //creamos un box si no hay ninguno 
    if (listaBoxes.longitud() == 0) {
        crearBox();
    }
}

//Muestra los pasajeros de la pila
void Aeropuerto::mostrarPilaPasajeros() {
    cout << "Mostrando pasajeros que llegarán al aeropuerto:" << endl;
    pilaPasajeros.mostrarTodos();
}

//Dimula el paso de n minutos en el sistema
void Aeropuerto::simularPasoTiempo(int minutos) {
    for (int i = 0; i < minutos; i++) {
        minuto_actual++;
        // Paso del tiempo de los pasajeros en los boxes
        for (int j = 0; j < listaBoxes.longitud(); j++) {
            Box& box = listaBoxes.obtenerEnPosicion(j);
            avanzarTiempoPasajerosBox(box);
        }

        avanzarTiempoPila();
        
    }

    borrarBoxesLibres();
    crearBox();

    // Si la pila está vacía y no quedan pasajeros en boxes
    if (pilaPasajeros.esVacia() && todosBoxesLibres()) {
        cout << "\nTodos los pasajeros han sido atendidos.\n";
        cout << "\nTiempo medio de espera: "<< getTiempoTotalPasajeros() / getNumeroPasajeros() << " minutos.\n";
    }
}

//Devuelve el tiempo total de todos los pasajeros
int Aeropuerto::getTiempoTotalPasajeros() {
    int tiempoTotal = 0;

    // Recorrer todos los boxes para sumar los tiempos de pasajeros atendidos
    for (int i = 0; i < listaBoxes.longitud(); i++) {
        Box box = listaBoxes.obtenerEnPosicion(i);

        if (!box.estaLibre()) {  
            Pasajero pasajero = box.getPasajeroActual();

            // Solo sumamos si el pasajero ya terminó el control
            if ( pasajero.getTiempoTotal() > 0) {
                tiempoTotal +=  pasajero.calcularTiempoEstancia();
            }
        }
    }

    return tiempoTotal;
}

//Numero de pasajeros que hay atendidos
int Aeropuerto::getNumeroPasajeros() {
    int totalPasajeros = 0;

    // Recorrer todos los boxes y contar solo los pasajeros atendidos
    for (int i = 0; i < listaBoxes.longitud(); i++) {
        Box box = listaBoxes.obtenerEnPosicion(i);

        if (!box.estaLibre()) {  
            Pasajero pasajero = box.getPasajeroActual();

            // Contar solo pasajeros que ya terminaron el control
            if ( pasajero.getTiempoTotal() > 0) {
                totalPasajeros++;
            }
        }
    }

    return totalPasajeros;
}


//Avanza el timepo de la simulacion manejando los boxes y los pasajeros en ellos
void Aeropuerto::avanzarTiempoPasajerosBox(Box& box) {
    if (box.estaLibre()) return;

    int tiempoRestante = box.getTiempoRestante();
    box.actualizarTiempo(tiempoRestante);
    
    if (box.getTiempoRestante() <= 0) {
        //actualizarTiempo ya libera el box
        mostrarSalida(box.getPasajeroActual(), box);
    }  
}

//Se encarga de manejar a los pasjeros de la pila en la simulacion del tiempo
void Aeropuerto::avanzarTiempoPila() {
    while (!pilaPasajeros.esVacia() && pilaPasajeros.mostrar()->getMinLlegada() <= minuto_actual) {
        Pasajero proximoPasajero = *pilaPasajeros.mostrar();

        bool atendido = false;

        for (int j = 0; j < listaBoxes.longitud(); j++) {
            Box& box = listaBoxes.obtenerEnPosicion(j);

            if (box.estaLibre() && box.getColaEsperaBox().get_longitud() <= 2) {
                if (box.colaEsperaVacia() || box.getColaEsperaBox().inicio().getPrioridad() < proximoPasajero.getPrioridad()) {
                    box.asignarPasajero(box.getColaEsperaBox().inicio());
                    mostrarEntrada(proximoPasajero, box);
                    atendido = true;
                    pilaPasajeros.desapilar();
                }
            } else {
                if (!box.getColaEsperaBox().es_vacia()) {
                    Pasajero siguiente = box.getColaEsperaBox().inicio();
                    box.asignarPasajero(siguiente);
                    box.getColaEsperaBox().desencolar();
                    mostrarEntrada(siguiente, box);
                }

            }
        }

        if (!atendido) {
            insertarEnCola(proximoPasajero);
            pilaPasajeros.desapilar();
            crearBox();
        }
    }
}

void Aeropuerto::mostrarEntrada(Pasajero p, Box b){
     cout << "\nEntra el pasajero " << p.getID() << " en el box "<< b.getIDBox() << " y en el minuto  "<<
     minuto_actual << endl;
}

void Aeropuerto::mostrarSalida(Pasajero p, Box b){
    cout << "\nSale el pasajero " << p.getID() << " en el box "<< b.getIDBox() << " y en el minuto  "<<
     minuto_actual << endl;
}

void Aeropuerto::borrarBoxesLibres() {
    for (int i = listaBoxes.longitud() - 1; i >= 0; i--) {
        Box box = listaBoxes.obtenerEnPosicion(i);

        if (box.estaLibre() && box.getColaEsperaBox().get_longitud() == 0 &&
            listaBoxes.longitud() > 1 && pilaPasajeros.esVacia()) {
            
            cout << "\nEl Box de asistencia número " << box.getIDBox() << " ha sido eliminado.\n";
            listaBoxes.eliminar(box);
        }
    }
}

int Aeropuerto::insertarEnCola(Pasajero p) {
    bool todasLasColasConDosPasajeros = true;

    // Revisar si todas las colas tienen al menos 2 pasajeros
    for (int i = 0; i < listaBoxes.longitud(); i++) {
        if (listaBoxes.obtenerEnPosicion(i).getColaEsperaBox().get_longitud() < 2) {
            todasLasColasConDosPasajeros = false;
        }
    }

    crearBox(); // Si todas están llenas, crear un nuevo box

    // Buscar el box con la cola más corta
    int pos = 0;
    int minCola = listaBoxes.obtenerEnPosicion(0).getColaEsperaBox().get_longitud();

    for (int i = 1; i < listaBoxes.longitud(); i++) {
        int longitudCola = listaBoxes.obtenerEnPosicion(i).getColaEsperaBox().get_longitud();
        if (longitudCola < minCola) {
            minCola = longitudCola;
            pos = i;
        }
    }

    // Insertar pasajero en la cola del box seleccionado
    Box& box = listaBoxes.obtenerEnPosicion(pos);
    box.agregarPasajeroAEspera(p);

    cout << "\nPasajero con ID " << p.getID() << " ha entrado en la cola de espera del Box " 
         << box.getIDBox() << " en el minuto " << minuto_actual << "\n";

    return box.getIDBox();
}


//Muestra los boxes que hay
void Aeropuerto::mostrarListaBoxes() {
    cout << "Lista de boxes en funcionamiento:" << endl;
    listaBoxes.mostrar();
}

//Devuelve el id del box con menos pasajeros esperando
int Aeropuerto::obtenerBoxMenosOcupado() {

    if (listaBoxes.longitud() == 0) {
            cout << "No hay boxes en funcionamiento actualmente.\n";
            return -1;
        }
    Box min = listaBoxes.obtenerEnPosicion(0);

    for (int i = 1; i < listaBoxes.longitud(); i++) {
        Box actual = listaBoxes.obtenerEnPosicion(i);

        if (GetLongitudColaBox(actual) < GetLongitudColaBox(min)) {
            min = actual;
        }
    }
    return min.getIDBox();
}

int Aeropuerto::GetLongitudColaBox(Box box){
    Cola c = box.getColaEsperaBox();
    return c.get_longitud();
}

void Aeropuerto::crearBox(){
    bool llenos = true;
    for(int i=0; i < listaBoxes.longitud(); i++ ){
        if(listaBoxes.obtenerEnPosicion(i).getColaEsperaBox().get_longitud() < 2){
            llenos = false;
        }
    }
    if (llenos) {
    std::cout << "Box número " << listaBoxes.longitud() + 1 << " creado. " << std::endl;
    listaBoxes.insertarFinal(Box(listaBoxes.longitud() + 1));
}

}

//Busca un pasajero en la lista de boxes por su id
void Aeropuerto::buscarPasajeroEnBoxes(int id) {
    cout << "Buscando pasajero en boxes con ID " << id << "..." << endl;
    // Implementación para buscar en la lista de boxes.
    for (int i = 0; i < listaBoxes.longitud(); i++) {
        Box box = listaBoxes.obtenerEnPosicion(i);

        // 1. Revisar si el pasajero está siendo atendido
        Pasajero actual = box.getPasajeroActual();
        if ( actual.getID() == id) {
            cout << "Pasajero " << id << " está siendo atendido en el box " << box.getIDBox() << endl;
            cout << "Tiempo restante para salir: " << box.getTiempoRestante() << " minutos" << endl;
            cout << "Destino: " << actual.getPais() << endl;
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

//Simula todos los minutos del aeropuerto
void Aeropuerto::simularCompleto() {
    while (!pilaPasajeros.esVacia() || !todosBoxesLibres()){
        simularPasoTiempo(1);
        cout << "[DEBUG] Fin minuto " << minuto_actual << ": " 
     << "pila vacía=" << pilaPasajeros.esVacia() 
     << ", todos boxes libres=" << todosBoxesLibres() << endl;
    }
        if (pilaPasajeros.esVacia() && todosBoxesLibres()) {
        cout << "\nTodos los pasajeros han sido atendidos.\n";
        cout << "\nTiempo medio de espera: " << getTiempoTotalPasajeros() / getNumeroPasajeros() << " minutos.\n";
    }
}

//Mira si estan todos libres
bool Aeropuerto::todosBoxesLibres() {
    for (int i = 0; i < listaBoxes.longitud(); i++) {
        Box box = listaBoxes.obtenerEnPosicion(i);
        
        if (!box.estaLibre() || box.getColaEsperaBox().get_longitud() > 0) {
            return false; // Al menos un box tiene pasajeros dentro o en espera
        }
    }

    return true; // Todos los boxes están vacíos
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
        cout << "Seleccione una opción: ";
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
                int idMin;
                idMin = obtenerBoxMenosOcupado();
                if (idMin == -1) {
                    cout << "No hay boxes en funcionamiento actualmente." << endl;
                } else {
                    cout << "El box menos ocupado es el que tiene el id-" << idMin << endl;
                }
                break;
            case 6: {
                int id;
                cout << "Ingrese ID del pasajero: ";
                cin >> id;
                buscarPasajeroEnBoxes(id);
                break;
            }
            case 7:
                simularCompleto();
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
