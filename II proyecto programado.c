
#include <stdio.h>   		       
#include <stdlib.h>			
#include <string.h>
			
typedef struct Nino{				
	int identificacion;
	char nombre[50];
	char username[20];
	char correo[30];
	char nacimiento[15];
	int edad;
	char necesidades[15];
	int arrayDeseos[15]; 
	struct Nino* siguiente;
}Nino;

typedef struct ListaNino{			
	Nino* cabeza;
	Nino* cola;
}ListaNino;

typedef struct Ayudante{				
	int identificacion;
	char nombre[50];
	char puesto[50];
	char funciones[100];
	char fechaInicio[15];
	int cantCartas;
	struct Ayudante* siguiente;
}Ayudante;

typedef struct ListaAyudante{			
	Ayudante* cabeza;
	Ayudante* cola;
}ListaAyudante;

typedef struct Comportamiento{
	int identificacion;
	int dia;
	int mes;
	int ano;
	int comportamiento;
	char nombrePadre[50]; 
	char descripcion[100];
	struct Comportamiento* siguiente;
}Comportamiento;

typedef struct ColaComportamiento{
	Comportamiento* front;
	Comportamiento* rear;
}ColaComportamiento;

typedef struct Juguete{
	int cantPedido;
	int codigo;
	char nombre[50];
	char descripcion[100];
	char categoria[50];
	int rangoInicial;
	int rangoFinal;
	float costo;
	struct Juguete *izq;
	struct Juguete *der;	
}Juguete;

typedef struct Carta{
	char estadoCarta[15];
	int IDAyudanteProce;
	int ano;
	int identificacion;
	int juguete1;
	char estadoJuguete1[25];
	int juguete2;
	char estadoJuguete2[25];
	int juguete3;
	char estadoJuguete3[25];
	int juguete4;
	char estadoJuguete4[25];
	int juguete5;
	char estadoJuguete5[25];
	int juguete6;
	char estadoJuguete6[25];
	int juguete7;
	char estadoJuguete7[25];
	int juguete8;
	char estadoJuguete8[25];
	int juguete9;
	char estadoJuguete9[25];
	int juguete10;
	char estadoJuguete10[25];
	struct Carta *siguiente;
}Carta;

typedef struct ColaCarta{
	Carta* front;
	Carta* rear;
}ColaCarta;

typedef struct Nodo{
	int dato;
	struct Nodo *siguiente;
}Nodo;

typedef struct ListaDeseos{
	Nodo* cabeza;
	Nodo* cola;
}ListaDeseos;

void gestionNino(ListaNino **listaNino);  //********
void registrarNino(ListaNino **listaNino);
void enlistarNino(ListaNino **listaNino, int identificacion, char *nombre, char *username, char *correo, char *nacimiento, int edad, char *necesidades);
void visualizarNino(ListaNino **listaNino);
void eliminarNino(ListaNino **listaNino);
int modificarNino(ListaNino **listaNino);
void gestionAyudantes();  //*************
void registrarAyudante(ListaAyudante **listaAyudante);
void enqueueAyudante(ListaAyudante **listaAyudante, int identificacion, char *nombre, char *puesto, char *funciones, char *fechaInicio);
void visualizarAyudante(ListaAyudante **listaAyudante);
void eliminarAyudante(ListaAyudante **listaAyudante);
int modificarAyudante(ListaAyudante **listaAyudante);
void gestionJuguetes();  //************
void registrarJuguete();
void insertarJuguete(int codigo, char *nombre, char *descripcion, char *categoria, int rangoInicial, int rangoFinal, float costo);
void visualizarJuguete(struct Juguete *reco);
void eliminarJuguete();
int modificarJuguete(struct Juguete *reco, char *nombre);
void gestionCatalogoLugares();  //***********
void registrarLugar();
void visualizarLugar();
void modificarLugar();
void eliminarLugar();
void visualizarRuta();
void eliminarRuta();
void modificarRuta();
void registrarComportamiento(ColaComportamiento **colaComportamiento); //*************
void enColarComportamiento(ColaComportamiento **colaComportamiento, int identificacion, int comportamiento, int dia, int mes, int ano, char *nombrePadre, char *descripcion);
void desplegarComportamiento(ColaComportamiento **colaComportamiento);  
int gestionCarta(ColaCarta **colaCarta, ListaNino **listaNino);  //**************
void registrarCarta(ColaCarta **colaCarta, ListaNino **listaNino);
int busquedaJuguete(char *nombre, struct Juguete *reco);
void enColarCarta(ColaCarta **colaCarta, int ano, int juguete1, int juguete2, int juguete3, int juguete4, int juguete5, int juguete6, int juguete7, int juguete8, int juguete9, int juguete10, int identificacion);
void visualizarCarta(ColaCarta **colaCarta);
void editarCarta(ListaNino **listaNino, ColaCarta **colaCarta);
void editarListaDeseos(ListaNino **listaNino, ColaCarta **colaCarta);
int busquedaJugueteID(int codigo, struct Juguete *reco);
int sumarSolicitud(int codigo, struct Juguete *reco);
void procesarCarta(ListaNino **listaNino, ColaCarta **colaCarta, ListaAyudante **listaAyudante, ColaComportamiento **colaComportamiento);  //*********
void entregarJuguetes();
void analisisDatos(ColaCarta **colaCarta, ListaAyudante **listaAyudante);  //*********
void AD_cantJuguetes(ColaCarta **colaCartas);
void AD_masmenosJuguetes();
int anoExisteCarta(int ano);
void AD_ninosAprobados(ColaCarta **colaCarta);
void AD_ninosRechazados(ColaCarta **colaCarta);
void AD_comportamientos();
void AD_cartasXAyudante(ListaAyudante **listaAyudante);
void AD_TopJuguetes(ColaCarta **colaCarta);
int anoExiste(int ano);

struct Juguete *raizJuguetes = NULL;
int contadorJuguetes = 1;
int a=0, b=0;
int comportamientosBuenos = 0;
int comportamientosMalos = 0;

int ArrayJuguetesAno[20];
int ArrayJuguetesCant[20];

int ArrayCartasAno[20];
int ArrayCartasAprov[20];
int ArrayCartasRechazo[20];

int ArrayCodJuguetes[20];
int ArrayCantJuguetes[20];

int main(int argc, char const *argv[]){

	ListaNino* listaNino = (ListaNino*) malloc(sizeof(ListaNino));
	ListaAyudante* listaAyudante = (ListaAyudante*) malloc(sizeof(ListaAyudante));
	ColaComportamiento* colaComportamiento = (ColaComportamiento*) malloc(sizeof(ColaComportamiento));
	ColaCarta* colaCarta = (ColaCarta*) malloc(sizeof(ColaCarta));
	


	enlistarNino(&listaNino, 118500815, "Juan Perez A", "perez12", "perez12@gmail.com", "14/08/02", 18, "NO");
	enlistarNino(&listaNino, 801070315, "Daniel Solis J", "Dani", "Dani@gmail.com", "23/04/80", 12, "SI");
	enlistarNino(&listaNino, 800990657, "Jose Salazar M", "jojo", "jojo@hotmail.com", "15/06/78", 15, "NO");
	enlistarNino(&listaNino, 123456789, "Mariano Ramirez H", "Mari134", "marianito@hotmail.com", "11/06/00", 16, "NO");
	enlistarNino(&listaNino, 987654321, "Mariana Gonzales R", "Mary01", "mari@gmail.com", "30/12/02", 18, "SI");
	enlistarNino(&listaNino, 2118500815, "Andres Arguedas F", "andresito", "andre14@gmail.com", "14/08/02", 18, "NO");
	enlistarNino(&listaNino, 2123456789, "Guillermo Dias H", "Guillermin", "guille@gmail.com", "11/06/00", 20, "NO");

	insertarJuguete(1, "Raqueta", "Juego de Mesa", "+8", 8, 16, 20500);
	insertarJuguete(2, "Twistter", "Juego en familia", "+12", 12, 35, 15600);
	insertarJuguete(3, "Bate", "Juego en Deporte", "+12", 12, 99, 10300);
	insertarJuguete(4, "Pictionary", "Juego de Mesa", "+8", 8, 40, 18900);
	insertarJuguete(5, "Scrabble", "Juego de Mesa", "+15", 15, 40, 7500);
	insertarJuguete(6, "Bola", "Juego de Deporte", "+10", 10, 99, 5000);
	insertarJuguete(7, "Pistola", "Juego violento", "+12", 12, 99, 7995);
	insertarJuguete(8, "Play5", "Juego electronico", "+18", 18, 99, 10000000);
	insertarJuguete(9, "Monopoly", "Juego Tenis", "+8", 8, 40, 30000);
	insertarJuguete(10, "Pistola lazer", "Juego violento", "+15", 15, 45, 350);

    int opcion = 0;
	char s_opcion[10];

	while(opcion != 10){
	printf("\n***************************MENU************************\n\n");
	printf("1- Gestion de chico/chicas\n");
	printf("2- Gestion de ayudantes\n");
	printf("3- Gestion de juguetes\n");
	printf("4- Gestion catalogo de lugares\n");
	printf("5- Ingresar comportamineto del chico/chica\n");
	printf("6- Gestion de carta para santa\n");
	printf("7- Procesar Carta\n");
	printf("8- Entrega de juguetes\n");
	printf("9- Analisis de datos\n");
	printf("10- Salir.\n\n");
	
		printf("Ingrese el numero de la opcion que desea realizar: ");
		//scanf("%s", s_opcion);
		fgets(s_opcion, 3, stdin);
		opcion = atoi(s_opcion);
		
		if(opcion > 10 || opcion < 0){
			printf("Error, opcion invalida.\n\n");
		}
		else if(opcion == 1){
			gestionNino(&listaNino);
		}
		else if(opcion == 2){
			gestionAyudantes(&listaAyudante);
		}
		else if(opcion == 3){
			gestionJuguetes();
		}
		else if(opcion == 4){
			gestionCatalogoLugares();
		}
		else if(opcion == 5){
			registrarComportamiento(&colaComportamiento);
		}
		else if(opcion == 6){
			gestionCarta(&colaCarta, &listaNino);
		}
		else if(opcion == 7){
			procesarCarta(&listaNino, &colaCarta, &listaAyudante, &colaComportamiento);
		}
		else if(opcion == 8){
			entregarJuguetes();
		}
		else if(opcion == 9){
			analisisDatos(&colaCarta, &listaAyudante);	 
		}
        else if(opcion == 10){
            printf("Bye Have a beautiful time");
	        return 0;
        }
		else{
			printf("opcion no valida");
		}	
	}
}

