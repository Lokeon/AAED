
#include "./Lista/ListaVectorialPseudoestatica.hpp"
#include <string>
#include <iostream>

class Paciente
{
  public:
    Paciente(std::string n, int id, int gra) : n_(n), id_(id), gr_(gra) {}
    std::string nombre() const { return n_; }
    int id() const { return id_; }
    int gravedad() const { return gr_; }

  private:
    int id_, gr_;
    std::string n_;
};

class Hospital
{
  public:
    explicit Hospital(size_t p, size_t u, size_t m) : PLANTA(Lista<Paciente>(p)),
                                                      UCI(Lista<Paciente>(u)),
                                                      MORGUE(Lista<Paciente>(m)),
                                                      uci_(u), planta_(p), morgue_(m) {}
    void hospital(const Paciente &x);
    void alta(const Paciente &x);
    void muerte();
    void UCIS() const;
    void PLANTAS() const;
    void gravedad_determinada(int h) const;

    ~Hospital() = default;

  private:
    Lista<Paciente> PLANTA;
    Lista<Paciente> UCI;
    Lista<Paciente> MORGUE;
    size_t uci_, planta_, morgue_;
    bool uciLLena();
    bool plantaLLena();
    bool morgueLLena();
};

void Hospital::hospital(const Paciente &p)
{
    if ((p.gravedad() > 0 && p.gravedad() < 6) && !uciLLena())
    {
        UCI.insertar(p, UCI.fin());
        --uci_;
    }
    else if ((p.gravedad() > 6 && p.gravedad() <= 9) || (uciLLena() && p.gravedad() != 0))
    {
        PLANTA.insertar(p, PLANTA.fin());
        --planta_;
    }
    else if (!morgueLLena() && !p.gravedad())
    {
        MORGUE.insertar(p, MORGUE.fin());
        --morgue_;
    }
}

void Hospital::alta(const Paciente &x)
{
    PLANTA.eliminar(PLANTA.buscar(x));
}

void Hospital::UCIS() const
{
    typename Lista<Paciente>::posicion p;

    for (p = UCI.primera(); p != UCI.fin(); p = UCI.siguiente(p))
    {
        std::cout << "Pacientes en UCI: " << UCI.elemento(p).nombre() << std::endl;
    }
}

void Hospital::PLANTAS() const
{
    typename Lista<Paciente>::posicion p;

    for (p = PLANTA.primera(); p != PLANTA.fin(); p = PLANTA.siguiente(p))
    {
        std::cout << "Pacientes en Planta: " << PLANTA.elemento(p).nombre() << std::endl;
    }
}

void Hospital::muerte()
{
    typename Lista<Paciente>::posicion p;

    for (p = MORGUE.primera(); p != MORGUE.fin(); p = MORGUE.siguiente(p))
    {
        MORGUE.eliminar(p);
    }
}

void Hospital::gravedad_determinada(int h) const
{
    typename Lista<Paciente>::posicion p;
    typename Lista<Paciente>::posicion u;
    typename Lista<Paciente>::posicion m;

    if (h > 0 && h < 6)
    {
        for (p = PLANTA.primera(); p != PLANTA.fin(); p = PLANTA.siguiente(p))
        {
            if (PLANTA.elemento(p).gravedad() == h)
            {
                std::cout << PLANTA.elemento(p).nombre() << std::endl;
            }
        }
    }
    else
    {
        if (h >= 6 && h < 10)
        {
            for (u = UCI.primera(); u != UCI.fin(); u = UCI.siguiente(u))
            {
                if (UCI.elemento(u).gravedad() == h)
                {
                    std::cout << UCI.elemento(u).nombre() << std::endl;
                }
            }
        }
        else
        {
            if (h == 0)
            {
                for (u = UCI.primera(); u != UCI.fin(); u = UCI.siguiente(u))
                {

                    std::cout << UCI.elemento(u).nombre() << std::endl;
                }
            }
        }
    }
}

bool Hospital::uciLLena()
{
    return (uci_ == 0);
}

bool Hospital::plantaLLena()
{
    return (planta_ == 0);
}

bool Hospital::morgueLLena()
{
    return (morgue_ == 0);
}

bool operator==(const Paciente &X, const Paciente &Y)
{
    return X.id() == Y.id();
}
