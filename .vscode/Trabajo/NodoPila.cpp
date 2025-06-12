#include "NodoPila.h"

NodoPila::NodoPila() : valor(Persona()), siguiente(nullptr) {}

NodoPila::NodoPila(Persona v, NodoPila *sig) : valor(v), siguiente(sig) {}

NodoPila::~NodoPila() {} // Destructor vacío
