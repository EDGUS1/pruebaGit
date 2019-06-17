#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main(){
	int i,j,a;
	double total1=0,total2=0,total3=0,total4=0,min1,min2,min3,min4,max1,max2,max3,max4,matriz[300][6],igv;
	srand(time(NULL));
	cout<<"Ingrese el igv: ";
	cin>>igv;
	for(i=0;i<300;i++){
		matriz[i][0] = rand() % 10 + 1;
		matriz[i][1] = rand() % 3 + 1;
		a = matriz[i][1];
		switch (a){
			case 1: matriz[i][2] = 100;break;
			case 2: matriz[i][2] = 350;break;
			case 3: matriz[i][2] = 500;break;
		}
		matriz[i][3] = matriz[i][2] * matriz[i][0];
		matriz[i][4] = matriz[i][3] * igv;
		matriz[i][5] = matriz[i][3] + matriz[i][4];
		total1 += matriz[i][0];
		total2 += matriz[i][3];
		total4 += matriz[i][4];
		total3 += matriz[i][5];
	}
	min1 = matriz[0][0];
	min2 = matriz[0][3];
	min4 = matriz[0][4];
	min3 = matriz[0][5];
	max1 = matriz[0][0];
	max2 = matriz[0][3];
	max4 = matriz[0][4];
	max3 = matriz[0][5];
	for(i=0;i<300;i++){
		if (min1 > matriz[i][0]){
			min1 = matriz[i][0];
		}
		if (min2 > matriz[i][3]){
			min2 = matriz[i][3];
		}
		if (min4 > matriz[i][4]){
			min4 = matriz[i][4];
		}
		if (min3 > matriz[i][5]){
			min3 = matriz[i][5];
		}
		if (max1 < matriz[i][0]){
			max1 = matriz[i][0];
		}
		if (max2 < matriz[i][3]){
			max2 = matriz[i][3];
		}
		if (max4 < matriz[i][4]){
			max4 = matriz[i][4];
		}
		if (max3 < matriz[i][5]){
			max3 = matriz[i][5];
		}
	}
	cout<<"\nMinutos totales: "<<total1<<endl;
	cout<<"Costo total sin impuestos: "<<total2<<endl;
	cout<<"Impuestos totales: "<<total4<<endl;
	cout<<"Costo total con impuestos: "<<total3<<endl;
	cout<<"Promedio de minutos: "<<total1/300<<endl;
	cout<<"Promedio del costo de las llamadas: "<<total2/300<<endl;
	cout<<"Promedio de los impuestos: "<<total4/300<<endl;
	cout<<"Promedio del costo total: "<<total3/300<<endl;
	cout<<"El minimo de los minutos es: "<<min1<<endl;
	cout<<"El minimo de los costos es: "<<min2<<endl;
	cout<<"El minimo de los impuestos es: "<<min4<<endl;
	cout<<"El minimo de los costos totales es: "<<min3<<endl;
	cout<<"El maximo de los minutos es: "<<max1<<endl;
	cout<<"El maximo de los costos es: "<<max2<<endl;
	cout<<"El maximo de los impuestos es: "<<max4<<endl;
	cout<<"El maximo de los costos totales es: "<<max3<<endl;
	return 0;
}
