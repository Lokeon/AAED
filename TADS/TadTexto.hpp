#include "./Pila/PilaDinamica.hpp"
#include <iostream>
#include <string>

class Texto
{
  public:
    Texto() = default;
    void insertarPila(std::string texto);
    void aplicarCaracteres();
    void mostrarTexto();
    ~Texto() = default;

  private:
    Pila<char> izq_, der_;
};

// Rellenamos en la izq
void Texto::insertarPila(std::string texto)
{
    for (int i = 0; i < texto.size(); ++i)
    {
        izq_.push(texto[i]);
    }
}

void Texto::mostrarTexto()
{
    while (!der_.vacia())
    {
        std::cout << der_.tope() << std::endl;
        der_.pop();
    }
}

void Texto::aplicarCaracteres()
{
    while (!izq_.vacia())
    {
        switch (izq_.tope())
        {
        // En el enunciado dice , que si hay varios seguidos, solo uno hace efecto
        // y los otros se guardan
        case '@':
            izq_.pop();
            if (izq_.tope() == '@')
                while (izq_.tope() == '@')
                {
                    der_.push(izq_.tope());
                    izq_.pop();
                }
            izq_.pop();
            break;

        case '#':
            while (!izq_.vacia())
            {
                izq_.pop();
            }
            break;

        default:

            der_.push(izq_.tope());
            izq_.pop();
            break;
        }
    }
}
