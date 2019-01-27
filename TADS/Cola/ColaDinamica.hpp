#ifndef COLA_ENLA_H
#define COLA_ENLA_H
#include <cassert>

template <typename T>
class Cola
{
  public:
    Cola();                               //constructor
    Cola(const Cola<T> &p);               //copia
    Cola<T> &operator=(const Cola<T> &p); //asig colas
    bool vacia() const;
    const T &frente() const;
    void pop();
    void push(const T &x);
    ~Cola(); //destructor
  private:
    struct nodo
    {
        T elto;
        nodo *sig;
        nodo(const T &e, nodo *p = 0) : elto(e), sig(p) {}
    };

    nodo *inicio, *fin; //extremos cola

    void copiar(const Cola<T> &c);
};

//M�todo privado
template <typename T>
void Cola<T>::copiar(const Cola<T> &c)
{
    if (c.inicio)
    {
        //c no vac�a. Copia el 1� elto
        inicio = fin = new nodo(c.inicio->elto);
        //copia el resto
        for (nodo *q = c.inicio->sig; q; q = q->sig)
        {
            fin->sig = new nodo(q->elto);
            fin = fin->sig;
        }
    }
}

template <typename T>
inline Cola<T>::Cola() : inicio(0), fin(0) {}

template <typename T>
inline Cola<T>::Cola(const Cola<T> &c) : inicio(0), fin(0)
{
    copiar(c);
}

template <typename T>
inline Cola<T> &Cola<T>::operator=(const Cola<T> &c)
{
    if (this != &c)
    {
        this->~Cola();
        copiar(c);
    }
    return *this;
}

template <typename T>
inline bool Cola<T>::vacia() const
{
    return (inicio == 0);
}

template <typename T>
inline const T &Cola<T>::frente() const
{
    assert(!vacia());
    return inicio->elto;
}

template <typename T>
inline void Cola<T>::pop()
{
    assert(!vacia());
    nodo *q = inicio;
    inicio = q->sig;
    if (!inicio)
        fin = 0;
    delete q;
}

template <typename T>
inline void Cola<T>::push(const T &x)
{
    nodo *q = new nodo(x);
    if (inicio == 0) //cola vac�a
        inicio = fin = q;
    else
        fin = fin->sig = q;
}

//Destructor: vac�a la cola
template <typename T>
Cola<T>::~Cola()
{
    nodo *q;
    while (inicio)
    {
        q = inicio->sig;
        delete inicio;
        inicio = q;
    }
    fin = 0;
}

#endif //Cola_ENLa_H
