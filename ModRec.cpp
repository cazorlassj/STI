#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include "libreria.h"
using namespace std;
bool logged = false;
Usuarios logg;

void login(FILE *usr);
void regClient(FILE *cliente);
int cantclient = 0;

main(){
	int op;
	FILE *usr;
	FILE *cliente;
	setlocale(LC_ALL, "spanish");
	system("cls");
    printf("Modulo del recepcionista\n");
    printf("=========================\n");
    if(!logged){
    	printf("No inicio sesión\n");
	}
	else{
		printf("Usuario Actual: %s\n\n\n\n", logg.apenom);
	}
    printf("1.- Iniciar sesion\n");
    printf("2.- Registrar cliente\n");
    printf("3.- Registrar turno\n");
    printf("4.- Listado de atenciones por profesional y fecha\n");
    printf("5.- Cerrar la aplicacion.\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &op);
    switch(op){
    	case 1:{
    		system("cls");
    		login(usr);
    		main();
			break;
		}
		case 2:{
			system("cls");
    		regClient(cliente);
    		main();
			break;
		}
		case 3:{
			
			break;
		}
		case 4:{
			
			break;
		}
		case 5:{
			system("cls");
			chau();
			break;
		}
		default:{
			system("cls");
			printf("Ingrese una opcion valida");
			main();
			break;
		}
	}
	return 0;
}

void regClient(FILE *cliente){
 	if(logged){
	    system("cls");
	    cliente = fopen("Clientes.dat", "a+b");
	    if(cliente == NULL){
	    	printf("ERROR: No se pudo abrir el archivo Clientes.dat");
	    } 
		else{
	    	Cliente clienT;
	      	printf("Registrar cliente\n");
	      	printf("=========================\n");
	      	printf("\nIngrese el apellido y nombre del cliente: ");
	      	_flushall();
	      	gets(clienT.apenom);
	      	printf("Ingrese el domicilio: ");
	      	_flushall();
	      	gets(clienT.dom);
	      	printf("Ingrese el DNI del cliente: ");
	      	scanf("%d", &clienT.dni);
	      	printf("Ingrese la localidad: ");
	      	_flushall();
	      	gets(clienT.localidad);
	      	printf("\nIngrese la fecha de nacimiento del cliente");
	      	printf("\nDia: ");
	      	scanf("%d", &clienT.fec.dia);
	      	printf("\nMes: ");
	      	scanf("%d", &clienT.fec.mes);
	      	printf("\nAño: ");
	      	scanf("%d", &clienT.fec.anio);
	      	fwrite(&clienT, sizeof(Cliente), 1, cliente);
	      	cantclient++;
	    }
	    fclose(cliente);
	    printf("\n\n");
	    system("pause");
  	}
	else{
    	system("cls");
    	printf("ERROR: usted no inicio sesión\n");
		printf("=========================\n");
    	system("pause");
  	}
}

void login(FILE *usr){
	system("cls");
	int err;
	Usuarios asis;
	usr = fopen("Recepcionistas.dat", "r+b");
	if(usr == NULL){
		printf("No se pudo abrir el archivo\n");
	}
	else{
		do{
    		system("cls");
			err = 0;
			Usuarios busc;
			printf("Iniciar Sesion\n");
			printf("=========================\n");
			_flushall();
    		printf("Ingrese el ID de usuario: ");
    		gets(asis.user);
    		rewind(usr);
    		fread(&busc, sizeof(Usuarios), 1, usr);
    		int match = 0;
    		Usuarios aux;
	    	while (!feof(usr)){
	    		if (strcmp(asis.user, busc.user) == 0){
	        		match++;
	    			aux = busc;
	        }
	        fread(&busc, sizeof(Usuarios), 1, usr);
	    	}
	    	if (match == 1){
	        	int match2 = 0;
	        	system("cls");
	        	printf("Iniciar Sesion\n");
				printf("=========================\n");
				_flushall();
	        	printf("Ingrese la contraseña: ");
	        	gets(asis.pw);
	        	if (strcmp(asis.pw, aux.pw) == 0) {
	          		match2++;
	        	}
	        	if (match2 > 0){
	          	asis = aux;
	          	system("cls");
	          	printf("Sesion iniciada con exito\n");
				printf("=========================\n");
				logg = asis;
	          	printf("Bienvenido %s\n\n\n\n", asis.apenom);
	          	logged = true;
	        	} 
				else{
	          	err = 1;
	          	system("cls");
	          	printf("Contraseña incorrecta\n");
				printf("=========================\n");
	          	system("pause");
	    		}
	      	}
			else{
	        	err = 1;
	        	system("cls");
	        	printf("ID de usuario no encontrado\n");
				printf("=========================\n");
	        	system("pause");
	    	}
    	}while (err == 1);
	}
	fclose(usr);
	printf("\n\n");
	system("pause");
}