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
 	int i,j,k,l;
	srand(time(NULL));
  	for (i = 0; i < filas; i++){
    		for ( j = 0; j < cols; j++){
      			matriz[i][j].cobertura='O';
			k=(rand()%(filas-2))+1;
			l=(rand()%(cols-2))+1;
			matriz[k][l].simbominas='M';
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
      			
			printf(" %c\t ",matriz[i][j].cobertura);
		}
		printf("|");
   		printf("\n");
	}
	printf("\n");
}

void numerodeminas(int filas,int cols, tipoCasilla** matriz){

	int i,j;
	for(i=1;i<filas-1;i++){
		for(j=1;j<cols-1;++j){
			if(matriz[i][j].simbominas!='M'){
				if(matriz[i-1][j-1].simbominas=='M'){

					matriz[i][j].numminas+=1;
				}

				if(matriz[i-1][j].simbominas=='M'){

					matriz[i][j].numminas+=1;
				}

				if(matriz[i][j-1].simbominas=='M'){

					matriz[i][j].numminas+=1;
				}

				if(matriz[i+1][j+1].simbominas=='M'){

					matriz[i][j].numminas+=1;
				}

				if(matriz[i][j+1].simbominas=='M'){

					matriz[i][j].numminas+=1;
				}	
				
				if(matriz[i+1][j].simbominas=='M'){

					matriz[i][j].numminas+=1;
				}

				if(matriz[i+1][j-1].simbominas=='M'){

					matriz[i][j].numminas+=1;
				}

				if(matriz[i-1][j+1].simbominas=='M'){

					matriz[i][j].numminas+=1;
				}
			}
		}
	}
}

void destapar(int filas, int cols, tipoCasilla** matriz){

	int posFilas,posCols,i,j;

	while(1){
	
		printf("Introduzca la posición:\n");
    		printf("Fila:\n");
    		scanf("%d", &posFilas);
    		printf("Columna:\n");
    		scanf("%d", &posCols);
    		printf("\n");

    		if(matriz[posFilas][posCols].simbominas=='M'){

    			imprimir(filas,cols,matriz);
    			printf("Destapaste una mina. Has perdido\n");
    			break;
    		}
    		else{
			imprimir(filas,cols,matriz);
			for(i=1;i<filas-1;i++){
				for(j=1;j<cols-1;++j){
					if(matriz[i-1][j-1].simbominas=='M'){

						matriz[i][j].cobertura=(char)(matriz[i][j].numminas);
					}

					if(matriz[i-1][j].simbominas=='M'){
				
						matriz[i][j].cobertura=(char)(matriz[i][j].numminas);
					}

					if(matriz[i][j-1].simbominas=='M'){

						matriz[i][j].cobertura=(char)(matriz[i][j].numminas);
					}

					if(matriz[i+1][j+1].simbominas=='M'){

						matriz[i][j].cobertura=(char)(matriz[i][j].numminas);
					}

					if(matriz[i][j+1].simbominas=='M'){

						matriz[i][j].cobertura=(char)(matriz[i][j].numminas);
					}	
				
					if(matriz[i+1][j].simbominas=='M'){

						matriz[i][j].cobertura=(char)(matriz[i][j].numminas);
					}

					if(matriz[i+1][j-1].simbominas=='M'){

						matriz[i][j].cobertura=(char)(matriz[i][j].numminas);
					}

					if(matriz[i-1][j+1].simbominas=='M'){

						matriz[i][j].cobertura=(char)(matriz[i][j].numminas);
					}
		
				}
			}
    		}
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
	numerodeminas(filas,cols,matriz);
	destapar(filas,cols,matriz);
}
///# Miniproyecto
