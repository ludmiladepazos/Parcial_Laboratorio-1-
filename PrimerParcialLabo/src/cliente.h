/*
 * cliente.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Ludo
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define LIBRE 0
#define OCUPADO 1


typedef struct
{
  int id;
  char NombreEmpresa[50];
  char cuit[12];
  char direccion[50];
  char localidad [50];
  int contadorPedidos;

  int isEmpty;

}eCliente;

/// @brief Inicializa el array clientes con el estado LIBRE, permitiendo que luego puedan cargarse datos.
///
/// @param listaClientes array que contiene los datos de la estructura a cargar
/// @param tam tamaño del array
/// @return retorna 1 en caso de que el estado del array cambie a LIBRE, 0 en caso de que la funcion no cumplio lo pedido
int InicializarListaProductos(eCliente listaClientes[],int tam);

/// @brief Funcion que carga con datos cada campo de la estructura, se genera un id autoincrementable y el estado pasa de LIBRE a OCUPADO
///
/// @param listaClientes array que contiene los datos de la estructura a cargar
/// @param tam tamaño del array
/// @param variable que paso por referencia para generar el id autoincrementable
/// @return retorna 1 en caso de que se dio el alta al cliente correctamente, 0 en caso de que no currio el alta
int AltaCliente(eCliente listaClientes[],int tam,int* idAutomatico,eLocalidad listaLocalidad[],int tamLocalidad);

/// @brief Funcion que muestra los campos de la estructura de un cliente
///
/// @param unCliente un cliente del array
void MostrarUnCliente(eCliente unCliente);

/// @brief Funcion que muestra el listado de clientes dados de alta
///
/// @param listaClientes array que contiene los datos de la estructura a mostrar
/// @param tam tamaño del array
/// @return retorna 1 en caso de que se muestren los clientes, 0 en caso de que no se puedan mostrar
int MostrarListadoClientes(eCliente listaClientes[], int tam);

/// @brief Funcion que permite hacer modificaciones en los datos del cliente
///
/// @param listaClientes array que contiene los datos a modificar
/// @param tam tamaño del array
/// @return retorna 1 en caso de que se haya podido realizar alguna modificacion, 0 en caso de que no se puedo modificar datos del cliente
int ModificarCliente(eCliente listaClientes[],int tam);

/// @brief Funcion que busca un cliente a traves del ingreso de su id
///
/// @param listaClientes array que contiene los datos de la estructura cliente
/// @param tam tamaño del array
/// @return retorna la posicion, indice, de ese cliente buscado, en caso de no realizarse la busqueda retorna -1
int BuscarCliente(eCliente listaClientes[],int tam);

/// @brief Funcion que produce la baja logica de un cliente a traves del cambio de su estado de OCUPADO a LIBRE
///
/// @param listaClientes array que contiene los datos de la estructura cliente
/// @param tam tamaño del array
/// @return en caso de realizarse la baja retorna 1, en caso contrario retorna 0
int BajaCliente(eCliente listaClientes[],int tam);


#endif /* CLIENTE_H_ */
