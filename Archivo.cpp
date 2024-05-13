#include "Archivo.h"

bool Archivo::open(std::string modoApbertura)
{

    _pFile = fopen(_fileName.c_str(), modoApbertura.c_str());

    if(_pFile == nullptr){
        return false;
    }
    else {
        return true;
    }

}
void Archivo::close()
{
    fclose(_pFile);
}
