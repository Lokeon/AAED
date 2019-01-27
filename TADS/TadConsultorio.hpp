#ifndef Consult_HPP
#define Consult_HPP

#include <string>
#include <iostream>
#include "./Lista/ListaDoEnlaCabe.hpp"
#include "./Cola/ColaDinamica.hpp"

class Paciente
{
  public:
    Paciente() = default;
    Paciente(std::string n, int id) : nombre_(n), id_(id) {}
    ~Paciente() = default;
    // Pruebas
    const int idPaciente() const { return id_; }
    const std::string nombrePaciente() const { return nombre_; }

  private:
    std::string nombre_;
    int id_;
};

class Medico
{
  public:
    Medico() = default;
    Medico(std::string n, int id) : nombre_(n), id_(id) {}
    const Cola<Paciente> colaPaciente() const { return cola_; }
    Cola<Paciente> metercolaPaciente() { return cola_; }

    ~Medico() = default;
    // Pruebas
    const int idMedico() const { return id_; }
    const std::string nombreMedico() const { return nombre_; }

  private:
    Cola<Paciente> cola_;
    std::string nombre_;
    int id_;
};

class Consultorio
{
  public:
    Consultorio() = default;
    void altaMedico(const Medico &medico);
    void bajaMedico(const Medico &medico);
    void esperaPaciente(const Paciente &paciente, const Medico &medico);
    void atenderPaciente(const Medico &medico);
    Paciente turnoPaciente(const Medico &medico);
    bool tienePaciente(const Medico &medico);
    ~Consultorio() = default;
    // Pruebas
    Lista<Medico> lista() const { return lista_; }
    void consultaMedico(const Medico &medico);
    void consultaPaciente(const Medico &medico);

  private:
    Lista<Medico> lista_;
};

void Consultorio::altaMedico(const Medico &medico)
{
    lista_.insertar(medico, lista_.fin());
}

void Consultorio::bajaMedico(const Medico &medico)
{
    lista_.eliminar(lista_.buscar(medico));
}

void Consultorio::esperaPaciente(const Paciente &paciente, const Medico &medico)
{
    lista_.elemento(lista_.buscar(medico)).metercolaPaciente().push(paciente);
}

void Consultorio::atenderPaciente(const Medico &medico)
{
    lista_.elemento(lista_.buscar(medico)).metercolaPaciente().pop();
}

Paciente Consultorio::turnoPaciente(const Medico &medico)
{
    return lista_.elemento(lista_.buscar(medico)).colaPaciente().frente();
}

bool Consultorio::tienePaciente(const Medico &medico)
{
    return lista_.elemento(lista_.buscar(medico)).colaPaciente().vacia();
}

// Pruebas
void Consultorio::consultaMedico(const Medico &medico)
{
    std::cout << "Id Medico:" << lista_.elemento(lista_.buscar(medico)).idMedico() << " "
              << "Nombre Medico:" << lista_.elemento(lista_.buscar(medico)).nombreMedico()
              << std::endl;
}

void Consultorio::consultaPaciente(const Medico &medico)
{
    std::cout << "Id Paciente:" << lista_.elemento(lista_.buscar(medico)).colaPaciente().frente().idPaciente()
              << "Nombre Paciente:" << lista_.elemento(lista_.buscar(medico)).colaPaciente().frente().nombrePaciente()
              << std::endl;
}

// Sobrecarga para la busqueda de la Lista
bool operator==(const Medico &medico, const Medico &medico2)
{
    return (medico2.idMedico() == medico.idMedico());
}

#endif