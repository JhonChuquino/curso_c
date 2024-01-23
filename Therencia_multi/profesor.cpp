#include<iostream>
#include<string>

using namespace std;

class Profesor{
    private:
    string nombre;
    string dni;
    string facultad;

    public:
    Profesor(string _nombre = "", string _dni = "", string _facultad = ""){
        nombre = _nombre;
        dni = _dni;
        facultad = _facultad;
    }

    string getNombre(){
        return nombre;
    }
    void setNombre(string _nombre){
        nombre = _nombre;
    }

    string getDni(){
        return dni;
    }
    void setDni(string _dni){
        dni = _dni;
    }

    string getFacultad(){
        return facultad;
    }
    void setFacultad(string _facultad){
        facultad = _facultad;
    }

    /*void setDatosProfesor(string _nombre = "", string _dni = "", string _facultad = ""){
        nombre = _nombre;
        dni = _dni;
        facultad = _facultad;

    }*/

    string getDataProfesor(){
        return "nombre: " + nombre + " ----> numero de dni ---> " + dni + " -----> facultad: " + facultad;
    }
};

