/*
 * informes.h
 *
 *  Created on: 18 oct. 2021
 *      Author: Ludo
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "pedido.h"

/// @brief Funcion que imprime cuit direccion y cantidad de kilos ingresados de los pedidos pendientes
///
/// @param listaClientes array que contiene los datos de las estructura cliente
/// @param tamCliente tamaño del array cliente
/// @param listaPedidos array que contiene los datos de la estructura pedidos
/// @param tamPedido tamaño del array pedidos
/// @return en caso de imprimir retorna 1, si no puede imprimir retorna 0
int ImprimirPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido);

/// @brief Funcion que imprime cuit direccion y los 3 tipos de plastico procesados en estado COMPLETADO
///
/// @param listaClientes  array que contiene los datos de las estructura cliente
/// @param tamCliente tamaño del array cliente
/// @param listaPedidos array que contiene los datos de la estructura pedidos
/// @param tamPedido tamaño del array pedidos
/// @return en caso de imprimir retorna 1, si no puede imprimir retorna 0
int ImprimirCompletados(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido);

/// @brief Funcion que imprime los pedidos pendientes segun su localidad
///
/// @param listaClientes listaClientes  array que contiene los datos de las estructura cliente
/// @param tam tamaño del array clientes
/// @return retorna el valor acumulado de pedidos pendientes por localidad, si no acumula retorna 0
int PendientesPorLocalidad(eCliente listaClientes[],int tam);

int ClienteMasPedidosPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido);
int ClienteMasPedidosCompletados(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido);


#endif /* INFORMES_H_ */
