#include <stdio.h> // Para el manejo de archivos
#include <string.h> // Para el manejo de cadenas
#include <conio.h> // Para el manejo de clrscr
#include <iostream> // Para el manejo de cout
#include <ctype.h> // Para el uso de toupper
struct tipo_registro
{
int no_prod;
char descrip[30];
int cantidad;
float precio;
char garantia;
};
struct tipo_registro Registro;
FILE *alias;
using namespace std;

void ALTA_SECUENCIAL(void);
void CONSULTA_SECUENCIAL(void);
void LISTADO_SECUENCIAL(void);
void MODIFICACION_SECUENCIAL(void);
void BAJA_LOGICA_SECUENCIAL(void);
void BAJA_FISICA_SECUENCIAL(void);

int main(int argc, char** argv) {
	int op;
  	do
  	{
    	 system("cls");
     	
		cout<<"\n\n\n\r\tMENU PRINCIPAL";
     	cout << "\t\n\n\n\r\t 1.- Altas secuencial";
     	cout << "\t\n\r\t 2.- Consultas secuencial";
     	cout << "\t\n\r\t 3.- Modificaciones secuencial";
     	cout << "\t\n\r\t 4.- Bajas logicas secuencial";
     	cout << "\t\n\r\t 5.- Listado secuencial";
     	cout << "\t\n\r\t 6.- Bajas secuencial ";
     	cout << "\t\n\r\t 0.- Salir";

     	cout << "\n\n\n\r Seleccione su opcion ---> ";
	     cin >> op;

	     switch(op)
    	 {
              case 1 : ALTA_SECUENCIAL();break;
              case 2 : CONSULTA_SECUENCIAL();break;
              case 3 : MODIFICACION_SECUENCIAL();break;
              case 4 : BAJA_LOGICA_SECUENCIAL();break;
              case 5 : LISTADO_SECUENCIAL();break;
              case 6 : BAJA_FISICA_SECUENCIAL();break;
     	}
		
	}while(op!=0);
	return 0;
}

