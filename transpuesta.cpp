#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main(){
	int fila,col,i,j;
	srand(time(NULL));
	cout<<"ingrese el numero de filas: ";cin>>fila;
	cout<<"ingrese el numero de columnas: ";cin>>col;
	int mat[fila+col][fila+col];
	for(i=0;i<fila;i++){
		for(j=0;j<col;j++){
			mat[i][j]=rand()%100;
		}
	}
	cout<<"\n"<<"MATRIZ"<<endl;
	for(i=0;i<fila;i++){
		for(j=0;j<col;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n"<<"MATRIZ TRANSPUESTA"<<endl;
	for(i=0;i<col;i++){
		for(j=0;j<fila;j++){
			cout<<mat[j][i]<<"\t";
		}
		cout<<"\n";
	}
	return 0;
}
