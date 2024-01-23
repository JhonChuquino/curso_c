// CLASE HIJA
#include <iostream>
#include <string>
#include "animal.cpp"
using namespace std;

class Gato : Animal
{
private:

    int vidas;
    string maulla;

public:
    Gato(int _vidas, string _maulla, string _familia, int _num_patas, int _num_dientes, string _cola, string _orejas)  :Animal(_familia, _num_patas, _num_dientes, _cola, _orejas)
    {
        vidas = _vidas;
        maulla = _maulla;
    }

    int getVidas()
    {
        return vidas;
    }
    void setVidas(int _vidas)
    {
        vidas = _vidas;
    }

    bool getMaulla(){
        return true;
        
    }
    void setMaulla(bool _maulla){
        maulla = _maulla;
    }

    void getDatos(){
     cout<<getFamilia();
     cout<<"EL GATO TIENE "<<getNum_patas()<<" PATAS \n";
     cout<<"EL GATO TIENE "<<getNum_dientes()<<" DIENTES \n";
     cout<<"EL GATO SI TIENE "<<getCola()<<endl;
     cout<<"EL GATO TIENE "<<getOrejas()<<" OREJAS \n";
     cout<<"EL GATO TIENE "<<getVidas()<<" VIDAS \n";
     cout<<"EL GATO "<<getMaulla();
     if(getMaulla() == 1){
            cout<<"MAULLA";
        }
        else{
            cout<<"NO MAULLA";
        }
    }
};

