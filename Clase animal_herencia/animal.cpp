#include<iostream>
#include<string>

using namespace std;

class Animal{
    protected:
    string familia;
    int num_patas;
    int num_dientes;
    string cola;
    string orejas;

    public:
    Animal(string _familia, int _num_patas, int _num_dientes, string _cola, string _orejas){
        familia = _familia;
        num_patas = _num_patas;
        num_dientes = _num_dientes;
        cola = _cola;
        orejas = _orejas;
    }

    string getFamilia(){
        return familia;
    }
    void setFamilia(string _familia){
        familia = _familia;
    }

    int getNum_patas(){
        return num_patas;
    }
    void setNum_patas(int _num_patas){
        num_patas = _num_patas;
    }

    int getNum_dientes(){
        return num_dientes;
    }
    void setNum_dientes(int _num_dientes){
        num_dientes = _num_dientes;
    }

    string getCola(){
        return cola;
    }
    void setCola(string _cola){
        cola = _cola;
    }

    string getOrejas(){
        return orejas;
    }
    void setOrejas(string _orejas){
        orejas = _orejas;
    }
};
/*int main(){
    cout<<"2";
}/**/