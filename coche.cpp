#include "Coche.h"
#include <cstdlib>
#include <ctime>

Coche::Coche(std::string _nombre) : nombre(_nombre), velocidad(0), distanciaRecorrida(0), nitroDisponible(true) {}

std::string Coche::getNombre() const { return nombre; }
int Coche::getVelocidad() const { return velocidad; }
int Coche::getDistanciaRecorrida() const { return distanciaRecorrida; }

void Coche::setVelocidad(int _velocidad) { velocidad = _velocidad; }

int Coche::lanzarDado() {
    return (rand() % 6) + 1;
}

bool Coche::puedeUsarNitro() const {
    return nitroDisponible;
}

void Coche::usarNitro() {
    if (nitroDisponible) {
        int random = rand() % 2;
        if (random == 0)
            velocidad /= 2;
        else
            velocidad *= 2;
        nitroDisponible = false;
    }
}

void Coche::avanzar() {
    distanciaRecorrida += velocidad * 100;
}
