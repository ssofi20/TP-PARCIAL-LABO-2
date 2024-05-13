#pragma once
#include <string>
#include "Municipio.h"
#include "Archivo.h"


class MunicipioArchivo: public Archivo
{
    public:

        ///CONTRUCTOR

        MunicipioArchivo();
        MunicipioArchivo(std::string fileName);

        ///COMPROBADORES

        bool isExist(int numeroMunicipio);
        bool isExist(std::string nombreMunicipio);

        ///METODOS DE LA CLASE
        int getCantidadRegistros(); //DEVUELVE LA CANTIDAD DE REGISTROS DEL ARCHIVO
        int buscarMunicipio(int numeroMunicipio); //BUSCA UN MUNICIPIO POR EL NUMERO
        bool guardarMunicipio(Municipio municipio); //GUARDA UN MUNICIPIO EN EL ARCHIVO
        bool guardarMunicipio(Municipio municipio, int index); //GUARDA UN REGISTRO DONDE SE INDICA
        Municipio read(int index); //LEE UN REGISTRO EN LA POSICION DADA Y RETORNA LOS DATOS
        bool eliminar(int numeroMunicipio); //ELIMINACION LOGICA DE UN REGISTRO
        bool copiaSeguridad(); //COPIA DE SEGURIDAD
        bool restaurarCopia(std::string fileName); //RESTAURA LA COPIA DE SEGURIDAD

    protected:

    private:
};

