#pragma once

#include "EmpresaArchivo.h"
#include "MunicipioArchivo.h"

class Configuracion
{
    public:
        void menuConfiguracion();

    protected:

    private:

        EmpresaArchivo empresaArchivo;
        MunicipioArchivo municipioArchivo;

        void copiaSeguridadEmpresas();
        void copiaSeguridadMunicipios();
        void restaurarCopiaEmpresas();
        void restaurarCopiaMunicipios();
        void establecerDatosInicio();
};