//*************************************************************************************************
void gestionNino(ListaNino **listaNino){
    int opcion = 0;
	char stringVerificador[6];
	
	while(opcion != 5){
		printf("\n*************************MENU DE CHICOS/CHICAS************************-\n\n");
		printf("1- Registrar Chico/Chica.\n");
		printf("2- Visualizar Chicos.\n");
		printf("3- Eliminar Chico\n");
        printf("4- Modificar datos del chico\n");
		printf("5- Salir.  \n");
		do{
			printf("Ingrese el numero de la opcion que desea realizar: ");
			fgets(stringVerificador, 3, stdin);
			//scanf("%s", stringVerificador);
			opcion = atoi(stringVerificador);
			if(opcion == 0){
				printf("Error, opcion invalida.\n\n");
			}
		}while(opcion == 0);
		
		if(opcion > 5 || opcion < 1){
			printf("Error, opcion invalida.\n\n");
		}
		else if(opcion == 1){
			registrarNino(&*listaNino);
		}
		else if(opcion == 2){
			visualizarNino(&*listaNino);
		}
		else if(opcion == 3){
			eliminarNino(&*listaNino);
		}
        else if(opcion == 4){
			modificarNino(&*listaNino);
		}
    }
}

void registrarNino(ListaNino **listaNino){
int identificacion, edad;
char nombre[40], username[30], correo[40], nacimiento[14], necesidades[50], c_identificacion[15], c_edad[2];

	printf("Ingrese el ID del nino: ");
	fgets(c_identificacion, 15, stdin);
	identificacion = atoi(c_identificacion);

	printf("Ingrese el nombre completo del nuevo chico/chica: ");
	fgets(nombre, 40, stdin);
	strtok(nombre, "\n");
	
	

	printf("Ingrese el nombre de usuario en el sistema: ");
	fgets(username, 30, stdin);
	strtok(username, "\n");


	printf("Ingrese el correo electronico: ");
	fgets(correo, 40, stdin);
	strtok(correo, "\n");


	printf("Ingrese la fecha de nacimiento del chico/chica (Formato: dd/mm/aa): ");
	fgets(nacimiento, 14, stdin);
	strtok(nacimiento, "\n");
	

	printf("Ingrese la edad del chico/chica: ");
	fgets(c_edad, 100, stdin);
	edad = atoi(c_edad);

	printf("Ingrese las necesidades especiales del chico/chica (si no tiene, escriba NO): ");
	fgets(necesidades, 50, stdin);
	strtok(necesidades, "\n");
	//scanf("%s", necesidades);

	enlistarNino(&*listaNino, identificacion, nombre, username, correo, nacimiento, edad, necesidades);

}

void enlistarNino(ListaNino **listaNino, int identificacion, char *nombre, char *username, char *correo, char *nacimiento, int edad, char *necesidades){
	
	
	
	Nino* nuevo = (Nino*) malloc(sizeof(Nino));
	nuevo->identificacion = identificacion;
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->username, username);
	strcpy(nuevo->correo, correo);
	strcpy(nuevo->nacimiento, nacimiento);
	nuevo->edad = edad;
	strcpy(nuevo->necesidades, necesidades);
	
	

	if((*listaNino)->cabeza == NULL){
		(*listaNino)->cabeza = nuevo;
		(*listaNino)->cola = nuevo;
	}
	else{
		(*listaNino)->cola->siguiente = nuevo;
		(*listaNino)->cola = nuevo;
	}
	
}

void visualizarNino(ListaNino **listaNino){
	int contador = 1;
    Nino* puntero = (Nino*)malloc(sizeof(Nino));
	puntero = (*listaNino)->cabeza;
	if((*listaNino)->cabeza != NULL){
		printf("\n*********************CHICO/CHICAS*********************\n");
		while(puntero != NULL){			
			printf("\n	Chico/Chica %i 	\n", contador);
			printf("Identificacion: %i    \n", puntero->identificacion);
			printf("Nombre: %s   \n", puntero->nombre);
			printf("Username: %s   \n", puntero->username);
			printf("Correo: %s   \n", puntero->correo);
			printf("Fecha de nacimiento: %s   \n", puntero->nacimiento);
			printf("Edad: %i   \n", puntero->edad);
			printf("Necesidades Especiales: %s   \n", puntero->necesidades);


			puntero = puntero->siguiente;
			contador++;
		}
		printf("\n*******************************************\n");
		free(puntero);
	}
	else{
		printf("No se ha agregado ningun miembro al sistema");
	}
}

void eliminarNino(ListaNino **listaNino){
	int identificacion, encontrado=0;
	char c_identificacion[15];
	Nino *aux = (Nino*) malloc(sizeof(Nino));
	Nino *atras = (Nino*) malloc(sizeof(Nino));
	
	printf("Digite la identificacion del chico/chica:");
	fgets(c_identificacion, 15, stdin);
	identificacion = atoi(c_identificacion);
	
	atras = NULL;
	aux = (*listaNino)->cabeza;
	
	if((*listaNino)->cabeza != NULL){
		while(aux != NULL && encontrado != 1){
			if(aux->identificacion == identificacion){
				
				if(aux == (*listaNino)->cabeza){
					Nino* copiaPrimero = (Nino*)malloc(sizeof(Nino));
					aux = (*listaNino)->cabeza;
					copiaPrimero = (*listaNino)->cabeza;
					(*listaNino)->cabeza = (*listaNino)->cabeza->siguiente;
					free(copiaPrimero);
				}
				else if(aux == (*listaNino)->cola){
					atras = (*listaNino)->cabeza;
					aux = (*listaNino)->cabeza->siguiente;
					while(atras->siguiente != NULL){
						if(aux->siguiente == NULL){
							(*listaNino)->cola = atras;
							free(aux);
							atras->siguiente=NULL;
						}
						else{
							atras = aux;
							aux= aux->siguiente;
						}
					}					
				}
				else{
					atras->siguiente = aux->siguiente;
				}
				
				printf("\n Eliminado exitosamente\n");
				encontrado = 1;
			}
			atras = aux;
			aux = aux->siguiente;
		}
		if(encontrado == 0){
			printf("\nNo encontrado\n");
		}
		else{
			free(atras);
		}
	}
	else{
		printf("\nLa lista no tiene miembros");
	}
}

int modificarNino(ListaNino **listaNino){
    int contador = 1, cedula;
    Nino* puntero = (Nino*)malloc(sizeof(Nino));
	puntero = (*listaNino)->cabeza;
    char username[30], correo[40], necesidades[50], c_cedula[15]; 	
	
	
	printf("Ingrese el numero de cedula del miembro a modificar: ");
	fgets(c_cedula, 15, stdin);
	cedula = atoi(c_cedula);
	
	if((*listaNino)->cabeza != NULL){
		
		while(puntero != NULL){
			
			if(cedula == puntero->identificacion){

				printf("Ingrese nuevo el nombre de usuario en el sistema: ");
				fgets(username, 30, stdin);
				strtok(username, "\n");

				printf("Aca deberia escoger un nuevo lugar de residencia\n");
		
				printf("Ingrese el nuevo correo electronico asociado: ");
				fgets(correo, 40, stdin);
				strtok(correo, "\n");

				printf("Ingrese las nuevas necesidades especiales del nino (si no tiene, escriba NO): ");
				fgets(necesidades, 50, stdin);
				strtok(necesidades, "\n");
				
				strcpy(puntero->correo, correo);
				strcpy(puntero->necesidades, necesidades);
				strcpy(puntero->username, username);	
				return 0;

			}
			puntero = puntero->siguiente;
			contador++;
		}
		printf("Esa identificacion no fue encontrada!");
		free(puntero);
		return 0;
	}
	else{
		printf("No se ha agregado ningun miembro al sistema");
	}
}

//----------------------------------------------------------------------------------------------------
void gestionAyudantes(ListaAyudante **listaAyudante){
    int opcion = 0;
	char stringVerificador[6];
	
	while(opcion != 5){
		printf("\n-------------------------MENU de AYUDANTES--------------------------\n\n");
		printf("1- Registrar Ayudante\n");
		printf("2- Visualizar Ayudante\n");
		printf("3- Eliminar Ayudante\n");
        printf("4- Modificar Info de ayudante\n");
		printf("5- Salir.  \n");
		do{
			printf("Digite la opcion que desea realizar: ");
			fgets(stringVerificador, 6, stdin);
			opcion = atoi(stringVerificador);
			if(opcion == 0){
				printf("Error, opcion invalida.\n\n");
			}
		}while(opcion == 0);
		
		if(opcion > 5 || opcion < 1){
			printf("Error, opcion invalida.\n\n");
		}
		else if(opcion == 1){
			registrarAyudante(&*listaAyudante);
		}
		else if(opcion == 2){
			visualizarAyudante(&*listaAyudante);
		}
		else if(opcion == 3){
			eliminarAyudante(&*listaAyudante);
		}
        else if(opcion == 4){
			modificarAyudante(&*listaAyudante);
		}
    }
}

