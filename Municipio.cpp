#include "Municipio.h"

Municipio::Municipio()
{
    _numero = 0;
    strcpy(_nombre, " ");
    _seccion = 0;
    _cantHabitantes = 0;
    _estado = true;

}

Municipio::Municipio(int numero, std::string nombre, int seccion, int cantHabitantes, bool estado)
{
    setNumero(numero);
    setNombre(nombre);
    setSeccion(seccion);
    setCantHabitantes(cantHabitantes);
    setEstado(estado);
}

///SETTERS

void Municipio::setNumero(int numero)
{
    _numero = numero;
}
void Municipio::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}
void Municipio::setSeccion(int seccion)
{
    _seccion = seccion;
}
void Municipio::setCantHabitantes(int cantHabitantes)
{
    _cantHabitantes = cantHabitantes;
}
void Municipio::setEstado(bool estado)
{
    _estado = estado;
}

///GETTERS

int Municipio::getNumero()
{
    return _numero;
}
std::string Municipio::getNombre()
{
    return _nombre;
}
int Municipio::getSeccion()
{
    return _seccion;
}
int Municipio::getCantHabitantes()
{
    return _cantHabitantes;
}
bool Municipio::getEstado()
{
    return _estado;
}
