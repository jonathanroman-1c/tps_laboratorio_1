/*
 * biblioteca_arrayPassenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: Jonat
 */

#ifndef BIBLIOTECA_ARRAYPASSENGER_H_
#define BIBLIOTECA_ARRAYPASSENGER_H_

#define LIBRE 0
#define OCUPADO 1

typedef struct{
	int IDtypePassenger;
	char status[50];
	char typePassenger[50];
}Flight;

typedef struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int IDtypePassenger;
int isEmpty;
}Passenger;

int initPassengers(Passenger* list_passenger, int len);//LISTO
int addPassenger(Passenger* list_passenger, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);//listo
int findPassengerById(Passenger* list_passenger, int len,int id);//listo
int removePassenger(Passenger* list_passenger, int len, int id);
int sortPassengers_byName(Passenger* list_passenger, int len, int order);
int printPassenger(Passenger* list_passenger, int length);
int sortPassengers_byID(Passenger* list, int len, int order,Flight* list_flight, int tam);
#endif /* BIBLIOTECA_ARRAYPASSENGER_H_ */