void registrarAyudante(ListaAyudante **listaAyudante){
	int identificacion;
	char nombre[100], puesto[50], funciones[100], fechaInicio[15], c_identificacion[15];

	printf("Digite la identificacion del Ayudante: ");
	fgets(c_identificacion, 15, stdin);
	identificacion = atoi(c_identificacion);

	printf("Ingrese el nombre completo del nuevo ayudante: ");
	fgets(nombre, 100, stdin);
	strtok(nombre, "\n");

	printf("Ingrese el puesto del nuevo ayudante: ");
	fgets(puesto, 50, stdin);
	strtok(puesto, "\n");

	printf("Ingrese las funciones a realizar en ese puesto: ");
	fgets(funciones, 100, stdin);
	strtok(funciones, "\n");

	printf("Digite la fecha que empezo a trabajar con santa (Formato: dd/mm/aa): ");
	fgets(fechaInicio, 15, stdin);
	strtok(fechaInicio, "\n");
	
	enqueueAyudante(&*listaAyudante, identificacion, nombre, puesto, funciones, fechaInicio);

}

void enqueueAyudante(ListaAyudante **listaAyudante, int identificacion, char *nombre, char *puesto, char *funciones, char *fechaInicio){
	Ayudante* nuevo = (Ayudante*) malloc(sizeof(Ayudante));
	nuevo->identificacion = identificacion;
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->puesto, puesto);
	strcpy(nuevo->funciones, funciones);
	strcpy(nuevo->fechaInicio, fechaInicio);


	if((*listaAyudante)->cabeza == NULL){
		(*listaAyudante)->cabeza = nuevo;
		(*listaAyudante)->cola = nuevo;
	}
	else{
		(*listaAyudante)->cola->siguiente = nuevo;
		(*listaAyudante)->cola = nuevo;	
	}
}

void visualizarAyudante(ListaAyudante **listaAyudante){
	int contador = 1;
    Ayudante* puntero = (Ayudante*)malloc(sizeof(Ayudante));
	puntero = (*listaAyudante)->cabeza;
	if((*listaAyudante)->cabeza != NULL){
		printf("\n------------------AYUDANTES DE SANTA------------------\n");
		while(puntero != NULL){
			printf("\n	Ayudante %i 	\n", contador);
			printf("Identificacion: %i    \n", puntero->identificacion);
			printf("Nombre: %s   \n", puntero->nombre);
			printf("Puesto: %s   \n", puntero->puesto);
			printf("Funciones a realizar: %s   \n", puntero->funciones);
			printf("Fecha que comenzo a trabajar: %s   \n", puntero->fechaInicio);


			puntero = puntero->siguiente;
			contador++;
		}
		printf("\n------------------------------------------\n");
		free(puntero);
	}
	else{
		printf("No se ha agregado ningun miembro al sistema");
	}
}

void eliminarAyudante(ListaAyudante **listaAyudante){
    int identificacion, encontrado=0;
	Ayudante *aux = (Ayudante*) malloc(sizeof(Ayudante));
	Ayudante *atras = (Ayudante*) malloc(sizeof(Ayudante));
	
	printf("Digite la identificacion del ayudante: ");
	scanf("%i", &identificacion);
	
	
	atras = NULL;
	aux = (*listaAyudante)->cabeza;
	
	if((*listaAyudante)->cabeza != NULL){
		while(aux != NULL && encontrado != 1){
			if(aux->identificacion == identificacion){
				
				if(aux == (*listaAyudante)->cabeza){
					Ayudante* copiaPrimero = (Ayudante*)malloc(sizeof(Ayudante));
					aux = (*listaAyudante)->cabeza;
					copiaPrimero = (*listaAyudante)->cabeza;
					(*listaAyudante)->cabeza = (*listaAyudante)->cabeza->siguiente;
					free(copiaPrimero);
				}
				else if(aux == (*listaAyudante)->cola){
					atras = (*listaAyudante)->cabeza;
					aux = (*listaAyudante)->cabeza->siguiente;
					while(atras->siguiente != NULL){
						if(aux->siguiente == NULL){
							(*listaAyudante)->cola = atras;
							free(aux);
							atras->siguiente=NULL;
						}
						else{
							atras = aux;
							aux= aux->siguiente;
						}
					}					
				}
				else{
					atras->siguiente = aux->siguiente;
				}
				
				printf("\n Ayudante eliminado exitosamente!");
				encontrado = 1;
			}
			atras = aux;
			aux = aux->siguiente;
		}
		if(encontrado == 0){
			printf("\nAyudante no encontrado\n");
		}
		else{
			free(atras);
		}
	}
	else{
		printf("\nLa lista no tiene miembros");
	}
}

int modificarAyudante(ListaAyudante **listaAyudante){
    int contador = 1, cedula;
    char c_cedula[15];
    Ayudante* puntero = (Ayudante*)malloc(sizeof(Ayudante));
	puntero = (*listaAyudante)->cabeza;
    char puesto[50], funciones[100], fechaInicio[15]; 	
	
	
	printf("Digite el numero de cedula del miembro a modificar (sin espacios): ");
	fgets(c_cedula, 15, stdin);
	cedula = atoi(c_cedula);
	
	if((*listaAyudante)->cabeza != NULL){
		
		while(puntero != NULL){
			
			if(cedula == puntero->identificacion){

				printf("Ingrese el nuevo puesto del ayudante: ");
				fgets(puesto, 50, stdin);
				strtok(puesto, "\n");
		
				printf("Ingrese las nuevas funciones del ayudante: ");
				fgets(funciones, 100, stdin);
				strtok(funciones, "\n");
				
				printf("Ingrese la nueva fecha de inicio que empezo a trabajar con santa (Formato: dd/mm/aa): ");
				fgets(fechaInicio, 15, stdin);
				strtok(fechaInicio, "\n");

				strcpy(puntero->puesto, puesto);
				strcpy(puntero->funciones, funciones);
				strcpy(puntero->fechaInicio, fechaInicio);
				return 0;

			}
			puntero = puntero->siguiente;
			contador++;
		}
		printf("Esa identificacion no fue encontrada!");
		free(puntero);
		return 0;
	}
	else{
		printf("No se ha agregado ningun miembro al sistema");
	}
}

//----------------------------------------------------------------------------------------------------
void gestionJuguetes(){
    int opcion = 0;
	char stringVerificador[6];
	
	while(opcion != 5){
		printf("\n-------------------------MENU de JUGUETES--------------------------\n\n");
		printf("1- Registrar Juguete\n");
		printf("2- Visualizar Juguete\n");
		printf("3- Eliminar Juguete\n");
        printf("4- Modificar Info de Juguete\n");
		printf("5- Salir.  \n");
		do{
			printf("Digite la opcion que desea realizar: ");
			fgets(stringVerificador, 6, stdin);
			opcion = atoi(stringVerificador);
			if(opcion == 0){
				printf("Error, opcion invalida.\n\n");
			}
		}while(opcion == 0);
		
		if(opcion > 5 || opcion < 1){
			printf("Error, opcion invalida.\n\n");
		}
		else if(opcion == 1){
			registrarJuguete();
		}
		else if(opcion == 2){
			printf("\n------------------ JUGUETES ------------------\n");
			contadorJuguetes = 0;
			visualizarJuguete(raizJuguetes);
			printf("----------------------------------------------------------\n");
			
		}
		else if(opcion == 3){
			eliminarJuguete();
		}
        else if(opcion == 4){
			char nombre[50];
			printf("ingrese el nombre del juguete a modificar: ");
			fgets(nombre, 50, stdin);
			strtok(nombre,"\n");
			modificarJuguete(raizJuguetes, nombre);
		}
    }
}

void registrarJuguete(){
    
	int codigo, rangoInicial, rangoFinal;
	float costo;
	char nombre[50], descripcion[100], categoria[50], c_codigo[10], c_rangoInicial[10], c_rangoFinal[10], c_costo[25];	

	printf("Digite el codigo del juguete: ");
	fgets(c_codigo, 10, stdin);
	codigo = atoi(c_codigo);

	printf("Ingrese el nombre del juguete: ");
	fgets(nombre, 50, stdin);
	strtok(nombre, "\n");

	printf("Ingrese la descripcion del juguete: ");
	fgets(descripcion, 50, stdin);
	strtok(descripcion, "\n");


	printf("Ingrese la categoria del juguete: ");
	fgets(categoria, 50, stdin);
	strtok(categoria, "\n");

	printf("Digite el rango de edad para el que esta hecho el juguete\nEdad menor: ");
	fgets(c_rangoInicial, 10, stdin);
	rangoInicial = atoi(c_rangoInicial);
	printf("Edad mayor: ");
	fgets(c_rangoFinal, 10, stdin);
	rangoFinal = atoi(c_rangoFinal);
	
	printf("Digite el costo de fabricacion: ");
	fgets(c_costo, 10, stdin);
	costo = atof(c_costo);

	insertarJuguete( codigo, nombre, descripcion, categoria, rangoInicial, rangoFinal, costo);
}

void insertarJuguete(int codigo, char *nombre, char *descripcion, char *categoria, int rangoInicial, int rangoFinal, float costo){
    struct Juguete *nuevo;
    nuevo = malloc(sizeof(struct Juguete));
    nuevo->codigo = codigo;
    nuevo->rangoInicial = rangoInicial;
    nuevo->rangoFinal = rangoFinal;
    nuevo->costo = costo;
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->descripcion, descripcion);
    strcpy(nuevo->categoria, categoria);
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if (raizJuguetes == NULL)
        raizJuguetes = nuevo;
    else{
        struct Juguete *anterior, *reco;
        anterior = NULL;
        reco = raizJuguetes;
        while (reco != NULL)
        {
            anterior = reco;
            if (codigo < reco->codigo)
                reco = reco->izq;
            else
                reco = reco->der;
        }
        if (codigo < anterior->codigo)
            anterior->izq = nuevo;
        else
            anterior->der = nuevo;
    }
}

