/*
 * biblioteca.c
 *
 *  Created on: 11 may. 2022
 *      Author: Jonat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_arrayPassenger.h"

/**
 * brief: hace el incremento del id
 */
static int id_incrementada = 1;
static int incremento();
static int incremento(){
	return id_incrementada++;
}

/**
 * \fn int get_number(char[], int, int, char[])
 * \brief pide un numero entero y valida que este en el rango
 * \param menssage
 * \param start
 * \param end
 * \param menssage_error
 * \return el numero ingresado
 */
int get_number(char menssage[]){
	int number;
		printf("\n%s\n",menssage);
		scanf("%d",&number);
	return number;
}
/**
 * \fn char pedirCaracter(char[])
 * \brief pide un caracter y lo retorna
 * \param menssage
 * \return
 */
char pedirCaracter(char menssage [])
{
	char caracter;
	printf("\n %s\n",menssage);
	fflush(stdin);
	scanf("%c",&caracter);

	return caracter;
}
/**
 * \fn int validacioNumerica(int, int, int, char[])
 * \brief valida el numero ingresado por parametro
 * \param numero
 * \param primerRango
 * \param segundoRango
 * \param mensaje
 * \return
 */
int validacioNumerica(int numero, int primerRango, int segundoRango,char mensaje[])
{
	while(numero > primerRango || numero < segundoRango)
	{
		printf("%s",mensaje);
		scanf("%d",&numero);
	}
	return numero;
}
/**
 * \fn float pedir_flotante(char[])
 * \brief pide un flotante y lo retorna
 * \param cadena
 * \return
 */
float pedir_flotante(char cadena[]){
	float numero;
	printf("%s",cadena);
	scanf("%f",&numero);
	return numero;
}
/**
 * \fn int search(Passenger[], int)
 * \brief busca la primera posciocion libre
 * \param list_passenger
 * \param tam
 * \return devuelve la primera posciocion libre
 */
int search(Passenger list_passenger [], int tam){
	int index;
	index = -1;
	if(list_passenger != NULL){
		if(tam > 0){
			for(int i = 0;i < tam ; i++){
				if(list_passenger[i].isEmpty == LIBRE){
					index = i;
					break;
				}
			}
		}
	}
	return index;
}
/**
 * \fn void alfanumerico(char*, char[])
 * \brief valida la cadena de caracteres ingresada por parametro para que sea alfanumerica
 * \param cadena
 * \param mensaje
 */
void alfanumerico(char* cadena,char mensaje[]){
	int tamCadena;
	int bandera;
	bandera = 0;
	printf("\n%s\n",mensaje);
	do{
		fflush(stdin);
		scanf("%[^\n]",cadena);
		tamCadena = strlen(cadena);
		if(tamCadena < 40){
			for(int i = 0;i <tamCadena;i++){
				if((cadena[i] <= 90 && cadena[i] >=65)||(cadena[i] <= 122 && cadena[i] >= 97)||(cadena[i] <= 57 && cadena[i] >= 48)){
					bandera =1;
				}else{
						bandera = 0;
						printf("\nIngrese caracteres validos\n");
						break;
				}
			}
		}
		else{
			printf("\nEl nombre ingresado supera el numero maximo de caracteres permitido.\n");
		}
	}while(bandera == 0);
}
/**
 * \fn void pedir_name(char*, char[])
 * \brief valida la cadena de caracteres ingresada por parametro para que sean solo caracteres
 * \param cadena
 * \param mensaje
 */
void pedir_name(char* cadena,char mensaje[]){
	int tamCadena;
	int bandera;
	bandera = 0;
	printf("\n%s\n",mensaje);
	do{
		fflush(stdin);
		scanf("%[^\n]",cadena);
		tamCadena = strlen(cadena);
		if(tamCadena < 40){
			for(int i = 0;i <tamCadena;i++){
				if((cadena[i] <= 90 && cadena[i] >=65)||(cadena[i] <= 122 && cadena[i] >= 97)){
					bandera =1;
				}else{
						bandera = 0;
						printf("\nIngrese caracteres validos\n");
						break;
				}
			}
		}
		else{
			printf("\nEl nombre ingresado supera el numero maximo de caracteres permitido.\n");
		}
	}while(bandera == 0);
}
/**
 * \fn void show_flight(Flight[], int)
 * \brief muestra el contenido del arrat lista de vuelo
 * \param list_flight
 * \param tam
 */
