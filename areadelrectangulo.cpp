#include<iostream>
using namespace std;
int area_rectangulo(int base, int altura)
{
	float area = 0;
	area = (base*altura);
	area = base*altura;
	cout << "el area del triangulo es : " ; cout << area << "m^2" ;
	return area;
}
int main()
{
	system("cls");
	int area, base, altura;
	cout << "ingrese la base y la altura " << endl;
	cin >> base; cin >> altura;
	return 0;

}