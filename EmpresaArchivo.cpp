#include "EmpresaArchivo.h"

EmpresaArchivo::EmpresaArchivo()
{
    _fileName = "Empresas.dat";
}

EmpresaArchivo::EmpresaArchivo(std::string fileName)
{
    _fileName = fileName;
}

///COMPROBADORES

bool EmpresaArchivo::isExist(int numeroEmpresa){

    return buscarEmpresa(numeroEmpresa) != -1;

}

bool EmpresaArchivo::isExist(std::string nombreEmpresa){

    Empresa empresa;

    if (open("rb") == false){return false;}

    while(fread(&empresa, sizeof(Empresa), 1, _pFile)){
        if (empresa.getNombreEmpresa() == nombreEmpresa){break;}
    }
    close();

    if(empresa.getNombreEmpresa() == nombreEmpresa){
        return true;
    }
    else {
        return false;
    }
}

///DEVUELVE LA CANTIDAD DE REGISTROS DEL ARCHIVO

int EmpresaArchivo::getCantidadRegistros()
{
    // BYTES TOTAL / BYTES REGISTRO

    open("rb");

    fseek(_pFile, 0, SEEK_END);

    int tam = ftell(_pFile);

    close();

    return tam / sizeof(Empresa);
}

///GUARDAR UN REGISTRO DE EMPRESA EN EL ARCHIVO

bool EmpresaArchivo::guardarEmpresa(Empresa empresa)
{
    int grabo;

    if (open("ab") == false) {return false;}

    grabo = fwrite(&empresa, sizeof(Empresa), 1, _pFile);

    close();

    return grabo;

}

///GUARDAR 1 REGISTRO EN LA POSICION DADA

bool EmpresaArchivo::guardarEmpresa(Empresa empresa, int index)
{
    int grabo;

    if(open("rb+") == false) {return false;}

    fseek(_pFile, index * sizeof(Empresa), SEEK_SET);

    grabo = fwrite(&empresa, sizeof(Empresa), 1, _pFile);

    close();

    return grabo;
}

///BUSCAR LA POSICION DE UN REGISTRO EN EL ARCHIVO POR EL NUMERO DE EMPRESA

int EmpresaArchivo::buscarEmpresa(int numeroEmpresa)
{
    Empresa empresa;
    int index = 0;

    if(open("rb") == false) {return -1;}

    while(fread(&empresa, sizeof(Empresa), 1, _pFile) == 1){
        if(empresa.getNumeroEmpresa() == numeroEmpresa){
            break;
        }
        index ++;
    }

    close();

    if (empresa.getNumeroEmpresa() == numeroEmpresa){
        return index;
    }
    else{
        return -1;
    }
}

///LEE UN REGISTRO DEL ARCHIVO EN LA POSICION DADA Y DEVUELVE LOS VALORES LEIDOS

Empresa EmpresaArchivo::read(int index)
{
    Empresa empresa;

    if (open("rb") == false){return empresa;}

    fseek(_pFile, index * sizeof(Empresa), SEEK_SET);

    fread(&empresa, sizeof(Empresa), 1, _pFile);

    close();

    return empresa;
}

///BAJA LOGICA DE UN REGISTRO

bool EmpresaArchivo::eliminar(int numeroEmpresa)
{

    Empresa empresa;
    int index;

    index = buscarEmpresa(numeroEmpresa);

    empresa = read(index);

    empresa.setEstado(false);

    return guardarEmpresa(empresa, index);

}

///REALIZA UNA COPIA DE SEGURIDAD

bool EmpresaArchivo::copiaSeguridad()
{
    Empresa empresa;

    FILE *pFileBkp;

    pFileBkp = fopen("Empresas.bkp", "wb");

    if (pFileBkp == nullptr){return false;}

    int cantRegistros = getCantidadRegistros();

    for (int i = 0; i < cantRegistros; i++)
    {
        empresa = read(i);
        fwrite(&empresa, sizeof(Empresa), 1, pFileBkp);
    }

    fclose(pFileBkp);

    return true;
}

///RESTAURA LA COPIA DE SEGURIDAD

bool EmpresaArchivo::restaurarCopia(std::string fileName)
{

    Empresa empresa;

    EmpresaArchivo archivoBKP(fileName);

    int cantidad = archivoBKP.getCantidadRegistros();

    if(open("wb") == false) {return false;}

    for (int i = 0; i < cantidad; i ++)
    {
        empresa = archivoBKP.read(i);
        fwrite(&empresa, sizeof(Empresa), 1, _pFile);
    }

    close();

    return true;

}


///ESTABLECE LOS DATOS DE INICIO

bool EmpresaArchivo::datosInicio(std::string fileName)
{

    Empresa empresa;

    EmpresaArchivo archivoInicio(fileName);

    int cantidad = archivoInicio.getCantidadRegistros();

    if(open("wb") == false) {return false;}

    for (int i = 0; i < cantidad; i ++)
    {
        empresa = archivoInicio.read(i);
        fwrite(&empresa, sizeof(Empresa), 1, _pFile);
    }

    close();

    return true;
}
