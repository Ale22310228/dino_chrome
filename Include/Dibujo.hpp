
#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <curses.h>

class Dibujo
{
private:
    std::fstream archivo;

protected:
    int y;
    int x;

public:
    Dibujo(int x, int y, std::string recurso)
    {
        archivo.open("./Data/" + recurso + ".txt");
        this->x = x;
        this->y = y;
    }
    Dibujo(std::string recurso)
    {
        archivo.open("./Data/" + recurso + ".txt");
        this->x = 0;
        this->y = 0;
    }
    void Dibujar()
{
    std::string linea;
    move(this->y, this->x);
    while (std::getline(archivo, linea))
    {
        mvaddstr(getcury(stdscr), this->x, linea.c_str());
        move(getcury(stdscr) + 1, this->x); // Mover el cursor a la siguiente línea
    }
    archivo.clear();
    archivo.seekg(0);
}

    ~Dibujo()
    {
        archivo.close();
    }
};