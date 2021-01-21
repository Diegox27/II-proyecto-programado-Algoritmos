#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructuras
typedef struct ListaCarta ListaCarta;
typedef struct Carta Carta;
typedef struct ListaDeseo ListaDeseo;
typedef struct Deseo Deseo;
typedef struct ListaComportamiento ListaComportamiento;
typedef struct Comportamiento Comportamiento;

//********************REGISTRO DEL COMPORTAMIENTO DE LOS NIÑOS/NIÑAS*********************//

struct Comportamiento
{
	char namePadre[20];
	int IDchild;
	char fecha[20];
	char descripcion[50];
	char comport[10];
	Comportamiento *siguiente;
};

struct ListaComportamiento
{
	Comportamiento *inicio;
};

//Crear lista de comportamientos
ListaComportamiento *listaNuevaComportamiento(void){
	ListaComportamiento *LCom;
	LCom = (ListaComportamiento *) malloc(sizeof(ListaComportamiento));
	LCom->inicio = NULL;
	return LCom;
}

//Agregar comportamientos

void CrearComportamiento(ListaComportamiento *LCom)
{
	Comportamiento *n, *aux;
	
	if(LCom->inicio == NULL) //Valida si la lista está vacía
	{
		//Inserta al inicio de la lista
		LCom->inicio = (Comportamiento *) malloc(sizeof(Comportamiento));
		
		fflush(stdin);
		//Guardar Nombre del padre
		printf("Ingrese el nombre del padre o madre: \n");
		gets(LCom->inicio->namePadre);
		
		//Guardar ID
		printf("Ingrese el ID del boy/girl: \n");
		scanf("%d",&LCom->inicio->IDchild);
		
		fflush(stdin);
		//Guardar fecha
		printf("Ingrese la fecha de hoy:\n");
		gets(LCom->inicio->fecha);
		
		fflush(stdin);
		//Guardar descripción dle comportamiento
		printf("Ingrese una breve descripcion del comportamiento del boy/girl:\n");
		gets(LCom->inicio->descripcion);
		
		fflush(stdin);
		//Guardar comportamiento del niño o niña
		printf("Ingrese el comportamiento del boy/girl (Bueno o Malo):\n");
		gets(LCom->inicio->comport);
		
		fflush(stdin);
		LCom->inicio->siguiente = NULL;
		
		return;
	}
	n = LCom->inicio;
	while(n!= NULL)
	{
		aux = n;
		n = n->siguiente;		
	}
	aux->siguiente = (Comportamiento *) malloc(sizeof(Comportamiento));
	aux->siguiente->siguiente = NULL;
	
	fflush(stdin);
	//Guardar Nombre del padre
	printf("Ingrese el nombre del padre o madre: \n");
	gets(aux->siguiente->namePadre);
		
	//Guardar ID
	printf("Ingrese el ID del boy/girl: \n");
	scanf("%d",&aux->siguiente->IDchild);
	
	fflush(stdin);	
	//Guardar fecha
	printf("Ingrese la fecha de hoy:\n");
	gets(aux->siguiente->fecha);
	
	fflush(stdin);	
	//Guardar descripción dle comportamiento
	printf("Ingrese una breve descripcion del comportamiento del boy/girl:\n");
	gets(aux->siguiente->descripcion);
		
	fflush(stdin);
	//Guardar comportamiento del niño o niña
	printf("Ingrese el comportamiento del boy/girl (Bueno o Malo):\n");
	gets(aux->siguiente->comport);
	
	fflush(stdin);
}

//**********CARTA PARA SANTA*********//
struct Carta
{
	int year;
	int ID;
	char Toy0[10];
	char Toy1[10];
	char Toy2[10];
	char Toy3[10];
	char Toy4[10];
	char Toy5[10];
	char Toy6[10];
	char Toy7[10];
	char Toy8[10];
	char Toy9[10];
	Carta *siguiente;
};

struct ListaCarta
{
	Carta *inicio;
};

//función para crear la lista de la carta

ListaCarta *listaNuevaCarta(void){
	ListaCarta *LC;
	LC = (ListaCarta *) malloc(sizeof(ListaCarta));
	LC->inicio = NULL;
	return LC;
} 

//Función para crear la carta

