#include<iostream>
using namespace std;
float calcular_prom(float not1, float not2, float not3)
{
	float prom = 0;
	prom = ( not1 + not2 + not3 )/3;
	return prom;
}
int main(){
	float not1 = 0, not2 = 0, not3 = 0;
	float prom = 0;
	cout << "ingrese sus notas " << endl;
	cin >> not1 ;
	cin >> not2 ;
	cin >> not3 ;
	system("cls");
	prom = calcular_prom( not1, not2, not3);
	if(prom >=10.5){
		cout << " USTED APROBO CON :  " ; cout<< prom;
	}else {
		cout << "USTED DESAPROBO CON : " ; cout << prom;
	}
	return 0;
}