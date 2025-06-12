#include "NodoPila.h"

NodoPila::NodoPila() : valor(Pasajero()), siguiente(nullptr) {}

NodoPila::NodoPila(Pasajero v, NodoPila *sig) : valor(v), siguiente(sig) {}

NodoPila::~NodoPila() {} // Destructor vacío
