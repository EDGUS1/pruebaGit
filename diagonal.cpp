#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main(){
	int fila,col,i,j;
	srand(time(NULL));
	cout<<"MATRIZ CUADRADA"<<endl;
	do{
		cout<<"ingrese el numero de filas: ";cin>>fila;
		cout<<"ingrese el numero de columnas: ";cin>>col;
	}while(fila!=col);
	int mat[fila][col];
	for(i=0;i<fila;i++){//llenando matriz
		for(j=0;j<col;j++){
			mat[i][j]=rand()%100;
		}
	}
	cout<<"\n"<<"MATRIZ ORIGINAL"<<"\n\n";
	for(i=0;i<fila;i++){//imprimiendo
		for(j=0;j<col;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n"<<"DIAGONALES"<<"\n\n";
	for(i=0;i<fila;i++){//imprimiendo diagonales
		for(j=0;j<col;j++){
			if((i==j)||(i+j==fila-1)){
				cout<<mat[i][j]<<"\t";
			}else{
				cout<<"\t";
			}
		}
		cout<<"\n";
	}
	return 0;
}
