#include<iostream>
using namespace std;
int main(){
	int mat[100][100],i,j,k,l;
	do{
		cout<<"ingrese el orden de la matriz: ";
		cin>>k;
		for(i = 0;i < k; i++){
			for(j = 0;j < k; j++){
				l = (i + 1)*(j + 1);
				mat[i][j] = l * l;
			}
		}
		for(i = 0;i < k; i++){
			for(j = 0;j < k; j++){
				cout<<mat[i][j]<<"\t";
			}
			cout<<endl;
		}
		system("pause");
		system("cls");
	}while(k != 100);
	return 0;
}