void ALTA_SECUENCIAL(void)
{
int no_prod; // Variable local para el numero de producto
// 	OJO  NO FUNCIONA clrscr();
cout << "\n\rALTAS DE REGISTROS DE PRODUCTOS";
alias=fopen("PRODUCTO.SEC","rb+"); // Intenta abrir el archivo
// en modo de lectura/escritura
if(alias==NULL)
alias=fopen("PRODUCTO.SEC","wb"); // Crea el archivo en caso de no
// existir
cout << "\n\n\n\rNumero de producto: "; cin >> no_prod;
fread(&Registro,sizeof(Registro),1,alias);
// Lee el "Registro", de tamano=sizeof(Registro) del archivo "alias"
while(!feof(alias)) // Ciclo mientras no se encuentre el final del
// archivo
{
if(Registro.no_prod==no_prod)
{
cout << "\n\n\n\rRegistro duplicado !!!";
fclose(alias);
getch();
return;
}
fread(&Registro,sizeof(Registro),1,alias);
}
fflush(stdin);
cout << "\n\rDescripcion: "; gets(Registro.descrip);
cout << "\n\rCantidad : "; cin >> Registro.cantidad;
cout << "\n\rPrecio : "; cin >> Registro.precio;
do
{
cout << "\n\rGarantia : "; Registro.garantia=toupper(getche());
}while(Registro.garantia!='S' && Registro.garantia!='N');
Registro.no_prod=no_prod;
fwrite(&Registro,sizeof(Registro),1,alias); // Grabar el Registro
fclose(alias); // Cierra el archivo
cout << "\n\n\n\rProducto registrado !!!";
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
void CONSULTA_SECUENCIAL(void)
{
int no_prod;
//clrscr();
cout << "\n\rCONSULTA DE REGISTROS DE PRODUCTOS";
alias=fopen("PRODUCTO.SEC","rb"); // Intenta abrir el archivo PRODUCTO.SEC
// en modo de solo lectura
if(alias==NULL)
{
cout << "\n\n\n\rNo existe el archivo !!!";
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
cout << "\n\n\n\rNumero de producto: "; cin >> no_prod;
fread(&Registro,sizeof(Registro),1,alias);
// Lee el "Registro", de tamano=sizeof(Registro) del archivo "alias"
while(!feof(alias))
{
if(Registro.no_prod==no_prod)
{
cout << "\n\rNo Prod Descripcion Cantidad Precio Garantia";
cout << "\n\r------------------------------------------------------------------------";
printf("\n\r%3d\t%30s\t%3d\t\t$%4.2f\t%c",Registro.no_prod,Registro.descrip,
Registro.cantidad,Registro.precio,Registro.garantia);
fclose(alias);
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
fread(&Registro,sizeof(Registro),1,alias);
}
cout << "\n\rNo se encuentra ese registro !!!";
fclose(alias); // Cierra el archivo
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
void LISTADO_SECUENCIAL(void)
{
//clrscr();
cout << "\n\rLISTADO DE REGISTROS DE PRODUCTOS";
alias=fopen("PRODUCTO.SEC","rb"); // Intenta abrir el archivo PRODUCTO.SEC
// en modo de solo lectura
if(alias==NULL)
{
cout << "\n\n\n\rNo existe el archivo !!!";
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
cout << "\n\rNo Prod Descripcion Cantidad Precio Garantia";
cout << "\n\r------------------------------------------------------------------------";
fread(&Registro,sizeof(Registro),1,alias);
// Lee el "Registro", de tamano=sizeof(Registro) del archivo "alias"
while(!feof(alias)) // Ciclo mientras no se encuentre el final delarchivo
{
printf("\n\r%3d\t%30s\t%3d\t\t$%4.2f\t%c",Registro.no_prod,Registro.descrip,
Registro.cantidad,Registro.precio,Registro.garantia);
fread(&Registro,sizeof(Registro),1,alias);
}
fclose(alias); // Cierra el archivo
cout << "\n\r------------------------------------------------------------------------";
cout << "\n\rFin del listado !!!";
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
void MODIFICACION_SECUENCIAL(void)
{
int no_prod; // Variable local para el numero de producto que desea modificar
//clrscr();
cout << "\n\rMODIFICACION DE REGISTROS DE PRODUCTOS";
alias=fopen("PRODUCTO.SEC","rb+"); // Intenta abrir el archivo PRODUCTO.SEC
// en modo de lectura/escritura
if(alias==NULL) // Valida la existencia del archivo
{
cout << "\n\n\n\rNo existe el archivo !!!";
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
cout << "\n\n\n\rNumero de producto: "; cin >> no_prod;
fread(&Registro,sizeof(Registro),1,alias);
// Lee el "Registro", de tamano=sizeof(Registro) del archivo "alias"
while(!feof(alias)) // Ciclo mientras no se encuentre el final del archivo
{
if(Registro.no_prod==no_prod)
{
cout << "\n\rNo Prod Descripcion Cantidad Precio Garantia";
cout << "\n\r------------------------------------------------------------------------";
printf("\n\r%3d\t%30s\t%3d\t\t$%4.2f\t%c",Registro.no_prod,Registro.descrip,
Registro.cantidad,Registro.precio,Registro.garantia);
cout << "\n\n\n\rAnote los nuevos datos ...";
fflush(stdin);
cout << "\n\rDescripcion: "; gets(Registro.descrip);
cout << "\n\rCantidad : "; cin >> Registro.cantidad;
cout << "\n\rPrecio : "; cin >> Registro.precio;
do
{
cout << "\n\rGarantia : "; Registro.garantia=toupper(getche());
}while(Registro.garantia!='S' && Registro.garantia!='N');
// Es necesario reposicionar el apuntador del archivo al principio DEL
// registro que desea modificar, ya que al leer un registro, el
// apuntador se posiciona en el registro siguiente
// La funcion ftell(alias) devuelve la posicion donde se encuentra el
// apuntador
fseek(alias,ftell(alias)-sizeof(Registro),SEEK_SET);
fwrite(&Registro,sizeof(Registro),1,alias); // Graba el registro con
// los nuevos campos
fclose(alias); // Cierra el archivo
cout << "\n\n\n\rRegistro modificado !!!";
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
fread(&Registro,sizeof(Registro),1,alias);
}
cout << "\n\rNo se encuentra ese registro !!!";
fclose(alias); // Cierra el archivo
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
void BAJA_LOGICA_SECUENCIAL(void)
{
int no_prod; // Variable local para el numero de producto que desea eliminar
char op; //Variable local
//clrscr();
cout << "\n\rBAJAS LOGICAS DE REGISTROS DE PRODUCTOS";
alias=fopen("PRODUCTO.SEC","rb+"); // Intenta abrir el archivo PRODUCTO.SEC
// en modo de lectura/escritura
if(alias==NULL) // Valida la existencia del archivo
{
cout << "\n\n\n\rNo existe el archivo !!!";
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
cout << "\n\n\n\rNumero de producto: "; cin >> no_prod;
fread(&Registro,sizeof(Registro),1,alias);
// Lee el "Registro", de tamano=sizeof(Registro) del archivo "alias"
while(!feof(alias)) // Ciclo mientras no se encuentre el final del archivo
{
if(Registro.no_prod==no_prod)
{
cout << "\n\rNo Prod Descripcion Cantidad Precio Garantia";
cout << "\n\r------------------------------------------------------------------------";
printf("\n\r%3d\t%30s\t%3d\t\t$%4.2f\t%c",Registro.no_prod,Registro.descrip,Registro.cantidad,Registro.precio,Registro.garantia);
Registro.no_prod=0;
strcpy(Registro.descrip,"");
Registro.cantidad=0;
Registro.precio=0.0;
Registro.garantia=' ';
do {
cout << "\n\n\rEsta seguro que desea borrarlo? [S/N] ---> ";
op=toupper(getche());
}while(op!='S' && op!='N');
if(op=='S')
{
// Es necesario reposicionar el apuntador del archivo al principio del
// registro que desea modificar, ya que al leer un registro, el
// apuntador se posiciona en el registro siguiente
// La funcion ftell(alias) devuelve la posicion donde se encuentra el
// apuntador
fseek(alias,ftell(alias)-sizeof(Registro),SEEK_SET);
fwrite(&Registro,sizeof(Registro),1,alias); // Graba el registro con
// los nuevos campos
cout << "\n\n\n\rRegistro eliminado !!!";
}
fclose(alias); // Cierra el archivo
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
fread(&Registro,sizeof(Registro),1,alias);
}
cout << "\n\rNo se encuentra ese registro !!!";
fclose(alias); // Cierra el archivo
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
void BAJA_FISICA_SECUENCIAL(void)
{
FILE *temporal; //Declaracion local de una variable para controlar el
// archivo temporal
//clrscr();
cout << "\n\rBAJAS FISICAS DE REGISTROS DE PRODUCTOS";
alias=fopen("PRODUCTO.SEC","rb"); // Intenta abrir el archivo PRODUCTO.SEC
// en modo de solo lectura
if(alias==NULL) // Valida la existencia del archivo
{
cout << "\n\n\n\rNo existe el archivo !!!";
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}
temporal=fopen("TEMPORAL.TMP","wb"); // Crea el archivo TEMPORAL.TMP
fread(&Registro,sizeof(Registro),1,alias);
// Lee el "Registro", de tamano=sizeof(Registro) del archivo "alias"
while(!feof(alias)) // Ciclo mientras no se encuentre el final del archivo
{
if(Registro.no_prod!=0)
fwrite(&Registro,sizeof(Registro),1,temporal);
// Graba el registro valido en el archivo temporal
fread(&Registro,sizeof(Registro),1,alias);
}
fclose(alias);
// fcloseall(); // Cierra todos los archivos abiertos
remove("PRODUCTO.SEC"); //Elimina el archivo original
rename("TEMPORAL.TMP","PRODUCTO.SEC");
//Renombra el archivo temporal con el nombre del archivo original
cout << "\n\n\n\rArchivo compactado !!!";
cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
getch();
return;
}


