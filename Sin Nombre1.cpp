#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main(){
	
	int a[100][100],x,y;
	
	srand(time(NULL));
	
	for(int i=0;i<10;i++){//ingrese
		for(int j=0;j<5;j++){
			a[i][j]=rand()%100000;//cin>>a[i[j;
		}
	}
	
	for(int i=0;i<10;i++){//imprime
		for(int j=0;j<5;j++){
			cout<<a[i][j]<<" \t";
		}
		cout<<endl;
	}
	
/*	cout<<"ingrese la fila a eliminar: ";cin>>x;
	x--;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			if(x<=i){
				a[i][j]=a[i+1][j];
			}
		}
	}
	for(int i=0;i<2;i++){//imprime
		for(int j=0;j<3;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	cout<<"............................"<<endl;
	for(int i=0;i<10;i++){//imprime
		for(int j=0;j<5;j++){
			if(i==0 || i==9 || j==0 || j==4){
				cout<<a[i][j]<<" \t";
			}else{
				cout<<"\t ";
			}
		}
		cout<<endl;
	}
	return 0;
}
