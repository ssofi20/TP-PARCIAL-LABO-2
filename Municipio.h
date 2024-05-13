#pragma once
#include <cstring>
#include <string>


class Municipio
{
    public:

        Municipio();
        Municipio(int numero, std::string nombre, int seccion, int cantHabitantes, bool estado);

        ///SETTERS

        void setNumero(int numero);
        void setNombre(std::string nombre);
        void setSeccion(int seccion);
        void setCantHabitantes(int cantHabitantes);
        void setEstado(bool estado);

        ///GETTERS

        int getNumero();
        std::string getNombre();
        int getSeccion();
        int getCantHabitantes();
        bool getEstado();

    protected:

    private:

        int _numero;
        char _nombre[30];
        int _seccion;
        int _cantHabitantes;
        bool _estado;
};
