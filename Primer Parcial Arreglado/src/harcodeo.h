/*
 * harcodeo.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Ludo
 */

#ifndef HARCODEO_H_
#define HARCODEO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

/// @brief Funcion que genera un alta forzada con datos pre-ingresados
///
/// @param lista array de la estructura cliente
/// @param tam tamaño del array
/// @param cantCargar cantidad que deseo hardcodear
/// @param pIdAtuomatico variable que paso por referencia para generar id
/// @return retorna el contenido cargado en el array
int HardcodearClientes(eCliente lista[],int tam,int cantCargar, int* pIdAtuomatico);

#endif /* HARCODEO_H_ */
