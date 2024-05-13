#include "MunicipioArchivo.h"


///CONSTRUCTOR

MunicipioArchivo::MunicipioArchivo()
{
    _fileName = "Municipios.dat";
}

MunicipioArchivo::MunicipioArchivo(std::string fileName)
{
    _fileName = fileName;
}

///BUSCAR LA POSICION DE UN REGISTRO EN EL ARCHIVO POR EL NUMERO DE MUNICIPIO

int MunicipioArchivo::buscarMunicipio(int numeroMunicipio)
{
    Municipio municipio;
    int index = 0;

    if(open("rb") == false) {return -1;}

    while(fread(&municipio, sizeof(Municipio), 1, _pFile) == 1){
        if(municipio.getNumero() == numeroMunicipio){
            break;
        }
        index ++;
    }

    close();

    if (municipio.getNumero() == numeroMunicipio){
        return index;
    }
    else{
        return -1;
    }
}

///COMPROBADORES

bool MunicipioArchivo::isExist(int numeroMunicipio)
{
    return buscarMunicipio(numeroMunicipio) != -1;
}

bool MunicipioArchivo::isExist(std::string nombreMunicipio)
{
    Municipio municipio;

    if (open("rb") == false){return false;}

    while(fread(&municipio, sizeof(Municipio), 1, _pFile)){
        if (municipio.getNombre() == nombreMunicipio){break;}
    }

    close();

    if(municipio.getNombre() == nombreMunicipio){
        return true;
    }
    else {
        return false;
    }
}

///DEVUELVE LA CANTIDAD DE REGISTROS DEL ARCHIVO

int MunicipioArchivo::getCantidadRegistros()
{
    // BYTES TOTAL / BYTES REGISTRO

    open("rb");

    fseek(_pFile, 0, SEEK_END);

    int tam = ftell(_pFile);

    close();

    return tam / sizeof(Municipio);
}

///GUARDAR UN MUNICIPIO EN EL ARCHIVO

bool MunicipioArchivo::guardarMunicipio(Municipio municipio)
{
    int grabo;

    if (open("ab") == false) {return false;}

    grabo = fwrite(&municipio, sizeof(Municipio), 1, _pFile);

    close();

    return grabo;
}

///GUARDAR 1 REGISTRO EN LA POSICION DADA

bool MunicipioArchivo::guardarMunicipio(Municipio municipio, int index)
{
    int grabo;

    if(open("rb+") == false) {return false;}

    fseek(_pFile, index * sizeof(Municipio), SEEK_SET);

    grabo = fwrite(&municipio, sizeof(Municipio), 1, _pFile);

    close();

    return grabo;
}

///LEER UN REGISTRO EN LA POSICION DADA

Municipio MunicipioArchivo::read(int index)
{
    Municipio municipio;

    if (open("rb") == false){return municipio;}

    fseek(_pFile, index * sizeof(Municipio), SEEK_SET);

    fread(&municipio, sizeof(Municipio), 1, _pFile);

    close();

    return municipio;
}

///BAJA LOGICA DE UN REGISTRO

bool MunicipioArchivo::eliminar(int numeroMunicipio)
{

    Municipio municipio;
    int index;

    index = buscarMunicipio(numeroMunicipio);

    municipio = read(index);

    municipio.setEstado(false);

    return guardarMunicipio(municipio, index);

}

///REALIZA UNA COPIA DE SEGURIDAD

bool MunicipioArchivo::copiaSeguridad()
{
    Municipio municipio;

    FILE *pFileBkp;

    pFileBkp = fopen("Municipios.bkp", "wb");

    if (pFileBkp == nullptr){return false;}

    int cantRegistros = getCantidadRegistros();

    for (int i = 0; i < cantRegistros; i++)
    {
        municipio = read(i);
        fwrite(&municipio, sizeof(Municipio), 1, pFileBkp);
    }

    fclose(pFileBkp);

    return true;
}

///RESTAURA LA COPIA DE SEGURIDAD

bool MunicipioArchivo::restaurarCopia(std::string fileName)
{

    Municipio municipio;

    MunicipioArchivo archivoBKP(fileName);

    int cantidad = archivoBKP.getCantidadRegistros();

    if(open("wb") == false) {return false;}

    for (int i = 0; i < cantidad; i ++)
    {
        municipio = archivoBKP.read(i);
        fwrite(&municipio, sizeof(Municipio), 1, _pFile);
    }

    close();

    return true;

}

