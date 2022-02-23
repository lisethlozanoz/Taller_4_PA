//Tengo que usar la funcion pow, delete

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>

using namespace std; 

void crearVector(int size); //Para crear e imprimir el vector inicial dinamicamente

void primerPaso(int size);//Primer ordenamiento del vector


////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	
	int longitud;
	
	cout<<"Ingrese la longitud del arreglo unidimensional"<<endl<<endl;
	cin>>longitud;
	
	crearVector(longitud);
	
	primerPaso(longitud);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
void crearVector(int size){
	
	int* vec;
	
	vec=new int[size];
	
	cout<<"El vector generado es:"<<endl<<endl;
	
	srand(time(NULL));
	for(int i=0; i<size; i++) {
		*(vec + i)=1 + rand()%100;
	}
	
	for(int i=0; i<size; i++){
		cout<<" ["<<*(vec + i)<<"] ";
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////
void primerPaso(int size){
	
	
	/////////////////////////////////// Crear la matriz /////////////////////////////////////////
	int* vec;
	int** mat;
	
	mat=new int*[10];
	for(int i=0;i<10;i++){
		*(mat+i)=new int[size];
	}
	
	int indice; 
	
	
	///////////////////////   Primer ordenamiento    /////////////////////////////////////////	
	for(int i=0;i<10;i++){
		indice=0;
		for(int j=0;j<size;j++){
			indice=(*(vec+i))%10;
			cout<<" ["<<indice<<" ]";
			
			if((*(*(mat+indice)+j))!=-1)
			*(*(mat+indice)+j)=*(vec+i);
			cout<<" ["<<*(*(mat+indice)+j)<<" ]";
		}
		cout<<endl;
    }
	
	for(int i=0;i<10;i++)delete[]mat[i]; //Para borrar la matriz creada
}

    ///////////////////////// Segundo ordenamiento //////////////
	for(int i=0;i<10;i++){
		for(int j=0;j<size;j++){
			*(*(mat+indice)+j)=-1;
		}
	}

