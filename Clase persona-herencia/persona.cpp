#include<iostream>
using namespace std;

class Persona{
    private:
    string apellido;
    string nombres;
    //string direccion;
    //string correo;
    string dni;

    public:
    Persona(string _apellido, string _nombres, string _dni){
        apellido = _apellido;
        nombres = _nombres;
        //direccion = _direccion;
        //correo = _correo;
        dni = _dni;
    }

    string getNombres(){
        return nombres;
    }
    void setNombres(string _nombres){
        nombres = _nombres;
    }

    string getApellido(){
        return apellido;
    }
    void setApellido(string _apellido){
        apellido = _apellido;
    }

    string getDni(){
        return dni;
    }
    void setDni(string _dni){
        dni = _dni;
    }  
};

//int main(){

    //Persona persona_1("jhon", "Chuquino Sifuentes", "123456");

    //cout<<"el nombres y apellido de la persona es: \n";
    //cout<<persona_1.getNombres();
    //cout<<persona_1.getApellido();
    //return 0;

//}