#include<iostream>
#include<string>

//#include "murcielago.cpp"
#include "gato.cpp"


using namespace std;

int main()
{
    system("cls");

   //OBJETO GATO DE LA CLASE GATO

   Gato gato_1(7,1,1,"felino","azules",4,"pequenias","blancos",1);
   gato_1.funciones_gato();
   gato_1.funciones_animal();
   cout<<gato_1.getvidas();
   
}