/*
 ============================================================================
 Name        : Trabajo.c
 Author      : jonathan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_arrayPassenger.h"
#include "biblioteca.h"

#define tam 2000
int main(void) {
	setbuf(stdout,NULL);
	Passenger list_passenger[tam];//={{1,"jonathan","roman",23.2,"alpha12",12,OCUPADO},{2,"lucas","castillo",23.2,"delta",12,OCUPADO},{3,"teodoro","ayala",23.2,"tetra23",12,OCUPADO},{4,"cristian","romero",2.2,"gama",12,OCUPADO}};
	Flight list_fligth[3]={{12,"ACTIVO","econimico"},{23,"en espera","primera clase"},{8,"finalizado","comercial"}};
	int opcion;
	int rtn;
	int bandera = -1;
	int imprimir;
	int imprimir_opcion;
	rtn = initPassengers(list_passenger, tam);
		do{
			opcion = get_number("1.ALTA"
								"\n2.MODIFICACION"
								"\n3.BAJA"
								"\n4.INFORMAR"
								"\n5.SALIR\n");
			opcion = validacioNumerica(opcion, 5, 1, "ERROR,OPCION INCORRECTA, por favor elija una opcion correcta"
													"\n1.ALTA"
													"\n2.MODIFICACION"
													"\n3.BAJA"
													"\n4.INFORMAR"
													"\n5.SALIR\n");

			switch (opcion){
				case 1:if(rtn == 0){
					switch((aux_passenger(list_passenger, tam, list_fligth, 3))){
					case -1:
						puts("\nError,CARGA NO REALIZADA");
					break;
					case 0:
						puts("\nCARGA OK");
						bandera = 0;
					break;
					case 1:
						puts("\nDATOS NO GUARDADOS");
						break;
					}
				}else{
					printf("\nNO HAY ESPACIO PARA CONTINUAR\n");
				}
					break;
				case 2:
					if(bandera == 0){
						switch((modification(list_passenger, tam, list_fligth, 3))){
						case -1:
							printf("\nNO SE HIZO LA MODIFICACION\n");
							break;
						default:
							printf("\nMODIFICACION REALIZADA\n");
							break;
						}
					}
					break;

				case 3:
					if(bandera == 0){
					switch((eliminar(list_passenger, tam))){
					case -1:
						printf("\nERROR,ID no encontrado\n");
						break;
					case 0:
						printf("\ELIMINACION REALIZADA\n");
						break;
					}
				}
					break;
				case 4:
					if(bandera == 0){
						imprimir = get_number("\nIMPRIMIR:\n"
											"\n1.Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero"
											"\n2.Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio. "
											"\n3.Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’");
						imprimir = validacioNumerica(imprimir, 3, 1, "\nERROR,OPCION INCORRECTA, por favor elija una opcion correcta\n"
								"\n1.Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero"
								"\n2.Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio. "
								"\n3.Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’");
						switch(imprimir){
						case 1:
							imprimir_opcion = get_number("\n1.ASCENDENTE"
														"\n2.DESCENDENTE");
							imprimir_opcion = validacioNumerica(imprimir_opcion, 3, 1, "\n1.ASCENDENTE"
														"\n2.DESCENDENTE");
							rtn = sortPassengers_byName(list_passenger, tam, imprimir_opcion);
							rtn = printPassenger(list_passenger, tam);
							break;
						case 2:
							imprimir_Precio(list_passenger, tam);
							break;
						case 3:
							imprimir_opcion = get_number("\n1.ASCENDENTE"
														"\n2.DESCENDENTE\n");
							imprimir_opcion = validacioNumerica(imprimir_opcion, 3, 1, "\n1.ASCENDENTE"
														"\n2.DESCENDENTE");
								imprimir_activo(list_passenger, tam, imprimir_opcion, list_fligth, 3);
							break;
						}

					}
					break;
			}
		}while(opcion != 5);

	return EXIT_SUCCESS;
}
