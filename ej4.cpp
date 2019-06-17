#include <iostream>
#define SIZE 4
using namespace std;
struct coordenadas{
	int latitud;
	int longitud;
}puntos[SIZE];
int main(){
	int opc,i,j,min,k;
	puntos[0].latitud = 200;
	puntos[0].longitud = 300;
	puntos[1].latitud = 400;
	puntos[1].longitud = 100;
	puntos[2].latitud = 100;
	puntos[2].longitud = 400;
	puntos[3].latitud = 300;
	puntos[3].longitud = 200;
	cout<<"1. Orden que se ha obtenido"<<endl;
	cout<<"2. Orden crecientemente por su latitud"<<endl;
	cout<<"3. Orden crecientemente por su longitud"<<endl;
	cout<<"Opcion: ";
	cin>>opc;
	switch (opc){
		case 1:
			for(i=0;i<4;i++){
				cout<<"Latitud: "<<puntos[i].latitud<<endl;
				cout<<"Longitud: "<<puntos[i].longitud<<endl;
			}
			break;
		case 2:
			for(i=0;i<4;i++){
				min = puntos[i].latitud;
				for(j=i;j<4;j++){
					if(puntos[j].latitud<min){
						min = puntos[j].latitud;
						puntos[j].latitud = puntos[i].latitud;
						puntos[i].latitud = min;
						k = puntos[j].longitud;
						puntos[j].longitud = puntos[i].longitud;
						puntos[i].longitud = k;
					}
				}
			}
			for(i=0;i<4;i++){
				cout<<"Latitud: "<<puntos[i].latitud<<endl;
				cout<<"Longitud: "<<puntos[i].longitud<<endl<<endl;
			}
			break;
		case 3:
			for(i=0;i<4;i++){
				k = puntos[i].longitud;
				for(j=i;j<4;j++){
					if(puntos[j].longitud<k){
						min = puntos[j].latitud;
						puntos[j].latitud = puntos[i].latitud;
						puntos[i].latitud = min;
						k = puntos[j].longitud;
						puntos[j].longitud = puntos[i].longitud;
						puntos[i].longitud = k;
					}
				}
			}
			for(i=0;i<4;i++){
				cout<<"Latitud: "<<puntos[i].latitud<<endl;
				cout<<"Longitud: " <<puntos[i].longitud<<endl<<endl;
			}
			
	}
	return 0;
}
