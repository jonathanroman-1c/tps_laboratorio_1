
#include <stdio.h>
#include <stdlib.h>
/**
 * \fn void mostrarOpciones(void)
 * \brief Le informa al usuario las opciones que puede seleccionar.
 */
	void mostrarOpciones(void){
		printf("\n1.Ingresar kilometros: ");
		printf("\n2.Igresar precio de vuelo: ");
		printf("\n3.Calcular todos los costos: ");
		printf("\n4.Informar resultados. ");
		printf("\n5.Carga forzada de datos. ");
		printf("\n6.Salir ");
	}
/**
 * \fn int pedirNumero(char[])
 * \brief Le pide al usuario que ingrese un numero entero
 * \param texto
 * \return
 */
	int pedirNumero(char texto[])
	{
		int numero;

		printf("%s",texto);
		scanf("%d",&numero);
		return numero;
	}
/**
 * \fn int validarOpcion(int)
 * \brief Valida el numero ingresado para que ingrese a una opcion
 * \param opcion
 * \return
 */
	int validarOpcion(int opcion){
		while(opcion < 1 || opcion >6)
		{
			printf("\ningresar una opcion valida: \n");
			void mostrarOpciones(void);
			scanf("%d",&opcion);
		}
	return opcion;
	}
/**
 * \fn int validarNumero(int)
 * \brief Valida el numero ingresado para que este dentro del rango asignado
 * \param numero
 * \return
 */
	int validarNumero(int numero){

		while(numero < 100 ||numero>200000)
		{
			printf("\ningresar un numero  valido (entre 100 y 200000) : ");
			scanf("%d",&numero);
		}

	return numero;

	}
/**
 * \fn float descuento(int)
 * \brief Aplica un descuento del 10% al precio ingresado
 * \param primerNumero
 * \return
 */
	float descuento(int primerNumero)
	{
		float resultado;
			resultado =(float) (primerNumero -(primerNumero*0.1));
		return resultado;
	}
/**
 * \fn float interes(int)
 * \brief Aplica un descuento del 25% al precio ingresado
 * \param primerNumero
 * \return
 */
	float	interes(int primerNumero)
	{
		float resultado;
			resultado = (float)(primerNumero +(primerNumero*0.25));
			return resultado;
	}
/**
 * \fn float bitcoin(int)
 * \brief Cambia el precio ingresado a su equivalente en bitcoins
 * \param primerNumero
 * \return
 */
	float bitcoin(int primerNumero)
	{
		float resultado;
		float bitcoin;
		bitcoin = 4606954.55;
			resultado = (float)(primerNumero  / bitcoin);
		return resultado;
	}
/**
 * \fn float precioUnitario(int, int)
 * \brief Calcula cuanto es el costo por kilometro
 * \param primerNumero
 * \param segundoNumero
 * \return
 */
	float precioUnitario(int primerNumero, int segundoNumero)
	{
		float resultado;
			resultado = (float)primerNumero / segundoNumero;
		return resultado;
	}
/**
 * \fn void diferencia(int, int)
 * \brief En caso de que el primer numero sea mayor al segundo, resta
 * el primer numero al segundo en caso contrario resta el segundo al primero
 * \param primerNumero
 * \param segundoNumero
 */
	void diferencia(int primerNumero, int segundoNumero)
	{
		int resultado;
		if(segundoNumero < primerNumero){
			resultado = primerNumero - segundoNumero;
		}
		else{
			resultado = segundoNumero - primerNumero;
		}
		printf("\n\nLa diferencia de precio es: %d\n\n",resultado);
	}
/**
 * \fn void mostrarLatam(float[], int)
 * \brief Muestra al usuario los resultados usando los resultados de la funcion calculo y los el precio de Latam
 * \param resultado
 * \param precioLtam
 */
	void mostrarLatam(float resultado[], int precioLtam)
	{
		printf("\nLatam\n\n");
		printf("\nPrecio Latam: %d",precioLtam);
		printf("\na)elprecio pagando con tarjeta de debito: %.2f",resultado[2]);
		printf("\nb)elprecio pagando con tarjeta de credito: %.2f",resultado[3]);
		printf("\nc)elprecio pagando con bitcoin: %.2f",resultado[5]);
		printf("\nd)elprecio unitario es: %.2f\n\n",resultado[7]);
	}
/**
 * \fn void mostrarAeroline(float[], int)
 * \brief Muestra al usuario los resultados usando los resultados de la funcion calculo y los el precio de aeroline
 * \param resultado
 * \param precioAeroline
 */
	void mostrarAeroline(float resultado[], int precioAeroline)
	{
		printf("\nAerolinea\n\n");
		printf("\nPrecio Aerolinea: %d",precioAeroline);
		printf("\na)elprecio pagando con tarjeta de debito: %.2f",resultado[0]);
		printf("\nb)elprecio pagando con tarjeta de credito: %.2f",resultado[1]);
		printf("\nc)elprecio pagando con bitcoin: %.2f",resultado[4]);
		printf("\nd)elprecio unitario es: %.2f\n\n",resultado[6]);


	}
/**
 * \fn void calculo(int, int, int, float[])
 * \brief Hace los calculos nescesarios para la aplicacion
 * \param precioAeroline
 * \param precioLtam
 * \param kilometros
 * \param resultado
 */
	void calculo(int precioAeroline, int precioLtam, int kilometros, float resultado[])
	{

			resultado[0]=descuento(precioAeroline);
			resultado[1]=interes(precioAeroline);
			resultado[2]=descuento(precioLtam);
			resultado[3]=interes(precioLtam);
			resultado[4]=bitcoin(precioAeroline);
			resultado[5]=bitcoin(precioLtam);
			resultado[6]=precioUnitario(precioAeroline, kilometros);
			resultado[7]=precioUnitario(precioLtam, kilometros);

	}
