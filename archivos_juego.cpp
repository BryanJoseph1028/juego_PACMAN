#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
 
 
 const char *nombre_archivo = "juego.txt";
 void ingresar_nombre();
 
int main(){
	ingresar_nombre();	
	return 0;	
}
void abrir_archivo(){
	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivo,ios::in);

	
	if (archivo.fail()){
	cout<<"No se pudo abrir el archivo";
	exit(1);
	}else{
	cout<<endl;
		do{
			getline(archivo,contenido);
			cout<<contenido<<endl;
		} while(archivo.eof()==false);
	}
}
void ingresar_nombre(){
	
	ofstream archivo;
	char continuar;
	archivo.open(nombre_archivo,ios::out);
	
	if (archivo.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
		string nombre;
		string punteo;

		do{
		fflush(stdin);
		cout<<"Ingrese el Nombre: ";
		getline(cin,nombre);
		archivo<<nombre<<endl;
		cout<<"Ingrese su punteo: ";
		getline(cin,punteo);
		archivo<<punteo<<endl;
		cout<<"Desea Agregar otro Jugador s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	}
	archivo.close();
	abrir_archivo();
}

