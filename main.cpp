#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Coche.h"

void mostrarEstadisticas(const std::vector<Coche>& coches);

int main() {
    srand(time(0));

    int numCoches;
    std::cout << "Cuantos coches van a participar en la carrera? ";
    std::cin >> numCoches;

    std::vector<Coche> coches;
    for (int i = 0; i < numCoches; ++i) {
        std::string nombreCoche;
        std::cout << "Ingrese el nombre del coche " << i + 1 << ": ";
        std::cin >> nombreCoche;
        coches.emplace_back(nombreCoche);
    }

    for (int turno = 1; turno <= 5; ++turno) {
        std::cout << "Turno " << turno << std::endl;

        for (auto& coche : coches) {
            std::cout << "Turno de " << coche.getNombre() << std::endl;
            int dado = coche.lanzarDado();
            std::cout << "Has aumentado la velocidad del coche a " << dado << " km/h" << std::endl;
            coche.setVelocidad(coche.getVelocidad() + dado);

            char respuesta;
            std::cout << "Quieres utilzar el Nitro? (s/n): ";
            std::cin >> respuesta;
            if (respuesta == 's' || respuesta == 'S') {
                if (coche.puedeUsarNitro()) {
                    coche.usarNitro();
                    std::cout << "El Nitro te ha potenciado" << std::endl;
                }
                else {
                    std::cout << "Ya has utilizado el nitro en esta carrera." << std::endl;
                }
            }

            coche.avanzar();
        }

        mostrarEstadisticas(coches);

        std::cout << std::endl;
    }

    std::string ganador = coches[0].getNombre();
    int maxDistancia = coches[0].getDistanciaRecorrida();
    bool empate = false;
    for (size_t i = 1; i < coches.size(); ++i) {
        if (coches[i].getDistanciaRecorrida() > maxDistancia) {
            maxDistancia = coches[i].getDistanciaRecorrida();
            ganador = coches[i].getNombre();
            empate = false;
        }
        else if (coches[i].getDistanciaRecorrida() == maxDistancia) {
            empate = true;
        }
    }

    if (empate) {
        std::cout << "Ha habido un empate en la carrera" << std::endl;
    }
    else {
        std::cout << "El ganador de la careera es: " << ganador << "!" << std::endl;
    }

    return 0;
}

void mostrarEstadisticas(const std::vector<Coche>& coches) {
    std::cout << "Estadisticas actuales:" << std::endl;
    for (const auto& coche : coches) {
        std::cout << "Nombre: " << coche.getNombre() << ", Velocidad: " << coche.getVelocidad() << ", Distancia recorrida: " << coche.getDistanciaRecorrida() << std::endl;
    }
}
