#include "MunicipioManager.h"
#include "Municipio.h"
#include <iostream>


using namespace std;

///CREAR UNA EMPRESA

Municipio MunicipioManager::crearMunicipio(Municipio municipio)
{
    int numero, seccion, cantHabitantes;
    string nombre;

    while(true)
    {
        cout << "NUMERO DE MUNICIPIO: ";
        cin >> numero;

        if(numero < 1 || numero > 135)
        {
            cout << "DEBE INGRESAR UN NUMERO DE MUNICIPIO VALIDO, INTENTE DE NUEVO..." << endl;
        }
        else if(municipioArchivo.isExist(numero))
        {
            cout << "NUMERO DE MUNICIPIO EXISTENTE, INTENTE CON OTRO..." << endl;
        }
        else{
            break;
        }
    }

    while(true)
    {
        cin.ignore();
        cout << "NOMBRE DEL MUNICIPIO: ";
        getline(cin, nombre);

        if(municipioArchivo.isExist(nombre))
        {
            cout << "NOMBRE DE EMPRESA EXISTENTE, PRUEBE CON OTRO..." << endl;
        }
        else{
            break;
        }
    }

    while(true)
    {
        cout << "SECCION: ";
        cin >> seccion;

        if(seccion < 1 || seccion > 9)
        {
            cout << "SECCION INVALIDA, INGRESE UNA SECCION VALIDA..." << endl;
        }
        else{
            break;
        }
    }

    while(true)
    {
        cout << "CANTIDAD DE HABITANTES: ";
        cin >> cantHabitantes;

        if(cantHabitantes <= 0)
        {
            cout << "CANTIDAD DE HABITANTES INVALIDA, INGRESE UNA CANTIDAD VALIDA..." << endl;
        }
        else{
            break;
        }
    }

    return Municipio(numero, nombre, seccion, cantHabitantes, true);
}

///MOSTRAR UN MUNICIPIO

void MunicipioManager::show(Municipio municipio)
{
    if(municipio.getEstado()){
        cout << "NUMERO MUNICIPIO: " << municipio.getNumero() << endl;
        cout << "NOMBRE MUNICIPIO: " << municipio.getNombre() << endl;
        cout << "SECCION: " << municipio.getSeccion() << endl;
        cout << "CANTIDAD DE HABITANTES: " << municipio.getCantHabitantes() << endl;
    }
}


///AGREGAR MUNICIPIO
void MunicipioManager::agregarMunicipio()
{
    Municipio municipio;

    municipio = crearMunicipio(municipio);

    if (municipioArchivo.guardarMunicipio(municipio)){
        cout << "EL MUNICIPIO SE GUARDO CORRECTAMENTE" << endl;
    }
    else{
        cout << "EL MUNICIPIO NO SE PUDO GUARDAR" << endl;
    }
    system("pause");
}

///LISTAR MUNICIPIO POR NUMERO
void MunicipioManager::listarMunicipio()
{
    int numero, index;
    Municipio municipio;

    cout << " INGRESE EL NUMERO DE MUNICIPIO QUE DESEA BUSCAR: ";
    cin >> numero;

    index = municipioArchivo.buscarMunicipio(numero);

    if (index == -1){
        cout << "EL MUNICIPIO NO FUE ENCONTRADO" << endl;
    }
    else{
        municipio = municipioArchivo.read(index);
        show(municipio);
        system("pause");
    }
}

///LISTAR TODOS LOS MUNICIPIOS
void MunicipioManager::listarMunicipios()
{
    int cantidad = municipioArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++){
        Municipio municipio = municipioArchivo.read(i);
        cout << "---------------------------" << endl;
        show(municipio);
        cout << "---------------------------" << endl;
    }
    system("pause");
}

///MODIFICAR LA CANTIDAD DE HABITANTES DE UN MUNICIPIO
void MunicipioManager::modificarCantHabitantes()
{
    Municipio municipio;

    int numero, index, cantHabitantes;
    bool cambiar;

    cout << "INGRESE EL NUMERO DEL MUNICIPIO QUE DESEA MODIFICAR: ";
    cin >> numero;

    index = municipioArchivo.buscarMunicipio(numero);

    if(index == -1)
    {
        cout << "EL MUNICIPIO NO FUE ENCONTRADO..." << endl;
        system("pause");
        return;
    }

    municipio = municipioArchivo.read(index);

    show(municipio);

    cout << " ¿ESTA SEGURO QUE DESE CAMBIAR LA CANTIDAD DE HABITANTES?" << endl;
    cout << "   1-  SI     0- NO" << endl;
    cin >> cambiar;

    if(cambiar)
    {
        cout << "INGRESE LA NUEVA CANTIDAD DE HABITANTES: " << endl;
        cin >> cantHabitantes;

        municipio.setCantHabitantes(cantHabitantes);

        if(municipioArchivo.guardarMunicipio(municipio, index)){
            cout << "LA CANTIDAD DE HABITANTES FUE MODIFICADA CON EXITO" << endl;
            system("pause");
        }
        else{
            cout << "LA FECHA NO PUDO SER MODIFICADA" << endl;
            system("pause");
        }
    }
    else{
        cout << "LA FECHA DE CREACION NO FUE MODIFICADA" << endl;
        system("pause");
    }
}

///ELIMINAR UN REGISTRO (BAJA LOGICA)
void MunicipioManager::eliminarRegistro()
{
    Municipio municipio;
    int numero, index;
    bool eliminar;

    cout << "INGRESE EL NUMERO DE MUNICIPIO QUE DESEA ELIMIAR: ";
    cin >> numero;

    index = municipioArchivo.buscarMunicipio(numero);

    municipio = municipioArchivo.read(index);

    show(municipio);

    cout << " ¿ESTA SEGURO QUE DESEA ELIMINAR ESTE MUNICIPIO?" << endl;
    cout << "      1- SI         0-NO " << endl;
    cin >> eliminar;

    if (eliminar){
        if(municipioArchivo.eliminar(numero)){
           cout << "LA EMPRESA FUE ELIMINADA" << endl;
        }
        else{
            cout << "LA EMPRESA NO PUDO SER ELIMINADA" << endl;
        }
        system("pause");
    }
    else {
        cout << "LA EMPRESA NO FUE ELIMINADA" << endl;
        system("pause");
    }
}


void MunicipioManager::menuMunicipios()
{
    int opcion;

    while(true)
    {
        system("cls");
        cout << " ------------ MENU MUNICIPIOS ------------ " << endl;
        cout << " 1. AGREGAR MUNICIPIO " << endl;
        cout << " 2. LISTAR MUNICIPIO POR NUMERO " << endl;
        cout << " 3. LISTAR TODOS LOS MUNICIPIOS " << endl;
        cout << " 4. MODIFICAR CANTIDAD DE HABITANTES " << endl;
        cout << " 5. ELIMINAR REGISTRO" << endl;
        cout << " ----------------------------------------- " << endl;
        cout << " 0. VOLVER AL MENU PRINCIPAl" << endl;
        cout << " ----------------------------------------- " << endl;
        cout << endl;
        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                system("cls");
                agregarMunicipio();
                break;
            case 2:
                system("cls");
                listarMunicipio();
                break;
            case 3:
                system("cls");
                listarMunicipios();
                break;
            case 4:
                system("cls");
                modificarCantHabitantes();
                break;
            case 5:
                system("cls");
                eliminarRegistro();
                break;
            case 0:
                return;
        }
    }
}
