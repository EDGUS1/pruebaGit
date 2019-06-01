#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main(){
	int a,fila,col,i,j,x,f,c;
	srand(time(NULL));
	cout<<"Ingres el numero de filas: ";cin>>fila;
	cout<<"Ingres el numero de columnas: ";cin>>col;
	int mat[fila][col];
	f=fila-1;
	c=col-1;
	for(i=0;i<fila;i++){
		for(j=0;j<col;j++){
			mat[i][j]=rand()%100;
		}
	}
	cout<<"\nMATRIZ \n";
	for(i=0;i<fila;i++){
		for(j=0;j<col;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<"\n";
	}
	do{
		cout<<"OPCIONES\n";
		cout<<"1. Eliminar fila\n";
		cout<<"2. Eliminar columna\n";
		cout<<"0. Salir"<<endl;
		cin>>a;
		switch(a){
			case 0: break;
			case 1: cout<<"Ingrese la fila que desea eliminar: ";cin>>x;
					x--;
					for(i=0;i<f;i++){
						for(j=0;j<c+1;j++){
							if(i>=x){
								mat[i][j]=mat[i+1][j];
							}
						}
					}
					for(i=0;i<f;i++){
						for(j=0;j<c+1;j++){
							cout<<mat[i][j]<<"\t";
						}
						cout<<"\n";
					}
					f--;
					break;
			case 2:cout<<"Ingrese la columna que desea eliminar: ";cin>>x;
					x--;
					for(i=0;i<f+1;i++){
						for(j=0;j<c;j++){
							if(j>=x){
								mat[i][j]=mat[i][j+1];
							}
						}
					}
					for(i=0;i<f+1;i++){
						for(j=0;j<c;j++){
							cout<<mat[i][j]<<"\t";
						}
						cout<<"\n";
					}
					c--;
		}
	}while(a!=0);
	return 0;
}
