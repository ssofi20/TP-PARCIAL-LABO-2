#include <string>
#include <iostream>
#include <cstring>
#include "Reportes.h"
#include "MunicipioManager.h"

using namespace std;

// PUNTO 1: Informar la cantidad de municipios con más de 5 empresas activas.

void Reportes::punto1()
{

    int contadorMunicipios = 0;

    MunicipioArchivo municipioArchivo;
    EmpresaArchivo empresaArchivo;
    MunicipioManager muniManager;

    int cantMunicipios = municipioArchivo.getCantidadRegistros();
    int cantEmpresas = empresaArchivo.getCantidadRegistros();

    for (int i = 0; i < cantMunicipios; i++)
    {
        int contadorEmpresas = 0;
        Municipio municipio = municipioArchivo.read(i);

        for (int j = 0; j < cantEmpresas; j++)
        {
            Empresa empresa = empresaArchivo.read(j);

            if (empresa.getEstado())
            {
                if (empresa.getMunicipioEmpresa() == municipio.getNumero())
                {
                    contadorEmpresas++;
                }
            }
        }

        if (contadorEmpresas > 5)
        {
            contadorMunicipios++;
        }
    }

    cout << "CANTIDAD DE MUNICIPIOS CON MAS DE 5 EMPRESAS: " << contadorMunicipios << endl;
    system("pause");
}



//PUNTO 2: Generar un archivo con las empresas que pertenezcan a una categoría que se ingresa por teclado.
//Cada registro del nuevo archivo debe tener el número de empresa, el nombre de la empresa y la facturación anual.

class Punto2
{
    public:

        Punto2(int numero = 0, string nombre = "S/N", float facturacion = 0)
        {
            _numeroEmpresa = numero;
            strcpy(_nombreEmpresa, nombre.c_str());
            _facturacionAnual = facturacion;
        }

        bool guardarRegistro(Punto2 registro)
        {
            FILE *pFile;

            pFile = fopen("ReportePunto2.dat", "wb");

            if (pFile == nullptr){return false;}

            int grabo = fwrite(&registro, sizeof(Punto2), 1, pFile);

            fclose(pFile);

            return grabo;
        }

        void mostrar()
        {
            cout << "NUMERO EMPRESA: " << _numeroEmpresa << endl;
            cout << "NOMBRE EMPRESA: " << _nombreEmpresa << endl;
            cout << "FACTURACION ANUAL: " << _facturacionAnual << endl;
            system("pause");
        }

    private:
        int _numeroEmpresa;
        char _nombreEmpresa[30];
        float _facturacionAnual;
};

void Reportes::punto2()
{
    int numeroCategoria;

    cout << "INGRESE EL NUMERO DE CATEGORIA: ";
    cin >> numeroCategoria;

    EmpresaArchivo empresaArchivo;

    int cantidadReg = empresaArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidadReg; i++)
    {
        Empresa empresa = empresaArchivo.read(i);

        if(empresa.getEstado())
        {
            if(empresa.getCategoria() == numeroCategoria)
            {
                Punto2 registro(empresa.getNumeroEmpresa(), empresa.getNombreEmpresa(), empresa.getFacturacionAnual());

                if(!registro.guardarRegistro(registro))
                {
                    cout << "ERROR DE ARCHIVO" << endl;
                    system("pause");
                }
            }
        }
    }

    cout << "ARCHIVO GENERADO CON EXITO!" << endl;
    system("pause");
}

void Reportes::menuReportes()
{
    int opcion;

    while (true)
    {
        system("cls");
        cout << " --------------------- MENU REPORTES --------------------- " << endl;
        cout << " 1. CANTIDAD DE MUNICIPIOS CON MAS DE 5 EMPRESAS ACTIVAS " << endl;
        cout << " 2. GENERAR ARCHIVO" << endl;
        cout << " --------------------------------------------------------- " << endl;
        cout << " 0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << " --------------------------------------------------------- " << endl;

        cout << endl;

        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                system("cls");
                punto1();
                break;
            case 2:
                system("cls");
                punto2();
                break;
            case 0:
                return;
        }
    }
}
