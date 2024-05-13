#include "Empresa.h"

Empresa::Empresa(){

    _numero = 0;
    strcpy(_nombre, "S/N");
    _cantEmpleados = 0;
    _categoria = 0;
    _municipio = 0;
    _fechaCreacion.setDia(0);
    _fechaCreacion.setMes(0);
    _fechaCreacion.setAnio(0);
    _facturacionAnual = 0;
    _estado = 0;

}


Empresa::Empresa(int numero, std::string nombre, int cantidad, int categoria, int municipio, Fecha fecha, float facturacion, bool estado)
{

    setNumeroEmpresa(numero);
    setNombreEmpresa(nombre);
    setCantidadEmpleados(cantidad);
    setCategoria(categoria);
    setMunicipioEmpresa(municipio);
    setFechaCreacion(fecha);
    setFacturacionAnual(facturacion);
    setEstado(estado);

}

///GETS

int Empresa::getNumeroEmpresa()
{
    return _numero;
}
std::string Empresa::getNombreEmpresa()
{
    return _nombre;
}
int Empresa::getCantidadEmpleados()
{
    return _cantEmpleados;
}
int Empresa::getCategoria()
{
    return _categoria;
}
int Empresa::getMunicipioEmpresa()
{
    return _municipio;
}
Fecha Empresa::getFechaCreacion()
{
    return _fechaCreacion;
}
float Empresa::getFacturacionAnual()
{
    return _facturacionAnual;
}
bool Empresa::getEstado()
{
    return _estado;
}

///SETS

void Empresa::setNumeroEmpresa(int numero)
{
    _numero = numero;
}
void Empresa::setNombreEmpresa(std::string nombre)
{
    strcpy(_nombre,nombre.c_str());
}
void Empresa::setCantidadEmpleados(int cant)
{
    _cantEmpleados = cant;
}
void Empresa::setCategoria(int cat)
{
    _categoria = cat;
}
void Empresa::setMunicipioEmpresa(int mun)
{
    _municipio = mun;
}
void Empresa::setFechaCreacion(Fecha fecha)
{
    _fechaCreacion.setDia(fecha.getDia());
    _fechaCreacion.setMes(fecha.getMes());
    _fechaCreacion.setAnio(fecha.getAnio());
}
void Empresa::setFacturacionAnual(float facturacion)
{
    _facturacionAnual = facturacion;
}
void Empresa::setEstado(bool estado)
{
    _estado = estado;
}
