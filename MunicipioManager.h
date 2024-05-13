#pragma once
#include "Municipio.h"
#include "MunicipioArchivo.h"


class MunicipioManager
{
    public:
        void menuMunicipios();
        Municipio crearMunicipio(Municipio municipio);
        void show(Municipio municipio);

    private:


        MunicipioArchivo municipioArchivo;

        ///FUNCIONES MENU
        void agregarMunicipio();
        void listarMunicipio();
        void listarMunicipios();
        void modificarCantHabitantes();
        void eliminarRegistro();
};
