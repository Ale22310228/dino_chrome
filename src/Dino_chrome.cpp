#include "Dibujo.hpp"
#include "Ventana.hpp"
#include "Dino.hpp"
#include <list>
#include <curses.h>

#ifdef border
#undef border
#endif

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;
using namespace std;

int main(int argc, char const *argv[])
{
    Ventana ventana;
    Dino *dino1 = new Dino(0, 0, "Dino");
    Dino *dino2 = new Dino(20, 0, "Dino1");
    Dino *dino3 = new Dino(40, 0, "Dino2");
    Dibujo *camino = new Dibujo(0, 10, "Camino");
    Dibujo *nube = new Dibujo(0, 5, "Nube");

    list<Dibujo *> dibujos;
    dibujos.push_back(dino1);
    dibujos.push_back(dino2);
    dibujos.push_back(dino3);
    dibujos.push_back(camino);
    dibujos.push_back(nube);

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
