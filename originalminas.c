#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct juego{  // DEFINIR LAS ESTRUCTURAS EN LAS MATRICES PARA QUE  SE PUEDAN COLOCAR TODOS LOS DATOS ""

	char cobertura;
	char simbominas;
	int  numminas;
};

typedef struct juego tipoCasilla; // para no escribir Struct casillas
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
tipoCasilla** armarmatriz(int filas,int cols,tipoCasilla **matriz){   // ESTA FUNCION ME VA A organizar  LA MATRIZ
	int i;
	for(i=0;i<filas;i++){
		matriz[i]=(tipoCasilla *)malloc(cols*sizeof(tipoCasilla)); // por cada fila reserva una columna de memoria
	}
}
/////////////////////////////////////////////////////////////////////////777
void rellenar(int filas, int cols,tipoCasilla **matriz) {
 	int i,j;
  	for (i = 0; i < filas; i++){
    		for ( j = 0; j < cols; j++){
      			matriz[i][j].cobertura='O';
    		}
  	}
}
///////////////////////////////////////////////////////////////////////////////7
void imprimir(int filas, int cols, tipoCasilla** matriz){

	int i;
  	int j;
	for(i = 0; i < filas; i++){
		printf("\n");
		printf("|");
		for (j = 0; j < cols; ++j){
      			
			printf(" %c ",matriz[i][j].cobertura);
		}
		printf("|");
   		printf("\n");
	}
}
////////////////////////////////////////////7
void main(int argc, char *argv[]){

	int filas=atoi(argv[1]);
	int cols=atoi(argv[2]);
  	tipoCasilla **matriz;
  	matriz=(tipoCasilla**)malloc(filas*sizeof(tipoCasilla*)); // reserva de memoria para las filas de la matriz
	armarmatriz(filas,cols,matriz);
	rellenar(filas,cols,matriz);
	imprimir(filas,cols,matriz);
}
# Miniproyecto
