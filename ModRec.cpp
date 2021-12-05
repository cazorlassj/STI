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
void regTurn(FILE *turnos, FILE *prof);
void Listado(FILE *turnos);
int cantclient = 0;

main(){
	int op;
	FILE *usr;
	FILE *cliente;
	FILE *prof;
	FILE *turnos;
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
			system("cls");
    		regTurn(turnos, prof);
    		main();
			break;
		}
		case 4:{
			system("cls");
    		Listado(turnos);
    		main();
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

void Listado(FILE *turnos){
	if(logged){
    	turnos = fopen("Turnos.dat", "r+b");
    if(turnos == NULL){
      	printf ("ERROR: No se pudo abrir el archivo Turnos.dat");
    }
	else{
      	system("cls");
      	Turnos turns;
      	Profesionales pro;
      	rewind(turnos);
      	fread(&turns, sizeof(Turnos), 1, turnos);
      	while (!feof(turnos)) {
        	printf("ID del profesional: %d\n", turns.idp);
        	printf("Dia del turno: %d/%d/%d\n", turns.fec.dia, turns.fec.mes, turns.fec.anio);
        	printf("Detalle del turno: ");
        	puts(turns.detalle);
        	printf("\n\n");
        	fread(&turns, sizeof(Turnos), 1, turnos);
      	}
    }

  	} 
	else{
	    system("cls");
		printf("ERROR: usted no inicio sesión\n");
		printf("=========================\n");
		system("pause");
  	}
  	fclose(turnos);
  	system("pause");
}

void regTurn(FILE *turnos, FILE *prof){
	if(cantclient > 0){
    	if(logged){
	      	system("cls");
	      	turnos = fopen("Turnos.dat", "a+b");
	      	prof = fopen("Profesionales.dat", "r+b");
	    	if(prof == NULL){
	       		printf ("ERROR: No se pudo abrir el archivo Profesionales.dat");
	      	}
	      	if(turnos == NULL){
	        	printf ("ERROR: No se pudo abrir el archivo Turnos.dat");
	      	}
      		else{
	        int match3 = 0;
	        Turnos turns;
	        Profesionales pro;
	        system("cls");
	        printf("Registrar Turno\n");
	        printf("=========================\n");
	        rewind(prof);
	        fread(&pro, sizeof(Profesionales), 1, prof);
	        printf("Profesionales: \n");
	        while (!feof(prof)){
	          printf("Apellido y nombre: ");
	          puts(pro.apenom);
	          printf("ID de profesional: %d\n\n", pro.idp);
	          fread(&pro, sizeof(Profesionales), 1, prof);
	        }
	        printf("\nIngrese la ID del profesional: ");
	        scanf("%d", &turns.idp);
	        rewind(prof);
	        while (!feof(prof)){
	        	if(turns.idp == pro.idp){
	            	match3++;
	          	}
	          	fread(&pro, sizeof(Profesionales), 1, prof);
	        }
	        if(match3 > 0){
	          	printf("\nIngrese la fecha del turno");
	          	printf("\nDia: ");
	          	scanf("%d", &turns.fec.dia);
	          	printf("\nMes: ");
	          	scanf("%d", &turns.fec.mes);
	          	printf("\nAño: ");
	          	scanf("%d", &turns.fec.anio);
	          	printf("Ingrese el DNI del dueño de la mascota: ");
	          	scanf("%d", &turns.dni);
	          	printf("Ingrese el detalle de la atencion: ");
	          	_flushall();
	          	gets(turns.detalle);
	          	fwrite(&turns, sizeof(Turnos), 1, turnos);
	        }
	        else{
	          	system("cls");
	          	printf("\nLa ID de profesional ingresada no existe.\n");
	          	system("pause");
	        }
	    }
	    	fclose(turnos);
	    	fclose(prof);
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
		else{
			system("cls");
		  	printf("ERROR: Antes de realizar esta operación debe registrar clientes\n");
		  	printf("=========================\n");
		  	system("pause");
		}
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