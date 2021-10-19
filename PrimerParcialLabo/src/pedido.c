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
	printf("%4d  %2.f \t\t\n",unPedido.idPedido,unPedido.TotalKilos);
}

int MostrarListaPedidos(ePedido listaPedidos[],int tamPedidos)
{
	int retorno;
	retorno = 0;
	if(listaPedidos != NULL && tamPedidos >0)
	{
		for(int i=0 ; i< tamPedidos; i++)
		{
			MostrarUnPedido(listaPedidos[i]);
			retorno = 1;
		}
	}
	return retorno;
}

int BuscarPedido(ePedido listaPedidos[],int tamPedido)
{
	int idBuscado;
	int indicePedido;
	indicePedido = -1;

	utn_getNumero(&idBuscado, "Ingrese id del pedido que desea buscar \n:" ,"Error\n" ,1,1000,10);

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


int CrearPedidoRecoleccion (eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido,int* idPedidos)
{
	int indiceCliente;
	int retorno;
	int auxId;
	float auxKilos;
	int auxCantPedidos;
	auxId = *idPedidos;
	retorno = 0;

	if(listaClientes != NULL && tamCliente > 0 && listaPedidos != NULL && tamPedido>0)
	{
		indiceCliente = BuscarCliente(listaClientes,tamCliente);

		if(indiceCliente != -1) //ya estoy trabajando en ese cliente porq trabajo en ese indice
		{
			for(int i = 0; i< tamPedido; i++)
			{
				if(listaPedidos[i].isEmpty == SINPEDIDO)
				{
					listaPedidos[i].idPedido = auxId;
					utn_getNumeroFlotante( &auxKilos,"Ingrese kilos totales\n","Error reingrese\n",0,1000,10);
					listaPedidos[i].TotalKilos = auxKilos;
					//listaPedidos[i].TotalKilos = IngresarEntero("Ingrese cantiad de kilos totales:  \n");
					listaPedidos[i].isEmpty = PENDIENTE;
					auxCantPedidos = listaClientes[indiceCliente].contadorPedidos;
					auxCantPedidos++;
					listaClientes[indiceCliente].contadorPedidos = auxCantPedidos;
					listaPedidos[i].idCliente = listaClientes[indiceCliente].id;
					auxId++;
					*idPedidos = auxId;
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}

int ProcesarPedido(ePedido listaPedidos[],int tamPedido,float* acumuladorPP) //punto5
{
	int iPedido;
	int retorno;
	int auxAcumuladorPP;
	auxAcumuladorPP = *acumuladorPP;

	retorno = 0;
	iPedido = BuscarPedido(listaPedidos,tamPedido);

	if(listaPedidos != NULL && tamPedido >0 && iPedido!= -1)
	{
		for(int i = 0; i<tamPedido; i++)
		{
			if(listaPedidos[i].isEmpty == PENDIENTE)
			{
				listaPedidos[iPedido].isEmpty = COMPLETADO;
				listaPedidos[iPedido].CantidadPP = listaPedidos[iPedido].TotalKilos /3;
				listaPedidos[iPedido].CantidadLDPE = listaPedidos[iPedido].TotalKilos /3;
				listaPedidos[iPedido].CantidadHDPE = listaPedidos[iPedido].TotalKilos /3;
				listaPedidos[iPedido].acumuladorPP = listaPedidos[iPedido].CantidadPP;
				auxAcumuladorPP = listaPedidos[iPedido].acumuladorPP + auxAcumuladorPP;
				*acumuladorPP = auxAcumuladorPP;

				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}


