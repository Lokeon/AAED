#include "./Lista/ListaDoEnlaCabe.hpp"

template <typename T>
class Conjunto
{
  public:
    Conjunto() = default;
    bool vacio() const;
    void anadirElemento(T elto);
    void eliminarElemento(T elto);
    Conjunto<T> unions(const Conjunto &c1, const Conjunto &c2);
    Conjunto<T> interse(const Conjunto &c1, const Conjunto &c2);
    Conjunto<T> diferencia(const Conjunto &c1, const Conjunto &c2);
    void mostrarConjunto() const;
    ~Conjunto() = default;

  private:
    Lista<T> lista_;
};

template <typename T>
bool Conjunto<T>::vacio() const
{
    return (lista_.primera() == lista_.fin());
}

template <typename T>
void Conjunto<T>::anadirElemento(T elto)
{
    lista_.insertar(elto, lista_.fin());
}

template <typename T>
void Conjunto<T>::eliminarElemento(T elto)
{
    lista_.eliminar(lista_.buscar(elto));
}

template <typename T>
Conjunto<T> Conjunto<T>::unions(const Conjunto &c1, const Conjunto &c2)
{
    Conjunto<T> aux;
    typename Lista<T>::posicion pos;

    for (pos = c1.lista_.primera(); pos != c1.lista_.fin(); pos = c1.lista_.siguiente(pos))
    {
        aux.anadirElemento(c1.lista_.elemento(pos));
    }

    for (pos = c2.lista_.primera(); pos != c2.lista_.fin(); pos = c2.lista_.siguiente(pos))
    {
        if (aux.lista_.buscar(c2.lista_.elemento(pos)) == aux.lista_.fin())
            aux.anadirElemento(c2.lista_.elemento(pos));
    }

    return aux;
}

template <typename T>
Conjunto<T> Conjunto<T>::interse(const Conjunto &c1, const Conjunto &c2)
{
    Conjunto<T> aux;
    typename Lista<T>::posicion pos1, pos2;

    for (pos1 = c1.lista_.primera(); pos1 != c1.lista_.fin(); pos1 = c1.lista_.siguiente(pos1))
    {
        for (pos2 = c2.lista_.primera(); pos2 != c2.lista_.fin(); pos2 = c2.lista_.siguiente(pos2))
        {
            if (c2.lista_.elemento(pos2) == c1.lista_.elemento(pos1))
                aux.lista_.insertar(c1.lista_.elemento(pos1), aux.lista_.fin());
        }
    }

    return aux;
}

template <typename T>
Conjunto<T> Conjunto<T>::diferencia(const Conjunto &c1, const Conjunto &c2)
{
    Conjunto<T> aux, uniona, intersea;
    typename Lista<T>::posicion pos1, pos2;

    uniona = uniona.unions(c1, c2);
    intersea = intersea.interse(c1, c2);

    for (pos1 = uniona.lista_.primera(); pos1 != uniona.lista_.fin(); pos1 = uniona.lista_.siguiente(pos1))
    {
        aux.anadirElemento(uniona.lista_.elemento(pos1));
    }

    for (pos2 = intersea.lista_.primera(); pos2 != intersea.lista_.fin(); pos2 = intersea.lista_.siguiente(pos2))
    {
        if (aux.lista_.buscar(intersea.lista_.elemento(pos2)) != aux.lista_.fin())
            aux.eliminarElemento(intersea.lista_.elemento(pos2));
    }

    return aux;
}

// Pruebas
template <typename T>
void Conjunto<T>::mostrarConjunto() const
{
    typename Lista<T>::posicion pos;

    for (pos = lista_.primera(); pos != lista_.fin(); pos = lista_.siguiente(pos))
    {
        std::cout << lista_.elemento(pos) << std::endl;
    }
}
