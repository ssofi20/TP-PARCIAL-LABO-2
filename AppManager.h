#pragma once
#include "MunicipioManager.h"
#include "EmpresaManager.h"
#include "Reportes.h"
#include "Configuracion.h"


class AppManager
{
    public:

        void menuPrincipal();

    protected:

    private:

        EmpresaManager me;
        MunicipioManager mm;
        Configuracion mc;
        Reportes mr;

};

