/*
 ============================================================================
 Name        : PrimerParcialLabo.c
 Author      : Ludmila
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "harcodeo.h"
#include "pedido.h"
#include "informes.h"
#include "validaciones.h"
#include "localidad.h"

#define TAM_CLIENTE 100
#define TAM_PEDIDO 1000
#define TAM_LOCALIDAD 5

int main(void)
{
	setbuf(stdout,NULL);

	char salir;
	salir = 'n';
	int idAutomatico;
	int idPedidos;
	float promedioPP;
	int flagA;

	flagA = 0;
	idPedidos = 1;
	idAutomatico = 1;

	eCliente listaClientes[TAM_CLIENTE];
	ePedido listaPedidos[TAM_PEDIDO];
	eLocalidad listaLocalidad[TAM_LOCALIDAD] = {{1,"TEMPERLEY"},{2,"BANFIELD"},{3,"LANUS"},{4,"CABA"},{5,"QUILMES"}};

	InicializarListaProductos(listaClientes,TAM_CLIENTE);
	InicializarListaPedido(listaPedidos,TAM_PEDIDO);
	HardcodearClientes(listaClientes,TAM_CLIENTE,5,&idAutomatico);
	//HardcodearLocalidad(listaLocalidad,TAM_LOCALIDAD,5);

	do
	{
		switch(MenuPrincipal())
		{
			case 1://ALTA
				if(AltaCliente(listaClientes,TAM_CLIENTE,&idAutomatico,listaLocalidad,TAM_LOCALIDAD))
				{
					printf("Carga exitosa\n");
				}
				else
				{
					printf("No se puede agregar cliente, lista llena \n");
				}
				break;
			case 2://MODIFICACION
				if(ModificarCliente(listaClientes,TAM_CLIENTE,listaLocalidad,TAM_LOCALIDAD))
				{
					printf("Modificacion exitosa\n");
				}
				else
				{
					printf("No se pudo modificar\n");
				}
				break;
			case 3: //BAJA
				if(BajaCliente(listaClientes,TAM_CLIENTE,listaLocalidad,TAM_LOCALIDAD))
				{
					printf("Baja de cliente exitosa\n");
				}
				else
				{
					printf("No se realizo la baja\n");
				}
				break;
			case 4: //CREAR PEDIDO DE RECOLECCION
				if(CrearPedidoRecoleccion (listaClientes,TAM_CLIENTE,listaPedidos,TAM_PEDIDO,&idPedidos,listaLocalidad,TAM_LOCALIDAD))
				{
					printf("Su pedido ha pasado a pendiente\n");
				}
				else
				{
					printf("No se realizo el pedido\n");
				}
				flagA = 1;
				break;
			case 5://Procesar Residuos
				if(flagA == 1)
				{
					MostrarListaPedidos(listaPedidos,TAM_PEDIDO);

					if(ProcesarPedido(listaPedidos,TAM_PEDIDO))
					{
						printf("Su pedido ha pasado a COMPLETADO\n");
					}
					else
					{
						printf("No se proceso el pedido\n");
					}
				}
				else
				{
					printf("No se puede acceder a la opcion 5 si previamente no se accedio a la opcion 4\n");
				}
				break;
			case 6: //MOSTRAR CLIENTES
				if(MostrarListadoClientesConPendientes(listaClientes,TAM_CLIENTE,listaLocalidad,TAM_LOCALIDAD,listaPedidos,TAM_PEDIDO))
				{
					printf("Listado mostrado correctamente \n");
				}
				else
				{
					printf("Lista vacia\n");
				}
				break;
			case 7: //Imprimir Pedidos pendientes
				if(ImprimirPendientes(listaClientes,TAM_CLIENTE,listaPedidos,TAM_PEDIDO))
				{
					printf("Pedidos pendientes impresos \n");
				}
				else
				{
					printf("No se imprimio los pendientes\n");
				}
				break;
			case 8://Imprimir Pedidos procesados
				if(ImprimirCompletados(listaClientes,TAM_CLIENTE,listaPedidos,TAM_PEDIDO))
				{
					printf("Pedidos completados impresos \n");
				}
				else
				{
					printf("No se imprimio los completados\n");
				}
				break;
			case 9:
				PendientesPorLocalidad(listaClientes, TAM_CLIENTE, listaLocalidad, TAM_LOCALIDAD, listaPedidos, TAM_PEDIDO);
				break;
			case 10: //Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
				promedioPP = CalcularPromedioPP(listaClientes, TAM_CLIENTE, listaPedidos, TAM_PEDIDO);

				if(promedioPP != -1)
				{

					printf("Promedio kilos PP por cliente %2.2f\n", promedioPP);
				}
				else
				{
					printf("No se pudo calcular promedio PP\n");
				}
				break;
			case 11:
				if(!ClientesMaximaCantidadPedidos(listaClientes,TAM_CLIENTE,listaPedidos,TAM_PEDIDO,PENDIENTE))
				{
					printf("Error\n");
				}
				break;
			case 12:
				if(!ClientesMaximaCantidadPedidos(listaClientes,TAM_CLIENTE,listaPedidos,TAM_PEDIDO,COMPLETADO))
				{
					printf("Error\n");
				}
				break;
			case 13:
				printf("Confirma salida s/n: \n");
				fflush(stdin);
				scanf("%c",&salir);
				break;
			default:
				printf("Error,opcion invalida \n");
		}

	}while(salir != 's');

	return EXIT_SUCCESS;

}



