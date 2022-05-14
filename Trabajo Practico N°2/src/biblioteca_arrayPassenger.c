/*
 * biblioteca_arrayPassenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: Jonat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_arrayPassenger.h"
#include "biblioteca.h"

/**
 * \fn int initPassengers(Passenger*, int)
 * \brief Para indicar que todas las posiciones en la matriz están vacías
 * \param list_passenger
 * \param len
 * \return Devuelve (-1) si hay error [longitud no válida o puntero NULL], o (0) si está bien
 */
int initPassengers(Passenger* list_passenger, int len)
{
	int rtn;
	rtn = -1;
	if(list_passenger != NULL){
		if(len > 0){
			for(int i = 0; i < len; i++){
				list_passenger[i].isEmpty = LIBRE;
			}
			rtn = 0;
		}
	}
return rtn;
}
/**
 * \fn int addPassenger(Passenger*, int, int, char[], char[], float, int, char[])
 * \brief agrega en una lista existente de pasajeros los valores recibidos como parámetros
 * \param list_passenger
 * \param len
 * \param id
 * \param name
 * \param lastName
 * \param price
 * \param IDtypePassenger
 * \param flycode
 * \return -1 (si Longitud no válida o puntero NULL o sin
espacio libre) y 0 (si todo ok)
 */
int addPassenger(Passenger* list_passenger, int len, int id, char name[],char
lastName[],float price,int IDtypePassenger, char flycode[])
{
	int index;
	int rtn;
	rtn = -1;
	if(list_passenger != NULL && lastName != NULL && name != NULL && flycode != NULL){
		if(len >0){
			index = search(list_passenger, len);
			if(index !=-1)
			{
				list_passenger[index].id = id;
				strcpy(list_passenger[index].name,name);
				strcpy(list_passenger[index].lastName,lastName);
				list_passenger[index].price = price;
				list_passenger[index].IDtypePassenger = IDtypePassenger;
				strcpy(list_passenger[index].flycode,flycode);
				list_passenger[index].isEmpty = OCUPADO;
				rtn = 0;
			}
		}
	}
return rtn;
}
/**
 * \fn int findPassengerById(Passenger*, int, int)
 * \brief busca la poscicion del array en base al id
 * \param list_passenger
 * \param len
 * \param id
 * \return devuelve la Posición del índice de pasajeros de regreso o (-1) si [Longitud o
Puntero NULL recibido o pasajero no encontrado]
 */

int findPassengerById(Passenger* list_passenger, int len,int id)
{
	int index;
	index = -1;
	if(list_passenger != NULL){
		if(len > 0 && id != 0){
			for(int i = 0;i < len; i++){
				if(list_passenger[i].id == id && list_passenger[i].isEmpty == OCUPADO){
					index = i;
					break;
				}
			}
		}
	}
return index;
}
/**
 * \fn int removePassenger(Passenger*, int, int)
 * \brief da baja logica en base a el id ingresado
 * \param list_passenger
 * \param len
 * \param id
 * \return Devuelve (-1) si hay un error [Longitud no válida o puntero NULL o si no se puede
encontrar un pasajero] - (0) si está bien
 */

int removePassenger(Passenger* list_passenger, int len, int id)
{
	int rtn;
	rtn = -1;
	if(list_passenger !=NULL){
		if(len > 0){
			for(int i = 0;i < len;i++){
				if(list_passenger[i].isEmpty == OCUPADO && list_passenger[i].id == id){
					list_passenger[i].isEmpty = LIBRE;
					rtn = 0;
					break;
				}
			}
		}
	}
return rtn;
}
/**
 * \fn int sortPassengers_byName(Passenger*, int, int)
 * \brief Ordena los elementos en la matriz de pasajeros
 * \param list_passenger
 * \param len
 * \param order
 * \return Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
 */
//RECORDAR ACORTAR ESTA FUNCION CON FUNCIONES MAS PEQUEÑAS

int sortPassengers_byName(Passenger* list_passenger, int len, int order)
{
	int rtn;
	int i;
	int j;
	//Passenger auxiliar;
	rtn =-1;
	if(list_passenger != NULL){
		if(len > 0){
				for(i = 0;i < len-1 ;i++){
					for(j = i+1;j < len;j++){
						if(list_passenger[i].isEmpty == OCUPADO && list_passenger[j].isEmpty == OCUPADO ){
							switch(order){
							case 1:
								comparacion(&list_passenger[i],&list_passenger[j]);
								break;
							case 2:
								comparacion(&list_passenger[j],&list_passenger[i]);
								break;
							}
						}
					}
				}
				rtn = 0;
			}
		}

return rtn;
}
/**
 * \fn int printPassenger(Passenger*, int)
 * \brief imprime el contenido del array
 * \param list_passenger
 * \param length
 * \return
 */
int printPassenger(Passenger* list_passenger, int length)
{
	int rtn;
	rtn = -1;
	if(list_passenger != NULL){
		if(length > 0){
			for(int i = 0;i < length;i++){
				if(list_passenger[i].isEmpty == OCUPADO){
					rtn = print_one(list_passenger[i]);
				}
			}
		}
	}
return rtn;
}
/**
 * \fn int sortPassengers_byID(Passenger*, int, int, Flight*, int)
 * \brief Ordenar los elementos en la matriz de pasajeros, el orden de los argumentos indica el orden ARRIBA o ABAJO
 * \param list
 * \param len
 * \param order
 * \param list_flight
 * \param tam
 * \return
 */
int sortPassengers_byID(Passenger* list, int len, int order,Flight* list_flight, int tam)
{
	int rtn;
	rtn =-1;
	Passenger auxiliar;
		if(list != NULL){
			if(len > 0){
						for(int i = 0;i < len-1 ;i++){
							for(int j = i+1;j < len;j++){
									switch(order){
								case 1:
										if((strcmp(list[j].flycode,list[i].flycode)) > 0){
											auxiliar=list[j];
											list[j]=list[i];
											list[i]=auxiliar;
										}
										break;
								case 2:
								if((strcmp(list[i].flycode,list[j].flycode)) > 0){
									auxiliar=list[i];
									list[i]=list[j];
									list[j]=auxiliar;
								}
							break;
						}
					}

				}
						rtn = 0;
			}
		}
return rtn;
}
