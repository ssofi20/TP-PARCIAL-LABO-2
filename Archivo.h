#pragma once
#include <string>


class Archivo
{
    public:

        FILE *_pFile;
        std::string _fileName;

        bool open(std::string modoApbertura);
        void close();

    protected:

    private:

};
