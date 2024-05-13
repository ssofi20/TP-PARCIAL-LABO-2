#pragma once
#include "Empresa.h"
#include "EmpresaArchivo.h"


class EmpresaManager
{
    public:

        Empresa crearEmpresa(Empresa empresa);
        void show(Empresa empresa);
        void menuEmpresas();


    private:

        EmpresaArchivo empresaArchivo;

        ///FUNCIONES MENU

        void agregarEmpresa();
        void listarEmpresa();
        void listarEmpresas();
        void modificarFechaCreacion();
        void eliminarRegistro();
};
