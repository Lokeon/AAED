#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H
#include <cassert>
template <typename T>
class Lista
{
	struct nodo; // declaraci�n adelantada privada
  public:
	typedef nodo *posicion;					// posici�n de un elemento
	Lista();								// constructor, requiere ctor. T()
	Lista(const Lista<T> &l);				// ctor. de copia, requiere ctor. T()
	Lista<T> &operator=(const Lista<T> &l); // asignaci�n de listas
	void insertar(const T &x, posicion p);
	void eliminar(posicion p);
	T elemento(posicion p) const;	  // acceso a elto, lectura
	T &elemento(posicion p);		   // acceso a elto, lectura/escritura
	posicion buscar(const T &x) const; // T requiere operador ==
	posicion siguiente(posicion p) const;
	posicion anterior(posicion p) const;
	posicion primera() const;
	posicion fin() const; // posici�n despu�s del �ltimo
	~Lista();			  // destructor
  private:
	struct nodo
	{
		T elto;
		nodo *sig;
		nodo(T e, nodo *p = 0) : elto(e), sig(p) {}
	};

	nodo *L; // lista enlazada de nodos
};

template <typename T>
inline Lista<T>::Lista() : L(0) {}

template <typename T>
inline Lista<T>::Lista(const Lista<T> &l)
{
	copiar(l);
}

template <typename T>
Lista<T> &Lista<T>::operator=(const Lista<T> &l)
{
	if (this != &l)
	{					// evitar autoasignaci�n
		this->~Lista(); // vaciar la lista actual
		copiar(l);
	}
	return *this;
}

template <typename T>
inline void Lista<T>::insertar(const T &x, Lista<T>::posicion p)
{
	nodo *q;
	if (p == L)
		p = L = new nodo(x, p);
	else
	{
		for (q = L; q->sig != p; q = q->sig)
			;
		p = q->sig = new nodo(x, p);
	}

	// el nuevo nodo con x queda en la posici�n p
}

template <typename T>
inline void Lista<T>::eliminar(Lista<T>::posicion p)
{
	assert(p->sig != L); // p no es ?n
	nodo *q = p->sig;
	p->sig = q->sig;
	p->sig->ant = p;
	delete q;
	// el nodo siguiente queda en la posici�n p
}

template <typename T>
inline T Lista<T>::elemento(Lista<T>::posicion p) const
{
	assert(p->sig != L); // p no es ?n
	return p->sig->elto;
}

template <typename T>
inline T &Lista<T>::elemento(Lista<T>::posicion p)
{
	assert(p->sig != L); // p no es ?n
	return p->sig->elto;
}

template <typename T>
typename Lista<T>::posicion
Lista<T>::buscar(const T &x) const
{
	nodo *q = L;
	bool encontrado = false;
	while (q->sig != L && !encontrado)
		if (q->sig->elto == x)
			encontrado = true;
		else
			q = q->sig;
	return q;
}

template <typename T>
inline
	typename Lista<T>::posicion
	Lista<T>::siguiente(Lista<T>::posicion p) const
{
	assert(p->sig != L); // p no es ?n
	return p->sig;
}

template <typename T>
inline
	typename Lista<T>::posicion
	Lista<T>::anterior(Lista<T>::posicion p) const
{
	assert(p != L); // p no es la primera posici�n
	return p->ant;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const
{
	return L;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const
{
	return L->ant;
}
// Destructor: Vac�a la lista y destruye el nodo cabecera
template <typename T>
Lista<T>::~Lista()
{
	nodo *q;
	while (L->sig != L)
	{
		q = L->sig;
		L->sig = q->sig;
		delete q;
	}
	delete L;
}
#endif // LISTA_DOBLE_H
