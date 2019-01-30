#include "./Lista/ListaDoEnlaCabe.hpp"

class Mueble
{
  public:
    Mueble() = default;
    explicit Mueble(double izq = 0, double larg = 0) : izquierda_(izq), ancho_(larg) {}
    double izquierda() const { return izquierda_; }
    double ancho() const { return ancho_; }
    double &izquierda() { return izquierda_; }
    double &ancho() { return ancho_; }

  private:
    double ancho_, izquierda_;
};

class Cocina
{
  public:
    Cocina(double longi) : longitud_(longi) {}
    typedef typename Lista<Mueble>::posicion posicion;
    bool colocar(const Mueble &x, posicion p);
    void anadirMueble(const Mueble &x, posicion p);
    void mover(posicion p);
    void eliminar(posicion p);
    Mueble &mueble(posicion p);

  private:
    double longitud_;
    Lista<Mueble> lista_;
};

void Cocina::eliminar(posicion p)
{
    lista_.eliminar(p);
}

bool Cocina::colocar(const Mueble &x, posicion p)
{
    Mueble aux = lista_.elemento(p);
    double longi = 0;

    if (p == lista_.primera())
    {
        longi = longitud_ + (aux.izquierda() + aux.ancho());
    }
    else
    {
        if (p == lista_.anterior(lista_.fin()))
        {
            longi = aux.izquierda();
        }
        else
        {
            longi = aux.izquierda() + aux.ancho() - lista_.elemento(lista_.siguiente(p)).ancho();
        }
    }
    return x.ancho() <= longi;
}

void Cocina::anadirMueble(const Mueble &x, posicion p)
{
    assert(colocar(x, p) == true);

    if (longitud_ != 0)
    {
        lista_.insertar(x, p);
        longitud_ -= x.ancho();
    }
}

Mueble &Cocina::mueble(posicion p)
{
    return lista_.elemento(p);
}

void Cocina::mover(posicion p)
{
    assert(p != lista_.fin());
    if (lista_.siguiente(p) != lista_.fin())
        lista_.elemento(p).izquierda() = lista_.elemento(lista_.siguiente(p)).izquierda() +
                                         lista_.elemento(lista_.siguiente(p)).ancho();
}

bool operator==(const Mueble &x, const Mueble &y)
{
    return (x.ancho() == y.ancho() && x.izquierda() == y.izquierda());
}