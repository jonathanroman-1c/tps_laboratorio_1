/*
 * biblioteca.c
 *
 *  Created on: 22 sep. 2022
 *      Author: Jonat
 */

#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
 * pide un numero entero y lo retorna
 */
int pedirNumero(int numero, char mensaje[]){
	char cadena[40];
	int tamCadena;
	int bandera = 0;
	printf("%s",mensaje);
	do{
		fflush(stdin);
		scanf("%[^\n]",cadena);
		tamCadena = strlen(cadena);
		for(int i = 0;i < tamCadena;i++){
			if(cadena[i] >= 48 && cadena[i] <= 57){
				bandera = 1;
			}else{
				bandera = 0;
				printf("ingrese solo numeros\n");
				break;
			}
		}
	}while(bandera == 0);
	numero = atoi(cadena);
	return numero;
}
/*
 * pide una cadena y  retorna un flotante
 */
float pedirFlotante(float numero,char mensaje[]){
	char cadena[40];
	int tamCadena;
	int bandera = 0;
	int contadorPunto = 0;
	printf("%s",mensaje);
	do{
		fflush(stdin);
		scanf("%[^\n]",cadena);
		tamCadena = strlen(cadena);
		for(int i = 0;i < tamCadena;i++){
			if(cadena[i] == '.'){
				contadorPunto ++;
			}
			if(cadena[i] >= 46 && cadena[i] <= 57 && contadorPunto <= 1){
				if(cadena[i] == 47){
					bandera = 0;
					printf("ingrese solo numeros\n");
					break;
				}else{
					bandera = 1;
				}
			}else{
				bandera = 0;
				printf("ingrese solo numeros\n");
				break;
			}
		}
	}while(bandera == 0);
	numero = atof(cadena);
	return numero;
}
/**
 * @fn int posicion_jugador(int)
 * @brief
 *
 * @pre
 * @post  pide y retorna la posicion del jugador
 * @param posicion
 * @return
 */
int posicion_jugador(int posicion,int contadores[]){

	posicion = pedirNumero(posicion, "ingrese la posicion del jugador:\n"
									"1.ARQUERO\n"
									"2.DEFENSA\n"
									"3.MEDIOCAMPISTA\n"
									"4.DELANTERO\n");
	while(posicion > 4 || posicion < 0){
		posicion = pedirNumero(posicion, "ERROR,ingrese la posicion del jugador:\n"
										"1.ARQUERO\n"
										"2.DEFENSA\n"
										"3.MEDIOCAMPISTA\n"
										"4.DELANTERO\n");
	}
	switch(posicion){
		case 1:
			if(contadores[0]>2){
				printf("ya se a ingresado 2 arqueros\n");
			}else{
			posicion = ARQUERO;
			contadores[0]++;
			}
			break;
		case 2:
			if(contadores[1] > 8){
				printf("ya se a ingresado 8 defensores\n");
			}else{
			posicion = Defensores;
			contadores[1]++;
			}
			break;
		case 3:
			if(contadores[2] > 8){
				printf("ya se a ingresado 8 mediocampistas\n");
			}else{
			posicion = Mediocampistas;
			contadores[2]++;
			}
			break;
		case 4:
			if(contadores[3] > 4){
				printf("ya se a ingresado 4 delanteros\n");
			}else{
			posicion = Delanteros;
			contadores[3]++;
			}
			break;
	}
	return posicion;
}
/**
 * @fn int confederacion_jugador(int, int[])
 * @brief pide de que confederacion
 *
 * @pre
 * @post
 * @param confederacion
 * @param contadores
 * @return
 */
int confederacion_jugador(int confederacion,int contadores[]){

	confederacion = pedirNumero(confederacion, "ingrese la confederacion del jugador:\n"
									"1.CONMEGOL\n"
									"2.CONCACAF\n"
									"3.CAF\n"
									"4.OFC\n"
									"5.AFC"
									"6.UEFA\n");
	while(confederacion > 6 || confederacion < 0){
		confederacion = pedirNumero(confederacion, "ERROR,ingrese la confederacion del jugador:\n"
										"1.CONMEGOL\n"
										"2.CONCACAF\n"
										"3.CAF\n"
										"4.OFC\n"
										"5.AFC\n"
										"6.UEFA\n");
	}
	switch(confederacion){
		case CONMEGOL:
			contadores[4]++;
			break;
		case CONCACAF:
			contadores[5]++;
			break;
		case CAF:
			contadores[6]++;
			break;
		case OFC:
			contadores[7]++;
			break;
		case AFC:
			contadores[8]++;
			break;
		case UEFA:
			contadores[9]++;
			break;
	}
	return confederacion;
}
/**
 * @fn Sjugador cargaJugadores(int[])
 * @brief
 *
 * @pre a traves de un auxiliar carga los datos del jugador
 * @post
 * @param contadores
 * @return
 */
Sjugador cargaJugadores(int contadores[]){
	Sjugador auxiliar;
	auxiliar.posicion = posicion_jugador(auxiliar.posicion, contadores);
	auxiliar.dorsal = pedirNumero(auxiliar.dorsal, "ingrese el numero de la camiseta\n");
	while(auxiliar.dorsal > 99 || auxiliar.dorsal < 0){
		auxiliar.dorsal = pedirNumero(auxiliar.dorsal, "ERROR,ingrese el numero de la camiseta  del jugador:\n");
	}
	auxiliar.confederacion = confederacion_jugador(auxiliar.confederacion, contadores);

	return auxiliar;
}
/**
 * @fn void calculos(int[], float[], int[])
 * @brief	hace todos los calculos requeridos sin informar el resultado
 *
 * @pre
 * @post
 * @param contadores
 * @param resultado
 * @param acumuladores
 */
void calculos(int contadores[],float resultado[],float acumuladores[]){
resultado[1] = contadores[4] + contadores[5] + contadores[6] + contadores[7] + contadores[8] + contadores[9]; //total de jugadores
resultado[2] = acumuladores[0] + acumuladores[1] + acumuladores[2];//costo total de mantenimiento
resultado[3] = contadores[4] + contadores[5] + contadores[6] + contadores[7] + contadores[8];
if(contadores[9] > resultado[3]){
	resultado[4] = resultado[2] * 0.35;
	resultado[5] = resultado[4] + resultado[2];
}
resultado[6] = (float)contadores[4] / resultado[1];
resultado[7] = (float)contadores[5] / resultado[1];
resultado[8] = (float)contadores[6] / resultado[1];
resultado[9] = (float)contadores[7] / resultado[1];
resultado[10] =(float) contadores[8] / resultado[1];
resultado[11] =(float) contadores[9] / resultado[1];
}
/**
 * @fn void mostrarResultados(float)
 * @brief recive los resultados y los muestra por consola
 *
 * @pre
 * @post
 * @param resultado
 */
void mostrarResultados(float resultado[]){
printf("\nINFORMAR RESULTADOS\n\n"
		"Promedio  CONMEGOL %f\n"
		"Promedio  CONCACAF %f\n"
		"Promedio  CAF %f\n"
		"Promedio  OFC %f\n"
		"Promedio AFC %f\n"
		"Promedio UEFA %f\n"
		"El costo de mantenimiento era de %f y recibio un aumento de $%f, su nuevo valor es de: %f",resultado[6],resultado[7],resultado[8],resultado[9],resultado[10],resultado[11],resultado[2],resultado[4],resultado[5]);
}
