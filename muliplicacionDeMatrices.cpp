#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main(){
	int fila1,col1,fila2,col2,i,j,k,a;
	srand(time(NULL));
	do{
		cout<<"ingrese el numero de filas de la primera matriz: ";cin>>fila1;
		cout<<"ingrese el numero de columnas de la primera matriz: ";cin>>col1;
		cout<<"ingrese el numero de filas de la segunda matriz: ";cin>>fila2;
		cout<<"ingrese el numero de columnas de la segunda matriz: ";cin>>col2;
		if(col1==fila2){
			a=1;
		}else{
			a=0;
			cout<<"no se puede multiplicar vuelva a ingresar los datos"<<endl;
		}
	}while(a!=1);
	int mat1[fila1][col1],mat2[fila2][col2],mat3[100][100];
	for(i=0;i<fila1;i++){
		for(j=0;j<col1;j++){
			mat1[i][j]=rand()%10;
		}
	}
	cout<<"\nMATRIZ 1\n"<<endl;
	for(i=0;i<fila1;i++){
		for(j=0;j<col1;j++){
			cout<<mat1[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<endl;
	for(i=0;i<fila2;i++){
		for(j=0;j<col2;j++){
			mat2[i][j]=rand()%10;
		}
	}
	cout<<"\nMATRIZ 2\n"<<endl;
	for(i=0;i<fila2;i++){
		for(j=0;j<col2;j++){
			cout<<mat2[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\nMULTIPLICACION DE MATRICES\n"<<endl;
	for(i=0;i<fila1;i++){
		for(j=0;j<col2;j++){
			mat3[i][j]=0;
			for(k=0;k<fila2;k++){
				mat3[i][j]=mat3[i][j]+mat1[i][k]*mat2[k][j];
			}
		}
	}
	for(i=0;i<fila1;i++){
		for(j=0;j<col2;j++){
			cout<<mat3[i][j]<<"\t";
		}
		cout<<"\n";
	}
	return 0;
}
