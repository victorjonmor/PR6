#ifndef COCHE_H
#define COCHE_H

#include <string>

class Coche {
private:
    std::string nombre;
    int velocidad;
    int distanciaRecorrida;
    bool nitroDisponible;

public:
    Coche(std::string _nombre);
    std::string getNombre() const;
    int getVelocidad() const;
    int getDistanciaRecorrida() const;

    void setVelocidad(int _velocidad);

    int lanzarDado();

    bool puedeUsarNitro() const;
    void usarNitro();

    void avanzar();
};

#endif
