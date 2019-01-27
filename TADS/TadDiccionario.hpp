#ifndef Diccionario_HPP
#define Diccionario_HPP

#include <string>
#include <iostream>
#include "./Lista/ListaDoEnlaCabe.hpp"

class Traduccion
{
  public:
    Traduccion() = default;
    Traduccion(std::string palabraIngles) : ingles_(palabraIngles) {}
    std::string palabraIngles() const { return ingles_; }
    // mi ñ  Æ
    void insertarTraducciones(const std::string palabraEspana);
    void eliminarTraducciones(const std::string palabraEspana);
    void mostrarTraducciones();
    ~Traduccion() = default;

  private:
    std::string ingles_;
    Lista<std::string> tradu_;
};

class Diccionario
{
  public:
    Diccionario() = default;
    void insertarDiccionario(const Traduccion &Tradu);
    void eliminarDiccionario(const Traduccion &Tradu);
    void mostrarDiccionario(const Traduccion &Tradu);
    ~Diccionario() = default;

  private:
    Lista<Traduccion> lista_;
};

void Traduccion::insertarTraducciones(const std::string palabra)
{
    tradu_.insertar(palabra, tradu_.fin());
}

void Traduccion::eliminarTraducciones(const std::string palabra)
{
    tradu_.eliminar(tradu_.buscar(palabra));
}

void Traduccion::mostrarTraducciones()
{
    typename Lista<std::string>::posicion pos;
    std::cout << "Palabra:" << " "<< ingles_ << std::endl;
    std::cout << "Traducciones: " << std::endl;
    for (pos = tradu_.primera(); pos != tradu_.fin(); pos = tradu_.siguiente(pos))
    {
        std::cout << tradu_.elemento(pos) << " ";
    }
    std::cout << std::endl;
}

void Diccionario::insertarDiccionario(const Traduccion &tradu)
{
    lista_.insertar(tradu, lista_.fin());
}

void Diccionario::eliminarDiccionario(const Traduccion &tradu)
{
    lista_.eliminar(lista_.buscar(tradu));
}

void Diccionario::mostrarDiccionario(const Traduccion &tradu)
{
    lista_.elemento(lista_.buscar(tradu)).mostrarTraducciones();
}

bool operator==(const Traduccion &trad, const Traduccion &tradu)
{
    return (trad.palabraIngles() == tradu.palabraIngles());
}

#endif