void CrearCarta(ListaCarta *LC)
{
	Carta *n, *aux;
	
	if(LC->inicio == NULL) //Valida si la lista está vacía
	{
		//Inserta al inicio de la lista
		LC->inicio = (Carta *) malloc(sizeof(Carta));
		
		//Guardar año
		printf("Ingrese el year de la carta: \n");
		scanf("%d",&LC->inicio->year);
		
		//Guardar ID
		printf("Ingrese su ID: \n");
		scanf("%d",&LC->inicio->ID);
		
		LC->inicio->siguiente = NULL;
		
		return;
	}
	n = LC->inicio;
	while(n!= NULL)
	{
		aux = n;
		n = n->siguiente;		
	}
	aux->siguiente = (Carta *) malloc(sizeof(Carta));
	aux->siguiente->siguiente = NULL;
	
	//Guardar año
	printf("Ingrese el year de la carta: \n");
	scanf("%d",&aux->siguiente->year);
	
	//Guardar ID
	printf("Ingrese su ID: \n");
	scanf("%d",&aux->siguiente->ID);
}

//Función para agregar jueguetes a la carta

void AgregarJuguetes(ListaCarta *LC)
{
	Carta *i;
	int ID;
	int num;
	
	//Ingresar el ID para buscar la carta
	printf("Ingrese su ID: \n");
	scanf("%d",&ID);
	
	for(i = LC->inicio; i!=NULL; i = i->siguiente)
	{
		if(i->ID==ID)
		{
			printf("Cuantos juguetes a agregado a la carta? Ingrese un numero del 0-9: \n");
			scanf("%d",&num);
			
			fflush(stdin);
			
			//Almacenar los juguetes
			if(num==0)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy0);
				fflush(stdin);
				return;
			}
			else if(num==1)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy1);
				fflush(stdin);
				return;
			}
			else if(num==2)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy2);
				fflush(stdin);
				return;
			}
			else if(num==3)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy3);
				fflush(stdin);
				return;
			}
			else if(num==4)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy4);
				fflush(stdin);
				return;
			}
			else if(num==5)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy5);
				fflush(stdin);
				return;
			}
			else if(num==6)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy6);
				fflush(stdin);
				return;
			}
			else if(num==7)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy7);
				fflush(stdin);
				return;
			}
			else if(num==8)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy8);
				fflush(stdin);
				return;
			}
			else if(num==9)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy9);
				fflush(stdin);
				return;
			}
			else 
			{
				printf("Ya no se pueden agregar más juguetes\n");
				return;
			}
		}
	}
	printf("Seguro que esta registrado en el sistema?\n");
	return;
}

//Función para ver la carta de santa

void VerCartaSanta(ListaCarta *LC)
{
	Carta *i;
	int ID;
	int num;
	
	//Ingresar el ID para buscar la carta
	printf("Ingrese su ID: \n");
	scanf("%d",&ID);
	
	//Ingresar el año
	printf("Ingrese el year para cuando es la carta:\n");
	scanf("%d",&num);
	
	for(i = LC->inicio; i!=NULL; i = i->siguiente)
	{
		if(i->ID==ID)
		{
			//Mostrar carta
			printf("Juguete 1: %s\nJuguete 2: %s\nJuguete 3: %s\nJuguete 4: %s\nJuguete 5: %s\nJuguete 6: %s\nJuguete 7: %s\nJuguete 8: %s\nJuguete 9: %s\nJuguete 10: %s\n",
			i->Toy0,i->Toy1,i->Toy2,i->Toy3,i->Toy4,i->Toy5,i->Toy6,i->Toy7,i->Toy8,i->Toy9);
			return;
		}
	}
}

//***********LISTA DE DESEOS************//

//Estructuras
struct Deseo
{
	int ID;
	char Toy0[10];
	char Toy1[10];
	char Toy2[10];
	char Toy3[10];
	char Toy4[10];
	char Toy5[10];
	char Toy6[10];
	char Toy7[10];
	char Toy8[10];
	char Toy9[10];
	Deseo *siguiente;
};

struct ListaDeseo
{
	Deseo *inicio;
};

//Función para crear la lista de deseos

ListaDeseo *listaNuevaDeseos(void){
	ListaDeseo *LD;
	LD = (ListaDeseo *) malloc(sizeof(ListaDeseo));
	LD->inicio = NULL;
	return LD;
}

