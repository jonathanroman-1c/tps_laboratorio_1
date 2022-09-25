/*
 ============================================================================
 Name        : TP1.c
 Author      : jonathan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
int main(void) {
	float costos[3] = {0,0,0};
	int opcion[2];
	int contadores[10] = {0,0,0,0,0,0,0,0,0,0};
	float resultado[12];
	float acumuladores[3] = {0,0,0};
	int bandera[2] = {0,0};
	Sjugador jugadores;

	setbuf(stdout,NULL);
	do{
		printf("\nMENU PRINCIPAL\n\n"
								"1.INGRESO DE LOS COSTOS DE MANTENIMIENTO\n"
								"\t1.Costo de hospedaje -> $%.2f\n"
								"\t2.Costo de comida -> $%.2f\n"
								"\t3.Costo de transporte -> $%.2f\n"
								"2.CARGA DE JUGADORES\n"
								"\tARQUEROS -> %d\n"
								"\tDEFENSORES -> %d\n"
								"\tMEDIOCAMPISTAS -> %d\n"
								"\tDELANTEROS -> %d\n"
								"3.REALIZAR CALCULOS DE GASTOS\n"
								"4.INFORMAR TODOS LOS RESULTADOS LOS RESULTADOS\n"
								"5.SALIR\n\n",acumuladores[0],acumuladores[1],acumuladores[2],contadores[0],contadores[1],contadores[2],contadores[3]);
	opcion[0] = pedirNumero(opcion[0],"ingrese su opcion:");//aca cambiar
	switch(opcion[0]){
	case 1:
		opcion[1] = pedirNumero(opcion[1],"\nINGRESE EL DATO QUE DESEA MODIFICAR\n\n"
													"1.Costo de hospedaje\n"
													"2.Costo de comida\n"
													"3.Costo de transporte\n");//ACA
			switch(opcion[1]){
				case 1:
					costos[0] = pedirFlotante(costos[0], "Ingrese los costos del hospedaje\n");
					acumuladores[0] = acumuladores[0] + costos[0];
					break;
				case 2:
					costos[1] = pedirFlotante(costos[1], "Ingrese los costos de la comida\n");
					acumuladores[1] = acumuladores[1] + costos[1];
					break;
				case 3:
					costos[2] = pedirFlotante(costos[2], "Ingrese los costos del transporte\n");
					acumuladores[2] = acumuladores[2] + costos[2];
					break;
				default:
					printf("ERROR NO EXISTE ESA OPCION\n");
					break;
			}
		break;
	case 2:
		resultado[0] = contadores[0] +contadores[1]+contadores[2];
		if(resultado[0] > 22){
			printf("ya se han ingresado 22 jugadores\n");
		}else{
				jugadores = cargaJugadores(contadores);
				bandera[0] = 1;
		}
		break;
	case 3:
		if(bandera[0] != 0 && 	acumuladores[0] != 0 && acumuladores[1] != 0 && acumuladores[2] != 0){
			calculos(contadores, resultado, acumuladores);
			bandera[1] = 1;
		}else{
			if(bandera[0] == 0){
				printf("ingrese los datos de al menos 1 jugador\n");
			}else{
				printf("no se han completado los gastos del equipo correctamente, por favor ingresar a la opcion 1\n");
			}
		}
		break;
	case 4:
		if(bandera[1] != 0){
			mostrarResultados(resultado);
		}else{
			printf("NO SE A INGRESADO A LA OPCION 3 PREVIAMENTE\n");
		}
		break;
	}
	}while(opcion[0] != 5);
	return EXIT_SUCCESS;
}
