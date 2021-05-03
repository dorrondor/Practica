/*
Programa nagusia

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "definiciones.h"
#include "funciones.h"
#include "interacciones.h"
#include "probabilidad.h"

int main(int argc, char *argv[]){

	int i;

    // irakurri sarrera-datuak
    if (argc != 2) {
        printf ("\n\nERROR: falta el fichero de los parametros. \n\n");
        exit (-1);
    }

    struct poblaciones poblacion;
    struct persona_virus *personas;
    
    //poblacioneko parametroak eta aldagai globalak jaso fitxategi batetik.
    leer_parametros(&poblacion);

    //ZALANTZA parametrotan * edo & zalantza hau argitu Josekin.               personas ya helbidea da ordun hola jartzeakin listo
    inicializar(poblacion.tam, personas, poblacion.tam_escenario);
    

    for(i=0; i<poblacion.tam; i++){
        printf(" Persona %d  /  Edad:  %d  /  Estado: %d\n", i, personas[i].edad, personas[i].estado );
    }
    //Escoger el primer infectado de manera aleatoria.
    paciente0(poblacion.tam, personas);
    //erakutsi(personas, &poblacion);

    //Simulazioarekin hasi
    for(i=0; i<poblacion.tiempo_simulacion; i++){

    	//Mover cada persona y determinar la nueva velocidad (para la proxima iteracion)
    	movimiento(personas, &poblacion);
    	//Calcular los estados y los contagios
    	propagacion(personas, &poblacion);

		if(i%5==0){
			escribir(&poblacion, personas);
		}
    }

}
