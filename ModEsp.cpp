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
void Evol(FILE *turnos, FILE *prof, FILE *cliente, FILE *usr);

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
			system("cls");
    		Evol(turnos, prof, client, usr);
    		main();
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

void Evol(FILE *turnos, FILE *prof, FILE *cliente, FILE *usr){
	int archs = 0, err;
	FILE *proTemp;
	FILE *turTemp;
	if(logged){
    turnos = fopen("Turnos.dat", "a+b");
    prof = fopen("Profesionales.dat", "r+b");
    cliente = fopen("Clientes.dat", "r+b");
    if(prof == NULL){
    	printf("ERROR: No se pudo abrir el archivo Profesionales.dat");
    }
	else{
    	archs++;
    }
    if(turnos == NULL){
    	printf("ERROR: No se pudo abrir el archivo Turnos.dat");
    }
	else{
    	archs++;
    }
    if(cliente == NULL){
    	printf ("ERROR: No se pudo abrir el archivo Clientes.dat");
    }
	else{
    	archs++;
    }
    if(archs == 3){
    	do{
      		err = 0;
        	int match = 0;
        	int match2 = 0;
        	int i = 0;
        	int j = 0;
        	Turnos turno;
	        Profesionales pro;
	        Cliente clienT;
	        Cliente busc;
	
	        system("cls");
	        printf("Registrar evolución\n");
	        printf("=========================\n");
	        rewind(prof);
	        fread(&pro, sizeof(Profesionales), 1, prof);
	        printf("Profesionales: \n");
        	while(!feof(prof)){
        		printf("Apellido y nombre: ");
        		puts(pro.apenom);
        		printf("ID de profesional: %d\n", pro.idp);
        		fread(&pro, sizeof(Profesionales), 1, prof);
        	}
        	printf("\nIngrese la matricula del veterinario: ");
        	int mat;
        	scanf("%d", &mat);
        	turno.idp = mat;
        	rewind(prof);
        	fread(&pro, sizeof(Profesionales), 1, prof);
        	while (!feof(prof)){
        		if(turno.idp == pro.idp){
            		match++;
        		}
        		fread(&pro, sizeof(Profesionales), 1, prof);
        	}
        	if(match > 0){
	          	system("cls");
				printf("Registrar evolución\n");
	        	printf("=========================\n");
	          	rewind(cliente);
	          	fread(&clienT, sizeof(Cliente), 1, cliente);
	          	while (!feof(cliente)){
	            	i++;
	            	fread(&clienT, sizeof(Cliente), 1, cliente);
	          	}
          		Cliente aux[i];
          		rewind(cliente);
          		fread(&clienT, sizeof(Cliente), 1, cliente);
          		while (!feof(prof)) {
          			aux[j] = clienT;
            		j++;
            		fread(&clienT, sizeof(Cliente), 1, cliente);
          		}
          		printf("Clientes: \n");
          		while (!feof(cliente)) {
            		printf("\nApellido y nombre: ");
            		puts(clienT.apenom);
            		printf("DNI del cliente: %d\n\n", clienT.dni);
            		fread(&clienT, sizeof(Cliente), 1, cliente);
          		}
          		busc = clienT;
          		Cliente temp;
          		printf("\nIngrese el DNI del cliente: ");
          		int dniA;
          		scanf("%d", &dniA);
          		rewind(cliente);
          		fclose(cliente);
          		cliente = fopen("Clientes.dat", "r+b");
          		int ct = 0;
          		while(!feof(cliente)){
	           		if(busc.dni == dniA){
	              		clienT = busc;
	            	}
            		fread(&busc, sizeof(Cliente), 1, cliente);
           			if(busc.dni == dniA) match2++;
          		}
          		if(match2 > 0){
					proTemp = fopen("AuxTemp.dat", "w+b");
					int count=0;
					int countM=0;
					rewind(cliente);
          			fread(&clienT, sizeof(Cliente), 1, cliente);
	          		while(!feof(cliente)){
	            		countM++;
	            		fread(&clienT, sizeof(Cliente), 1, cliente);
	          		}
	          		Cliente auxMsc[countM];
	          		rewind(cliente);
	          		fread(&clienT, sizeof(Cliente), 1, cliente);
	          		int c2=0;
	          		while(!feof(cliente)){
	            		auxMsc[c2] = clienT;
	            		fread(&clienT, sizeof(Cliente), 1, cliente);
	            		c2++;
	        		}	          
	          		rewind(prof);
          			fread(&pro, sizeof(Profesionales), 1, prof);
		          	while(!feof(prof)){
		            	count++;
		            	fread(&pro, sizeof(Profesionales), 1, prof);
		          	}
	          		Profesionales proAux[count];
	          		rewind(prof);
	          		fread(&pro, sizeof(Profesionales), 1, prof);
	          		int c1=0;
		          	while(!feof(prof)){
		            	proAux[c1] = pro;
		            	fread(&pro, sizeof(Profesionales), 1, prof);
		            	c1++;
		          	}
	          		for(int i = 0; i < count; i++){
		          		if(mat == proAux[i].idp){
		          			proAux[i].rank++;
						}
					}
					rewind(proTemp);
					for(int i = 0; i < count; i++) {
						fwrite(&proAux[i], sizeof(Profesionales), 1, proTemp);
					}
					fclose(prof);
					if(remove("Profesionales.dat") != 0){
						perror("ERROR");
						system("pause");
					}
					fclose(proTemp);
					if(rename("AuxTemp.dat", "Profesionales.dat") != 0){
						perror("ERROR");
						system("pause");
					}
					fclose(turnos);
	            	system("cls");
	            	prof = fopen("Profesionales.dat", "r+b");
	            	turnos = fopen("Turnos.dat", "a+b");
	            	char rep[380];
	            	printf("Registrar evolución\n");
	        		printf("=========================\n");
	            	printf("Ingrese la evolución de %s ", busc.apenom);
	            	printf("\n\nEntrada: ");
	            	Turnos tmpT;
		            _flushall();
		            gets(rep);
		            rewind(turnos);
		            fread(&tmpT, sizeof(turno), 1, turnos);
			        while (!feof(turnos)){
			        	count++;
			        	fread(&tmpT, sizeof(turno), 1, turnos);
			        }
	         		Turnos vecT[count];
					int c3=0;
					rewind(turnos);
					fread(&tmpT, sizeof(turno), 1, turnos);
	          		while(!feof(turnos)){
	            		vecT[c3] = tmpT;
	            		fread(&tmpT, sizeof(turno), 1, turnos);
	            		c3++;
	          		}
					for(int i = 0; i < c3; i++){
						if(vecT[i].dni == dniA){
								strcpy(vecT[i].detalle, rep);
						}
					}
					turTemp = fopen("TurAux.dat", "w+b");
						
					for(int i = 0; i < c3; i++) {
						fwrite(&vecT[i], sizeof(turno), 1, turTemp);
					}
						
					fclose(turnos);
					if(remove("Turnos.dat") != 0){
						perror("ERROR: ");
						system("pause");
						Evol(turnos, prof, cliente, usr);
					}
					fclose(turTemp);
					if(rename("TurAux.dat", "Turnos.dat") != 0){
						perror("ERROR: ");
						system("pause");
						Evol(turnos, prof, cliente, usr);
					}
					fclose(usr);
					fclose(cliente);
					//fclose(turnos);
					fclose(prof);
          			}
					else{
			            system("cls");
						printf("ERROR: El DNI ingresado es inexistente.\n");
						printf("=========================\n");
			            system("pause");
			            err = 1;
			        }
        			}
					else{
			        	system("cls");
						printf("--> ERROR: La matricula ingresada es inexistente.\n");
						printf("=========================\n");
			        	system("pause");
			        	err = 1;
		        	}
      			}while(err == 1);
    		}
  		}
  	else{
	    system("cls");
	    system("cls");
    	printf("ERROR: usted no inicio sesión\n");
		printf("=========================\n");
    	system("pause");
  	}
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
