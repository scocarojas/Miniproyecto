#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct juego{  // DEFINIR LAS ESTRUCTURAS EN LAS MATRICES PARA QUE  SE PUEDAN COLOCAR TODOS LOS DATOS ""

	char cobertura;
	char simbominas;
	int  numminas;
	int  nummarco;
	int  ganador;
};

typedef struct juego tipoCasilla; // para no escribir Struct casillas
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
tipoCasilla** armarmatriz(int filas,int cols,tipoCasilla **matriz){   // ESTA FUNCION ME VA A organizar  LA MATRIZ
	int i;
	for(i=0;i<filas;i++){
		matriz[i]=(tipoCasilla *)malloc((cols+2)*sizeof(tipoCasilla)); // por cada fila reserva una columna de memoria
	}
}
/////////////////////////////////////////////////////////////////////////777
void rellenar(int filas, int cols,int nminas,tipoCasilla **matriz) {
 	int a,b,i,j,k,l;
	srand(time(NULL));
	for (size_t a = 1; a < filas-1; a++) {
		for (size_t b = 1; b < cols-1; b++) {
			matriz[a][b].cobertura='*';
			matriz[a][b].ganador=10;
			/* code */
		}
		/* code */
	}
	for (size_t x = 0; x < filas; x++) {
			matriz[0][x].nummarco=x;
			matriz[0][x].numminas=1;
			if (x==filas-1) {
				for (size_t y = 0; y < cols; y++) {
					matriz[y][0].nummarco=y;
					matriz[y][0].numminas=10;
				}
				/* code */
	}
}

	for (size_t i = 0; i <nminas; i++) {
		k=1+(rand()%(filas-2));
		l=1+(rand()%(cols-2));
		//printf("%d%d\n",k,l );
		if (matriz[k][l].simbominas=='M') {
			k=1+(rand()%(filas)-2);
			l=1+(rand()%(cols)-2);
			//printf("%d%d\n",k,l );
			matriz[k][l].simbominas='M';
		}
		else{
		matriz[k][l].simbominas='M';
		}
	}
}
///////////////////////////////////////////////////////////////////////////////7
void imprimir(int filas, int cols, tipoCasilla** matriz){

	int i;
  int j;
	for(i = 0; i < filas-1; i++){
		printf("\n");
		printf("|");
		for (j = 0; j < cols-1; ++j){
			printf(" %c\t",matriz[i][j].cobertura/*,matriz[i][j].numminas,matriz[i][j].simbominas,matriz[i][j].nummarco*/);
		//	printf(" %c%d\t",matriz[i][j].cobertura,matriz[i][j].nummarco);
		//	printf(" %c\t",matriz[i][j].cobertura);
		}
		printf("|");
   	printf("\n");
	}
	printf("\n");
}

void numerodeminas(int filas,int cols, tipoCasilla** matriz){

	int i,j,contMin;
	for (i=1; i < filas-1; i ++){
		for(j=1; j<cols-1; j++){
			if (matriz[i][j].simbominas == 'M'){
				matriz[i][j].numminas=1;
				if(matriz[i-1][j-1].simbominas != 'M'){
					matriz[i-1][j-1].numminas+=1;

				}if(matriz[i][j-1].simbominas !='M'){
					matriz[i][j-1].numminas+=1;

				}if (matriz[i-1][j].simbominas != 'M'){
					matriz[i-1][j].numminas+=1;

				}if (matriz[i-1][j+1].simbominas != 'M'){
					matriz[i-1][j+1].numminas +=1;

				}if (matriz[i][j+1].simbominas != 'M'){
					matriz[i][j+1].numminas+=1;

				}if (matriz[i+1][j-1].simbominas != 'M'){
					matriz[i+1][j-1].numminas+=1;

				}if (matriz[i+1][j].simbominas != 'M'){
					matriz[i+1][j].numminas+=1;

				}if (matriz[i+1][j+1].simbominas != 'M'){
					matriz[i+1][j+1].numminas+=1;
				}
			}
		}
	}
}


void ganar(int filas,int cols,tipoCasilla **matriz, int nminas){
	int i,j,k=0;	
	for(i=1;i<filas-1;i++){
		for(j=1; j<cols-1;j++){
			if(matriz[i][j].cobertura!='*'){
				printf("234\n");
				k+=1;
				printf("%d\n",k );
			}
		}
	}
	if(k==((filas*cols)-nminas)){
		printf("Ganaste\n");
	}
}

void destapar(int filas, int cols, tipoCasilla** matriz, int nminas){

	int posFilas,posCols,i,j,respuesta;


	while(1){

		printf("Introduzca la posición:\n");
    	printf("Fila:");
    	scanf("%d", &posFilas);
    	printf("Columna:");
    	scanf("%d", &posCols);
    	printf("\n");
    	//ganar(filas,cols,matriz,nminas);

    if(matriz[posFilas][posCols].simbominas=='M'){
    	matriz[posFilas][posCols].cobertura='X';
    	imprimir(filas,cols,matriz);
		break;
		}
		else{
			matriz[posFilas][posCols].cobertura=matriz[posFilas][posCols].numminas+'0';
			imprimir(filas,cols,matriz);

			if((posFilas>0)&&(posCols>0)){

				if(matriz[posFilas][posCols].numminas==0){
					printf("entró\n");
					matriz[posFilas][posCols].cobertura='0';

					if(matriz[posFilas-1][posCols-1].numminas==0){

						matriz[posFilas-1][posCols-1].cobertura='0';

					}

					if(matriz[posFilas-1][posCols].numminas==0){

						matriz[posFilas-1][posCols].cobertura='0';
					}

					if(matriz[posFilas][posCols-1].numminas==0){

						matriz[posFilas][posCols-1].cobertura='0';
					}

					if(matriz[posFilas+1][posCols+1].numminas==0){

						matriz[posFilas+1][posCols+1].cobertura='0';
					}

					if(matriz[posFilas][posCols+1].numminas==0){

						matriz[posFilas][posCols+1].cobertura='0';
					}

					if(matriz[posFilas+1][posCols].numminas==0){

						matriz[posFilas+1][posCols].cobertura='0';
					}

					if(matriz[posFilas+1][posCols-1].numminas==0){

						matriz[posFilas+1][posCols-1].cobertura='0';
					}

					if(matriz[posFilas-1][posCols+1].numminas==0){

						matriz[posFilas-1][posCols+1].cobertura='0';
					}				
				}
			}
		}
	}
	
}



////////////////////////////////////////////7
void main(int argc, char *argv[]){

	int filas=(atoi(argv[1]))+2;
	int cols=(atoi(argv[2]))+2;
	int nminas=atoi(argv[3]);
	int jugar;
 	tipoCasilla **matriz;
 	matriz=(tipoCasilla**)malloc((filas+2)*sizeof(tipoCasilla*)); // reserva de memoria para las filas de la matriz
	printf("BIENVENIDO A BUSCAMINAS EN C\n");
	printf("\n");
	printf("Para jugar introduzca mediante el teclado la posición deseada.\n");
	printf("El rango de posiciones va desde (1,1) hasta (filas,columnas)#valores ingresados al principio de la ejecución#\n");
	printf("Si está listo para jugar, por favor presione 1, de lo contrario presione otra tecla: ");
	scanf("%d",&jugar);
	printf("\n");
	if(jugar==1){
		armarmatriz(filas,cols,matriz);
		rellenar(filas,cols,nminas,matriz);
		numerodeminas(filas,cols,matriz);
		imprimir(filas,cols,matriz);
		destapar(filas,cols,matriz,nminas);
		ganar(filas,cols,matriz,nminas);
	}
}
