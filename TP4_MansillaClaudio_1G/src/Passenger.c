#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "Passenger.h"


// CONSTRUCTORES ------------------------------------------------------------

Passenger* Passenger_new(){

	Passenger* nuevoPass = (Passenger*) malloc(sizeof(Passenger));

	if(nuevoPass != NULL )
	{
		//si el return es false libero memoria asignada y retorna null
		if( !(Passenger_setId(nuevoPass, 0) &&
			Passenger_setNombre(nuevoPass, "") &&
			Passenger_setApellido(nuevoPass, "") &&
			Passenger_setPrecio(nuevoPass, 0) &&
			Passenger_setTipoPasajero(nuevoPass, 0) &&
			Passenger_setCodigoVuelo(nuevoPass, "") &&
			Passenger_setEstadoVuelo(nuevoPass, "")
				))
		{

			free(nuevoPass);
			nuevoPass = NULL;
		}
	}
	return nuevoPass;
}


Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* tipoPasajeroStr,
								   char* apellido, char* precioStr, char* codigoVuelo, char* estadoVuelo) {

	Passenger* nuevoPass = Passenger_new();
	if(nuevoPass == NULL)
	{
		printf("rompe");
	}

	// printf por consola para debug, verificar return ok de setters
//	printf("id parametro: %d\n", Passenger_setIdString(nuevoPass, idStr));
//			 printf("nombre parametro: %d\n", Passenger_setNombre(nuevoPass, nombreStr));
//			 printf("apellido parametro: %d\n", Passenger_setApellido(nuevoPass, apellido));
//			 printf("precio parametro: %d\n", Passenger_setPrecioString(nuevoPass, precioStr));
//			 printf("codigo parametro: %d\n", Passenger_setCodigoVuelo(nuevoPass, codigoVuelo));
//			 printf("tipo parametro: %d\n", Passenger_setTipoPasajeroString(nuevoPass, tipoPasajeroStr));
//			 printf("estado parametro: %d\n", Passenger_setEstadoVuelo(nuevoPass, estadoVuelo));

	if(nuevoPass != NULL )
	{
		//si el return es false libero memoria asignada y retorna null
		if( !(Passenger_setIdString(nuevoPass, idStr) &&
			Passenger_setNombre(nuevoPass, nombreStr) &&
			Passenger_setApellido(nuevoPass, apellido) &&
			Passenger_setPrecioString(nuevoPass, precioStr) &&
			Passenger_setTipoPasajeroString(nuevoPass, tipoPasajeroStr) &&
			Passenger_setCodigoVuelo(nuevoPass, codigoVuelo) &&
			Passenger_setEstadoVuelo(nuevoPass, estadoVuelo)
		   ))
		{
			free(nuevoPass);
			nuevoPass = NULL;
		}
	}

	return nuevoPass;
}



//Destructor
void Passenger_delete(Passenger* passenger){

	free(passenger);
}





// SETTERS Y GETTERS ------------------------------------------------------------

int Passenger_setId(Passenger* this, int id) {

	int retorno = 0;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}


int Passenger_setIdString(Passenger* this, char* idStr) {

	int retorno = 0;
	if(this != NULL && idStr != NULL)
	{
		this->id = atoi(idStr);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getId(Passenger* this, int* id){

	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}


int Passenger_setPrecio(Passenger* this, float precio) {

	int retorno = 0;
	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setPrecioString(Passenger* this, char* precioStr) {

	int retorno = 0;
	if(this != NULL && precioStr != NULL)
	{
		this->precio = atof(precioStr);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getPrecio(Passenger* this, float* precio) {

	int retorno = 0;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}

	return retorno;
}


int Passenger_setNombre(Passenger* this, char* nombre){

	int retorno = 0;
//	int len = strlen(nombre);
//	int lenThis = strlen(this->nombre);

	// valido nombres de tres letras y que no superen longitud maxima
	if(this != NULL && nombre != NULL )
	{
		strcpy(this->nombre, nombre);
		strlwr(this->nombre);
		(this->nombre)[0] = toupper((this->nombre)[0]);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this, char* nombre) {

	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}


int Passenger_setApellido(Passenger* this,char* apellido){

	int retorno = 0;
//	int len = strlen(apellido);
//	int lenThis = strlen(this->apellido);

	// valido nombres de tres letras y que no superen longitud maxima
	if(this != NULL && apellido != NULL )
	{
		strcpy(this->apellido, apellido);
		strlwr(this->apellido);
		(this->apellido)[0] = toupper((this->apellido)[0]);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this, char* apellido) {

	int retorno = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 1;
	}

	return retorno;
}


int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo) {

	int retorno = 0;
//	int len = strlen(codigoVuelo);
//	int lenThis = strlen(this->codigoVuelo);

	// valido nombres de tres letras y que no superen longitud maxima
//	if(this != NULL && codigoVuelo != NULL && len > 2 && (len < lenThis) )
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		strupr(this->codigoVuelo);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo) {

	int retorno = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 1;
	}

	return retorno;
}


int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero){

	int retorno = 0;
	if(this != NULL)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setTipoPasajeroString(Passenger* this, char* tipoPasajeroStr){

	int retorno = 0;
	if(this != NULL && tipoPasajeroStr != NULL)
	{
		if(strcmp(tipoPasajeroStr, "Primera Clase")==0)
		{
			this->tipoPasajero = 1;
		}

		else if (strcmp(tipoPasajeroStr, "Ejecutivo")==0)
		{
			this->tipoPasajero = 2;
		}

		else if(strcmp(tipoPasajeroStr, "Economy")==0)
		{
			this->tipoPasajero = 3;
		}
		retorno = 1;
	}

	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero) {

	int retorno = 0;
	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo) {

	int retorno = 0;
//	int len = strlen(estadoVuelo);
//	int lenThis = strlen(this->estadoVuelo);

	// valido nombres de tres letras y que no superen longitud maxima
	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->estadoVuelo, estadoVuelo);
		strupr(this->estadoVuelo);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo) {

	int retorno = 0;
	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		retorno = 1;
	}

	return retorno;
}


// Funciones para print de informacion

void printStructEstatica(Passenger param) {

    printf("%d      %10s      %10s      %.2f      %d	 %10s	 %10s\n",
    		param.id,
			param.nombre,
			param.apellido,
			param.precio,
			param.tipoPasajero,
			param.codigoVuelo,
			param.estadoVuelo
    );
}

void printPassengerDinamico(Passenger* pPassenger){

    printf("%d      %10s      %10s      %.2f      %d	 %10s	 %10s\n",
    		pPassenger->id,
			pPassenger->nombre,
			pPassenger->apellido,
			pPassenger->precio,
			pPassenger->tipoPasajero,
			pPassenger->codigoVuelo,
			pPassenger->estadoVuelo
    );
}

/**
 * return se utiliza criterio de return de strcmp
 */
int compareFloatNumber(void* param1, void* param2){

    int retorno = 0;
    float buffer1;
    float buffer2;

    if(param1 != NULL && param2 != NULL)
    {
    	//aqui utilizar los getters que correspondan al contexto
        Passenger_getPrecio(param1, &buffer1);
        Passenger_getPrecio(param2, &buffer2);
        if(buffer1 > buffer2)
        {
            retorno = 1;
        }
        else
        {
            if(buffer1 < buffer2)
            {
            	retorno = -1;
            }
        }
    }
    return retorno;
}


int numberFloatFilter(void* param){

    int retorno = 0;
    float aux;

    if(param != NULL)
    {
        Passenger_getPrecio(param, &aux);
        if(aux >=5000)
        {
            retorno = 1;
        }
    }
    return retorno;
}
