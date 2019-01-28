#include <iostream>
#include "../Pila/PilaDinamica.hpp"

struct tCubo
{
    enum ORIENTACION
    {
        ARRIBA,
        ABAJO,
        NULA
    };
    tCubo(size_t tam = 0, ORIENTACION o = NULA) : tam_(tam), or_(o) {}
    ORIENTACION &orientacion() { return or_; }
    ORIENTACION orientacion() const { return or_; }
    size_t &tamano() { return tam_; }
    size_t tamano() const { return tam_; }
    void rotar()
    {
        if (or_ == ARRIBA)
        {
            or_ = ABAJO;
        }
        else if (or_ == ABAJO)
        {
            or_ = ARRIBA;
        }
    }
    bool abajo() { return or_ == ABAJO; }

    ORIENTACION or_;
    size_t tam_;
};

Pila<tCubo> una_pila(Pila<tCubo> &p)
{
    Pila<tCubo> l;
    while (!p.vacia())
    {
        tCubo tmp = p.tope();
        p.pop();
        while (!l.vacia() && tmp > l.tope())
        {
            p.push(l.tope());
            l.pop();
        }
        if (tmp.abajo())
            tmp.rotar();
        l.push(tmp);
    }

    return l;
}

bool operator==(const tCubo &l, const tCubo &r)
{
    return l.tamano() == r.tamano() &&
           l.orientacion() == r.orientacion();
}

bool operator>(const tCubo &l, const tCubo &r)
{
    return l.tamano() > r.tamano();
}
