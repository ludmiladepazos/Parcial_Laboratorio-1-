/*
 * harcodeo.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Ludo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "harcodeo.h"
#include "cliente.h"

char cuit[5][12] = {{"27359961575"},{"27409961605"},{"28330996157"},{"30359251577"},{"27401256877"}};

char nombreEmpresa[5][14] = { {"IKEA"},{"CANON"},{"LEGO"},{"SONY"},{"WD-40"}};
char direccion[5][18] = {{"Riobamba 5525"},{"Meeks 414"},{"Yrigoyen 956"},{"Frias 5963"},{"Latarico 1697"}};
int idlocalidad[5] = {1,1,2,3,4};

int HardcodearClientes(eCliente lista[],int tam, int cantCargar, int* pIdAtuomatico)
{
    int cantidad = 0;

    if(lista!= NULL && cantCargar > 0 && cantCargar <= tam && pIdAtuomatico != NULL)
    {
        for(int i=0; i<cantCargar; i++)
        {
            lista[i].id = (*pIdAtuomatico);
            strcpy(lista[i].NombreEmpresa, nombreEmpresa[i]);
            strcpy(lista[i].direccion, direccion[i]);
            lista[i].idClocalidad =idlocalidad[i];
            strcpy(lista[i].cuit,cuit[i]);

            lista[i].isEmpty = OCUPADO;
            (*pIdAtuomatico)++;
             cantidad++;
        }
    }
    return cantidad;
}



