[11:04 p. m., 17/6/2024] _: Dino:
#pragma once
#include<Dibujo.hpp>
#include<Actualizable.hpp>

class Dino : public Dibujo, public Actualizable //Dino es un Dibujo
{
private:
public:
    Vaca() : Dibujo("DinoS")
    {
    }
    Vaca(int x, int y) : Dibujo(x, y, "DinoS")
    {
    }
    void DesplazarIzq(){
        this->x += -1;
    }
    void DesplazarDer(){
        this->x += 1;
    }
    void Actualizar(){
        this->x +=0;
        this->y +=0;
    }
  
    ~Dino() {}
};