void visualizarJuguete(struct Juguete *reco){
     
	 if (reco != NULL){
        visualizarJuguete(reco->izq);
        printf("\n	Juguete %i 	\n", contadorJuguetes);
		printf("Codigo: %i    \n", reco->codigo);
		printf("Nombre: %s   \n", reco->nombre);
		printf("Descripcion: %s   \n", reco->descripcion);
		printf("Categoria: %s   \n", reco->categoria);
		printf("Rango de edad: De %i a %i anos \n", reco->rangoInicial, reco->rangoFinal);
		printf("Costo: %.2f \n", reco->costo); //eliminar despues
		contadorJuguetes++;
        visualizarJuguete(reco->der);
    }
}

void eliminarJuguete(){
    printf("Aca se elimina un Juguete");
}

int modificarJuguete(struct Juguete *reco, char *nombre){
	
	int rangoInicial, rangoFinal;
	float costo;
	char descripcion[100], categoria[50], c_rangoInicial[10], c_rangoFinal[10], c_costo[25];	


    if (reco != NULL)
    {
        modificarJuguete(reco->izq, nombre);
		
		if(strcmp(reco->nombre, nombre) == 0){

			printf("Ingrese la nueva descripcion del juguete: ");
			fgets(descripcion, 50, stdin);
			strtok(descripcion, "\n");

			printf("Ingrese la nueva categoria del juguete: ");
			fgets(categoria, 50, stdin);
			strtok(categoria, "\n");

			printf("Digite el nuevo rango de edad para el que esta hecho el juguete\nEdad menor: ");
			fgets(c_rangoInicial, 10, stdin);
			rangoInicial = atoi(c_rangoInicial);
			printf("Edad mayor: ");
			fgets(c_rangoFinal, 10, stdin);
			rangoFinal = atoi(c_rangoFinal);
	
			printf("Digite el nuevo costo de fabricacion: ");
			fgets(c_costo, 10, stdin);
			costo = atof(c_costo);
        	
        	reco->costo = costo;
        	reco->rangoInicial = rangoInicial;
        	reco->rangoFinal = rangoFinal;
        	strcpy(reco->categoria, categoria);
        	strcpy(reco->descripcion, descripcion);
        	
			return 0;
			
		}
    	modificarJuguete(reco->der, nombre);
    }
}

//----------------------------------------------------------------------------------------------------
void gestionCatalogoLugares(){
    int opcion = 0;
	char stringVerificador[6];
	
	while(opcion != 8){
		printf("\n-------------------------MENU de CATALOGO LUGARES--------------------------\n\n");
		printf("1- Registrar lugar\n");
		printf("2- Visualizar Lugares\n");
        printf("3- Eliminar Lugares\n");
        printf("4- Modificar Lugares\n");
        printf("5- Visualizar Ruta\n");
        printf("6- Eliminar Ruta\n");
		printf("7- Modificar Ruta\n");
		printf("8- Salir.  \n");
		do{
			printf("Digite la opcion que desea realizar: ");
			scanf("%s", stringVerificador);
			opcion = atoi(stringVerificador);
			if(opcion == 0){
				printf("Error, opcion invalida.\n\n");
			}
		}while(opcion == 0);
		
		if(opcion > 8 || opcion < 1){
			printf("Error, opcion invalida.\n\n");
		}
		else if(opcion == 1){
			registrarLugar();
		}
		else if(opcion == 2){
			visualizarLugar();
		}
		else if(opcion == 3){
			eliminarLugar();
		}
        else if(opcion == 4){
			modificarLugar();
		}
        else if(opcion == 5){
			visualizarRuta();
		}
        else if(opcion == 6){
			eliminarRuta();
		}
        else if(opcion == 7){
			modificarRuta();
		}
    }
}

void registrarLugar(){
    printf("Desde aca se registran lugares");
}

void visualizarLugar(){
    printf("Desde aca de visualizan todos los lugares");
}

void modificarLugar(){
    printf("Desde aca se modifican los lugares agregados");
}

void eliminarLugar(){
    printf("Desde aca se eliminan los lugares agregados");
}

void visualizarRuta(){
    printf("Desde aca se visualizan las rutas creadas");
}

void eliminarRuta(){
    printf("Desde aca se eliminan las rutas agregadas");
}

void modificarRuta(){
    printf("Desde aca se mdifican los datos de rutas");
}

//----------------------------------------------------------------------------------------------------
void registrarComportamiento(ColaComportamiento **colaComportamiento){

    int identificacion, comportamiento, dia, mes, ano;
	char nombrePadre[50], descripcion[100], c_dia[5], c_mes[5], c_ano[5], c_identificacion[15], c_comportamiento[5];

	printf("Digite la identificacion del nino: ");
	fgets(c_identificacion, 15, stdin);
	identificacion = atoi(c_identificacion);

	printf("Ingrese el nombre completo del padre o madre que realiza este reporte: ");
	fgets(nombrePadre, 50, stdin);
	strtok(nombrePadre, "\n");

	printf("Digite la fecha de hoy:\n Dia: ");
	fgets(c_dia, 5, stdin);
	dia = atoi(c_dia);

	printf("Mes: ");
	fgets(c_mes, 5, stdin);
	mes = atoi(c_mes);
	
	printf("Ano: ");
	fgets(c_ano, 5, stdin);
	ano = atoi(c_ano);

	printf("Ingrese una descripcion del comportamiento del nino: ");
	fgets(descripcion, 50, stdin);
	strtok(descripcion, "\n");
	
	printf("Ingrese si el comportamiento del nino fue bueno o malo (1 para BUENO, 2 para MALO): ");
	fgets(c_comportamiento, 50, stdin);
	comportamiento = atoi(c_comportamiento);
	if(comportamiento == 1){
		comportamientosBuenos++;
	}
	else{
		comportamientosMalos++;
	}
	
	enColarComportamiento(&*colaComportamiento, identificacion, comportamiento, dia, mes, ano, nombrePadre, descripcion);
}

void enColarComportamiento(ColaComportamiento **colaComportamiento, int identificacion, int comportamiento, int dia, int mes, int ano, char *nombrePadre, char *descripcion){
	
	Comportamiento* nuevo = (Comportamiento*)malloc(sizeof(Comportamiento));
	
	nuevo->identificacion = identificacion;
	nuevo->comportamiento = comportamiento;
	nuevo->dia = dia;
	nuevo->mes = mes;
	nuevo->ano = ano;
	strcpy(nuevo->descripcion, descripcion);
	strcpy(nuevo->nombrePadre, nombrePadre);
	
	nuevo->siguiente = NULL;
	
	if((*colaComportamiento)->front == NULL){
		(*colaComportamiento)->front = nuevo;
		(*colaComportamiento)->rear = nuevo;
	}
	else{
		(*colaComportamiento)->rear->siguiente = nuevo;
		(*colaComportamiento)->rear = nuevo;
	}
	printf("Comportamiento ingresado con exito");
	
	desplegarComportamiento(&*colaComportamiento);
}
	
void desplegarComportamiento(ColaComportamiento **colaComportamiento){
	int cont = 0;
	Comportamiento* actual = (Comportamiento*)malloc(sizeof(Comportamiento));
	actual = (*colaComportamiento)->front;
	if((*colaComportamiento)->front != NULL){
		while(actual != NULL){
			
			printf("\n---Comportamiento %i---\n", cont);
			printf("Identificacion: %i  \n", actual->identificacion);
			printf("Nombre del padre: %s  \n", actual->nombrePadre);
			printf("Fecha de registro: %i/%i/%i  \n", actual->dia, actual->mes, actual->ano);
			printf("Descripcion: %s  \n", actual->descripcion);
			if(actual->comportamiento == 1){
				printf("Comportamiento: Bueno  \n");
			}
			else{
				printf("Comportamiento: Malo \n");
			}
			cont++;
			actual = actual->siguiente;
		}
	}
	else{
		printf("La cola esta vacia\n");
	}
	
}

//----------------------------------------------------------------------------------------------------
int gestionCarta(ColaCarta **colaCarta, ListaNino **listaNino){
    int opcion = 0;
	char stringVerificador[6];
	
	while(opcion != 4){
		printf("\n-------------------------MENU de CARTAS--------------------------\n\n");
		printf("1- Registrar Carta\n");
		printf("2- Visualizar Carta\n");
        printf("3- Editar Carta\n");
        printf("4- Editar Lista de Deseos\n");
		printf("5- Salir.  \n");
		do{
			printf("Digite la opcion que desea realizar: ");
			fgets(stringVerificador, 50, stdin);
			opcion = atoi(stringVerificador);
			if(opcion == 0){
				printf("Error, opcion invalida.\n\n");
			}
		}while(opcion == 0);
		
		if(opcion > 6 || opcion < 1){
			printf("Error, opcion invalida.\n\n");
		}
		else if(opcion == 1){
			registrarCarta(&*colaCarta, &*listaNino);
		}
		else if(opcion == 2){
			visualizarCarta(&*colaCarta);
		}
		else if(opcion == 3){
			editarCarta(&*listaNino, &*colaCarta);
		}
		else if(opcion == 4){
			editarListaDeseos(&*listaNino, &*colaCarta);
		}
		else if(opcion ==5){
			return 0;
		}
    }
}

