#pragma once


class Fecha
{
    public:

        void cargarFecha();
        void mostrarFecha();

        ///GETS

        int getDia(){return _dia;}
        int getMes(){return _mes;}
        int getAnio(){return _anio;}

        ///SETS

        void setDia(int d){_dia = d;}
        void setMes(int m){_mes = m;}
        void setAnio(int a){_anio = a;}

    private:
        int _dia, _mes, _anio;
};
