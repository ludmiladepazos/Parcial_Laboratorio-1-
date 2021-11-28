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
#include "localidad.h"



int ImprimirPendientes(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido)
{
	int retorno;
	retorno = 0;
	if(listaClientes != NULL && tamCliente >0 && listaPedidos != NULL && tamPedido >0)
	{
		printf("DATOS DE PEDIDOS PENDIENTES\n");
		printf("CUIT           DIRECCION        kILOS A RECOLECTAR  \n");
		for(int i= 0; i<tamCliente; i++) //recorro lista clientes
		{
			if(listaClientes[i].isEmpty == OCUPADO)
			{
				ImprimirClienteConPendientes(listaClientes[i], listaPedidos, tamPedido);

				retorno = 1;
			}
		}
	}
	return retorno;
}

void ImprimirClienteConPendientes(eCliente unCliente, ePedido listaPedidos[],int tamPedido)
{
	for(int j=0; j<tamPedido;j++) // recorro pedidos
	{
		if(listaPedidos[j].isEmpty == PENDIENTE && unCliente.id == listaPedidos[j].idCliente)
		{
			printf("%-15s %-15s   %-2.f \n",unCliente.cuit,unCliente.direccion,listaPedidos[j].TotalKilos);
		}
	}

}

int ImprimirCompletados(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido)
{
	int retorno;
	retorno = 0;

	if(listaClientes != NULL && tamCliente >0 && listaPedidos != NULL && tamPedido >0)
	{
		printf("DATOS PEDIDOS COMPLETADOS\n");
		printf("CUIT  DIRECCION   CANTIDAD KG PP   CANTIDAD KG HDPE   CANTIDAD KG LDPE \n");
		for(int i= 0; i<tamCliente; i++) //recorro lista clientes
		{
			if(listaClientes[i].isEmpty == OCUPADO)
			{
				ImprimirUnClienteCompletado(listaClientes[i], listaPedidos, tamPedido);
				retorno = 1;
			}
		}
	}
	return retorno;
}

void ImprimirUnClienteCompletado(eCliente unCliente, ePedido listaPedidos[],int tamPedido)
{
	for(int j=0; j<tamPedido;j++) // recorro pedidos
	{
		if(listaPedidos[j].isEmpty == COMPLETADO && unCliente.id == listaPedidos[j].idCliente)
		{
			printf("%-15s  %-15s  %-2.2f  %-2.2f  %2.2f \n",unCliente.cuit,unCliente.direccion,listaPedidos[j].CantidadPP,listaPedidos[j].CantidadHDPE,listaPedidos[j].CantidadLDPE);

		}
	}
}

//Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
int PendientesPorLocalidad(eCliente listaClientes[],int tamClientes,eLocalidad listaLocalidad[],int tamLocalidad,ePedido listaPedido [], int tamPedido)
{
	int retorno;
	int acumulador;
	int localidadBuscar;
	acumulador = 0;
	retorno = 0;

	localidadBuscar = BuscarLocalidad(listaLocalidad,tamLocalidad);

	if(localidadBuscar!= -1)
	{
		retorno = 1;
		for(int i=0; i<tamClientes; i++)
		{
			if((listaClientes[i].isEmpty == OCUPADO) && listaLocalidad[localidadBuscar].idLocalidad == listaClientes[i].idClocalidad)
			{
				acumulador = acumulador + ContadorPedidosPendientesPorCliente(listaClientes[i], listaPedido, tamPedido);
			}
		}
		printf(" Localidad     Cantidad Pedidos pendientes\n");
		printf("   %15s            %4d\n",listaLocalidad[localidadBuscar].nombreLocalidad,acumulador);
	}
	else
	{
		printf("No hay clientes con la localidad ingresada \n");
	}

	return retorno;
}

void MostrarUnClienteConPendientes(eCliente unCliente, eLocalidad listaLocalidad[], int tamLocalidad,ePedido listaPedidos[],int tamPedido)
{
	char nombreLocalidad[50];
	int cantPendientes;
	CargarNombreLocalidad(unCliente.idClocalidad,listaLocalidad,tamLocalidad,nombreLocalidad );
	cantPendientes = ContadorPedidosPendientesPorCliente(unCliente,listaPedidos,tamPedido);
	printf("%4d   %12s     %15s    %15s   %15s   %4d     \n",unCliente.id,unCliente.NombreEmpresa, unCliente.cuit,unCliente.direccion,nombreLocalidad,cantPendientes);
}