//Función para crear la lista de deseos

void CrearListaDeseo(ListaDeseo *LD)
{
	Deseo *n, *aux;
	
	if(LD->inicio == NULL) //Valida si la lista está vacía
	{
		//Inserta al inicio de la lista
		LD->inicio = (Deseo *) malloc(sizeof(Deseo));
		
		//Guardar ID
		printf("Ingrese su ID: \n");
		scanf("%d",&LD->inicio->ID);
		
		LD->inicio->siguiente = NULL;
		
		return;
	}
	n = LD->inicio;
	while(n!= NULL)
	{
		aux = n;
		n = n->siguiente;		
	}
	aux->siguiente = (Deseo *) malloc(sizeof(Deseo));
	aux->siguiente->siguiente = NULL;
	
	//Guardar ID
	printf("Ingrese su ID: \n");
	scanf("%d",&aux->siguiente->ID);
}

//Función para agregar jueguetes a la lista

void AgregarJuguetesListaDeseos(ListaDeseo *LD)
{
	Deseo *i;
	int ID;
	int num;
	
	//Ingresar el ID para buscar la carta
	printf("Ingrese su ID: \n");
	scanf("%d",&ID);
	
	for(i = LD->inicio; i!=NULL; i = i->siguiente)
	{
		if(i->ID==ID)
		{
			printf("Cuantos juguetes a agregado a la lista?: \n");
			scanf("%d",&num);
			
			fflush(stdin);
			
			//Almacenar los juguetes
			if(num==0)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy0);
				fflush(stdin);
				return;
			}
			else if(num==1)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy1);
				fflush(stdin);
				return;
			}
			else if(num==2)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy2);
				fflush(stdin);
				return;
			}
			else if(num==3)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy3);
				fflush(stdin);
				return;
			}
			else if(num==4)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy4);
				fflush(stdin);
				return;
			}
			else if(num==5)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy5);
				fflush(stdin);
				return;
			}
			else if(num==6)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy6);
				fflush(stdin);
				return;
			}
			else if(num==7)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy7);
				fflush(stdin);
				return;
			}
			else if(num==8)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy8);
				fflush(stdin);
				return;
			}
			else if(num==9)
			{
				printf("Ingrese el nombre del juguete: \n");
				gets(i->Toy9);
				fflush(stdin);
				return;
			}
			else 
			{
				printf("Upss nos quedamos sin juguetes\n");
				return;
			}
		}
	}
	printf("Seguro que esta registrado en el sistema?\n");
	return;
}

//Función para pasar los juguetes de la lsita de desos a la carta

void pasarJuguetes(ListaDeseo *LD,ListaCarta *LC)
{
	Carta *i1;
	Deseo *i2;
	char juguete[10], nada[1]="";
	int ID;
	int num;
	
	//Insertar ID
	printf("Ingrese su ID:\n");
	scanf("%d",&ID);
	
	//Ingresar juguete de la lista
	printf("Ingrese el juguete que desea pasar a la carta:\n");
	fflush(stdin);
	gets(juguete);
	fflush(stdin);
	
	for(i2 = LD->inicio; i2!=NULL; i2 = i2->siguiente)
	{
		//Comparar ID
		if(i2->ID==ID)
		{
			//Comparar juguetes de la lista con el ingresado
			if(strcmp(i2->Toy0,juguete)==0)
			{
				strcpy(i2->Toy0,nada);
			}
			else if(strcmp(i2->Toy1,juguete)==0)
			{
				strcpy(i2->Toy1,nada);
			}
			else if(strcmp(i2->Toy2,juguete)==0)
			{
				strcpy(i2->Toy2,nada);
			}
			else if(strcmp(i2->Toy3,juguete)==0)
			{
				strcpy(i2->Toy3,nada);
			}
			else if(strcmp(i2->Toy4,juguete)==0)
			{
				strcpy(i2->Toy4,nada);
			}
			else if(strcmp(i2->Toy5,juguete)==0)
			{
				strcpy(i2->Toy5,nada);
			}
			else if(strcmp(i2->Toy6,juguete)==0)
			{
				strcpy(i2->Toy6,nada);
			}
			else if(strcmp(i2->Toy7,juguete)==0)
			{
				strcpy(i2->Toy7,nada);
			}
			else if(strcmp(i2->Toy8,juguete)==0)
			{
				strcpy(i2->Toy8,nada);
			}
			else if(strcmp(i2->Toy9,juguete)==0)
			{
				strcpy(i2->Toy9,nada);
			}
		}
	}
	for(i1 = LC->inicio; i1!=NULL; i1 = i1->siguiente)
	{
		//Comparar ID
		if(i1->ID==ID)
		{
			printf("Cuantos juguetes a agregado a la carta? Ingrese un numero del 0-9: \n");
			scanf("%d",&num);
			
			//Pasar el juguete de la lista a la carta
			if(num==0)
			{
				strcpy(i1->Toy0,juguete);
			}
			else if(num==1)
			{
				strcpy(i1->Toy1,juguete);
			}
			else if(num==2)
			{
				strcpy(i1->Toy2,juguete);
			}
			else if(num==3)
			{
				strcpy(i1->Toy3,juguete);
			}
			else if(num==4)
			{
				strcpy(i1->Toy4,juguete);
			}
			else if(num==5)
			{
				strcpy(i1->Toy5,juguete);
			}
			else if(num==6)
			{
				strcpy(i1->Toy6,juguete);
			}
			else if(num==7)
			{
				strcpy(i1->Toy7,juguete);
			}
			else if(num==8)
			{
				strcpy(i1->Toy8,juguete);
			}
			else if(num==9)
			{
				strcpy(i1->Toy9,juguete);
			}
		}
	}
	return;
}


