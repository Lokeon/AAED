#ifndef BICOLA_HPP
#define BICOLA_HPP

#include <cassert>
#include <iostream>

template <typename T>
class Bicola
{

  public:
    Bicola() = default;                       //Constructor
    Bicola(const Bicola<T> &B);               //Constructor de copia
    Bicola<T> &operator=(const Bicola<T> &B); //Asignacion de bicolas
    bool vacia() const;
    const T &frente() const;  //Elemento del inicio
    const T &detras() const;  //Elemento del final
    void pop();               //Elimina por el comienzo
    void popInv();            //Elimina por el final
    void pushInv(const T &x); //Inserta por el comienzo
    void push(const T &x);    //Inserta por el final
    ~Bicola() = default;      //destructor

  private:
    struct nodo
    {
        T elto;
        nodo *sig;
        nodo(const T &e, nodo *P = 0) : elto(e),
                                        sig(P)
        {
        }
    };

    nodo *inicio, *fin; //extremos de la bicola

    void copiar(const Bicola<T> &B);
};

//Metodo privado
template <typename T>
void Bicola<T>::copiar(const Bicola<T> &B)
{
    nodo *p;

    //C no esta vacia

    if (B.inicio)
    {
        //Copiar el primer elemento

        inicio = fin = new nodo(B.inicio->elto);

        //Copiar el resto de elementos hasta el final de la cola

        for (p = B.inicio->sig; p; p = p->sig)
        {
            fin->sig = new nodo(p->elto);
            fin = fin->sig;
        }
    }
}

template <typename T>
inline Bicola<T>::Bicola() : inicio(0), fin(0)
{
}

template <typename T>
inline Bicola<T>::Bicola(const Bicola<T> &B) : inicio(0), fin(0)
{
    copiar(B);
}

template <typename T>
inline Bicola<T> &Bicola<T>::operator=(const Bicola<T> &B)
{
    //Evitar autoasignacion

    if (this != &B)
    {
        //Vaciar la cola actual

        this->~Bicola();
        copiar(B);
    }

    return *this;
}

template <typename T>
inline bool Bicola<T>::vacia() const
{
    return (inicio == 0);
}

template <typename T>
inline const T &Bicola<T>::frente() const
{
    assert(!vacia());

    return inicio->elto;
}

template <typename T>
inline const T &Bicola<T>::detras() const
{
    assert(!vacia());

    return fin->elto;
}

template <typename T>
inline void Bicola<T>::pop()
{
    assert(!vacia());

    nodo *p = inicio;
    inicio = p->sig;

    if (!inicio)
        fin = 0;

    delete p;
}

template <typename T>
inline void Bicola<T>::popInv()
{
    assert(!vacia());

    nodo *p, *q;

    p = inicio;

    if (inicio == fin)
        inicio = fin = 0;
    else
        while (fin != p->sig)
            p = p->sig;

    q = p;
    p = fin;
    fin = q;

    delete p;
}

template <typename T>
inline void Bicola<T>::pushInv(const T &x)
{
    nodo *p = new nodo(x);

    //Bicola vacia

    if (fin == 0)
        fin = inicio = p;
    else
        inicio = inicio->sig = p;
}

template <typename T>
inline void Bicola<T>::push(const T &x)
{
    nodo *p = new nodo(x);

    //Bicola vacia

    if (inicio == 0)
        inicio = fin = p;
    else
        fin = fin->sig = p;
}

//Destructor: vacia la cola

template <typename T>
Bicola<T>::~Bicola()
{
    nodo *p;
    while (inicio)
    {
        p = inicio->sig;

        delete inicio;

        inicio = p;
    }

    fin = 0;
}

#endif // Bicola_hpp