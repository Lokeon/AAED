#ifndef Simbolo_HPP
#define Simbolo_HPP

#include <string>
#include <iostream>
#include "./Lista/ListaDoEnlaCabe.hpp"

#define ARRIBA 0
#define ABAJO 1
#define IZQUIERDA 2
#define DERECHA 3

class Simbolo
{
  public:
    Simbolo() = default;
    void anadirTrazo(int trazo);
    void deshacerTrazo(int n);
    Simbolo respectoX();
    Simbolo respectoY();
    Simbolo respectoXY();

  private:
    Lista<int> lista_;
};

void Simbolo::anadirTrazo(int trazo)
{
    lista_.insertar(trazo, lista_.fin());
}

void Simbolo::deshacerTrazo(int n)
{
    while (n > 0)
    {
        lista_.eliminar(lista_.anterior(lista_.fin()));
        --n;
    }
}

Simbolo Simbolo::respectoX()
{
    Simbolo simetria;

    typename Lista<int>::posicion p;

    for (p = lista_.primera(); p != lista_.fin(); p = lista_.siguiente(p))
    {
        switch (lista_.elemento(p))
        {
        case IZQUIERDA:
            simetria.anadirTrazo(IZQUIERDA);
            break;
        case DERECHA:
            simetria.anadirTrazo(DERECHA);
            break;
        case ARRIBA:
            simetria.anadirTrazo(ABAJO);
            break;
        case ABAJO:
            simetria.anadirTrazo(ARRIBA);
            break;
        }
    }
    return simetria;
}

Simbolo Simbolo::respectoY()
{
    Simbolo simetria;

    typename Lista<int>::posicion p;

    for (p = lista_.primera(); p != lista_.fin(); p = lista_.siguiente(p))
    {
        switch (lista_.elemento(p))
        {
        case IZQUIERDA:
            simetria.anadirTrazo(DERECHA);
            break;
        case DERECHA:
            simetria.anadirTrazo(IZQUIERDA);
            break;
        case ARRIBA:
            simetria.anadirTrazo(ARRIBA);
            break;
        case ABAJO:
            simetria.anadirTrazo(ABAJO);
            break;
        }
    }
    return simetria;
}

Simbolo Simbolo::respectoXY()
{
    Simbolo simetria;

    typename Lista<int>::posicion p;

    for (p = lista_.primera(); p != lista_.fin(); p = lista_.siguiente(p))
    {
        switch (lista_.elemento(p))
        {
        case IZQUIERDA:
            simetria.anadirTrazo(DERECHA);
            break;
        case DERECHA:
            simetria.anadirTrazo(IZQUIERDA);
            break;
        case ARRIBA:
            simetria.anadirTrazo(ABAJO);
            break;
        case ABAJO:
            simetria.anadirTrazo(ARRIBA);
            break;
        }
    }
    return simetria;
}

#endif