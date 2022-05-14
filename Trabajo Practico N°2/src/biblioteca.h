/*
 * biblioteca.h
 *
 *  Created on: 11 may. 2022
 *      Author: Jonat
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int get_number(char menssage[]);
char pedirCaracter(char menssage []);
int validacioNumerica(int numero, int primerRango, int segundoRango,char mensaje[]);
float pedir_flotante(char cadena[]);
int search(Passenger list_passenger [], int tam);
void show_flight(Flight list_flight[],int tam);
void alfanumerico(char* cadena,char mensaje[]);
void pedir_name(char* cadena,char mensaje[]);
int aux_passenger(Passenger* list_passenger, int len,Flight list_flight[],int tam);
int modification(Passenger list_passenger[],int tam,Flight list_flight[], int len);
int eliminar(Passenger list_passenger[], int len);
int print_one(Passenger un_passenger);
float calcular_promedio(Passenger listPassenger[], int tam,float* precioTotal);
void imprimir_Precio(Passenger listPassenger[], int tam);
void comparacion(Passenger* i_passenger,Passenger* j_passenger);
void imprimir_activo(Passenger* list, int len, int order,Flight* list_flight, int tam);

#endif /* BIBLIOTECA_H_ */
