#include <iostream>
#include "Reportes.h"

using namespace std;


void Reportes::menuReportes()
{
    int opcion;

    while (true)
    {
        system("cls");
        cout << " --------------- MENU REPORTES --------------- " << endl;
        cout << " 1. " << endl;
        cout << " 2. " << endl;
        cout << " 3. " << endl;
        cout << " 4. " << endl;
        cout << " 5. " << endl;
        cout << " --------------------------------------------- " << endl;
        cout << " 0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << " --------------------------------------------- " << endl;

        cout << endl;

        cout << " SELECCIONE UNA DE LAS OPCIONES: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                system("cls");
                //FUNCION
                break;
            case 2:
                system("cls");
                //FUNCION
                break;
            case 3:
                system("cls");
                //FUNCION
                break;
            case 4:
                system("cls");
                //FUNCION
                break;
            case 5:
                system("cls");
                //FUNCION
                break;
            case 0:
                return;
        }
    }
}
