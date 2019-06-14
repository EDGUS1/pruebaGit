#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main(){
	int matriz[50][2],anotados = 0,contra = 0,i,j,cont1=0,cont2=0;
	int panotado,pcontra;
	srand(time(NULL));
	for(i=0;i<50;i++){
		for(j=0;j<2;j++){
			matriz[i][j] = rand () % 5;
			}
		}
	
	for(i=0;i<50;i++){
		for(j=0;j<2;j++){
			if (j == 0){
				anotados += matriz[i][j];
				cont1++;
			}
			if (j == 1){
				contra += matriz[i][j];
				cont2++;
			}	
		}
	}
	
	cout<<"El promedio de goles anotados por la U es: "<<anotados/cont1<<endl;
	cout<<"El promedio de goles en contra por la U es: "<<contra/cont2<<endl;
	return 0;
}
