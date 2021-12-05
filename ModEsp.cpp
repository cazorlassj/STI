#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <iostream>
#include <chrono>
#include <time.h>
#include <unistd.h>
#include "libreria.h"
using namespace std;

bool logged = false;
Profesionales logg;


void login(FILE *prof);
void Lista(FILE *turnos);

main(){
	setlocale(LC_ALL, "spanish");
	int op;
	FILE *prof;
	FILE *usr;
	FILE *client;
	FILE *turnos;
	system("cls");
    printf("Modulo Espacios\n");
    printf("=========================\n");
    if(!logged){
    	printf("No inicio sesión\n");
	}
	else{
		printf("Usuario Actual: %s\n\n\n\n", logg.apenom);
	}
    printf("=========================\n");
    printf("1.- Iniciar sesion\n");
    printf("2.- Visualizar lista de espera de turnos (informe)\n");
    printf("3.- Registrar evolucion del tratamiento\n");
    printf("4.- Cerrar la aplicacion.\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &op);
    switch(op){
    	case 1:{
    		system("cls");
    		login(prof);
    		main();
			break;
		}
		case 2:{
			system("cls");
    		Lista(turnos);
    		main();
			break;
		}
		case 3:{
			
			break;
		}
		case 4:{
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

void Lista(FILE *turnos){	
	if(logged){
		system("cls");
		turnos = fopen("Turnos.dat","r+b");
		if(turnos == NULL){
			printf("No se pudo abrir el archivo\n");
		}
		else{
			printf("Lista de turnos\n");
			printf("=========================\n");
			Turnos trn;
			rewind(turnos);
			int s=0;
			fread(&trn, sizeof(Turnos), 1, turnos);
			while(!feof(turnos)){
				printf("ID del profesional: ");
				printf("%d", trn.idp);
				printf("\nFecha del turno: %d/%d/%d", trn.fec.dia, trn.fec.mes, trn.fec.anio);
				printf("\nDNI del cliente: %d", trn.dni);
				printf("\nDetalle de la visita: ");
				puts(trn.detalle);
				fread(&trn, sizeof(Turnos), 1, turnos);
				printf("\n\n");
			}
		}
		fclose(turnos);
		printf("\n\n");
		system("pause");
  	}
	else{
    system("cls");
    printf("ERROR: usted no inicio sesión\n");
	printf("=========================\n");
    system("pause");
  	}
  	system("pause");
  	fclose(turnos);
}

void login(FILE *prof){
	system("cls");
	int err;
	Profesionales asis;
	prof = fopen("Profesionales.dat", "r+b");
	if(prof == NULL){
		printf("No se pudo abrir el archivo\n");
	}
	else{
		do{
    		system("cls");
			err = 0;
			Profesionales busc;
			printf("Iniciar Sesion\n");
			printf("=========================\n");
			_flushall();
    		printf("Ingrese el ID de usuario: ");
    		gets(asis.User.user);
    		rewind(prof);
    		fread(&busc, sizeof(Profesionales), 1, prof);
    		int match = 0;
    		Profesionales aux;
	    	while (!feof(prof)){
	    		if (strcmp(asis.User.user, busc.User.user) == 0){
	        		match++;
	    			aux = busc;
	        }
	        fread(&busc, sizeof(Profesionales), 1, prof);
	    	}
	    	if (match == 1){
	        	int match2 = 0;
	        	system("cls");
	        	printf("Iniciar Sesion\n");
				printf("=========================\n");
				_flushall();
	        	printf("Ingrese la contraseña: ");
	        	gets(asis.User.pw);
	        	if (strcmp(asis.User.pw, aux.User.pw) == 0) {
	          		match2++;
	        	}
	        	if (match2 > 0){
	          	asis = aux;
	          	system("cls");
	          	printf("Sesion iniciada con exito\n");
				printf("=========================\n");
				logg = asis;
	          	printf("Bienvenido %s\n\n\n\n", asis.User.apenom);
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
	fclose(prof);
	printf("\n\n");
	system("pause");
}
