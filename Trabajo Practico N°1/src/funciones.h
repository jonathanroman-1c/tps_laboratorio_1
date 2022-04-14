/**
 * @def FUNCIONES_H_
 * @brief
 *
 */
#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/**
 * \fn void mostrarOpciones(void)
 * \brief
 */
void mostrarOpciones(void);
/**
 * \fn int pedirNumero(char[])
 * \brief
 * \param texto
 * \return
 */
int pedirNumero(char texto[]);
/**
 * \fn int validarOpcion(int)
 * \brief
 * \param opcion
 * \return
 */
int validarOpcion(int opcion);
/**
 * \fn int validarNumero(int)
 * \brief
 * \param numero
 * \return
 */
int validarNumero(int numero);
/**
 * \fn float descuento(int)
 * \brief
 * \param primerNumero
 * \return
 */
float descuento(int primerNumero);
/**
 * \fn float interes(int)
 * \brief
 * \param primerNumero
 * \return
 */
float  interes(int primerNumero);
/**
 * \fn float bitcoin(int)
 * \brief
 * \param primerNumero
 * \return
 */
float bitcoin(int primerNumero);
/**
 * \fn float precioUnitario(int, int)
 * \brief
 * \param primerNumero
 * \param segundoNumero
 * \return
 */
float precioUnitario(int primerNumero, int segundoNumero);
/**
 * \fn void diferencia(int, int)
 * \brief
 * \param primerNumero
 * \param segundoNumero
 */
void diferencia(int primerNumero, int segundoNumero);
/**
 * \fn void mostrarLatam(float[], int)
 * \brief
 * \param vector
 * \param precioLtam
 */
void mostrarLatam(float vector[],int precioLtam);
/**
 * \fn void mostrarAeroline(float[], int)
 * \brief
 * \param resultado
 * \param precioAeroline
 */
void mostrarAeroline(float resultado[], int precioAeroline);
/**
 * \fn void calculo(int, int, int, float[])
 * \brief
 * \param precioAeroline
 * \param precioLtam
 * \param kilometros
 * \param resultado
 */
void calculo(int precioAeroline, int precioLtam, int kilometros, float resultado[]);
#endif /* FUNCIONES_H_ */
