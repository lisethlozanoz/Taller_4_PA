//Tengo que usar la funcion pow, delete

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>

using namespace std; 

void crearVector(int size); //Para crear e imprimir el vector inicial dinamicamente

void procesoOrdenamiento(int size);//Ordenar el vector segun el metodo de las cubetas



////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	
	int longitud;
	
	cout<<"Ingrese la longitud del arreglo unidimensional"<<endl<<endl;
	cin>>longitud;
	
	crearVector(longitud);
	
	procesoOrdenamiento(longitud);
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
void procesoOrdenamiento(int size){
	
	
	/////////////////////////////////// Crear la matriz /////////////////////////////////////////
	int* vec;
	int* *mat;
	mat=new int*[10];
	for(int i=0;i<10;i++){
		*(mat+i)=new int[size];
	}
	    
	    
	///////////////////////////// Crear un vector auxiliar ///////////////////////////////////////
	int* vectorAux;
	//vectorAux=new int*[10];
	
	
    /////////////////////////////// Ordenamiento segun el primer digito /////////////////////////////
	int indice,numero,exponente=3;
	
	for(int i=0;i<10;i++){
		for(int j=0;j<size;j++){
			indice=*(vec+i)%10;
			*(*(mat+indice)+j)=*(vec+i);
			
			cout<<*(*(mat+indice)+j)<<"\t";
			
			if(i!=0){
				*(vectorAux+i)=*(vec+i)/exponente;
			}
			
			exponente --;
		}
		
		cout<<endl;
	}
	
	
	/////////////////////////////// Trasladar los valores al vector  /////////////////////////////
	for(int i=0;i<10;i++){
		for(int j=0;j<size;j++){
			*vec=*(*(mat+i)+j);
		}
	}
}





