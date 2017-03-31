#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>  // me busca fecha y hora
#define N 6	// "ancho" de la red
#define M 6	// "altura" de la red
#define P 0.1   // probabilidad de ocupación

void grilla_inicial(float* g, float* g2);
void grilla(float* g);
void imprimir(float* g, float* g2);

int main(){

     time_t seed = time(NULL);  // semilla para números pseudoaleatorios			
     float* g;	// declara un puntero para la grilla final
     float* g_inicial;	// declara un puntero para la grilla inicial 
     g = malloc(N*M*sizeof(float));	//define espacio en memoria--> N*M espacio tipo float (4 bytes) 	
     g_inicial = malloc(N*M*sizeof(float));
     srand(seed);  // genera la semilla para números pseudoaleatorios con la hora del reloj.
	
     grilla_inicial(g,g_inicial);  // inicializa la grilla
     grilla(g);  //  define si cada nodo va a estar o no ocupado.
     printf("\n");
     imprimir(g,g_inicial);	// imprime grilla en pantalla
     printf("\n");
     free(g); free(g_inicial);	
     return 0;
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

void grilla_inicial(float* g, float* g2){

     int i;  
     for (i=0; i<N*M; i++){
		g[i] = (float)rand() / (float)RAND_MAX;   // número aleatorio entre 0 y 1
		g2[i] = g[i];
	
     }	

}

void grilla(float* g){

     int i;     	
     for (i=0; i<N*M; i++){
		if(g[i] <= P){ g[i] = 1; }
                else { g[i] = 0; }
     }
}

void imprimir(float* g, float* g2){
     int i, j;

     for (i=0; i<N; i++){
	for(j=0; j<M; j++){	

     		printf("%.3f   ",g2[i*N+j]);
		if(j==M-1){ printf("\n"); } 		
		}
     }
     printf("\n\n"); 

     for (i=0; i<N; i++){
	for(j=0; j<M; j++){	

     		printf("%.0f   ",g[i*N+j]);
		if(j==M-1){ printf("\n"); } 		
		}
     }		

}



