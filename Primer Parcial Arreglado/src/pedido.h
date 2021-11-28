/*
 * pedido.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Ludo
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cliente.h"
#include "localidad.h"


#define SINPEDIDO -1
#define PENDIENTE 0
#define COMPLETADO 1

typedef struct
{
	int idCliente;
	int idPedido;
	float CantidadHDPE;
	float CantidadLDPE;
	float CantidadPP;
	float TotalKilos;
	int isEmpty;


}ePedido;

/// @brief Funcion que inicializa todos los espacios de la lista en SIN PEDIDO
///
/// @param listaPedidos array que contiene los datos de la estructura pedido
/// @param tam tamaño del array
/// @return en caso de realizarse el cambio del estado retorna 1, retorna 0 en caso de no realizarse la inicializacion
int InicializarListaPedido(ePedido listaPedidos[],int tam);

/// @brief Funcion que muestra los campos de un pedido
///
/// @param unPedido un pedido del array listaPedidos
void MostrarUnPedido(ePedido unPedido);

/// @brief Funcion que muestra el listado de pedidos cargados
///
/// @param listaPedidos array que contiene los datos de la estructura pedido
/// @param tamPedidos tamaño del array
/// @return retorna 1 si muestra la lista de pedidos, 0 en caso de no mostrarla
int MostrarListaPedidos(ePedido listaPedidos[],int tamPedidos);

/// @brief Funcion que busca un pedido a traves del id que se genera a la estructura pedido
///
/// @param listaPedidos array que contiene los datos de la estructura pedido
/// @param tamPedido tamaño del array
/// @return retorna el indice del pedido buscado, en caso de no encontrarlo retorna -1
int BuscarPedido(ePedido listaPedidos[],int tamPedido);

/// @brief Funcion que crea un pedido a recolectar donde se cargan los datos de la estructura pedido, generando un estado de PENDIENTE
///
/// @param listaClientes array que contiene los datos de la estructura cliente, donde al igualar los id vamos a asignarle un pedido a un cliente
/// @param tamCliente tamaño del array listaClientes
/// @param listaPedidos array que contiene los datos de la estructura pedido
/// @param tamPedido tamaño del array listaPedidos
/// @param idPedidos variable que paso por referencia para genera un id autoincrementable
/// @return si se creo el pedido retorna 1, si no se dio el alta al pedido retorna 0
int CrearPedidoRecoleccion (eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido,int* idPedidos,eLocalidad listaLocalidad[],int tamLocalidad);





/// @brief Luego de dado de alta el pedido y su estado a PENDIENTE, esta funcion le cambia el estado a COMPLETADO, separa los kilos ingresados
/// en los 3 tipos de plastico y acumula los pedidos de PP
///
/// @param listaPedidos array que contiene los datos de la estructura pedido
/// @param tamPedido tamaño del array
/// @param acumuladorPP variable que paso por referencia y me acumula los pedidos procesados de PP
/// @return retorna 1 en caso de que la funcion realice lo detallado, 0 si no se proceso el pedido
int ProcesarPedido(ePedido listaPedidos[],int tamPedido);

#endif /* PEDIDO_H_ */



