#include<iostream>
#include<string>

using namespace std;

class Investigador{
    private:
    string codigo;
    string especialidad;
    string libros_pub;

    public:
    Investigador(string _codigo = "", string _especialidad = "", string _libros_pub = ""){
        codigo = _codigo;
        especialidad = _especialidad;
        libros_pub = _libros_pub;
    }

    string getCodigo(){
        return codigo;
    }
    void setCodigo(string _codigo){
        codigo = _codigo;
    }

    string getEspecialidad(){
        return especialidad;
    }
    void setEspecialidad(int _especialidad){
        especialidad = _especialidad;
    }

    string getLibros_pub(){
        return libros_pub;
    }
    void setFacultad(string _libros_pub){
        libros_pub = _libros_pub;
    }

    void setDatosInvestigador(string _codigo = "", string _especialidad = "", string _libros_pub = ""){
        codigo = _codigo;
        especialidad = _especialidad;
        libros_pub = _libros_pub;
    }
    

    string getDatosInvestigador(){
        return "codigo: " + codigo + " numero de especialidad ---> " + especialidad + "libros_pub: " + libros_pub;
    }
};
