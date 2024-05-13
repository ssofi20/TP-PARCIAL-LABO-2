#include "Fecha.h"

#include <iostream>

using namespace std;

void Fecha::cargarFecha()
{
    int dia, mes, anio;

    while (true){
        cout << "DIA: ";
        cin >> dia;

        if (dia < 1 || dia > 31){
            cout << "INGRESE UN DIA VALIDO...";
        }
        else {
            _dia = dia;
            break;
        }
    }

    while (true){
        cout << "MES: ";
        cin >> mes;

        if (mes < 1 || mes > 12){
            cout << "INGRESE UN MES VALIDO...";
        }
        else{
            _mes = mes;
            break;
        }
    }

    while (true){
        cout << "ANIO: ";
        cin >> anio;

        if(anio < 1800 || anio > 2024){
            cout << "INGRESE UN ANIO VALIDO...";
        }
        else{
            _anio = anio;
            break;
        }
    }
}

void Fecha::mostrarFecha()
{

     cout << _dia << "/" << _mes << "/" << _anio << endl;

}
