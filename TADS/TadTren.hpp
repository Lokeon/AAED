#include "./Pila/PilaDinamica.hpp"

// Para quitar los errores molestos . . .
typedef int vagon;

class Tren
{

  public:
    Tren() = default;
    void desplazarIzquierda();
    void desplazarDerecha();
    void eliminarVagonActivo();
    void insertarVagonActivo(const vagon &x);
    vagon &vagonActivo();
    bool trenVacio() const;

  private:
    Pila<vagon> izq_;
    Pila<vagon> der_;
};

// Mi vagon activo siempre sera el de la izq(Pila)
void Tren::insertarVagonActivo(const vagon &vagonsito)
{
    if (!izq_.vacia())
    {
        der_.push(izq_.tope());
        izq_.pop();
    }

    izq_.push(vagonsito);
}

void Tren::desplazarIzquierda()
{
    if (!der_.vacia())
    {
        izq_.push(der_.tope());
        der_.pop();
    }
}

void Tren::desplazarDerecha()
{
    if (!izq_.vacia())
    {
        der_.push(izq_.tope());
        izq_.pop();
    }
}

void Tren::eliminarVagonActivo()
{
    if (!izq_.vacia())
    {
        izq_.pop();
    }
    if (!der_.vacia() && izq_.vacia())
    {
        desplazarIzquierda();
    }
}

vagon &Tren::vagonActivo() 
{
    if (izq_.vacia())
    {
        return der_.tope();
    }

    return izq_.tope();
}

bool Tren::trenVacio() const
{
    return (izq_.vacia() && der_.vacia());
}