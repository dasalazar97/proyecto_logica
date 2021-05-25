#include<iostream>
using namespace std;
int const filas=4;
int const columnas=5;

void lasDisponibles(bool disponibilidad[filas][columnas]);
void limpiarMatrices(bool disponibilidad[filas][columnas],int pesos[filas][columnas]);
void imprimirMatrizBooleana(bool matriz[filas][columnas]);
void imprimirMatrizTexto(string matriz[filas][columnas]);
void imprimirMatrizEnteros(int matriz[filas][columnas]);
string marcaMasPesada(int pesos[filas][columnas],string marcas[filas][columnas]);

int main(){
int puertos=0;
	cout<<"ingrese cantidad de puertos"<<endl;
	cin>>puertos;
	string nombrepuertos[puertos];
	int contenedores[puertos];
	for(int i=0;i<puertos;i++){
		cout<<"ingrese nombre de puerto"<<endl;
		cin>>nombrepuertos[i];
		cout<<"ingrese cantidad de contenedores"<<endl;
		cin>>contenedores[i];	
	}
	cout<<"imprimiendo cantidad contenedores"<<endl;
	for(int i=0;i<puertos;i++){
		cout<<nombrepuertos[i]<<"="<<contenedores[i]<<endl;
	}
	string marcaPesada="";
	bool disponibilidad[filas][columnas];
	
	string marcas[filas][columnas];
	int pesos[filas][columnas];
	string puertoCarga[filas][columnas];
	string tipoArticulo[filas][columnas];
	limpiarMatrices(disponibilidad,pesos);
	//disponibilidad
	int filasocupadas=0;
	int columnasocupadas=0;
	for(int contadorpuertos=0;contadorpuertos<puertos;contadorpuertos++){
		cout<<"elija un lugar disponible"<<endl;
		lasDisponibles(disponibilidad);
		cout<<"ingrese la posicion de i[filas]"<<endl;
		cin>>filasocupadas;
		cout<<"ingrese la posicion de j[columnas]"<<endl;
		cin>>columnasocupadas;
	}	
	//Determine la marca del contenedor mas pesado
	marcaPesada=marcaMasPesada(pesos,marcas);
	
	cout<<"Matriz disponibilidad"<<endl;
	imprimirMatrizBooleana(disponibilidad);
	cout<<"Matriz marcas "<<endl;
	imprimirMatrizTexto(marcas);
	cout<<"Matriz puertos "<<endl;
	imprimirMatrizTexto(puertoCarga);
	cout<<"Matriz Tipo Articulo "<<endl;
	imprimirMatrizTexto(tipoArticulo);
	cout<<"Matriz Pesos "<<endl;
	imprimirMatrizEnteros(pesos);
	return 0;
}
void lasDisponibles(bool disponibilidad[filas][columnas]){
	for(int i=0; i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(disponibilidad[i][j]==1){
				cout<<i<<" , "<<j<<endl;
			}
		}
	}
}

void limpiarMatrices(bool disponibilidad[filas][columnas],int pesos[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			disponibilidad[i][j]=1;
			pesos[i][j]=0;
		}
	}
}
void imprimirMatrizBooleana(bool matriz[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void imprimirMatrizTexto(string matriz[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<", \t";
		}
		cout<<endl;
	}
}
void imprimirMatrizEnteros(int matriz[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}
string marcaMasPesada(int pesos[filas][columnas],string marcas[filas][columnas]){
	int mayor=INT_MIN;
	string respuesta="";
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(pesos[i][j]>mayor){
				mayor=pesos[i][j];
				respuesta=marcas[i][j];
			}
		}
	}
	return respuesta;
}
