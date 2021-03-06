/*
 * localidad.h
 *
 *  Created on: 19 oct. 2021
 *      Author: Ludo

 1) Agregar la entidad Localidad.
2) Refactorizar las funciones que considere necesarias para que utilicen la nueva entidad.
3) Agregar los siguientes informes:
a) Cliente con m?s pedidos pendientes.
b) Cliente con m?s pedidos completados.
Nota 1: Se deber?n desarrollar bibliotecas por cada entidad las cuales contendr?n las funciones (Alta, Baja, Modificar, etc.).
Los informes deber?n estar en una biblioteca aparte.
Nota 2: El c?digo deber? tener comentarios con la documentaci?n de cada una de las funciones y respetar las reglas de estilo
de la c?tedra.*/

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct
{
	int idCLocalidad;
	char nombreLocalidad[50];
}eLocalidad;


#endif /* LOCALIDAD_H_ */
