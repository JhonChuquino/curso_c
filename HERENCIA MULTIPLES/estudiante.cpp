#include <iostream>
#include <string>

using namespace std;

class Estudiante {
    private:
     string codigo;
     string carrera;
    public: 
    Estudiante(string _codigo = "", string _carrera =""){
        codigo = _codigo;
        carrera = _carrera;
    }

    void setEstudiante(string _codigo, string _carrera){
        codigo = _codigo;
        carrera = _carrera;
    }

    string getDataEstudiante(){
        return "codigo de estudiante: " + codigo + ", carrera: " + carrera;
    }
};