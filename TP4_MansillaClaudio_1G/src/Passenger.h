
#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char estadoVuelo[20];

}Passenger;

// Constructores
Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* tipoPasajeroStr,
								   char* apellido, char* precioStr, char* codigoVuelo, char* estadoVuelo) ;

// Destructor
void Passenger_delete(Passenger* passenger);


// Setters y Getters

int Passenger_setIdString(Passenger* this, char* idStr);
int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int* id);

int Passenger_setNombre(Passenger* this, char* nombre);
int Passenger_getNombre(Passenger* this, char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this, char* apellido);

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo);

int Passenger_setTipoPasajeroString(Passenger* this, char* tipoPasajeroStr);
int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero);

int Passenger_setPrecioString(Passenger* this, char* precioStr);
int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float* precio);

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo);

void printStructEstatica(Passenger param);
void printPassengerDinamico(Passenger* pPassenger);
int compareFloatNumber(void* param1, void* param2);
int numberFloatFilter(void* param);
#endif /* PASSENGER_H_ */
