/*
 * TP 4 - DIV: 1G - Alumno: Mansilla Claudio Matias - email: clau.mmatt@gmail.com
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"



void ListarNodosElement(LinkedList* this);

int main(void) {

	setbuf(stdout, NULL);

	int retornoInt;

    LinkedList* lista = ll_newLinkedList();

	Passenger* pasajero1 = Passenger_newParametros("1000", "Freddie", "Primera Clase", "Mercury", "9500.5", "UA 818", "Activo");
	Passenger* pasajero2 = Passenger_newParametros("1001", "Brian", "Primera Clase", "May", "8040.5", "AE 910", "Activo");
	Passenger* pasajero3 = Passenger_newParametros("1002", "Roger", "Ejecutivo", "Taylor", "7890.6", "QR 777", "Activo");
	Passenger* pasajero4 = Passenger_newParametros("1004", "John", "Economy", "Deacon", "5677.1", "UA 818", "Activo");

    ll_add(lista, pasajero1);
    ll_add(lista, pasajero2);
    ll_add(lista, pasajero3);
    ll_add(lista, pasajero4);


    printf("\n----------------- Funcion utilizada: ll_len -----------------\n");
    retornoInt = ll_len(lista);
    printf("Pasajeros agregados = %d (ll_len)\n", retornoInt);
    ListarNodosElement(lista);
    printf("\n\n");


    printf("\n----------------- Funcion utilizada: ll_set -----------------\n");
	Passenger* pasAuxiliar = Passenger_newParametros("1005", "Farrokh", "Primera Clase", "Bulsara", "4802.1", "UA 818", "Activo");
	ll_set(lista, 0, pasAuxiliar);
	ListarNodosElement(lista);
	printf("\n\n");


    printf("\n----------------- Funcion utilizada: ll_remove -----------------\n");
	ll_remove(lista, 3);
	ListarNodosElement(lista);
	printf("\n\n");


	printf("\n----------------- Funcion utilizada: ll_indexOf -----------------\n");
	retornoInt= ll_indexOf(lista, pasajero3);
    printf("index encontrado segun busqueda: %d\n\n", retornoInt);


    printf("\n----------------- Funcion utilizada: ll_isEmpty -----------------\n");
    if(ll_isEmpty(lista))
    {
    	printf("LinkedList vacio (sin elementos)\n");
    }
    printf("ll_isEmpty ejecutado (contiene elementos)\n\n");


    printf("\n----------------- Funcion utilizada: ll_push -----------------\n");
    Passenger* pasAuxiliar2 = Passenger_newParametros("1006", "David", "Ejecutivo", "Bowie", "3000.1", "UA 818", "Activo");
    ll_push(lista, 0, pasAuxiliar2);
	ListarNodosElement(lista);
	printf("\n\n");


	printf("\n----------------- Funcion utilizada: ll_pop -----------------\n");
	pasAuxiliar = ll_pop(lista, 3);
	printf("Id: %d | Pasajero: %s  %s | Precio: $%.2f | FlyCode: %s\n",
			pasAuxiliar->id,
			pasAuxiliar->nombre,
			pasAuxiliar->apellido,
			pasAuxiliar->precio,
//			pasAuxiliar->tipoPasajero,
			pasAuxiliar->codigoVuelo
//			pasAuxiliar->estadoVuelo
	);

	printf("\n\n");


	printf("\n----------------- Funcion utilizada: ll_contains -----------------\n");
	if(ll_contains(lista, pasajero2))
	{
		printf("ll_contains ejecutado, cuyo retorno fue exitoso (pElement esta en el LinkedList)\n");
	}


	printf("\n----------------- Funcion utilizada: ll_subList -----------------\n");
	LinkedList* listaAux = ll_newLinkedList();
	listaAux = ll_subList(lista, 0, 2);
	ListarNodosElement(listaAux);
	printf("\n\n");


	printf("\n----------------- Funcion utilizada: ll_clone -----------------\n");
	listaAux = ll_clone(lista);
	ListarNodosElement(listaAux);
	printf("\n\n");

	printf("\n----------------- Funcion utilizada: ll_containsAll -----------------\n");
	if(ll_containsAll(lista, listaAux))
	{
		printf("Los elementos de -listaAux- estan contenidos en -lista-\n");
	}
	printf("\n\n");


	printf("\n----------------- Funcion utilizada: ll_sort -----------------\n");
	retornoInt = ll_sort(listaAux, compareFloatNumber, 1);
	printf("Criterio: Precios ASC aplicado a -lista-\n");
	ListarNodosElement(listaAux);
	printf("\n\n");


	printf("\n----------------- Funcion utilizada: ll_filter -----------------\n");
	printf("Criterio de filtrado: precio >= '5000'\n");
	listaAux = ll_filter(lista, numberFloatFilter);
	if(listaAux == NULL)
	{
		printf("Se ha producido un error: ll_filter devolvio un element null\n");
	}
	else
	{
		ListarNodosElement(listaAux);
	}
	printf("\n\n");


    printf("\n----------------- Funcion utilizada: ll_clear -----------------\n");
	retornoInt = ll_clear(lista);
	if( !retornoInt )
	{
		printf("Los elementos de -lista- han sido des-referenciado\n");
	}

	retornoInt = ll_clear(listaAux);
	{
		printf("Los elementos de -listaAux- han sido des-referenciado\n");
	}
	printf("\n\n");

	Passenger_delete(pasajero1);
	Passenger_delete(pasajero2);
	Passenger_delete(pasajero3);
	Passenger_delete(pasajero4);
//	Passenger_delete(pasAuxiliar); --> pasAuxiliar ya fue des-ref al utilizar ll_pop
	Passenger_delete(pasAuxiliar2);


    printf("\n----------------- Funcion utilizada: ll_deleteLinkedList -----------------\n");
	retornoInt = ll_deleteLinkedList(lista);
	if( !retornoInt)
	{
		printf("LinkedList -lista- ha sido eliminada\n");
	}

	retornoInt = ll_deleteLinkedList(listaAux);
	if( !retornoInt)
	{
		printf("LinkedList -listaAux- ha sido eliminada\n");
	}
	printf("\n\n");

	system("pause");
    return EXIT_SUCCESS;
}


void ListarNodosElement(LinkedList* this){

	Passenger* aux = NULL;

	int len = ll_len(this);

    if(this != NULL)
    {
        for(int i=0; i < len ; i++)
        {
        	aux = (Passenger*) ll_get(this, i);
    		printf("Id: %d | Pasajero: %s  %s | Precio: $%.2f | FlyCode: %s\n",
    				aux->id,
					aux->nombre,
					aux->apellido,
					aux->precio,
//					aux->tipoPasajero, // lo quito para que entre lo demas en cmd de windows
					aux->codigoVuelo
//					aux->estadoVuelo
    		);
        }
    }
}