//Función Carta de Santa

void CartaSanta(ListaCarta *LC,ListaDeseo *LD)
{
	//Menu de la carta
	int opcion;
	do{
		printf("--------MENU para la carta y la lista de deseos-----------\n");
		printf("1-Consultar el catalogo de juguetes\n");
		printf("2-Crear la Carta para Santa\n");
		printf("3-Anadir juguete a la carta\n");
		printf("4-Crear la lista de deseos\n");
		printf("5-Anadir juguete a la lista de deseos\n");
		printf("6-Cambiar juguete de la lista a la carta\n");
		printf("7-Consultar carta\n");
		printf("Para regresar al menu principal ingrese el numero 99\n");
		printf("Ingrese el numero de la opcion que desea realizar:\n");
		scanf("%d",&opcion);
		
		switch (opcion){
			case 1: //Funcion de consultar catalogo
			break;
			case 2: CrearCarta(LC);
			break;
			case 3: AgregarJuguetes(LC);
			break;
			case 4: CrearListaDeseo(LD);
			break;
			case 5: AgregarJuguetesListaDeseos(LD);
			break;
			case 6: pasarJuguetes(LD,LC);
			break;
			case 7: VerCartaSanta(LC);
			break;
		}
	}while(opcion!=99);
}

int main()
{
	//Crear lista para las cartas
	ListaCarta *LC;
	LC=listaNuevaCarta();
	
	//Crear lista para las listas de deseos
	ListaDeseo *LD;
	LD=listaNuevaDeseos();
	
	//Crear lista de comportamientos
	ListaComportamiento *LCom;
	LCom=listaNuevaComportamiento();
	
	//Menú
	int opcion;
	do{
		printf("----------MENU PRINCIPAL---------\n");
		printf("1-Registrar boy/girls\n");
		printf("2-Registro de ayudanre de Santa\n");
		printf("3-Resgistrar juguetes\n");
		printf("4-Registro de catalogo para lugares de domicilio\n");
		printf("5-Registro de comportamiento de boys/girls\n");
		printf("6-Carta para Santa/Lista de deseos\n");
		printf("7-Procesar carta para Santa\n");
		printf("8-Entrega de juguetes\n");
		printf("9-Analisis de datos\n");
		printf("Para salir del programa inserte el numero 100\n");
		scanf("%d",&opcion);
		switch (opcion){
			case 1: 
			break;
			case 2: 
			break;
			case 3: 
			break;
			case 4: 
			break;
			case 5: CrearComportamiento(LCom);
			break;
			case 6: CartaSanta(LC,LD);
			break;
			case 7: 
			break;
			case 8: 
			break;
			case 9: 
			break;
		}
	}while(opcion!=100);
	return 0;
}



















































