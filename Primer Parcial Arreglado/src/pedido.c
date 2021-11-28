/*
 * pedido.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Ludo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "cliente.h"
#include "pedido.h"

int InicializarListaPedido(ePedido listaPedidos[],int tam) //todos los espacios de la lista comienzan sin pedido
{
	int retorno;
	retorno = 0;

	if(listaPedidos != NULL && tam > 0)
	{
		for(int i=0 ; i<tam; i++ )
		{
			listaPedidos[i].isEmpty= SINPEDIDO;
			retorno = 1;
		}
	}
	return retorno;
}


void MostrarUnPedido(ePedido unPedido)
{
	printf("ID PEDIDO   TOTAL KILOS\n");
	printf("%4d           %2.f \t\t\n",unPedido.idPedido,unPedido.TotalKilos);
}

int MostrarListaPedidos(ePedido listaPedidos[],int tamPedidos)
{
	int retorno;
	retorno = 0;
	if(listaPedidos != NULL && tamPedidos >0)
	{
		for(int i=0 ; i< tamPedidos; i++)
		{
			if(listaPedidos[i].isEmpty == PENDIENTE)
			{
				MostrarUnPedido(listaPedidos[i]);
				retorno = 1;
			}
		}
	}
	return retorno;
}

int BuscarPedido(ePedido listaPedidos[],int tamPedido)
{
	int idBuscado;
	int indicePedido;
	indicePedido = -1;

	utn_getNumero(&idBuscado, "Ingrese id del pedido que desea buscar:  \n" ,"Error\n" ,1,1000,10);

	for(int i=0; i<tamPedido; i++)
	{
		if(listaPedidos[i].isEmpty == PENDIENTE && listaPedidos[i].idPedido == idBuscado)
		{
			indicePedido = i;
			break;

		}
	}
	return indicePedido;
}


int CrearPedidoRecoleccion (eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido,int* idPedidos,eLocalidad listaLocalidad[],int tamLocalidad)
{
	int indiceCliente;
	int retorno;
	int auxId;
	float auxKilos;

	auxId = *idPedidos;
	retorno = 0;

	if(listaClientes != NULL && tamCliente > 0 && listaPedidos != NULL && tamPedido>0)
	{
		indiceCliente = BuscarCliente(listaClientes,tamCliente,listaLocalidad,tamLocalidad);

		if(indiceCliente != -1) //ya estoy trabajando en ese cliente porq trabajo en ese indice
		{
			for(int i = 0; i< tamPedido; i++)
			{
				if(listaPedidos[i].isEmpty == SINPEDIDO)
				{

					if(!utn_getNumeroFlotante( &auxKilos,"Ingrese kilos totales\n","Error reingrese\n",0,1000,10))
					{
						listaPedidos[i].idPedido = auxId;
						listaPedidos[i].TotalKilos = auxKilos;
						listaPedidos[i].isEmpty = PENDIENTE;
						listaPedidos[i].idCliente = listaClientes[indiceCliente].id;
						auxId++;
						*idPedidos = auxId;
						retorno = 1;

					}
				break;
				}
			}
		}
	}
	return retorno;
}



int ProcesarPedido(ePedido listaPedidos[],int tamPedido) //punto5
{
	int iPedido;
	int retorno;
	ePedido auxPedido;

	retorno = 0;
	iPedido = BuscarPedido(listaPedidos,tamPedido);

	if(listaPedidos != NULL && tamPedido >0 && iPedido!= -1)
	{
		if(listaPedidos[iPedido].isEmpty == PENDIENTE)
		{
			auxPedido = listaPedidos[iPedido];//el array es un puntero

			if(!utn_getNumeroFlotante(&auxPedido.CantidadPP, "Ingrese kilos de PP\n", "Error reingrese\n", 0, auxPedido.TotalKilos, 10) &&
			!utn_getNumeroFlotante(&auxPedido.CantidadHDPE, "Ingrese kilos de HDPE\n", "Error reingrese\n", 0, auxPedido.TotalKilos -auxPedido.CantidadPP, 10) &&
			!utn_getNumeroFlotante(&auxPedido.CantidadLDPE, "Ingrese kilos de LDPE\n", "Error reingrese\n", 0, auxPedido.TotalKilos-(auxPedido.CantidadPP+ auxPedido.CantidadHDPE), 10))
			{
				listaPedidos[iPedido] = auxPedido;
				listaPedidos[iPedido].isEmpty = COMPLETADO;
				retorno = 1;
			}
		}
	}
	return retorno;
}



