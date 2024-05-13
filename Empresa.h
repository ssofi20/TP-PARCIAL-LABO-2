#pragma once
#include <cstring>
#include <string>
#include "Fecha.h"


class Empresa
{
    public:

        Empresa();
        Empresa(int numero, std::string nombre, int cantidad, int categoria, int municipio, Fecha fecha, float facturacion, bool estado);

        ///GETS

        int getNumeroEmpresa();
        std::string getNombreEmpresa();
        int getCantidadEmpleados();
        int getCategoria();
        int getMunicipioEmpresa();
        Fecha getFechaCreacion();
        float getFacturacionAnual();
        bool getEstado();

        ///SETS

        void setNumeroEmpresa(int numero);
        void setNombreEmpresa(std::string nombre);
        void setCantidadEmpleados(int cant);
        void setCategoria(int cat);
        void setMunicipioEmpresa(int mun);
        void setFechaCreacion(Fecha fecha);
        void setFacturacionAnual(float facturacion);
        void setEstado(bool estado);

    protected:

    private:

        int _numero;
        char _nombre[30];
        int _cantEmpleados;
        int _categoria;
        int _municipio;
        Fecha _fechaCreacion;
        float _facturacionAnual;
        bool _estado;

};
