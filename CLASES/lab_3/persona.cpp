#include <iostream>
#include <string>
using namespace std;
class Persona{
    protected:
    string nombre;
    string apellido;
    string dni;
    string correo;
    string telefono;
    string direccion;
    public:
    Persona(string _nombre="", string _apellido="", string _dni="", string _correo="", string _telefono="", string _direccion=""){
        nombre=_nombre;
        apellido=_apellido;
        dni=_dni;
        correo=_correo;
        telefono=_telefono;
        direccion=_direccion;
    }
    string getNombre(){
        return nombre;
    }
    void setNombre(string _nombre){
        nombre=_nombre;
    }
    string getApellido(){
        return apellido;
    }
    void setApellido(string _apellido){
        apellido=_apellido;
    }
    string getDni(){
        return dni;
    }
    void setDni(string _dni){
        dni=_dni;
    }
    string getCorreo(){
        return correo;
    }
    void setCorreo(string _correo){
        correo=_correo;
    }
    string getTelefono(){
        return telefono;
    }
    void setTelefono(string _telefono){
        telefono=_telefono;
    }
    string getDireccion(){
        return direccion;
    }
    void setDireccion(string _direccion){
        direccion=_direccion;
    }
};