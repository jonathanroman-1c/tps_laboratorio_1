/*
 * biblioteca.h
 *
 *  Created on: 22 sep. 2022
 *      Author: Jonat
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#define OCUPADO 0
#define LIBRE 1

#define ARQUERO 1
#define Defensores 4
#define Mediocampistas 6
#define Delanteros 10

#define CONMEGOL 1
#define CONCACAF 2
#define CAF 3
#define OFC 4
#define AFC 5
#define UEFA 6

typedef struct{
	int posicion;
	int dorsal;
	int confederacion;
}Sjugador;

int pedirNumero(int numero,char mensaje[]);
float pedirFlotante(float numero,char mensaje[]);
Sjugador cargaJugadores(int contadores[]);
int posicion_jugador(int posicion,int contadores[]);
int confederacion_jugador(int confederacion,int contadores[]);
void calculos(int contadores[],float resultado[],float acumuladores[]);
void mostrarResultados(float resultado[]);

#endif /* BIBLIOTECA_H_ */
