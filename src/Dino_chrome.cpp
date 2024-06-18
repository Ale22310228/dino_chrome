
#include <Dibujo.hpp>
#include <Ventana.hpp>
#include <Dino.hpp>
#include <list>
#include <curses.h>

using namespace std;
using namespace ftxui;

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

    list<Actualizable *> Actualizables;
    Actualizables.push_back(dino1);
    Actualizables.push_back(dino2);
    Actualizables.push_back(dino3);
   
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
        ventana.Actualizar(Actualizables);
        ventana.Dibujar(dibujos);
    }

    return 0;
}
#include <iostream>
#include <list>
#include <curses.h>

// Suponiendo que estos son los archivos de encabezado que defines para tus clases
#include "Ventana.hpp"
#include "Dino.hpp"
#include "Dibujo.hpp"

using namespace std;

int main() {
    // Inicialización de curses
    initscr();
    cbreak();  // Desactiva el búfer de línea, lee la entrada del usuario carácter por carácter
    noecho();  // No muestra la entrada del usuario en pantalla
    keypad(stdscr, true);  // Habilita el teclado especial (por ejemplo, flechas)

    // Creación de la ventana principal
    Ventana ventana;

    // Creación de objetos Dino y los agregamos a listas
    Dino* dino1 = new Dino(0, 0);
    Dino* dino2 = new Dino(100, 0);
    Dino* dino3 = new Dino(50, 50);

    list<Dibujo*> dibujos {dino1, dino2, dino3};
    list<Actualizable*> actualizables {dino1, dino2, dino3};

    // Bucle principal
    while (true) {
        int key = getch();

        // Manejo de las teclas de movimiento y salida
        switch (key) {
            case 'q':
            case 'Q':
                endwin();  // Termina curses antes de salir
                return 0;
            case 'a':
            case KEY_LEFT:
                dino1->DesplazarIzq();
                break;
            case 'd':
            case KEY_RIGHT:
                dino1->DesplazarDer();
                break;
        }

        // Actualizar y dibujar la ventana
        ventana.Actualizar(actualizables);
        ventana.Dibujar(dibujos);
    }

    // Liberar memoria y finalizar curses antes de salir
    endwin();
    return 0;
}
