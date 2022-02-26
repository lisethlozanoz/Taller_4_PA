//Tengo que usar la funcion pow, delete

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>

using namespace std; 

int* crearVector(int size); //Para crear e imprimir el vector inicial dinamicamente

void procesoOrdenamiento(int size, int* vec);//Ordenar el vector segun el metodo de las cubetas

int digit(int a, int b) {
    return a / (int) pow(10, b - 1) % 10;
}

int numDigitos(int n){
	int number_of_digits = 0;

	do {
	     ++number_of_digits; 
	     n /= 10;
	} while (n);
	return number_of_digits;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	
	int longitud;
	int* vec;
	
	cout<<"Ingrese la longitud del arreglo unidimensional"<<endl<<endl;
	cin>>longitud;
	
	vec = crearVector(longitud);
	
	procesoOrdenamiento(longitud, vec);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
int* crearVector(int size){
	
	int* vec;
	
	vec=new int[size];
	
	cout<<"El vector generado es:"<<endl<<endl;
	
	srand(time(NULL));
	for(int i=0; i<size; i++) {
		*(vec + i)=1 + rand()%1000;
	}
	
	for(int i=0; i<size; i++){
		cout<<" ["<<*(vec + i)<<"] ";
	}
	cout<<endl<<endl;
	return vec;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
void procesoOrdenamiento(int size, int* vec){
	
	cout<<endl;
	/////////////////////////////////// Crear la matriz /////////////////////////////////////////
	int* *mat;
	mat=new int*[10];
	for(int i=0;i<10;i++){
		*(mat+i)=new int[size];
	}
	
	for(int i=0;i<10;i++){
		for(int j=0;j<size;j++){
			*(*(mat+i)+j)=-1;
		}
	}
		
	    
	for(int it=0;it<3;it++){
		int dig=0;
		int num = 0;
		int ind = 0;
		
		for(int i=0;i<size;i++){
			num = *(vec+i);
			
			dig = digit(num, it + 1);
			
			while(*(*(mat+dig)+ind)!=-1){
				ind++;
			}
			
			*(*(mat+dig)+ind)=num;
			ind=0;
		}
		
		ind = 0;
		for(int i=0;i<10;i++){
			for(int j=0;j<size;j++){
				//cout<<*(*(mat+i)+j)<<" ";
				if(*(*(mat+i)+j) != -1){
					*(vec + ind) = *(*(mat+i)+j);
					ind++;
				}
			}
			//cout<<endl;
		}
		
		cout<<"iteracion "<< it<<": "<<endl;
			for(int i=0; i<size; i++){
			cout<<" ["<<*(vec + i)<<"] ";
		}
		ind = 0;
		cout<<endl<<endl;
		
		for(int i=0;i<10;i++){
			for(int j=0;j<size;j++){
				*(*(mat+i)+j)=-1;
			}
		}
	}
	
}
