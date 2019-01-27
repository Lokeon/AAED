#ifndef COLA_ENLACIRCU_H
#define COLA_ENLACIRCU_H
#include <cassert>

template <typename T>
class Cola
{
 public:
   Cola();                               // constructor
   Cola(const Cola<T> &p);               // ctor. de copia
   Cola<T> &operator=(const Cola<T> &p); // asignaci�n de colas
   bool vacia() const;
   T frente() const;
   void pop();
   void push(const T &x);
   ~Cola(); // destructor
 private:
   struct nodo
   {
      T elto;
      nodo *sig;
      nodo(const T &e, nodo *p = 0) : elto(e), sig(p) {}
   };
   nodo *fin; // extremo de la cola
   void copiar(const Cola<T> &c);
};

// M�todo privado
template <typename T>
void Cola<T>::copiar(const Cola<T> &c)
{
   if (c.fin != 0)
   { // c no est� vac�a
      // Copiar el primer elto.
      fin = new nodo(c.fin->elto);
      // Copiar el resto de elementos hasta el final de la cola.
      for (nodo *q = c.fin->sig; q; q = q->sig)
      {
         fin->sig = new nodo(q->elto);
         fin = fin->sig;
      }
   }
}

template <typename T>
inline Cola<T>::Cola() : fin(0)
{
}

template <typename T>
inline Cola<T>::Cola(const Cola<T> &c) : fin(0)
{
   copiar(c);
}

template <typename T>
inline Cola<T> &Cola<T>::operator=(const Cola<T> &c)
{
   if (this != &c)
   {                 // evitar autoasignaci�n
      this->~Cola(); // vaciar la cola actual
      copiar(c);
   }
   return *this;
}

template <typename T>
inline bool Cola<T>::vacia() const
{
   return (fin == 0);
}

template <typename T>
inline T Cola<T>::frente() const
{
   assert(!vacia());
   return fin->sig->elto;
}

template <typename T>
inline void Cola<T>::pop()
{
   assert(!vacia());
   nodo *q = fin->sig;
   if (fin->sig == fin)
      fin = 0;
   else
      fin->sig = q->sig;
   delete q;
}

template <typename T>
inline void Cola<T>::push(const T &x)
{
   nodo *q = new nodo(x);
   if (fin == 0)
   {
      fin = q;
      fin->sig = q;
   }
   else
   {
      q->sig = fin->sig;
      fin->sig = q;
      fin = q;
   }
}

// Destructor: vac�a la cola
template <typename T>
Cola<T>::~Cola()
{
   nodo *q;
   while (fin != 0)
   {
      q = fin->sig;
      delete fin;
      fin = q;
   }
   fin = 0;
}
#endif // COLA_ENLACIRCU_H
