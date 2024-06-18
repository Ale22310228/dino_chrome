#pragma once

#include "Dibujo.hpp"
#include "Actualizable.hpp"

class Dino : public Dibujo, public Actualizable {
private:
    int x;
    int y;

public:
    Dino() : Dibujo("DinoS"), x(0), y(0) {}
    Dino(int x, int y) : Dibujo(x, y, "DinoS"), x(x), y(y) {}

    void DesplazarIzq() {
        x -= 1;
    }

    void DesplazarDer() {
        x += 1;
    }

    void Actualizar() override {
        // Implementación de la función Actualizar según sea necesario
        // Por ejemplo, actualizar las coordenadas u otros atributos
    }

    ~Dino() {} // Destructor vacío si no hay recursos adicionales que liberar
};