int MostrarListadoClientesConPendientes(eCliente listaClientes[], int tamCliente,eLocalidad listaLocalidad[],int tamLocalidad,ePedido listaPedidos[],int tamPedido)
{
    int retorno;
    retorno = 0;

    printf("ID CLIENTE   NOMBRE EMPRESA     CUIT         DIRECCION            LOCALIDAD        CANTIDAD EN ESTADO PENDIENTE \t \n");

    if(listaClientes != NULL && tamCliente > 0)
    {	for(int i=0; i<tamCliente ; i++)
    	{
    		if(listaClientes[i].isEmpty == OCUPADO)
    		{
    			MostrarUnClienteConPendientes(listaClientes[i],listaLocalidad,tamLocalidad,listaPedidos,tamPedido);
    			retorno = 1;
    		}
    	}
    }
    return retorno;
}

int ContadorPedidosPendientesPorCliente(eCliente unCliente,ePedido listaPedidos[],int tamPedido)
{
	int cantPendientes;
	cantPendientes = 0;

	for(int i = 0; i<tamPedido;i++)
	{
		if(listaPedidos[i].idCliente == unCliente.id && listaPedidos[i].isEmpty == PENDIENTE)
		{
			cantPendientes = cantPendientes+ 1;
		}
	}
	return cantPendientes;
}

int ContadorClientesPP(eCliente listaClientes[], int tamCliente, ePedido listaPedido[], int tamPedido)
{

	int contadorClientes;
	contadorClientes = 0;

	for(int i=0; i<tamCliente;i++)
	{
		if(listaClientes[i].isEmpty == OCUPADO)
		{
			for(int j=0; j<tamPedido;j++)
			{
				if(listaPedido[j].isEmpty == COMPLETADO && listaPedido[j].CantidadPP>0 && listaPedido[j].idCliente == listaClientes[i].id)
				{
					contadorClientes++; //ya con q tenga un pedido me alcanza
					break;
				}
			}
		}
	}
  return contadorClientes;
}

int AcumularPP(ePedido listaPedido[], int tamPedido)
{
	float acumuladorPP;
	acumuladorPP = 0;

	for(int i= 0; i< tamPedido; i++)
	{
		if(listaPedido[i].isEmpty == COMPLETADO)
		{
			acumuladorPP = listaPedido[i].CantidadPP + acumuladorPP;
		}
	}

	return acumuladorPP;
}



float CalcularPromedioPP(eCliente listaClientes[], int tamCliente, ePedido listaPedido[], int tamPedido)
{
	int contadorPP;
	float acumuladorPP;
	float promedioPP;
	promedioPP = -1;

	contadorPP = ContadorClientesPP(listaClientes,tamCliente,listaPedido,tamPedido);
	acumuladorPP = AcumularPP(listaPedido, tamPedido);

	printf("%d\n",contadorPP);
	printf("%f\n",acumuladorPP);
	if(contadorPP != 0)
	{
		promedioPP = acumuladorPP/contadorPP;
	}

	return promedioPP;
}

int ClientesMaximaCantidadPedidos(eCliente listaClientes[], int tamCliente, ePedido listaPedidos[],int tamPedido,int estado)
{
    int retorno;
    int flag;
    int maximo;
    retorno = 0;
    flag = 0;

    eAuxiliar contador[tamCliente];


    if(tamPedido > 0 && listaPedidos != NULL && tamCliente > 0 && listaClientes != NULL)
	{
    	retorno = 1;
    	for(int i = 0; i<tamCliente;i++) //recorro lista clientes INICIO CONTADOR
    	{
    		if(listaClientes[i].isEmpty == OCUPADO)
    		{
    			contador[i].idAux = listaClientes[i].id; //en el mismo indice asigno mismo valor de id
    			contador[i].contadorAux = 0; //inicializo contador
    		}
    	}

    	for(int i=0 ; i<tamCliente;i++) // CUENTO
    	{
    		if(listaClientes[i].isEmpty == OCUPADO)
    		{
    			for(int j=0 ;j<tamPedido;j++)
    			{
    				if(listaPedidos[j].isEmpty == estado && listaPedidos[j].idCliente == contador[i].idAux)
    				{
    					contador[i].contadorAux++;
    					// NO VA BREAK PORQ CUENTO TODOS LOS PEDIDOS , SINO SOLO ME CUENTA UNO
    				}
    			}
    		}
    	}

    	for(int i = 0; i<tamCliente;i++) //busco maximo
    	{
    		if(listaClientes[i].isEmpty == OCUPADO && (contador[i].contadorAux > maximo || flag == 0))
    		{
    			maximo = contador[i].contadorAux;
    			flag = 1;
    		}
    	}

    	printf("Cliente/s con mas pedidos pendientes: \n");
    	for(int i=0;i<tamCliente;i++) //comparo contadores, si ese contador del cliente coincide con el valor maximo
    	{
    		if(listaClientes[i].isEmpty== OCUPADO &&contador[i].contadorAux == maximo)
    		{
    			printf("%s\n",listaClientes[i].NombreEmpresa);
    		}
    	}



	}
    return retorno;
}




