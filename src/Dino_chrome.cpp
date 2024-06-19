#include "Dibujo.hpp"
#include "Ventana.hpp"
#include "Dino.hpp"
#include <list>
#include <curses.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(0));

    Ventana ventana;
    Dino *dino = new Dino(5, 15); // Ajusta la posición del dinosaurio
    Dibujo *camino = new Dibujo(0, 20, "Camino"); // Ajusta la posición del camino
    Dibujo *nube = new Dibujo(20, 5, "Nube"); // Ajusta la posición de la nube

    list<Dibujo *> dibujos;
    dibujos.push_back(dino);
    dibujos.push_back(camino);
    dibujos.push_back(nube);

    list<Actualizable *> actualizables;
    actualizables.push_back(dino);

    list<Dibujo *> cactus;

    int tick = 0;

    while (true)
    {
        int key = getch();
        if (key == 'q' || key == 'Q')
        {
            break;
        }
        if (key == 'a' || key == KEY_LEFT)
        {
            dino->DesplazarIzq();
        }
        if (key == 'd' || key == KEY_RIGHT)
        {
            dino->DesplazarDer();
        }
        if (key == 'w' || key == KEY_UP)
        {
            dino->Saltar();
        }
        if (key == 's' || key == KEY_DOWN)
        {
            dino->Agacharse();
        }
        if (key == 'e' || key == 'E')
        {
            dino->Levantarse();
        }

        if (tick % 50 == 0) {
            int cactus_x = rand() % 50 + 30;
            Dibujo *nuevoCactus = new Dibujo(cactus_x, 15, "Cactus"); // Ajusta la posición de los cactus
            dibujos.push_back(nuevoCactus);
            cactus.push_back(nuevoCactus);
        }

        for (auto it = cactus.begin(); it != cactus.end(); ) {
            Dibujo *c = *it;
            c->DesplazarIzq();
            if (c->getX() < 0) {
                it = cactus.erase(it);
                delete c;
            } else {
                ++it;
            }
        }

        ventana.Actualizar(actualizables);
        ventana.Dibujar(dibujos);
        tick++;
    }

    // Limpiar memoria
    for (auto c : cactus) {
        delete c;
    }
    delete dino;
    delete camino;
    delete nube;

    return 0;
}