void show_flight(Flight list_flight[],int tam){
	if(list_flight){
		if(tam > 0){
			for(int i = 0;i < tam;i++){
				printf("%10d %20s %20s\n",list_flight[i].IDtypePassenger,list_flight[i].typePassenger,list_flight[i].status);
			}
		}
	}
}
/**
 * \fn int aux_passenger(Passenger*, int, Flight[], int)
 * \brief pide los campos requeridos para la estructura
 * \param list_passenger
 * \param len
 * \param list_flight
 * \param tam
 * \return
 */
int aux_passenger(Passenger* list_passenger, int len,Flight list_flight[],int tam){
	Passenger auxiliar;
	int opcion;
	int bandera;
	char guardado;
	int rtn;
	rtn = -1;
	bandera =-1;
	if(list_passenger != NULL && list_flight !=NULL){
		if(len > 0){
			pedir_name(auxiliar.name, "\nIngrese el nombre del pasajero\n");
			pedir_name(auxiliar.lastName, "\nIngrese el apellido del pasajero\n");
			auxiliar.price = pedir_flotante("\nIgrese el precio\n");
			alfanumerico(auxiliar.flycode, "\nIngrese codigo de vuelo\n");
			do{
				show_flight(list_flight, tam);
				opcion = get_number("\ningrese el ID del tipo de pasajero\n");
				for(int i = 0;i < tam;i++){
					if(opcion == list_flight[i].IDtypePassenger){
						auxiliar.IDtypePassenger = list_flight[i].IDtypePassenger;
						bandera = 0;
						break;
					}
				}
				if(bandera == -1){
					printf("\nERROR,el ID tipo de pasajero. no esta registrado\n");
				}
			}while(bandera == -1);
			for(int i = 0;i<tam;i++){
				if(auxiliar.IDtypePassenger == list_flight[i].IDtypePassenger){
					printf("\nel nombre del pasajero es:%s \t\tel apellido del pasajero es:%s \t\tel precio es:%f \t\tel Tipo de pasajero es:%s \t\telcodigo de vuelo es:%s\n",
					auxiliar.name,auxiliar.lastName,auxiliar.price,list_flight[i].typePassenger,auxiliar.flycode);
					break;
				}
			}
			guardado = pedirCaracter("\nSi los datos son correctos presione 's', en case contrario presione otro caracter\n");
			if(guardado == 's' ||guardado == 'S'){
				auxiliar.id = incremento();
				rtn = addPassenger(list_passenger, len, auxiliar.id, auxiliar.name, auxiliar.lastName, auxiliar.price, auxiliar.IDtypePassenger, auxiliar.flycode);
			}else{
				rtn = 1;
			}
		}
	}
	return rtn;
}
/**
 * \fn int modification(Passenger[], int, Flight[], int)
 * \brief modifica los datos en base al id ingresado
 * \param list_passenger
 * \param tam
 * \param list_flight
 * \param len
 * \return
 */
int modification(Passenger list_passenger[],int tam,Flight list_flight[], int len){
	int index;
	int id;
	int opcion;
	int bandera;
	int numero;
	if(list_passenger != NULL && list_flight !=NULL){
		if(len > 0 && tam >0){
	bandera =-1;
		id=get_number("\nIngrese el id\n");
		index = findPassengerById(list_passenger, tam, id);
		if(id != -1){
			do{
				opcion = get_number("\nQUE DESEA MIDIFICAR\n"
									"\n1.NOMBRE"
									"\n2.APELLIDO"
									"\n3.PRECIO"
									"\n4.TIPO DE PASAJERO"
									"\n5.CODIGO DE VUELO"
									"\n6.SALIR");
				opcion = validacioNumerica(opcion, 6, 1, "\nIngrese una opcion correcta\n");
				switch(opcion){
				case 1:
					pedir_name(list_passenger[index].name, "\nIngrese el nombre del pasajero\n");
					break;
				case 2:
					pedir_name(list_passenger[index].lastName, "\nIngrese el apellido del pasajero\n");
					break;
				case 3:
					list_passenger[index].price = pedir_flotante("\nIgrese el precio\n");
					break;
				case 4:
					do{
						show_flight(list_flight, len);
						numero = get_number("\ningrese el ID del tipo de pasajero\n");
						for(int i = 0;i < len;i++){
							if(numero == list_flight[i].IDtypePassenger){
								list_passenger[index].IDtypePassenger = list_flight[i].IDtypePassenger;
								bandera = 0;
								break;
							}
						}
						if(bandera == -1){
							printf("\nERROR,el ID tipo de pasajero. no esta registrado\n");
						}
					}while(bandera == -1);
					break;
				case 5:
					alfanumerico(list_passenger[index].flycode, "\nIngrese codigo de vuelo\n");
					break;
				}
			}while(opcion != 6);
		}
	}
}
return index;
}
/**
 * \fn int eliminar(Passenger[], int)
 * \brief pide un id para eliminar de forma logica un pasajero
 * \param list_passenger
 * \param len
 * \return
 */
