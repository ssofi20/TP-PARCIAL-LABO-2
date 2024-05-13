#include <iostream>
#include "AppManager.h"

using namespace std;

void AppManager::menuPrincipal()
{

    int opcion;

    EmpresaManager em;
    MunicipioManager mm;
    Configuracion mc;
    Reportes mr;

    while (true){

        system("cls");
        cout << " ------------- MENU PRINCIPAL ------------- " << endl;
        cout << " 1. MENU EMPRESAS " << endl;
        cout << " 2. MENU MUNICIPIOS " << endl;
        cout << " 3. REPORTES " << endl;
        cout << " 4. CONFIGURACION " << endl;
        cout << " ------------------------------------------ " << endl;
        cout << " 0. SALIR DE LA APLICACION" << endl;
        cout << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                em.menuEmpresas();
                break;
            case 2:
                mm.menuMunicipios();
                break;
            case 3:
                mr.menuReportes();
                break;
            case 4:
                mc.menuConfiguracion();
                break;
            case 0:
                return;

        }
    }
}
