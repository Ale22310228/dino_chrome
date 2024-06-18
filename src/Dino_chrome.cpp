dino.cpp:
#include <Dibujo.hpp>
#include <Ventana.hpp>
#include <Dino.hpp>
#include <list>
#include <curses.h>

using namespace std;

int main(int argc, char const *argv[])
{
    Ventana ventana;
    Dino *dino1 = new Dino(0, 0);
    Dino *dino2 = new Dino(100, 0);
    Dino *dino3 = new Dino(50, 50);

    list<Dibujo *> dibujos;
    dibujos.push_back(dino1);
    dibujos.push_back(dino2);
    dibujos.push_back(dino3);

    list<Actualizable *> actualizables;
    actualizables.push_back(dino1);
    actualizables.push_back(dino2);
    actualizables.push_back(dino3);
   
    while (true)
    {
        int key = getch();
        if (key == 'q' || key == 'Q')
        {
            break;
        }
        if (key == 'a' || key == KEY_LEFT)
        {
            dino1->DesplazarIzq();
        } 
        if (key == 'd' || key == KEY_RIGHT)
        {
            dino1->DesplazarDer();
        } 
        ventana.Actualizar(actualizables);
        ventana.Dibujar(dibujos);
    }

    return 0;
}