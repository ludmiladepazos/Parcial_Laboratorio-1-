/*
 * localidad.c
 *
 *  Created on: 19 oct. 2021
 *      Author: Ludo
 *
1) Agregar la entidad Localidad.
2) Refactorizar las funciones que considere necesarias para que utilicen la nueva entidad.
3) Agregar los siguientes informes:
a) Cliente con más pedidos pendientes.
b) Cliente con más pedidos completados.
Nota 1: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las funciones (Alta, Baja, Modificar, etc.).
Los informes deberán estar en una biblioteca aparte.
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo
de la cátedra.*/

#ifndef LOCALIDAD_C_
#define LOCALIDAD_C_
#include "localidad.h"
#include "validaciones.h"


#endif /* LOCALIDAD_C_ */



void MostrarLocalidad(eLocalidad localidad)
{
  printf("%4d   %12s \n",localidad.idLocalidad,localidad.nombreLocalidad);
}

int MostrarListaLocalidades(eLocalidad listaLocalidad[],int tamLocalidad)
{
    int retorno;
    retorno = 0;

    printf("  LOCALIDAD \t \n");

    if(listaLocalidad != NULL && tamLocalidad > 0)
    {	for(int i=0; i<tamLocalidad ; i++)
    	{
    		MostrarLocalidad(listaLocalidad[i]);
    		retorno = 1;
    	}
    }
    return retorno;
}


int CargarNombreLocalidad(int idLocalidad, eLocalidad listaLocalidad[],int tamLocalidad,char aux[])
{
	int retorno;
	retorno = 0;
	if(idLocalidad>0 && idLocalidad<6 && listaLocalidad!=NULL && tamLocalidad >0 && aux!= NULL)
	{
		for(int i = 0; i<tamLocalidad;i++)
		{
			if(idLocalidad == listaLocalidad[i].idLocalidad)
			{
				strcpy(aux,listaLocalidad[i].nombreLocalidad);
				retorno = 1;
				break; //si encontre lo que busco para que seguir buscando, lo corto
			}
		}


	}
	return retorno;
}



int BuscarLocalidad(eLocalidad listaLocalidad[],int tamLocalidad)
{
	int idBuscado;
	int indiceLocalidad;
	indiceLocalidad = -1;

	MostrarListaLocalidades(listaLocalidad,tamLocalidad);

	utn_getNumero(&idBuscado, "Ingrese id de localidad que desea buscar: \n" ,"Error\n" ,1,5,10);

	for(int i=0; i<tamLocalidad; i++)
	{
		if(listaLocalidad[i].idLocalidad == idBuscado)
		{
			indiceLocalidad = i;
			break;
		}
	}
	return indiceLocalidad;
}

/*int id[5] = {1,1,2,3,4};
char nombreL[5][14] = {{"TEMERLEY"},{"TEMPERLEY"},{"LANUS"},{"GERLI"},{"CABA"}};
int HardcodearLocalidad(eLocalidad listaLocalidad[],int tam,int cantCargar)
{
    int cantidad = 0;

    if(listaLocalidad!= NULL && cantCargar > 0 && cantCargar <= tam)
    {
        for(int i=0; i<cantCargar; i++)
        {
        	listaLocalidad[i].idLocalidad = id[i];
        	strcpy(listaLocalidad[i].nombreLocalidad ,nombreL[i]);
        	listaLocalidad[i].isEmpty = OCUPADO;
        	cantidad++;
        }
    }
    return cantidad;
}*/

/*int InicializarLocalidad(eLocalidad listaLocalidad[],int tamLocalidad) //todos los espacios de la lista comienzan vacios
{
	int retorno;
	retorno = 0;

	if(listaLocalidad != NULL && tamLocalidad > 0)
	{
		for(int i=0 ; i<tamLocalidad; i++ )
		{
			listaLocalidad[i].isEmpty= LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}

CargarLocalidades(eLocalidad listaLocalidad[],int tamLocalidad,int cantCargar, int* pIdAtuomatico)
{
	 int cantidad = 0;

	 if(listaLocalidad!= NULL && cantCargar > 0 && cantCargar <= tamLocalidad && pIdAtuomatico != NULL)
	 {
	       for(int i=0; i<cantCargar; i++)
	       {
	    	   listaLocalidad[i].idCLocalidad = (*pIdAtuomatico);


	            strcpy(listaLocalidad[i].nombreLocalidad, NombreLocalidad[i]);

	            listaLocalidad[i].isEmpty = OCUPADO;
	            (*pIdAtuomatico)++;
	             cantidad++;
	       }
	   }
	    return cantidad;

}



int Altalocalidad(eLocalidad listaLocalidad[],int tamLocalidad,int* autoIdLocalidad) // CARGO EL ARRAY CON LOS DATOS DE LA ESTRUCTURA
{
	int retorno;
	int auxId;
	auxId = *autoIdLocalidad;
	retorno = 0;

	if(listaLocalidad != NULL && tamLocalidad > 0 && listaLocalidad != NULL && tamLocalidad >0)
	{
		for(int i=0 ; i<tamLocalidad; i++ )
		{
			if(listaLocalidad[i].isEmpty == LIBRE )
			{
				listaLocalidad[i].idCLocalidad = auxId;
				myGets(listaLocalidad[i].nombreLocalidad,"Ingrese nombre de la localidad : \n",sizeof(listaLocalidad[i].nombreLocalidad));

				listaLocalidad[i].isEmpty = OCUPADO;

				auxId++;
				*autoIdLocalidad = auxId;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}






int ModificarLocalidad(eLocalidad listaLocalidad[],int tamLocalidad)//
{
	int idBuscado;
	int subMenu;
	int retorno;
	retorno = 0;

	if(listaLocalidad != NULL && listaLocalidad > 0)
	{
		MostrarListaLocalidades(listaLocalidad,listaLocalidad);
		utn_getNumero(&idBuscado, "Ingrese Id del cliente a modificar: n" ,"Error\n" ,1,100,10);

		for(int i=0; i<listaLocalidad; i++)//buscar dato
		{
			if(listaLocalidad[i].isEmpty == OCUPADO && listaLocalidad[i].idCLocalidad == idBuscado)
			{
				printf("1)Modificar localidad\n");
				utn_getNumero(&subMenu, "Ingrese opcion \n:" ,"Error\n" ,1,1,10);

				switch(subMenu)
				{
				   case 1:
					   myGets(listaLocalidad[i].nombreLocalidad,"Ingrese localidad de la empresa: \n",sizeof(listaLocalidad[i].nombreLocalidad));
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

int Bajalocalidad(eLocalidad listaLocalidad[],int tamLocalidad)
{
	int idBuscado;
	int retorno;
	char respuesta;
	retorno = 0;

	if(listaLocalidad != NULL && tamLocalidad > 0)
	{
		idBuscado = Buscarlocalidad(listaLocalidad,tamLocalidad);
		if(idBuscado != -1)
		{
			MostrarLocalidad(listaLocalidad[idBuscado]);
			printf("Desea eliminar este cliente: s/n");
			fflush(stdin);
			scanf("%c",&respuesta);
			if(respuesta == 's')
			{
				listaLocalidad[idBuscado].isEmpty = LIBRE;
				retorno = 1;
			}
		}
	}
	return retorno;
}*/

