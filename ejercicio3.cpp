#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main(){
	int orden,i,j,matriz[10][10],sd=0,sts=0,sti=0,sc=0,c=0,diag1=0,diag2=0;
	srand(time(NULL));
	do {
		cout<<"Ingrese el orden"<<endl;
		cin>>orden;
	}while(orden<4 && orden>10);
	
	for(i=0;i<orden;i++){
		for(j=0;j<orden;j++){
			matriz[i][j] = rand() % 20;
		}
	}
	for(i=0;i<orden;i++){
		for(j=0;j<orden;j++){
			if(i==j){
				diag1+=matriz[i][j];
			}
			if(i+j==(orden-1)){
				diag2+=matriz[i][j];
			}
			
			if(i>j){
				sts+=matriz[i][j];
			}
			if(i<j){
				sti+=matriz[i][j];
			}
			if(i==0 || j==0 || j==(orden-1) || i==(orden-1)){
				c += matriz[i][j];
			}
		}
	}
	cout<<"la suma de las diagonales es: "<<diag1+diag2<<endl;
	cout<<"la suma de los elementos de la parte triangular superior: "<<sts<<endl;
	cout<<"la suma de los elementos de la parte triangular inferior: "<<sti<<endl;
	cout<<"la suma de los elementos del contorno: "<<c<<endl;
	return 0;
}
