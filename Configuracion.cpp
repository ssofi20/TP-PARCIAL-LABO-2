#include <iostream>
#include "Configuracion.h"

using namespace std;

void Configuracion::copiaSeguridadEmpresas()
{

    bool hacerCopia;

    cout << " ¿ESTA SEGURO QUE QUIERE REALIZAR UNA COPIA DE SEGURIDAD?" << endl;
    cout << "              1- SI          0- NO" << endl;
    cin >> hacerCopia;

    if(hacerCopia)
    {
        if(empresaArchivo.copiaSeguridad())
        {
            cout << "LA COPIA DE SEGURIDAD SE REALIZO CON EXITO" << endl;
        }
        else {
            cout << "NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD" << endl;
        }
    }
    else {
        cout << "NO SE REALIZO LA COPIA DE SEGURIDAD" << endl;
    }

    system("pause");

}

void Configuracion::copiaSeguridadMunicipios()
{

    bool hacerCopia;

    cout << " ¿ESTA SEGURO QUE QUIERE REALIZAR UNA COPIA DE SEGURIDAD?" << endl;
    cout << "              1- SI          0- NO" << endl;
    cin >> hacerCopia;

    if(hacerCopia)
    {
        if(municipioArchivo.copiaSeguridad())
        {
            cout << "LA COPIA DE SEGURIDAD SE REALIZO CON EXITO" << endl;
        }
        else {
            cout << "NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD" << endl;
        }
    }
    else {
        cout << "NO SE REALIZO LA COPIA DE SEGURIDAD" << endl;
    }

    system("pause");

}

void Configuracion::restaurarCopiaEmpresas()
{

    bool restaurar;

    cout << " ¿ESTA SEGURO QUE QUIERE RESTAURAR LA COPIA DE SEGURIDAD?" << endl;
    cout << "              1- SI          0- NO" << endl;
    cin >> restaurar;

    if(restaurar)
    {
        if(empresaArchivo.restaurarCopia("Empresas.bkp"))
        {
            cout << " LA COPIA SE RESTAURO CON EXITO" << endl;
        }
        else {
            cout << " NO SE PUDO RESTAURAR LA COPIA" << endl;
        }
    }
    else {
        cout << " NO SE RESTAURO LA COPIA DE SEGURIDAD" << endl;
    }

    system("pause");

}

void Configuracion::restaurarCopiaMunicipios()
{

    bool restaurar;

    cout << " ¿ESTA SEGURO QUE QUIERE RESTAURAR LA COPIA DE SEGURIDAD?" << endl;
    cout << "              1- SI          0- NO" << endl;
    cin >> restaurar;

    if(restaurar)
    {
        if(municipioArchivo.restaurarCopia("Municipios.bkp"))
        {
            cout << " LA COPIA SE RESTAURO CON EXITO" << endl;
        }
        else {
            cout << " NO SE PUDO RESTAURAR LA COPIA" << endl;
        }
    }
    else {
        cout << " NO SE RESTAURO LA COPIA DE SEGURIDAD" << endl;
    }

    system("pause");

}

void Configuracion::establecerDatosInicio()
{

    bool establecer;

    cout << " ¿ESTA SEGURO QUE QUIERE ESTABLECER LOS DATOS DE INICIO?" << endl;
    cout << "              1- SI          0- NO" << endl;
    cin >> establecer;

    if(establecer)
    {
        if(empresaArchivo.datosInicio("EmpresasInicio.dat"))
        {
            cout << " LOS DATOS FUERON ESTABLECIDOS CON EXITO" << endl;
        }
        else {
            cout << " NO SE PUDIERON ESTABLECER LOS DATOS" << endl;
        }
    }
    else {
        cout << " NO SE ESTABLECIERON LOS DATOS" << endl;
    }

    system("pause");

}

///MENU CONFIGURACION

void Configuracion::menuConfiguracion()
{
    int opcion;

    while (true)
    {
        system("cls");
        cout << " ------------ MENU CONFIGURACION ------------ " << endl;
        cout << " 1. COPIA DE SEGURIDAD DEL ARCHIVO DE EMPRESAS" << endl;
        cout << " 2. COPIA DE SEGURIDAD DEL ARCHIVO DE MUNICIPIOS" << endl;
        cout << " 3. RESTAURAR COPIA DEL ARCHIVO DE EMPRESAS" << endl;
        cout << " 4. RESTAURAR COPIA DEL ARCHIVO DE MUNICIPIOS" << endl;
        cout << " 5. ESTABLECER DATOS DE INICIO" << endl;
        cout << " -------------------------------------------- " << endl;
        cout << " 0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << " -------------------------------------------- " << endl;

        cout << endl;

        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                system("cls");
                copiaSeguridadEmpresas();
                break;
            case 2:
                system("cls");
                copiaSeguridadMunicipios();
                break;
            case 3:
                system("cls");
                restaurarCopiaEmpresas();
                break;
            case 4:
                system("cls");
                restaurarCopiaMunicipios();
                break;
            case 5:
                system("cls");
                establecerDatosInicio();
                break;
            case 0:
                return;
        }
    }
}

