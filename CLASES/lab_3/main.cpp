#include <iostream>
#include <fstream>
#include <string>
#include "user.cpp"
using namespace std;
int main(){
    int num_prestamo=0;
    int num_prestar;
    string mensaje;
    Bibliotecario bibli_01("001","flor","rosas","76492826","flor.rosas@gmail.com","934565248","Av. losRosales");
    Usuario user_01("01","stiven","garcia","72494158","stiven.garcia@gmail.com","976018810","Av. Aleluya");
    Usuario user_02("02","toledo","castillo","72654658","toledo.castillo@gmail.com","964964585","Av. Olvidados_de_Dios");
    Usuario users[2]={user_01, user_02};
    bibli_01.setDatos_biblio();
    users[0].rellenar_lib();
    users[1].rellenar_lib();
    cout<<users[0].getData_User();
    do{
        for(int j=0;j<5;j++){
        cout<<j<<" = "<<users[0].getData_Lib(j)<<"\n";
        }
        cout<<"que libro quiere prestar";
        cin>>num_prestar;
        bibli_01.setLibro_prestado(users[0].getData_Lib(num_prestar),num_prestamo);
        num_prestamo++;
        cout<<"quieres prestar otro libro \n";
        cin>>mensaje;
        if(mensaje=="si"){
            if(num_prestamo==5){
                num_prestamo=0;
            }
            system("cls");
        }
    }while(mensaje=="si");
    ofstream registro("registro.txt");
    if (!registro.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        return 1;
    }
    for(int i=0;i<2;i++){
        registro<<users[i].getData_User();
        for(int j=0;j<5;j++){
            registro<<users[i].getData_Lib(j)<<"\n";
        }
    }
    registro<<"biblioteca\n";
    registro<<bibli_01.getDatos_biblio()<<"\n";
    for(int i=0;i<5;i++){
        registro<<bibli_01.getLibro_prestado(i)<<"\n";
    }
    registro.close();
    return 0;
}