int eliminar(Passenger list_passenger[], int len){
	int rtn;
	int id;
		if(list_passenger != NULL){
			if(len > 0){
				printPassenger(list_passenger, len);
				id = get_number("\nIngrese el ID\n");
				rtn = removePassenger(list_passenger, len, id);
			}
		}
	return rtn;
}
/**
 * \fn int print_one(Passenger)
 * \brief imprime uno de los elementos del array
 * \param un_passenger
 * \return
 */
int print_one(Passenger un_passenger){
	int rtn;
	rtn = 0;

		printf("\n%10d %20s %20s\n",un_passenger.IDtypePassenger,un_passenger.name,un_passenger.lastName);

	return rtn;
}
/**
 * \fn void comparacion(Passenger*, Passenger*)
 * \brief compara los parametros recibidos
 * \param i_passenger
 * \param j_passenger
 */
void comparacion(Passenger* i_passenger,Passenger* j_passenger){
	Passenger auxiliar;
	if((strcmp(i_passenger->lastName,j_passenger->lastName))>0){
		auxiliar = *i_passenger;
		*i_passenger = *j_passenger;
		*j_passenger = auxiliar;
	}else{
		if((strcmp(j_passenger->lastName,i_passenger->lastName)) == 0){
			if(i_passenger->IDtypePassenger > j_passenger->IDtypePassenger){
				auxiliar = *j_passenger;
				*j_passenger = *i_passenger;
				*i_passenger = auxiliar;
			}
		}
	}
}
/**
 * \fn void imprimir_activo(Passenger*, int, int, Flight*, int)
 * \brief busca las pociciones en donde el estado sea activo y los imprime
 * \param list
 * \param len
 * \param order
 * \param list_flight
 * \param tam
 */
void imprimir_activo(Passenger* list, int len, int order,Flight* list_flight, int tam){
	int rtn;
	rtn = -1;
	if(list != NULL){
		if(len > 0){
			rtn = sortPassengers_byID(list, len, order, list_flight, tam);
			if(rtn != -1){
			for(int i = 0;i < len;i++){
				for(int j = 0;j < tam;j++){
					if(list[i].IDtypePassenger == list_flight[j].IDtypePassenger){
						if((strcmp(list_flight[j].status,"ACTIVO")) == 0){
								printf("\n%20s%20s%20s",list[i].name,list[i].flycode,list_flight[j].status);
								break;
							}
						}
					}
				}
			}
		}
	}
}
/**
 * \fn float calcular_promedio(Passenger[], int, float*)
 * \brief calcula el promedio y el precio total
 * \param listPassenger
 * \param tam
 * \param precioTotal
 * \return
 */
float calcular_promedio(Passenger listPassenger[], int tam,float* precioTotal){
	int contador;

	float promedio;
	*precioTotal = 0;
	contador = 0;
	if(listPassenger != NULL){
		if(tam > 0){
			for(int i = 0;i < tam;i++){
				if(listPassenger[i].isEmpty == OCUPADO){
					contador++;
					*precioTotal = *precioTotal + listPassenger[i].price;
				}
			}
			promedio = (float)( *precioTotal /contador);
		}
	}
	return promedio;
}
/**
 * \fn void imprimir_Precio(Passenger[], int)
 * \brief imprime el precio total, el promedio y la cantidad de pasajeros arriva del promedio
 * \param listPassenger
 * \param tam
 */
void imprimir_Precio(Passenger listPassenger[], int tam){
	float precioTotal;
	float promedio;
	int contadorPromedioAlto;
	contadorPromedioAlto = 0;
	if(listPassenger != NULL){
		if(tam > 0){
			promedio = calcular_promedio(listPassenger, tam, &precioTotal);
			for(int i = 0;i < tam;i++){
				if(listPassenger[i].price > promedio){
					contadorPromedioAlto++;
				}
			}
			printf("\nEl precio total es:%.2f\n",precioTotal);
			printf("\nEl promedio de los precios es:%.2f\n",promedio);
			printf("\nLa cantidad de pasajeros que superan el promedio es:%d\n",contadorPromedioAlto);
		}
	}
}