void registrarCarta(ColaCarta **colaCarta, ListaNino **listaNino){
	int ano, juguete1 = 0, juguete2 = 0, juguete3 = 0, juguete4 = 0, juguete5 = 0, juguete6 = 0, juguete7 = 0, juguete8 = 0, juguete9 = 0, juguete10 = 0, opcion = 0, codigoJuguete, identificacion;
	char stringVerificador[50], nombre[50], c_ano[10];
	
	
    printf("Digite el ano al que corresponde la carta(formato: 0000): ");
    fgets(c_ano, 50, stdin);
    ano = atoi(c_ano);
    
	printf("Digite su identificacion: ");
	fgets(stringVerificador, 50, stdin);
	identificacion = atoi(stringVerificador);
    
	
	
    while(opcion != 2){
    	
    	printf("Digite el nombre del juguete: ");
		fgets(nombre, 50, stdin);
		strtok(nombre, "\n");
    	a = 0;
    	codigoJuguete =  busquedaJuguete(nombre, raizJuguetes);
    	codigoJuguete = b;
    	printf("Desea anadir este juguete a la carta o a la lista de deseos (1-Carta, 2-Lista de deseo): ");
    	fgets(stringVerificador, 50, stdin);
    	opcion = atoi(stringVerificador);
    	
    	if(opcion == 1){
    		if(juguete1 == 0){
    			juguete1 = codigoJuguete;
			}
			else if(juguete2 == 0){
    			juguete2 = codigoJuguete;
			}
			else if(juguete3 == 0){
    			juguete3 = codigoJuguete;
			}
			else if(juguete4 == 0){
    			juguete4 = codigoJuguete;
			}
			else if(juguete5 == 0){
    			juguete5 = codigoJuguete;
			}
			else if(juguete6 == 0){
    			juguete6 = codigoJuguete;
			}
			else if(juguete7 == 0){
    			juguete7 = codigoJuguete;
			}
			else if(juguete8 == 0){
    			juguete8 = codigoJuguete;
			}
			else if(juguete9 == 0){
    			juguete9 = codigoJuguete;
			}
			else if(juguete10 == 0){
    			juguete10 = codigoJuguete;
			}
			else{
				printf("Ya no puede agregar mas juguetes a la carta");
			}
			
		
		}
		else if(opcion == 2){
    		int i = 0;
    		Nino* puntero = (Nino*) malloc(sizeof(Nino*));
    		puntero = (*listaNino)->cabeza;
		
	
			if((*listaNino)->cabeza != NULL){
				while(puntero != NULL){		
					if(identificacion == puntero->identificacion){
    					for(i = 0; i<15; i++){
    						if(puntero->arrayDeseos[i] == 0){
    							puntero->arrayDeseos[i] = codigoJuguete;
    							i = 15;
    						}
    					}
    				}
    				puntero = puntero->siguiente;
				}	
			}	
		}
		printf("Desea anadir otro juguete (1 para si, 2 para no): ");
			fgets(stringVerificador, 50, stdin);
			opcion = atoi(stringVerificador);
	}
    enColarCarta(&*colaCarta, ano, juguete1, juguete2, juguete3, juguete4, juguete5, juguete6, juguete7, juguete8, juguete9, juguete10, identificacion);
  
}

int busquedaJuguete(char *nombre, struct Juguete *reco){
	int codigo;
	
	if (reco != NULL){
    		
        busquedaJuguete(nombre, reco->izq);
        
       	if(strcmp(reco->nombre, nombre) == 0){
        
        	printf("\n	Juguete %i 	\n", contadorJuguetes);
			printf("Codigo: %i    \n", reco->codigo);
			printf("Nombre: %s   \n", reco->nombre);
			printf("Descripcion: %s   \n", reco->descripcion);
			printf("Categoria: %s   \n", reco->categoria);
			printf("Rango de edad: De %i a %i anos \n", reco->rangoInicial, reco->rangoFinal);
			printf("Costo: %.2f \n", reco->costo); //eliminar despues
			if(a == 0){
				b = reco->codigo;
			}
			a = 1;
    	}
    	busquedaJuguete(nombre, reco->der);
    }
}

void enColarCarta(ColaCarta **colaCarta, int ano, int juguete1, int juguete2, int juguete3, int juguete4, int juguete5, int juguete6, int juguete7, int juguete8, int juguete9, int juguete10, int identificacion){
	
	Carta* nuevo = (Carta*)malloc(sizeof(Carta));
	
	nuevo->ano = ano;
	nuevo->identificacion = identificacion;
	nuevo->juguete1 = juguete1;
	strcpy(nuevo->estadoCarta, "Sin procesar");
	if(juguete1 == 0){
		strcpy(nuevo->estadoJuguete1, "No solicitado"); 
	}else{
		strcpy(nuevo->estadoJuguete1, "Solicitado");
		sumarSolicitud(juguete1, raizJuguetes);
	}
	nuevo->juguete2 = juguete2;
	if(juguete1 == 0){
		strcpy(nuevo->estadoJuguete2, "No solicitado"); 
	}else{
		strcpy(nuevo->estadoJuguete2, "Solicitado");
		sumarSolicitud(juguete2, raizJuguetes);
	}
	nuevo->juguete3 = juguete3;
	if(juguete3 == 0){
		strcpy(nuevo->estadoJuguete3, "No solicitado"); 
	}else{
		strcpy(nuevo->estadoJuguete3, "Solicitado");
		sumarSolicitud(juguete3, raizJuguetes);
	} 
	nuevo->juguete4 = juguete4;
	if(juguete4 == 0){
		strcpy(nuevo->estadoJuguete4, "No solicitado"); 
	}else{
		strcpy(nuevo->estadoJuguete4, "Solicitado");
		sumarSolicitud(juguete4, raizJuguetes);
	} 
	nuevo->juguete5 = juguete5;
	if(juguete5 == 0){
		strcpy(nuevo->estadoJuguete5, "No solicitado"); 
	}else{
		strcpy(nuevo->estadoJuguete5, "Solicitado");
		sumarSolicitud(juguete5, raizJuguetes);
	} 
	nuevo->juguete6 = juguete6;
	if(juguete6 == 0){
		strcpy(nuevo->estadoJuguete6, "No solicitado"); 
	}else{
		strcpy(nuevo->estadoJuguete6, "Solicitado");
		sumarSolicitud(juguete6, raizJuguetes);
	} 
	nuevo->juguete7 = juguete7;
	if(juguete7 == 0){
		strcpy(nuevo->estadoJuguete7, "No solicitado"); 
	}else{
		strcpy(nuevo->estadoJuguete7, "Solicitado");
		sumarSolicitud(juguete7, raizJuguetes);
	} 
	nuevo->juguete8 = juguete8;
	if(juguete8 == 0){
		strcpy(nuevo->estadoJuguete8, "No solicitado"); 
	}else{
		strcpy(nuevo->estadoJuguete8, "Solicitado");
		sumarSolicitud(juguete8, raizJuguetes);
	}
	nuevo->juguete9 = juguete9;
	if(juguete9 == 0){
		strcpy(nuevo->estadoJuguete9, "No solicitado"); 
	}else{
		strcpy(nuevo->estadoJuguete9, "Solicitado");
		sumarSolicitud(juguete9, raizJuguetes);
	} 
	nuevo->juguete10 = juguete10;
	if(juguete10 == 0){
		strcpy(nuevo->estadoJuguete10, "No solicitado"); 
	}else{
		strcpy(nuevo->estadoJuguete10, "Solicitado");
		sumarSolicitud(juguete10, raizJuguetes);
	}
	nuevo->siguiente = NULL;
	
	if((*colaCarta)->front == NULL){
		(*colaCarta)->front = nuevo;
		(*colaCarta)->rear = nuevo;
	}
	else{
		(*colaCarta)->rear->siguiente = nuevo;
		(*colaCarta)->rear = nuevo;
	}
	printf("Carta ingresado con exito\n");
}

void visualizarCarta(ColaCarta **colaCarta){
    int identificacion, ano;
	char stringVerificador[50];
    
    printf("Digite su identificacion: ");
	fgets(stringVerificador, 50, stdin);
	identificacion = atoi(stringVerificador);
	
	printf("Digite el ano de la carta: ");
	fgets(stringVerificador, 50, stdin);
	ano = atoi(stringVerificador);
	
	Carta* actual = (Carta*)malloc(sizeof(Carta));
	actual = (*colaCarta)->front;
	if((*colaCarta)->front != NULL){
		while(actual != NULL){
			if(actual->identificacion == identificacion && actual->ano == ano){
				printf("Identificacion: %i \n", actual->identificacion);
				printf("Ano: %i  \n", actual->ano);
				printf("Codigo juguete 1: %i  \n", actual->juguete1);
				printf("Codigo juguete 2: %i  \n", actual->juguete2);
				printf("Codigo juguete 3: %i  \n", actual->juguete3);
				printf("Codigo juguete 4: %i  \n", actual->juguete4);
				printf("Codigo juguete 5: %i  \n", actual->juguete5);
				printf("Codigo juguete 6: %i  \n", actual->juguete6);
				printf("Codigo juguete 7: %i  \n", actual->juguete7);
				printf("Codigo juguete 8: %i  \n", actual->juguete8);
				printf("Codigo juguete 9: %i  \n", actual->juguete9);
				printf("Codigo juguete 10: %i  \n", actual->juguete10);	
			}
			actual = actual->siguiente;
		}
	}
	else{
		printf("La cola esta vacia\n");
	}
}

