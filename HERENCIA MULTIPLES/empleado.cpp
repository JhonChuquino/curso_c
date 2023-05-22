#include <iostream>
#include <string>

using namespace std;

class Empleado{
    private:
     string puesto;
     float salario;
    public:
    Empleado(string _puesto ="", float _salario=0){
        puesto = _puesto;
        salario = _salario;
    }

    void setSalario(float _salario){
        salario = _salario;
    }

    string getDataEmpleado(){
        return "puesto : " + puesto + ",  salario: " + to_string(salario);
    }
};