#pragma once
#include <string>
#include "Empresa.h"
#include "Archivo.h"


class EmpresaArchivo: public Archivo
{
    public:

        ///CONSTRUCTORES

        EmpresaArchivo();
        EmpresaArchivo(std::string fileName);

        ///COMPROBADORES

        bool isExist(int numeroEmpresa);
        bool isExist(std::string nombreEmpresa);

        ///METODOS DE LA CLASE

        int getCantidadRegistros(); //DEVUELVE LA CANTIDAD DE REGISTROS DEL ARCHIVO
        bool guardarEmpresa(Empresa empresa); //GUARDA LA EMPRESA EN EL ARCHIVO
        bool guardarEmpresa(Empresa empresa, int index); //GUARDA LA EMPRESA EN EL ARCHIVO EN LA POSICION DADA
        int buscarEmpresa(int numeroEmpresa);  //BUSCA LA POSICION DEL NUMERO REFERENCIAL DADO Y LA RETORNA
        Empresa read(int index); //LEE EL ARCHIVO EN LA POSICION DADA
        bool eliminar(int numeroEmpresa); //BAJA LOGICA
        bool copiaSeguridad(); //COPIA DE SEGURIDAD
        bool restaurarCopia(std::string fileName); //RESTAURA LA COPIA DE SEGURIDAD
        bool datosInicio(std::string fileName); //ESTABLECE LOS DATOS DE INICIO QUE CONTIENE EL ARCHIVO DADO COMO PARAMETRO


    protected:

    private:
};