void editarCarta(ListaNino **listaNino, ColaCarta **colaCarta){
	int opcion, identificacion, codigoJuguete;
	char stringVerificador[50], nombre[50];
	
	printf("Digite su identificacion: ");
	fgets(stringVerificador, 50, stdin);
	identificacion = atoi(stringVerificador);
	
	printf("1- Agregar Juguete\n");
	printf("2- Eliminar Juguete\n");
	printf("3- Salir\n");
	printf("Digite la opcion a realizar: ");
	fgets(stringVerificador, 50, stdin);
	opcion = atoi(stringVerificador);
	
	if(opcion > 3 || opcion < 1){
		printf("Error, opcion invalida.\n\n");
	}
		
	else if(opcion == 1){
		
		printf("Digite el nombre del juguete: ");
		fgets(nombre, 50, stdin);
		strtok(nombre, "\n");
    	a = 0;
    	codigoJuguete =  busquedaJuguete(nombre, raizJuguetes);
    	codigoJuguete = b;
    	Carta* actual = (Carta*)malloc(sizeof(Carta));
		actual = (*colaCarta)->front;
		if((*colaCarta)->front != NULL){
			while(actual != NULL){
				if(actual->identificacion == identificacion){
					if(actual->juguete1 == 0){
						actual->juguete1 = codigoJuguete;
						strcpy(actual->estadoJuguete1, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete2 == 0){
						actual->juguete2 = codigoJuguete;
						strcpy(actual->estadoJuguete2, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete3 == 0){
						actual->juguete3 = codigoJuguete;
						strcpy(actual->estadoJuguete3, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete4 == 0){
						actual->juguete4 = codigoJuguete;
						strcpy(actual->estadoJuguete4, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete5 == 0){
						actual->juguete5 = codigoJuguete;
						strcpy(actual->estadoJuguete5, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete6 == 0){
						actual->juguete6 = codigoJuguete;
						strcpy(actual->estadoJuguete6, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete7 == 0){
						actual->juguete7 = codigoJuguete;
						strcpy(actual->estadoJuguete7, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete8 == 0){
						actual->juguete8 = codigoJuguete;
						strcpy(actual->estadoJuguete8, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete9 == 0){
						actual->juguete9 = codigoJuguete;
						strcpy(actual->estadoJuguete9, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete10 == 0){
						actual->juguete10 = codigoJuguete;
						strcpy(actual->estadoJuguete10, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else{
						printf("No puede agregar mas juguetes a la carta\n");
					}
				}
				actual = actual->siguiente;
			}
		}
		else{
		printf("La cola esta vacia\n");
		}
	
	}
	else if(opcion == 2){
		Carta* puntero = (Carta*)malloc(sizeof(Carta));
		puntero = (*colaCarta)->front;
		if((*colaCarta)->front != NULL){
			while(puntero != NULL){	
				if(identificacion == puntero->identificacion){
					printf("----------Juguetes----------");
					
					busquedaJugueteID(puntero->juguete1, raizJuguetes);
					busquedaJugueteID(puntero->juguete2, raizJuguetes);
					busquedaJugueteID(puntero->juguete3, raizJuguetes);
					busquedaJugueteID(puntero->juguete4, raizJuguetes);
					busquedaJugueteID(puntero->juguete5, raizJuguetes);
					busquedaJugueteID(puntero->juguete6, raizJuguetes);
					busquedaJugueteID(puntero->juguete7, raizJuguetes);
					busquedaJugueteID(puntero->juguete8, raizJuguetes);
					busquedaJugueteID(puntero->juguete9, raizJuguetes);
					busquedaJugueteID(puntero->juguete10, raizJuguetes);
	
				}
				puntero = puntero->siguiente;
			}
				
		}
		printf("Digite el codigo del juguete a eliminar: ");
		fgets(stringVerificador, 50, stdin);
		codigoJuguete = atoi(stringVerificador);
		puntero = (*colaCarta)->front;
		if((*colaCarta)->front != NULL){
			while(puntero != NULL){	
				if(identificacion == puntero->identificacion){
					if(puntero->juguete1 == codigoJuguete){
						puntero->juguete1 = 0;
						strcpy(puntero->estadoJuguete1, "No Solicitado");
						printf("El juguete se elimino con exito\n");
					}
					else if(puntero->juguete2 == codigoJuguete){
						puntero->juguete2 = 0;
						strcpy(puntero->estadoJuguete2, "No Solicitado");
						printf("El juguete se elimino con exito\n");
					}
					else if(puntero->juguete3 == codigoJuguete){
						puntero->juguete3 = 0;
						strcpy(puntero->estadoJuguete3, "No Solicitado");
						printf("El juguete se elimino con exito\n");
					}
					else if(puntero->juguete4 == codigoJuguete){
						puntero->juguete4 = 0;
						strcpy(puntero->estadoJuguete4, "No Solicitado");
						printf("El juguete se elimino con exito\n");
					}
					else if(puntero->juguete5 == codigoJuguete){
						puntero->juguete5 = 0;
						strcpy(puntero->estadoJuguete5, "No Solicitado");
						printf("El juguete se elimino con exito\n");
					}
					else if(puntero->juguete6 == codigoJuguete){
						puntero->juguete6 = 0;
						strcpy(puntero->estadoJuguete6, "No Solicitado");
						printf("El juguete se elimino con exito\n");
					}
					else if(puntero->juguete7 == codigoJuguete){
						puntero->juguete7 = 0;
						strcpy(puntero->estadoJuguete7, "No Solicitado");
						printf("El juguete se elimino con exito\n");
					}
					else if(puntero->juguete8 == codigoJuguete){
						puntero->juguete8 = 0;
						strcpy(puntero->estadoJuguete8, "No Solicitado");
						printf("El juguete se elimino con exito\n");
					}
					else if(puntero->juguete9 == codigoJuguete){
						puntero->juguete9 = 0;
						strcpy(puntero->estadoJuguete9, "No Solicitado");
						printf("El juguete se elimino con exito\n");
					}
					else if(puntero->juguete10 == codigoJuguete){
						puntero->juguete10 = 0;
						strcpy(puntero->estadoJuguete10, "No Solicitado");
						printf("El juguete se elimino con exito\n");
					}
				}
				puntero = puntero->siguiente;
			}	
		}
	}
	
	
	else if(opcion == 3){
		
	
	}
}

void editarListaDeseos(ListaNino **listaNino, ColaCarta **colaCarta){
	int identificacion, i = 0, codigoJuguete, opcion;
	char stringVerificador[50], nombre[50];
    
	printf("Digite su identificacion: ");
	fgets(stringVerificador, 50, stdin);
	identificacion = atoi(stringVerificador);
	
	Nino* puntero = (Nino*)malloc(sizeof(Nino));
	puntero = (*listaNino)->cabeza;
	if((*listaNino)->cabeza != NULL){
		while(puntero != NULL){	
			if(identificacion == puntero->identificacion){
				printf("----------Lista de Deseos----------");
				for(i = 0; i<15; i++){
					//printf("C: %i \n", puntero->arrayDeseos[i]);
    				a = 0;
    				codigoJuguete =  busquedaJugueteID(puntero->arrayDeseos[i], raizJuguetes);
    				
				}	
			}
			puntero = puntero->siguiente;	
		}
	}
	printf("Digite el codigo del juguete a editar: ");
	fgets(stringVerificador, 50, stdin);
	codigoJuguete = atoi(stringVerificador);
	codigoJuguete = 10;
	
	printf("-----Opciones a realizar-----\n");
	printf("1- Mover juguete a la carta\n");
	printf("2- Eliminar juguete de la lista de deseos\n");
	printf("3- Salir\n");
	printf("Digite la opcion que desea realizar: ");
	fgets(stringVerificador, 50, stdin);
	opcion = atoi(stringVerificador);
	
	if(opcion > 3 || opcion < 1){
		printf("Error, opcion invalida.\n\n");
	}
		
	else if(opcion == 1){
		Carta* actual = (Carta*)malloc(sizeof(Carta));
		actual = (*colaCarta)->front;
		if((*colaCarta)->front != NULL){
			while(actual != NULL){
				if(actual->identificacion == identificacion){
					if(actual->juguete1 == 0){
						actual->juguete1 = codigoJuguete;
						strcpy(actual->estadoJuguete1, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete2 == 0){
						actual->juguete2 = codigoJuguete;
						strcpy(actual->estadoJuguete2, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete3 == 0){
						actual->juguete3 = codigoJuguete;
						strcpy(actual->estadoJuguete3, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete4 == 0){
						actual->juguete4 = codigoJuguete;
						strcpy(actual->estadoJuguete4, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete5 == 0){
						actual->juguete5 = codigoJuguete;
						strcpy(actual->estadoJuguete5, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete6 == 0){
						actual->juguete6 = codigoJuguete;
						strcpy(actual->estadoJuguete6, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete7 == 0){
						actual->juguete7 = codigoJuguete;
						strcpy(actual->estadoJuguete7, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete8 == 0){
						actual->juguete8 = codigoJuguete;
						strcpy(actual->estadoJuguete8, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete9 == 0){
						actual->juguete9 = codigoJuguete;
						strcpy(actual->estadoJuguete9, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else if(actual->juguete10 == 0){
						actual->juguete10 = codigoJuguete;
						strcpy(actual->estadoJuguete10, "Solicitado");
						printf("El juguete se agrego con exito\n");
						sumarSolicitud(codigoJuguete, raizJuguetes);
					}
					else{
						printf("No puede agregar mas juguetes a la carta\n");
					}
				}
				actual = actual->siguiente;
			}
		}
		else{
		printf("La cola esta vacia\n");
		}
	}
	else if(opcion == 2){
		Nino* puntero = (Nino*)malloc(sizeof(Nino));
		puntero = (*listaNino)->cabeza;
		if((*listaNino)->cabeza != NULL){
			while(puntero != NULL){	
				if(identificacion == puntero->identificacion){
					for(i = 0; i<15; i++){
						if(puntero->arrayDeseos[i] == codigoJuguete){
							puntero->arrayDeseos[i] = 0;
							printf("Juguete eliminado de la lista de deseos con exito\n");
						}
					}
				}
				puntero = puntero->siguiente;
			}
		}
	}
	else if(opcion == 3){
		
	}
	
}

int busquedaJugueteID(int codigo, struct Juguete *reco){
	

	
	if (reco != NULL){
    		
        busquedaJugueteID(codigo, reco->izq);
        
       	if(reco->codigo == codigo ){
        
        	printf("\n	Juguete %i 	\n", contadorJuguetes); contadorJuguetes++;
			printf("Codigo: %i    \n", reco->codigo);
			printf("Nombre: %s   \n", reco->nombre);
			printf("Descripcion: %s   \n", reco->descripcion);
			printf("Categoria: %s   \n", reco->categoria);
			printf("Rango de edad: De %i a %i anos \n", reco->rangoInicial, reco->rangoFinal);
			printf("Costo: %.2f \n", reco->costo); //eliminar despues
			if(a == 0){
				b = reco->codigo;
			}
			a = 1;
    	}
    	busquedaJugueteID(codigo, reco->der);
    }
}

int sumarSolicitud(int codigo, struct Juguete *reco){
	
	if (reco != NULL){
    		
        busquedaJugueteID(codigo, reco->izq);
        
       	if(reco->codigo == codigo ){
        
        	reco->cantPedido++;
        	return 0;
    	}
    	busquedaJugueteID(codigo, reco->der);
    }
}
//----------------------------------------------------------------------------------------------------
void procesarCarta(ListaNino **listaNino, ColaCarta **colaCarta, ListaAyudante **listaAyudante, ColaComportamiento **colaComportamiento){

    
    int identificacion, IDProcesar, ano, contador = 0, opcion, contadorComportamientos =0;
    char stringVerificador[50];
	
	printf("Digite su identificacion: ");
	fgets(stringVerificador, 50, stdin);
	identificacion = atoi(stringVerificador);
	
	printf("Digite el ano que va a procesar las cartas: ");
	fgets(stringVerificador, 50, stdin);
	ano = atoi(stringVerificador);
	
	Carta* actual = (Carta*)malloc(sizeof(Carta));
	actual = (*colaCarta)->front;
	if((*colaCarta)->front != NULL){
		while(actual != NULL){
			if(actual->ano == ano){
				Nino* puntero = (Nino*)malloc(sizeof(Nino));
				puntero = (*listaNino)->cabeza;
				if((*listaNino)->cabeza != NULL){
					while(puntero != NULL){
						if(puntero->identificacion == actual->identificacion){
							printf("---- Nino %i ----\n", contador);
							printf("Nombre: %s\n", puntero->nombre);
							printf("Identificacion: %i\n\n", puntero->identificacion);
							contador++;
						}
						puntero = puntero->siguiente;
					}
				}
			}
			actual = actual->siguiente;
		}
	}
		
	printf("Digite la identificacion del nino que desea procesar la carta: ");
	fgets(stringVerificador, 50, stdin);
	IDProcesar = atoi(stringVerificador);
	
	Carta* actual1 = (Carta*)malloc(sizeof(Carta));
	actual1 = (*colaCarta)->front;
	if((*colaCarta)->front != NULL){
		while(actual1 != NULL){
			if(actual1->identificacion == IDProcesar && actual1->ano == ano){
				printf("Identificacion: %i \n", actual1->identificacion);
				printf("Ano: %i  \n", actual1->ano);
				printf("Codigo juguete 1: %i  \n", actual1->juguete1);
				printf("Codigo juguete 2: %i  \n", actual1->juguete2);
				printf("Codigo juguete 3: %i  \n", actual1->juguete3);
				printf("Codigo juguete 4: %i  \n", actual1->juguete4);
				printf("Codigo juguete 5: %i  \n", actual1->juguete5);
				printf("Codigo juguete 6: %i  \n", actual1->juguete6);
				printf("Codigo juguete 7: %i  \n", actual1->juguete7);
				printf("Codigo juguete 8: %i  \n", actual1->juguete8);
				printf("Codigo juguete 9: %i  \n", actual1->juguete9);
				printf("Codigo juguete 10: %i  \n", actual1->juguete10);	
			}
			actual1 = actual1->siguiente;
		}
	}
	
	printf("Digite 1 para procesar carta, 2 para salir: ");
	fgets(stringVerificador, 50, stdin);
	opcion = atoi(stringVerificador);
	
	if(opcion == 2){
		
	}
	else if(opcion == 1){
		
    	Ayudante* puntero = (Ayudante*)malloc(sizeof(Ayudante));
		puntero = (*listaAyudante)->cabeza;
			if((*listaAyudante)->cabeza != NULL){
				while(puntero != NULL){
					if(puntero->identificacion == identificacion){
						puntero->cantCartas++;
					}
					puntero = puntero->siguiente;
				}
				free(puntero);
			}
		
		Comportamiento* actual2 = (Comportamiento*)malloc(sizeof(Comportamiento));
		actual2 = (*colaComportamiento)->front;
		if((*colaComportamiento)->front != NULL){
			while(actual2 != NULL){
				if(actual2->identificacion == IDProcesar && actual2->comportamiento == 2){
					contadorComportamientos++;
				}
				actual2 = actual2->siguiente;
			}	
		}
		
		if(contadorComportamientos > 6){
			printf("No se puede procesar la carta por exceso de malos comportamientos\n");
			Carta* actual4 = (Carta*)malloc(sizeof(Carta));
			actual4 = (*colaCarta)->front;
			if((*colaCarta)->front != NULL){
				while(actual4 != NULL){
					if(actual4->identificacion == IDProcesar){
						strcpy(actual4->estadoCarta, "Rechazada");
					}
					actual4 = actual4->siguiente;
				}
			}
		}
		else{
			Carta* actual3 = (Carta*)malloc(sizeof(Carta));
			actual3 = (*colaCarta)->front;
			if((*colaCarta)->front != NULL){
				while(actual3 != NULL){
					if(actual3->identificacion == IDProcesar){
						actual3->IDAyudanteProce = identificacion;
						strcpy(actual3->estadoJuguete1, "Listo Para Entregar");
						strcpy(actual3->estadoJuguete2, "Listo Para Entregar");
						strcpy(actual3->estadoJuguete3, "Listo Para Entregar");
						strcpy(actual3->estadoJuguete4, "Listo Para Entregar");
						strcpy(actual3->estadoJuguete5, "Listo Para Entregar");
						strcpy(actual3->estadoJuguete6, "Listo Para Entregar");
						strcpy(actual3->estadoJuguete7, "Listo Para Entregar");
						strcpy(actual3->estadoJuguete8, "Listo Para Entregar");
						strcpy(actual3->estadoJuguete9, "Listo Para Entregar");
						strcpy(actual3->estadoJuguete10, "Listo Para Entregar");
						strcpy(actual3->estadoCarta, "Aprobada");
					}
					actual3 = actual3->siguiente;
				}
			}
			printf("Carta procesada con exito!!\n");
		}
	}
}

//----------------------------------------------------------------------------------------------------
void entregarJuguetes(){
    printf("Entregar juguetes");
}

//----------------------------------------------------------------------------------------------------
void analisisDatos(ColaCarta **colaCarta, ListaAyudante **listaAyudante){
    int opcion = 0, i =0;
	char stringVerificador[6];
	
	while(opcion != 8){
		printf("\n-------------------------MENU de ANALISIS DE DATOS--------------------------\n\n");
		printf("1- Cantidad de juguetes al ano\n");
		printf("2- Lugares con mas y menos juguetes\n");
        printf("3- Cantidad de ninos con carta aprobada\n");
        printf("4- Cantidad de ninos con carta rechazada\n");
        printf("5- Cantidad de comportamientos buenos y malos\n");
        printf("6- Cantidad de cartas procesadas por ayudante\n");
		printf("7- Top 10 juguetes mas pedidos\n");
		printf("8- Salir.  \n");
		do{
			printf("Digite la opcion que desea realizar: ");
			scanf("%s", stringVerificador);
			opcion = atoi(stringVerificador);
			if(opcion == 0){
				printf("Error, opcion invalida.\n\n");
			}
		}while(opcion == 0);
		
		if(opcion > 8 || opcion < 1){
			printf("Error, opcion invalida.\n\n");
		}
		else if(opcion == 1){
			for(i=0; i<20;i++){
				ArrayJuguetesAno[i] = 0;
				ArrayJuguetesCant[i] = 0;
			}
			AD_cantJuguetes(&*colaCarta);
		}
		else if(opcion == 2){
			AD_masmenosJuguetes();
		}
		else if(opcion == 3){
			for(i=0; i<20;i++){
				ArrayCartasAno[i] = 0;
				ArrayCartasAprov[i] = 0;
			}
			AD_ninosAprobados(&*colaCarta);
		}
        else if(opcion == 4){
        	for(i=0; i<20;i++){
				ArrayCartasAno[i] = 0;
				ArrayCartasRechazo[i] = 0;
			}
			AD_ninosRechazados(&*colaCarta);
		}
        else if(opcion == 5){
			AD_comportamientos();
		}
        else if(opcion == 6){
			AD_cartasXAyudante(&*listaAyudante);
		}
        else if(opcion == 7){
			AD_TopJuguetes(&*colaCarta);
		}
    }
}

void AD_cantJuguetes(ColaCarta **colaCarta){
	int i=0;
    Carta* actual = (Carta*)malloc(sizeof(Carta));
	actual = (*colaCarta)->front;
	if((*colaCarta)->front != NULL){
		while(actual != NULL){
			if(anoExiste(actual->ano) == 1){
				for(i=0;i<20;i++){
					if(actual->ano == ArrayJuguetesAno[i]){
						if(strcmp(actual->estadoJuguete1, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete2, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete3, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete4, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete5, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete6, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete7, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete8, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete9, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete10, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayJuguetesAno[i]){
						ArrayJuguetesAno[i] = actual->ano;
						if(strcmp(actual->estadoJuguete1, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete2, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete3, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete4, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete5, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete6, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete7, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete8, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete9, "Solicitado") == 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						if(strcmp(actual->estadoJuguete10, "Solicitado")== 0 || strcmp(actual->estadoJuguete1, "Listo Para Entregar")== 0){
							ArrayJuguetesCant[i]++;
						}
						i = 21;
					}
				}
			}
			actual = actual->siguiente;
		}
	}
	for(i=0;i<20;i++){
		if(ArrayJuguetesAno[i] != 0){
			printf("Ano: %i \n", ArrayJuguetesAno[i]);
			printf("Cantidad: %i \n\n", ArrayJuguetesCant[i]);
		}
	}
}

int anoExiste(int ano){
	int i =0;
	for(i=0;i<20;i++){
		if(ano == ArrayJuguetesAno[i]){
			return 1;
		}
	}
	return 0;
}

int anoExisteCarta(int ano){
	int i =0;
	for(i=0;i<20;i++){
		if(ano == ArrayCartasAno[i]){
			return 1;
		}
	}
	return 0;
}

int codExiste(int cod){
	int i =0;
	for(i=0;i<20;i++){
		if(cod == ArrayCodJuguetes[i]){
			return 1;
		}
	}
	return 0;
}

void AD_masmenosJuguetes(){
    printf("Se imprimen los lugares con + y - juguetes");
}

void AD_ninosAprobados(ColaCarta **colaCarta){
    int i=0;
    Carta* actual = (Carta*)malloc(sizeof(Carta));
	actual = (*colaCarta)->front;
	if((*colaCarta)->front != NULL){
		while(actual != NULL){
			if(anoExisteCarta(actual->ano) == 1){
				for(i=0;i<20;i++){
					if(actual->ano == ArrayCartasAno[i]){
						if(strcmp(actual->estadoCarta, "Aprobada")== 0){
							ArrayCartasAprov[i]++;
						}
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCartasAno[i]){
						ArrayCartasAno[i] = actual->ano;
						if(strcmp(actual->estadoCarta, "Aprobada")== 0){
							ArrayCartasAprov[i]++;
						}
						i = 21;
					}
				}
			}
			actual = actual->siguiente;
		}
	}
	for(i=0;i<20;i++){
		if(ArrayCartasAno[i] != 0){
			printf("Ano: %i \n", ArrayCartasAno[i]);
			printf("Cantidad: %i \n\n", ArrayCartasAprov[i]);
		}
	}
}

void AD_ninosRechazados(ColaCarta **colaCarta){
    int i=0;
    Carta* actual = (Carta*)malloc(sizeof(Carta));
	actual = (*colaCarta)->front;
	if((*colaCarta)->front != NULL){
		while(actual != NULL){
			if(anoExisteCarta(actual->ano) == 1){
				for(i=0;i<20;i++){
					if(actual->ano == ArrayCartasAno[i]){
						if(strcmp(actual->estadoCarta, "Rechazada")== 0){
							ArrayCartasRechazo[i]++;
						}
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCartasAno[i]){
						ArrayCartasAno[i] = actual->ano;
						if(strcmp(actual->estadoCarta, "Rechazada")== 0){
							ArrayCartasRechazo[i]++;
						}
						i = 21;
					}
				}
			}
			actual = actual->siguiente;
		}
	}
	for(i=0;i<20;i++){
		if(ArrayCartasAno[i] != 0){
			printf("Ano: %i \n", ArrayCartasAno[i]);
			printf("Cantidad: %i \n\n", ArrayCartasRechazo[i]);
		}
	}
}

void AD_comportamientos(){
    printf("Total de comportamientos buenos: %i\n", comportamientosBuenos);
    printf("Total de comportamientos malos: %i", comportamientosMalos);

}

void AD_cartasXAyudante(ListaAyudante **listaAyudante){
	int contador = 1;
    Ayudante* puntero = (Ayudante*)malloc(sizeof(Ayudante));
		puntero = (*listaAyudante)->cabeza;
			if((*listaAyudante)->cabeza != NULL){
				while(puntero != NULL){
					printf("Ayudante %i:  %s (%i): %i\n", contador, puntero->nombre, puntero->identificacion, puntero->cantCartas);
					puntero = puntero->siguiente;
					contador++;
				}
				free(puntero);
			}
}

void AD_TopJuguetes(ColaCarta **colaCarta){
	int i=0;
    Carta* actual = (Carta*)malloc(sizeof(Carta));
	actual = (*colaCarta)->front;
	if((*colaCarta)->front != NULL){
		while(actual != NULL){
			if(codExiste(actual->juguete1) == 1){
				for(i=0;i<20;i++){
					if(actual->juguete1 == ArrayCodJuguetes[i]){
						ArrayCantJuguetes[i]++;
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCodJuguetes[i]){
						ArrayCodJuguetes[i] = actual->juguete1;
						ArrayCantJuguetes[i]++;
						i = 21;
					}
				}
			}
			 //-----------
			if(codExiste(actual->juguete2) == 1){ //
				for(i=0;i<20;i++){
					if(actual->juguete2 == ArrayCodJuguetes[i]){
						ArrayCantJuguetes[i]++;
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCodJuguetes[i]){
						ArrayCodJuguetes[i] = actual->juguete2;
						ArrayCantJuguetes[i]++;
						i = 21;
					}
				}
			}
			 //-----------
			if(codExiste(actual->juguete3) == 1){
				for(i=0;i<20;i++){
					if(actual->juguete3 == ArrayCodJuguetes[i]){
						ArrayCantJuguetes[i]++;
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCodJuguetes[i]){
						ArrayCodJuguetes[i] = actual->juguete3;
						ArrayCantJuguetes[i]++;
						i = 21;
					}
				}
			}
			 //-----------
			if(codExiste(actual->juguete4) == 1){
				for(i=0;i<20;i++){
					if(actual->juguete4 == ArrayCodJuguetes[i]){
						ArrayCantJuguetes[i]++;
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCodJuguetes[i]){
						ArrayCodJuguetes[i] = actual->juguete4;
						ArrayCantJuguetes[i]++;
						i = 21;
					}
				}
			}
			 //-----------
			if(codExiste(actual->juguete5) == 1){
				for(i=0;i<20;i++){
					if(actual->juguete5 == ArrayCodJuguetes[i]){
						ArrayCantJuguetes[i]++;
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCodJuguetes[i]){
						ArrayCodJuguetes[i] = actual->juguete5;
						ArrayCantJuguetes[i]++;
						i = 21;
					}
				}
			}
			 //-----------
			if(codExiste(actual->juguete6) == 1){
				for(i=0;i<20;i++){
					if(actual->juguete6 == ArrayCodJuguetes[i]){
						ArrayCantJuguetes[i]++;
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCodJuguetes[i]){
						ArrayCodJuguetes[i] = actual->juguete6;
						ArrayCantJuguetes[i]++;
						i = 21;
					}
				}
			}
			 //-----------
			if(codExiste(actual->juguete7) == 1){
				for(i=0;i<20;i++){
					if(actual->juguete7 == ArrayCodJuguetes[i]){
						ArrayCantJuguetes[i]++;
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCodJuguetes[i]){
						ArrayCodJuguetes[i] = actual->juguete7;
						ArrayCantJuguetes[i]++;
						i = 21;
					}
				}
			}
			 //-----------
			if(codExiste(actual->juguete8) == 1){
				for(i=0;i<20;i++){
					if(actual->juguete8 == ArrayCodJuguetes[i]){
						ArrayCantJuguetes[i]++;
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCodJuguetes[i]){
						ArrayCodJuguetes[i] = actual->juguete8;
						ArrayCantJuguetes[i]++;
						i = 21;
					}
				}
			}
			 //-----------
			if(codExiste(actual->juguete9) == 1){
				for(i=0;i<20;i++){
					if(actual->juguete9 == ArrayCodJuguetes[i]){
						ArrayCantJuguetes[i]++;
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCodJuguetes[i]){
						ArrayCodJuguetes[i] = actual->juguete9;
						ArrayCantJuguetes[i]++;
						i = 21;
					}
				}
			}
			 //-----------
			if(codExiste(actual->juguete10) == 1){
				for(i=0;i<20;i++){
					if(actual->juguete10 == ArrayCodJuguetes[i]){
						ArrayCantJuguetes[i]++;
					}
				}
			}
			else{
				for(i=0;i<20;i++){
					if(0 == ArrayCodJuguetes[i]){
						ArrayCodJuguetes[i] = actual->juguete10;
						ArrayCantJuguetes[i]++;
						i = 21;
					}
				}
			}
			actual = actual->siguiente;
		}
	}

	int e;
	printf("TOP JUGUETES\n");
	for(e=0; e<10; e++){
	
		int mayor=0;	
		int IDMayor=0;
		for(i=0;i<20;i++){
			if(ArrayCantJuguetes[i] > mayor){
				mayor = ArrayCantJuguetes[i];
				IDMayor = ArrayCodJuguetes[i];
			}
		}
		printf("\nCodigo: %i     Cantidad: %i", IDMayor, mayor);
		for(i=0;i<20;i++){
			if(ArrayCodJuguetes[i] == IDMayor){
				ArrayCantJuguetes[i] = ArrayCantJuguetes[i] - ArrayCantJuguetes[i] -ArrayCantJuguetes[i];
			}
		}
	}
	
//	int ArrayCodJuguetes[20];
//	int ArrayCantJuguetes[20];
	
	
	
	
}










