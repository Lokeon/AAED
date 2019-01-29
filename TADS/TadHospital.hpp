
#include "ListaVectorial.hpp"
#include <string>
#include <iostream>


class Paciente
{
    public:

    Paciente(std::string n , int id, int gra):n_(n),id_(id),gr_(gra){}
    std::string nombre() const { return n_ ; }
    int gravedad() const { return gr_ ; }
    bool operator == ( const Paciente& X){ return X.id_ == id_ ;}
    
    private:
    int id_,gr_;
    std::string n_ ; 
};

class Hospital
{
    public:

    explicit Hospital(size_t p,size_t u,size_t m): 
         PLANTA(Lista<Paciente>(p)) , UCI(Lista<Paciente>(u)) , MORGUE(Lista<Paciente>(m)) {}
    void hospital(const Paciente& x);
    void alta(const Paciente& x);
    void muerte();
    void UCIS() const; 
    void PLANTAS() const ; 
    void gravedad_determinada(int) const ; 
   
    ~Hospital() = default;

    private:
    
    Lista<Paciente> PLANTA;
    Lista<Paciente> UCI;
    Lista<Paciente> MORGUE;
};

void Hospital::hospital(const Paciente& p)
{
    if( (p.gravedad() > 0 && p.gravedad() < 6) && !UCI.llena())
            UCI.insertar(p,UCI.fin());
    else 
        if ((p.gravedad() > 6 && p.gravedad() <= 9) || ( UCI.llena() && p.gravedad() != 0) )
            PLANTA.insertar(p,PLANTA.fin());
        else 
            if(!MORGUE.llena() && !p.gravedad())
                MORGUE.insertar(p,MORGUE.fin());
}



void Hospital::alta(const Paciente& x)
{
    PLANTA.eliminar(PLANTA.buscar(x)) ;
}

void Hospital::UCIS() const
{
    typename Lista<Paciente>::posicion p ;

    for(p = UCI.primera() ; p != UCI.fin(); p = UCI.siguiente(p))
    {
        std::cout << "Pacientes en UCI: " << UCI.elemento(p).nombre() << std::endl ; 
    }
}

void Hospital::PLANTAS() const
{
    typename Lista<Paciente>::posicion p ;

    for(p = PLANTA.primera() ; p != PLANTA.fin(); p = PLANTA.siguiente(p))
    {
        std::cout << "Pacientes en Planta: " << PLANTA.elemento(p).nombre() << std::endl ; 
    }
}

void Hospital::muerte()
{
    typename Lista<Paciente>::posicion p ;

    for(p = MORGUE.primera() ; p != MORGUE.fin(); p = MORGUE.siguiente(p))
    {
        MORGUE.eliminar(p) ; 
    }
}

void Hospital::gravedad_determinada(int h) const
{
    typename Lista<Paciente>::posicion p ;
    typename Lista<Paciente>::posicion u ;
    typename Lista<Paciente>::posicion m ;
     
     if(h > 0 && h < 6)
     {
        for(p = PLANTA.primera() ; p != PLANTA.fin(); p = PLANTA.siguiente(p))
        {
           if(PLANTA.elemento(p).gravedad() == h)
           {
               std::cout << PLANTA.elemento(p).nombre() << std::endl ; 
           }
        }     
     }
     else
     {
         if(h >= 6 && h < 10)
         {
            for(u = UCI.primera() ; u != UCI.fin(); u = UCI.siguiente(u))
            {
                if(UCI.elemento(u).gravedad() == h)
                {
                    std::cout << UCI.elemento(u).nombre() << std::endl ; 
                }
            }    
         }
         else
         {
             if(h == 0)
             {
                for(u = UCI.primera() ; u != UCI.fin(); u = UCI.siguiente(u))
                {
                                        
                    std::cout << UCI.elemento(u).nombre() << std::endl ; 
                    
                }    
             }
         }
     }
}