#include "./Lista/ListaDoEnlaCabe.hpp"

template <typename T>
class Punto
{
  public:
    Punto(T x, T y) : x_(x), y_(y) {}
    T &x() { return x_; }
    T x() const { return x_; }
    T &y() { return y_; }
    T y() const { return y_; }
    ~Punto() = default;

  private:
    T x_, y_;
};

template <typename T>
class Intervalo
{
  public:
    Intervalo() = default;
    Intervalo(T x1 = 0, T x2 = 0, T y = 0) : inicio_(Punto<T>(x1, y)), fin_(Punto<T>(x2, y)) {}
    Punto<T> inicio() { return inicio_; }
    Punto<T> fina() { return fin_; }
    ~Intervalo() = default;

  private:
    Punto<T> inicio_, fin_;
};

template <typename T>
class Escalonada
{
  public:
    Escalonada(unsigned int salto) : salto_(salto), saltoTotales(0) {}
    void anadirSalto(const Intervalo<T> &inter);
    void eliminarSalto(const Intervalo<T> &inter);
    void translacion(float w, float z);
    T valor(T x) const;
    T maximo() const;
    T minimo() const;
    ~Escolanada() = default;

  private:
    Lista<Intervalo<T>> lista_;
    unsigned int salto_;
    unsigned int saltoTotales;
};

template <typename T>
void Escalonada<T>::anadirSalto(const Intervalo<T> &inter)
{
    if (saltoTotales < salto_)
    {
        if (!saltoTotales)
        {
            lista_.insertar(inter, lista_.fin());
            ++saltoTotales;
        }
        else
        {
            if (lista_.elemento(lista_.anterior(lista_.fin())).fina().x() == inter.inicio().x())
            {
                if (lista_.elemento(lista_.anterior(lista_.fin())).inicio().y() == inter.inicio().y())
                {
                    lista_.insertar(inter, lista_.fin());
                    ++saltoTotales;
                }
            }
        }
    }
}

template <typename T>
void Escalonada<T>::eliminarSalto(const Intervalo<T> &inter)
{
    typename Lista < Intervalo<T>::posicion pos;

    for (pos = lista_.primera(); pos != lista_.fin(); pos = lista_.siguiente(pos))
    {
        if (lista_.elemento(pos) == inter)
        {
            if (pos != lista_.primera())
            {
                lista_.elemento(lista_.anterior()).fina().x() = inter.fina().x();
            }
            lista_.eliminar(pos);
            --saltoTotales;
        }
    }
}

template <typename T>
void Escalonada<T>::translacion(float w, float z)
{
    typename Lista<Intervalo<T>>::posicion pos;

    for (pos = lista_.primera(); pos != lista_.fin(); pos = lista_.siguiente(pos))
    {
        lista_.elemento(pos).inicio().x() += w;
        lista_.elemento(pos).fina().x() += w;
        lista_.elemento(pos).fina().y() += z;
        lista_.elemento(pos).fina().y() += z;
    }
}

template <typename T>
T Escalonada<T>::maximo() const
{
    typename Lista<Intervalo<T>>::posicion pos;
    T max;

    max = lista_.elemento(lista_.primera()).inicio().y();

    for (pos = lista_.primera(); pos != lista_.fin(); pos = lista_.siguiente(pos))
    {
        if (max <= lista_.elemento(pos).inicio().y())
        {
            max = lista_.elemento(pos).inicio().y();
        }
    }

    return max;
}

template <typename T>
T Escalonada<T>::minimo() const
{
    typename Lista<Intervalo<T>>::posicion pos;
    T min;

    min = lista_.elemento(lista_.primera()).inicio().y();

    for (pos = lista_.primera(); pos != lista_.fin(); pos = lista_.siguiente(pos))
    {
        if (min >= lista_.elemento(pos).inicio().y())
        {
            min = lista_.elemento(pos).inicio().y();
        }
    }

    return min;
}

template <typename T>
T Escalonada<T>::valor(T x) const
{
    typename Lista<Intervalo<T>>::posicion pos;
    T y = 0;
    bool inter = false;

    for (pos = lista_.primera(); pos != lista_.fin() && !inter; pos = lista_.siguiente(pos))
    {
        if (lista_.elemento(pos).inicio().x() <= x && lista_.elemento(pos).fina().x() >= x)
        {
            inter = true;
            y = lista_.elemento(pos).inicio().y();
        }
    }
    return y;
}

template <typename T>
bool operator==(const Intervalo<T> &l, const Intervalo<T> &t)
{
    return l.inicio() == t.inicio() && l.fin() == t.fin();
}
template <typename T>
bool operator==(const Punto<T> &l, const Punto<T> &t)
{
    return l.x() == t.x() && l.y() == t.y();
}