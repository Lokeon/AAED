#ifndef COLA_CIR_H
#define COLA_CIR_H
#include <cassert>

using namespace std ; 

template <typename T> class Cola {
public:

explicit Cola(size_t TamaMax); // constructor
Cola(const Cola<T>& c); // ctor. de copia
Cola<T>& operator =(const Cola<T>& c); // asignación de colas
bool vacia() const;
bool llena() const; // Requerida por la implementación
T frente() const;
void pop();
void push(const T& x);
~Cola(); // destructor

private:

T *elementos; // vector de elementos
int Lmax; // tamaño del vector
int inicio, fin; // posiciones de los extremos de la cola
};


template <typename T>
Cola<T>::Cola(size_t TamaMax) :
elementos(new T[TamaMax + 1]), // +1 para detectar cola llena
Lmax(TamaMax + 1),
inicio(0),
fin(TamaMax)
{}


template <typename T>
Cola<T>::Cola(const Cola<T>& c) :
elementos(new T[c.Lmax]),
Lmax(c.Lmax),
inicio(c.inicio),
fin(c.fin)
{
if (!c.vacia()) // Copiar el vector
for (int i = inicio; i != (fin + 1) % Lmax;
i = (i + 1) % Lmax)
elementos[i] = c.elementos[i];
}


template <typename T>
Cola<T>& Cola<T>::operator =(const Cola<T>& c)
{
if (this != &c) { // evitar autoasignación
// Destruir el vector y crear uno nuevo si es necesario
if (Lmax != c.Lmax) {
delete[] elementos;
Lmax = c.Lmax;
elementos = new T[Lmax];
}
// Copiar el vector
inicio = c.inicio;
fin = c.fin;
if (!c.vacia())
for (int i = inicio; i != (fin + 1) % Lmax;
i = (i + 1) % Lmax)
elementos[i] = c.elementos[i];
}
return *this;
}


template <typename T>
inline bool Cola<T>::vacia() const
{
return ((fin + 1) % Lmax == inicio);
}


template <typename T>
inline bool Cola<T>::llena() const
{
return ((fin + 2) % Lmax == inicio);
}


template <typename T>
inline T Cola<T>::frente() const
{
assert(!vacia());
return elementos[inicio];
}


template <typename T>
inline void Cola<T>::pop()
{
assert(!vacia());
inicio = (inicio + 1) % Lmax;
}


template <typename T>
inline void Cola<T>::push(const T& x)
{
assert(!llena());
fin = (fin + 1) % Lmax;
elementos[fin] = x;
}


template <typename T>
inline Cola<T>::~Cola()
{
delete[] elementos;
}


 #endif // COLA_CIR_H
