/*
 * cliente.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Ludo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "cliente.h"
#include "localidad.h"

int InicializarListaProductos(eCliente listaClientes[],int tam) //todos los espacios de la lista comienzan vacios
{
	int retorno;
	retorno = 0;

	if(listaClientes != NULL && tam > 0)
	{
		for(int i=0 ; i<tam; i++ )
		{
			listaClientes[i].isEmpty= LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}

int AltaCliente(eCliente listaClientes[],int tam,int* idAutomatico,eLocalidad listaLocalidad[],int tamLocalidad) // CARGO EL ARRAY CON LOS DATOS DE LA ESTRUCTURA
{
	int retorno;
	int auxId;
	auxId = *idAutomatico;
	retorno = 0;

	if(listaClientes != NULL && tam > 0 && listaLocalidad != NULL && tamLocalidad >0)
	{
		for(int i=0 ; i<tam; i++ ) //lista cliente
		{
			if(listaClientes[i].isEmpty == LIBRE )
			{
				listaClientes[i].id = auxId;
				myGets(listaClientes[i].NombreEmpresa,"Ingrese nombre de la empresa: \n",sizeof(listaClientes[i].NombreEmpresa));
				myGets(listaClientes[i].cuit,"Ingrese nro de Cuit 12 digitos: \n",sizeof(listaClientes[i].cuit));
				myGets(listaClientes[i].direccion,"Ingrese direccion de la empresa: \n",sizeof(listaClientes[i].direccion));

				printf("Ingrese localidad por ID: \n");
				MostrarListaLocalidades(listaLocalidad,tamLocalidad);
				fflush(stdin);
				scanf("%d",&listaClientes[i].idClocalidad);

				listaClientes[i].isEmpty = OCUPADO;

				auxId++;
				*idAutomatico = auxId;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}



int ModificarCliente(eCliente listaClientes[], int tamCliente,eLocalidad listaLocalidad[],int tamLocalidad)//busco un producto por su id modifico direccion y localidad
{
	int idBuscado;
	int subMenu;
	int retorno;
	retorno = 0;

	if(listaClientes != NULL && tamCliente > 0)
	{
		MostrarListadoClientes(listaClientes,tamCliente,listaLocalidad,tamLocalidad);
		utn_getNumero(&idBuscado, "Ingrese Id del cliente a modificar:  " ,"Error\n" ,1,100,10);

		for(int i=0; i<tamCliente; i++)//buscar dato
		{
			if(listaClientes[i].isEmpty == OCUPADO && listaClientes[i].id == idBuscado)
			{
				printf("1)Modificar direccion\n 2)Modificar localidad\n");
				utn_getNumero(&subMenu, "Ingrese opcion: \n" ,"Error\n" ,1,2,10);

				switch(subMenu)
				{
				   case 1:
					   myGets(listaClientes[i].direccion,"Ingrese direccion de la empresa: \n",sizeof(listaClientes[i].direccion));
				       break;
				   case 2:
					   printf("Ingrese id de localidad a modificar: \n");
					   MostrarListaLocalidades(listaLocalidad,tamLocalidad);
					   fflush(stdin);
					   scanf("%d",&listaClientes[i].idClocalidad);
					   //myGets(listaClientes[i].localidad,"Ingrese localidad de la empresa: \n",sizeof(listaClientes[i].localidad));
				       break;
				   default:
					   printf("Opcion erronea\n");
					   break;
				 }
				 retorno = 1;
				 break;
			}
		}
	}
	return retorno;
}

int BajaCliente(eCliente listaClientes[], int tamCliente,eLocalidad listaLocalidad[],int tamLocalidad) //Se ingresa el ID del cliente. Luego se preguntará si se quiere confirmar la eliminación.
{
	int idBuscado;
	int retorno;
	char respuesta;
	retorno = 0;

	if(listaClientes != NULL && tamCliente > 0)
	{
		idBuscado = BuscarCliente(listaClientes,tamCliente,listaLocalidad,tamLocalidad); //idBuscado retorna el indice correspondiente al id que busque
		if(idBuscado != -1)
		{
			MostrarUnCliente(listaClientes[idBuscado],listaLocalidad,tamLocalidad);
			printf("Desea eliminar este cliente: s/n");
			fflush(stdin);
			scanf("%c",&respuesta);
			if(respuesta == 's')
			{
				listaClientes[idBuscado].isEmpty = LIBRE;
				retorno = 1;
			}
		}
	}
	return retorno;
}

int BuscarCliente(eCliente listaClientes[], int tamCliente,eLocalidad listaLocalidad[],int tamLocalidad)
{
	int idBuscado;
	int indiceCliente;
	indiceCliente = -1;

	MostrarListadoClientes(listaClientes,tamCliente,listaLocalidad,tamLocalidad);

	utn_getNumero(&idBuscado, "Ingrese id del cliente que desea buscar: \n" ,"Error\n" ,1,100,10);

	for(int i=0; i<tamCliente; i++)
	{
		if(listaClientes[i].isEmpty == OCUPADO && listaClientes[i].id == idBuscado)
		{
			indiceCliente = i;
			break;
		}
	}
	return indiceCliente;
}

void MostrarUnCliente(eCliente unCliente,eLocalidad listaLocalidad[], int tamLocalidad)
{
	char nombreLocalidad[50];
	CargarNombreLocalidad(unCliente.idClocalidad,listaLocalidad,tamLocalidad,nombreLocalidad );
	printf("%4d   %12s     %15s    %15s   %15s     \n",unCliente.id,unCliente.NombreEmpresa, unCliente.cuit,unCliente.direccion,nombreLocalidad);
}

void MostrarListadoClientes(eCliente listaClientes[], int tamCliente,eLocalidad listaLocalidad[], int tamLocalidad)
{
	printf("ID CLIENTE   NOMBRE EMPRESA     CUIT         DIRECCION            LOCALIDAD       \t \n");
	if(listaClientes != NULL && tamCliente > 0)
	{
		for(int i=0; i<tamCliente ; i++)
		{
			if(listaClientes[i].isEmpty == OCUPADO)
			{
				MostrarUnCliente(listaClientes[i],listaLocalidad,tamLocalidad);

			}
		}
	}

}





