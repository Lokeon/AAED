#ifndef COLA_ENLA_H
#define COLA_ENLA_H
#include <cassert>

template <typename T> class Bicola
{
    public:
        Bicola(); //constructor
        Bicola(const Bicola<T>& p); //copia
        Bicola<T>& operator =(const Bicola<T>& p); //asig colas
        bool vacia() const;
        T frente() const;
        T ultimo () const :
        void pop_f();
        void pop() ;
        void push(const T& x);
        void push_f(const T& x) ;
        ~Bicola(); //destructor
    private:
        struct nodo{
            T elto;
            nodo* sig;
            nodo(const T& e, nodo* p = 0): elto(e), sig(p){}
    };

    nodo *inicio, *fin; //extremos cola

   void copiar(const Bicola<T>& c);
};

//Método privado
template <typename T>
void Cola<T>::copiar(const Cola<T>& c)
{
    if(c.inicio){
        //c no vacía. Copia el 1º elto
        inicio= fin= new nodo(c.inicio->elto);
        //copia el resto
        for(nodo *q = c.inicio->sig; q; q= q->sig)
        {
            fin->sig = new nodo(q->elto);
            fin = fin->sig;
        }
    }
}

template <typename T>
inline Bicola<T>::Bicola() : inicio(0), fin(0) {}

template <typename T>
inline Bicola<T>::Bicola(const Bicola<T>& c) : inicio(0),fin(0)
{ copiar(c); }

template <typename T>
inline Bicola<T>& Bicola<T>::operator =(const Bicola<T>& c)
{
    if (this != &c) {
        this->~Bicola();
        copiar(c);
    }
    return *this;
}

template <typename T>
inline bool Bicola<T>::vacia() const
{ return (inicio==0); }

template <typename T>
inline T Bicola<T>::frente() const
{
    assert(!vacia());
    return inicio->elto;
}

template <typename T>
inline void Bicola<T>::pop()
{
    assert(!vacia());
    nodo* q = inicio;
    inicio = q->sig;
    if(!inicio) fin=0;
    delete q;
}
template <typename T>
T Bicola<T>::ultimo() const
{
    assert(!vacia()) ;
    return fin->elto ;
}

template <typename T>
inline void Bicola<T>::pop_u()
{
    assert(!vacia());
    nodo* q = inicio;
    if(inicio == fin)
        inicio = 0 ;
    else{
    while(q-> sig != fin) {q = q -> sig ;}
    delete fin :
    fin = q ;

     }
}
template <typename T>
void Bicola<T>::push(const T& x)
{
    nodo* q = new nodo(x);
    if(inicio == 0) //cola vacía
        inicio = fin = q;
    else
        fin = fin->sig = q;
}
template <typename T>
void Bicola<T>::push_u(const T& x)
{

    if(vacia()) //cola vacía
        inicio = fin = new nodo(x);
    else
    {
        nodo* q = inicio ;
        inicio = new nodo(x,q) ;
    }

}
//Destructor: vacía la cola
template <typename T>
Bicola<T>::~Bicola()
{
    nodo* q;
    while(inicio){
        q=inicio->sig;
        delete inicio;
        inicio=q;
    }
    fin=0;
}

#endif //Cola_ENLa_H
