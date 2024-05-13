#include "EmpresaManager.h"
#include <iostream>


using namespace std;

Empresa EmpresaManager::crearEmpresa(Empresa empresa)
{

    Fecha fecha;
    int numero, cant, cat, mun;
    float facturacion;
    string nombre;

    while(true){

        cout << "NUMERO DE EMPRESA: ";
        cin >> numero;

        if(empresaArchivo.isExist(numero)){
            cout << "LA EMPRESA YA EXISTE, PRUEBE CON OTRO NUMERO...";
        }
        else{
            break;
        }

    }

    while (true){

        cin.ignore();
        cout << "NOMBRE DE LA EMPRESA: ";
        getline(cin,nombre);
        bool opc;

        if(empresaArchivo.isExist(nombre)){

            cout << "ESE NOMBRE DE EMPRESA YA EXISTE. ¿DESEA CARGAR OTRO O DEJAR EN BLANCO EL ESPACIO? 1-CARGAR OTRO 0-DEJAR EN BLANCO: ";
            cin >> opc;

            if(opc == false){
                nombre = "S/N";
            }
        }
        else{
            break;
        }

    }

    while (true){
         cout << "CANTIDAD DE EMPLEADOS: ";
         cin >> cant;

         if(cant <= 0){
            cout << "DEBE INGRESAR UN VALOR POSITIVO, INTENTE NUEVAMENTE...";
         }
         else{
            break;
         }
    }

    while (true){
        cout << "CATEGORIA: ";
        cin >> cat;

        if (cat < 1 || cat > 80){
            cout << "INGRESE UNA CATEGORIA VALIDA...";
        }
        else{
            break;
        }
    }

    while (true){
        cout << "NUMERO DE MUNICIPIO: ";
        cin >> mun;

        if (mun < 1 || mun > 135){
            cout << "INGRESE UN NUMERO DE MUNICIPIO VALIDO...";
        }
        else{
            break;
        }
    }

    cout << "FECHA DE CREACION: " << endl;
    fecha.cargarFecha();


    cout << "TOTAL DE FACTURACION ANUAL: "; cin >> facturacion;

    return Empresa(numero, nombre, cant, cat, mun, fecha, facturacion, true);

}


///MOSTRAR UNA EMPRESA

void EmpresaManager::show(Empresa empresa)
{
    if(empresa.getEstado()){
        cout << "NUMERO EMPRESA: " << empresa.getNumeroEmpresa() << endl;;
        cout << "NOMBRE EMPRESA: " << empresa.getNombreEmpresa() << endl;
        cout << "CANTIDAD DE EMPLEADOS: " << empresa.getCantidadEmpleados() << endl;
        cout << "CATEGORIA: " << empresa.getCategoria() << endl;
        cout << "NUMERO DE MUNICIPIO: " << empresa.getMunicipioEmpresa() << endl;
        cout << "FECHA DE CREACION: ";
        Fecha fecha = empresa.getFechaCreacion(); fecha.mostrarFecha();
        cout << "FACTURACION ANUAL: " << empresa.getFacturacionAnual() << endl;
    }
}


///AGREGAR EMPRESA: CARGAR Y GUARDAR

void EmpresaManager::agregarEmpresa()
{
    Empresa empresa;

    empresa = crearEmpresa(empresa);

    if (empresaArchivo.guardarEmpresa(empresa)){
        cout << "LA EMPRESA SE GUARDO CORRECTAMENTE" << endl;
    }
    else{
        cout << "LA EMPRESA NO SE PUDO GUARDAR" << endl;
    }
}

///LISTA UNA EMPRESA DETERMINADA

void EmpresaManager::listarEmpresa()
{
    int numero, index;
    Empresa empresa;

    cout << " INGRESE EL NUMERO DE EMPRESA QUE DESEA BUSCAR: ";
    cin >> numero;

    index = empresaArchivo.buscarEmpresa(numero);

    if (index == -1){
        cout << "LA EMPRESA NO FUE ENCONTRADA" << endl;
    }
    else{
        empresa = empresaArchivo.read(index);
        show(empresa);
        system("pause");
    }
}

///LISTAR TODAS LAS EMPRESAS

void EmpresaManager::listarEmpresas()
{

    int cantidad = empresaArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++){
        Empresa empresa = empresaArchivo.read(i);
        cout << "---------------------------" << endl;
        show(empresa);
        cout << "---------------------------" << endl;
    }
    system("pause");
}

///MODIFICAR FECHA DE CREACION

void EmpresaManager::modificarFechaCreacion()
{
    Empresa empresa;
    Fecha fecha;

    int numero, index;
    bool cambiar;

    cout << "INGRESE EL NUMERO DE EMPRESA QUE DESEA MODIFICAR: ";
    cin >> numero;

    index = empresaArchivo.buscarEmpresa(numero);

    if(index == -1)
    {
        cout << "LA EMPRESA NO FUE ENCONTRADA..." << endl;
        system("pause");
        return;
    }

    empresa = empresaArchivo.read(index);

    show(empresa);

    cout << " ¿ESTA SEGURO QUE DESE CAMBIAR LA FECHA DE CREACION?" << endl;
    cout << "   1-  SI     0- NO" << endl;
    cin >> cambiar;

    if(cambiar)
    {
        cout << "INGRESE LOS DATOS DE LA NUEVA FECHA: " << endl;

        fecha.cargarFecha();

        empresa.setFechaCreacion(fecha);

        if(empresaArchivo.guardarEmpresa(empresa, index)){
            cout << "LA FECHA FUE MODIFICADA CON EXITO" << endl;
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

///ELIMINAR REGISTRO

void EmpresaManager::eliminarRegistro()
{

    Empresa empresa;
    int numero, index;
    bool eliminar;

    cout << "INGRESE EL NUMERO DE EMPRESA QUE DESEA ELIMIAR: ";
    cin >> numero;

    index = empresaArchivo.buscarEmpresa(numero);

    empresa = empresaArchivo.read(index);

    show(empresa);

    cout << " ¿ESTA SEGURO QUE DESEA ELIMINAR ESTA EMPRESA?" << endl;
    cout << "      1- SI         0-NO " << endl;
    cin >> eliminar;

    if (eliminar){
        if(empresaArchivo.eliminar(numero)){
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

///MENU DE EMPRESAS

void EmpresaManager::menuEmpresas()
{

    int opcion;

    while(true)
    {
        system("cls");
        cout << " ------------ MENU EMPRESAS ------------ " << endl;
        cout << " 1. AGREGAR EMPRESA " << endl;
        cout << " 2. LISTAR EMPRESA POR NUMERO " << endl;
        cout << " 3. LISTAR TODAS LAS EMPRESAS " << endl;
        cout << " 4. MODIFICAR FECHA DE CREACION " << endl;
        cout << " 5. ELIMINAR REGISTRO" << endl;
        cout << " --------------------------------------- " << endl;
        cout << " 0. VOLVER AL MENU PRINCIPAl" << endl;
        cout << "---------------------------------------- " << endl;
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                system("cls");
                agregarEmpresa();
                break;
            case 2:
                system("cls");
                listarEmpresa();
                break;
            case 3:
                system("cls");
                listarEmpresas();
                break;
            case 4:
                system("cls");
                modificarFechaCreacion();
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
