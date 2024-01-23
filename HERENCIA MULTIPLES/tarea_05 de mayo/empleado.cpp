//implemente una clase empleado que herede de persona, los atributos de empleado son puesto, 
//sueldo y antiguedad.
#include<iostream>
#include<string>

#include "persona.cpp"
using namespace std;

class Empleado : public Persona
{
    protected:
    string puesto;
    string sueldo;
    string antiguedad;

    public:
    Empleado(string _nombres =  "", string _apellidos = "", string _dni = "", string _fecha_naci= "", int _edad = 0,string _puesto = "", string _sueldo = "", string _antiguedad = "") :Persona(_nombres, _apellidos, _dni , _fecha_naci, _edad)
    {
        puesto = _puesto;
        sueldo = _sueldo;
        antiguedad = _antiguedad;
    }

    string getPuesto(){
        return puesto;
    }
    void setPuesto(string _puesto){
        puesto = _puesto;
    }

    string getSueldo(){
        return sueldo;
    }
    void setSueldo(string _sueldo){
        sueldo = _sueldo;
    }

    string getAntiguedad(){
        return antiguedad;
    }
    void setAntiguedad(string _antiguedad){
        antiguedad = _antiguedad;
    }
    
    string toString(){
        string resumen = "|| Nombre: " + nombres + ",  || Apellidos: " + apellidos + ", || Dni: " + dni + ", || Fecha de nacimiento: " + fecha_naci + " , || Edad: " + to_string(edad) + " \n"+ "|| Puesto de trabajo: " + puesto + ", || Sueldo : $" + sueldo + ", || Antiguedad " + antiguedad;
        return resumen;
    }

};