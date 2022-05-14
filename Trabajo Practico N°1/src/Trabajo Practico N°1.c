/*
 ============================================================================
Jonathan Roman
1-c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	int opcion;
	int kilometros=0;
	int precioLtam=0;
	int precioAeroline=0;
	float resultado[8] = {0};

	setbuf(stdout,NULL);

	mostrarOpciones();
	opcion=pedirNumero("\n\nIngrese una opcion: ");
	opcion=validarOpcion(opcion);

	while(opcion != 6)
	{
		switch(opcion)
		{
		case 1:
			kilometros=pedirNumero("\n\nIngrese los kilometros: ");
			kilometros=validarNumero(kilometros);
			break;
		case 2:
			precioLtam=pedirNumero("\n\nIngrese Precio de vuelos Latam: ");
			precioLtam=validarNumero(precioLtam);
			precioAeroline=pedirNumero("\n\nIngrese Precio de Vuelos Aeroline: ");
			precioAeroline=validarNumero(precioAeroline);
			printf("\nPrecio Latam: %d",precioLtam);
			printf("\nPrecio Aerolinea: %d\n\n",precioAeroline);
			break;
		case 3:
			if(precioAeroline != 0 && precioLtam != 0 && kilometros != 0)
			{
					calculo(precioAeroline, precioLtam, kilometros, resultado);
					printf("\n\nelprecio unitario de Aeroline es: %.2f\n",resultado[6]);
					printf("\nelprecio unitario Latam es: %.2f\n\n",resultado[7]);
					diferencia(precioLtam, precioAeroline);
			}

			break;
		case 4:
			if(resultado[1] != 0){
				printf("\nKilometros ingresados: %d\n\n",kilometros);
						mostrarAeroline(resultado,precioAeroline);
						mostrarLatam(resultado,precioLtam);
			}
			break;
		case 5:

			kilometros = 7090;
			precioAeroline = 162965;
			precioLtam = 159339;
			calculo(precioAeroline, precioLtam, kilometros, resultado);

			printf("\nKilometros Ingresados: %d\n\n",kilometros);

			printf("\n\nPrecio Latam: %d\n\n",precioLtam);
			mostrarLatam(resultado,precioLtam);

			printf("\n\nPrecio Aerolinea: %d\n\n",precioAeroline);
			mostrarAeroline(resultado,precioAeroline);

			diferencia(precioLtam, precioAeroline);

			break;
		}
		mostrarOpciones();
		opcion=pedirNumero("\n\nIngrese una opcion: ");
		opcion=validarOpcion(opcion);
	}
	return EXIT_SUCCESS;
}
