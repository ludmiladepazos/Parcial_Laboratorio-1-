/*
 * informes.c
 *
 *  Created on: 18 oct. 2021
 *      Author: Ludo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"
#include "cliente.h"
#include "pedido.h"
#include "validaciones.h"



int ImprimirPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido)
{
	int retorno;
	retorno = 0;
	if(listaClientes != NULL && tamCliente >0 && listaPedidos != NULL && tamPedido >0)
	{
		printf("DATOS PEDIDOS PENDIENTES\n");
		printf("CUIT           DIRECCION     kILOS A RECOLECTAR  \n");
		for(int i= 0; i<tamCliente; i++) //recorro lista clientes
		{
			for(int j=0; j<tamPedido;j++) // recorro pedidos
			{
				if(listaPedidos[j].isEmpty == PENDIENTE && listaClientes[i].id == listaPedidos[j].idCliente)
				{
					printf("%15s    %15s     %2.f \t\t\t \n",listaClientes[i].cuit,listaClientes[i].direccion,listaPedidos[j].TotalKilos);

					retorno = 1;
				}
			}
		}
	}
	return retorno;
}


int ImprimirCompletados(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido)
{
	int retorno;
	retorno = 0;
		if(listaClientes != NULL && tamCliente >0 && listaPedidos != NULL && tamPedido >0)
		{
			printf("DATOS PEDIDOS COMPLETADOS\n");
			printf("CUIT DIRECCION CANTIDAD KG HDPE CANTIDAD KG LDPE CANTIDAD KG PP \t\t\t\t\t   \n");
			for(int i= 0; i<tamCliente; i++) //recorro lista clientes
			{
				for(int j=0; j<tamPedido;j++) // recorro pedidos
				{
					if(listaPedidos[j].isEmpty == COMPLETADO && listaClientes[i].id == listaPedidos[j].idCliente)
					{
						printf("%15s  %15s  %2.f  %2.f  %2.f \t\t\t\t\t\n",listaClientes[i].cuit,listaClientes[i].direccion,listaPedidos[j].CantidadHDPE,listaPedidos[j].CantidadLDPE,listaPedidos[j].CantidadPP);
						retorno = 1;
					}
				}
			}
		}
	return retorno;
}

int PendientesPorLocalidad(eCliente listaClientes[],int tam)
{
	int acumulador;
	int retorno;
	char localidadBuscada[50];
	acumulador = 0;
	MostrarListadoClientes(listaClientes,tam);

	retorno = myGets(localidadBuscada,"Ingrese localidad: \n",sizeof(localidadBuscada));

	if(retorno!= -1)
	{
		for(int i=0; i<tam; i++)
		{
			if((listaClientes[i].isEmpty == OCUPADO) && (strncmp(listaClientes[i].localidad,localidadBuscada,50) == 0 ))
			{

				acumulador = acumulador+listaClientes[i].contadorPedidos;
			}
		}
	}
	else
	{
		printf("No hay clientes con la localidad ingresada \n");
	}

	return acumulador;
}

int ClienteMasPedidosPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido)
{
    int retorno;
    retorno = -1;
    int cantidadPendientes;
    cantidadPendientes = 0;
    int cantidadMaxPendientes;
    cantidadMaxPendientes = 0;
    int idClienteMax;


    if(tamPedido > 0 && listaPedidos != NULL && tamCliente > 0 && listaClientes != NULL)
	{
		retorno = 0;
        for(int i=0;i<tamCliente;i++)
        {

                for(int j=0;j<tamPedido;j++)
                {
                	if(listaPedidos[j].idCliente == listaClientes[i].id)
                	{
                		if(listaPedidos[j].isEmpty == PENDIENTE)
                		{
                			cantidadPendientes++;
                		}
                	}
                }

            if(cantidadPendientes > cantidadMaxPendientes)
            {
            	cantidadMaxPendientes = cantidadPendientes;
            	idClienteMax = listaClientes[i].id;
            }

            cantidadPendientes = 0;
            retorno = 1;
        }
        printf("Id del cliente con mas pedidos pendientes\n",idClienteMax);
	}
    return retorno;
}


int ClienteMasPedidosCompletados(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido)
{
    int retorno;
    retorno = -1;
    int cantidadCompletados;
    cantidadCompletados= 0;
    int cantidadCompletadosMax;
    cantidadCompletadosMax = 0;
    int idCompletados;


    if(tamPedido > 0 && listaPedidos != NULL && tamCliente > 0 && listaClientes != NULL)
	{
		retorno = 0;

        for(int i=0;i < tamCliente; i++)
        {
                for(int j=0; j<tamPedido; j++)
                {
                	if(listaPedidos[j].idCliente == listaClientes[i].id)
                	{
                		if(listaPedidos[j].isEmpty == COMPLETADO)
                			cantidadCompletados++;
                    }
                }
                if(cantidadCompletados > cantidadCompletadosMax)
                {
                	cantidadCompletadosMax = cantidadCompletados;
                	cantidadCompletados = listaClientes[i].id;
                }

                cantidadCompletados = 0;
                retorno = 1;
        }

        printf("Id cliente con mas pedidos completados \n",idCompletados);
	}

    return retorno;
}
