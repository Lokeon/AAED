#include "./Lista/ListaDobleEnlazaCabezera.hpp"
#include <string>

class Binario
{
  public:
    Binario() = default;
    explicit Binario(std::string cadena); 
    Binario operator&(const Binario &r) const; //AND
    Binario operator|(const Binario &r) const; //OR
    Binario operator^(const Binario &r) const; //XOR
    Binario operator~() const;                 //NOT
    Binario operator<<(int n) const;
    Binario operator>>(int n) const;
    ~Binario() = default;

  private:
    Lista<int> lista_;
};

Binario::Binario(std::string cadena)
{
    for (int i = 0; i < cadena.size(); ++i)
    {
        lista_.insertar(cadena.at(i), lista_.fin());
    }
}

Binario Binario::operator~() const
{
    Binario aux;
    typename Lista<int>::posicion pos;

    for (pos = lista_.primera(); pos != lista_.fin(); pos = lista_.siguiente(pos))
    {
        if (!lista_.elemento(pos))
            aux.lista_.insertar(1, aux.lista_.fin());
        else
            aux.lista_.insertar(0, aux.lista_.fin());
    }
    return aux;
}

Binario Binario::operator&(const Binario &binario) const
{
    Binario aux;
    typename Lista<int>::posicion pos1, pos2;

    pos1 = lista_.fin();
    pos2 = binario.lista_.fin();

    while (pos1 != lista_.primera() && pos2 != binario.lista_.primera())
    {
        if (lista_.elemento(pos1) && binario.lista_.elemento(pos2))
            aux.lista_.insertar(1, aux.lista_.primera());
        else
            aux.lista_.insertar(0, aux.lista_.primera());

        if (pos1 != lista_.primera())
            pos1 = lista_.anterior(pos1);

        if (pos2 != binario.lista_.primera())
            pos2 = binario.lista_.anterior(pos2);
    }
    return aux;
}

Binario Binario::operator|(const Binario &binario) const
{
    Binario aux;
    typename Lista<int>::posicion pos1, pos2;

    pos1 = lista_.fin();
    pos2 = binario.lista_.fin();

    while (pos1 != lista_.primera() && pos2 != binario.lista_.primera())
    {
        if (lista_.elemento(pos1) || binario.lista_.elemento(pos2))
            aux.lista_.insertar(1, aux.lista_.primera());
        else
            aux.lista_.insertar(0, aux.lista_.primera());

        if (pos1 != lista_.primera())
            pos1 = lista_.anterior(pos1);

        if (pos2 != binario.lista_.primera())
            pos2 = binario.lista_.anterior(pos2);
    }
    return aux;
}

Binario Binario::operator^(const Binario &binario) const
{
    Binario aux;
    typename Lista<int>::posicion pos1, pos2;

    pos1 = lista_.fin();
    pos2 = binario.lista_.fin();

    while (pos1 != lista_.primera() && pos2 != binario.lista_.primera())
    {
        if (lista_.elemento(pos1) == binario.lista_.elemento(pos2))
            aux.lista_.insertar(0, aux.lista_.primera());
        else
            aux.lista_.insertar(1, aux.lista_.primera());

        if (pos1 != lista_.primera())
            pos1 = lista_.anterior(pos1);

        if (pos2 != binario.lista_.primera())
            pos2 = binario.lista_.anterior(pos2);
    }
    return aux;
}

Binario Binario::operator>>(int n) const
{
    Binario aux = *this;

    while (n > 0)
    {
        aux.lista_.insertar(0, aux.lista_.primera());
        aux.lista_.eliminar(aux.lista_.anterior(aux.lista_.fin()));
        --n;
    }

    return aux;
}

Binario Binario::operator<<(int n) const
{
    Binario aux = *this;

    while (n > 0)
    {
        aux.lista_.insertar(0, aux.lista_.fin());
        aux.lista_.eliminar(aux.lista_.primera());
        --n;
    }

    return aux;
}
