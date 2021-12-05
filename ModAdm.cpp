#include <stdio.h>
#include <ctype.h>
#include "libreria.h"

void rPro(FILE *prof);
void rRep(FILE *usr);
void atenciones();
void rank();
void secret(FILE *prof);

main(){
	int op;
	
	FILE *prof;
	FILE *usr;
	FILE *client;
	FILE *turnos;
	
	system("cls");
    printf("Modulo Administracion\n");
    printf("=========================\n");
    printf("1.- Registrar Profesional\n");
    printf("2.- Registrar Usuario Recepcionista\n");
    printf("3.- Atenciones por Profesional\n");
    printf("4.- Ranking de Profesionales por Atenciones\n");
    printf("5.- Cerrar la aplicacion\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &op);
	
	switch(op){
    	case 1:{
    		system("cls");
    		rPro(prof);
    		main();
			break;
		}
		case 2:{
			system("cls");
			rRep(usr);
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
		case 69:{
			system("cls");
			printf("nice");Sleep(500);
			secret(prof);
			main();
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

void secret(FILE *prof){
	prof=fopen("Profesionales.dat","ab+");
	
	int i=0;
	Profesionales pro;
	fread(&pro,sizeof(pro),1,prof);
	while(!feof(prof)){
		printf("\nDatos: \n");
		puts(pro.apenom);
		printf("%d\n", pro.idp);
		printf("%d\n", pro.dni);
		puts(pro.tel);
		fread(&pro,sizeof(pro),1,prof);
	}
	system("pause");	
}

void rPro(FILE *prof){
	prof = fopen("Profesionales.dat", "a+b");
	Profesionales pro;
	if(prof == NULL){
		printf ("No se pudo abrir el archivo\n");
	}
	else{
		printf("Registro de un nuevo profesional\n");
		printf("=========================\n");
		_flushall();
		printf("Ingrese el apellido y nombre: ");
		gets(pro.apenom);
		printf("\nIngrese la ID del profesional: ");
		scanf("%d", &pro.idp);
		printf("\nIngrese el DNI: ");
		scanf("%d", &pro.dni);
		_flushall();
		printf("\nIngrese el numero de telefono: ");
		gets(pro.tel);
		fwrite(&pro, sizeof(Profesionales), 1, prof);
	}
	fclose(prof);
	printf("\nDatos registrados exitosamente\n\n");
	system("pause");
	system("cls");
}

void rRep(FILE *usr){
	int aux = 0, aux1 = 0;
	usr = fopen("Recepcionistas.dat", "a+b");
	Usuarios user;
	if(usr == NULL){
		printf ("No se pudo abrir el archivo\n");
	}
	else{
		do{
			aux = 0;
			printf("Registro de un nuevo usuario recepcionista\n");
			printf("=========================\n");
			printf("\nEl usuario debe ser unico\nEl usuario debe  tener entre 6 y 10 caracteres\nEl usuario debe comenzar con una letra minuscula\nEl usuario debe tener al menos 2 letras mayusculas\nEl usuario puede tener maximo 3 digitos.");
			_flushall();
			printf("\nIngrese el usuario: ");
			gets(user.user);
			if(strlen(user.user) < 6 || strlen(user.user) > 10){
	        	aux = 1;
	        	system("cls");
				printf("El usuario debe  tener entre 6 y 10 caracteres\n");
				system("pause");
				system("cls");
	    	}
			else{
	        if(!islower(user.user[0])){
	        	aux = 1;
	        	system("cls");
				printf("El usuario debe comenzar con una letra minuscula\n");
				system("pause");
				system("cls");
	        } 
			else{
	        	int contM = 0, contD = 0;
	        	for(int i = 0; i < strlen(user.user); i++){
	            if(isupper(user.user[i])){
	            	contM++;
	            }
	            if(isdigit(user.user[i])){
	            	contD++;
	        	}
	        }
	        if(contM < 2){
	        	aux = 1;
	            system("cls");
				printf("El usuario debe tener al menos 2 letras mayusculas\n");
				system("pause");
				system("cls");
	            aux1 = 0;
	            contM = 0;
	            contD = 0;
	        }
			else{
	            aux1++;
	        }
	        if(contD > 3){
	        	aux = 1;
	            system("cls");
	            printf("El usuario no puede tener mas de 3 digitos\n");
	            system("pause");
	            system("cls");
	            aux1 = 0;
	            contM = 0;
	            contD = 0;
	        }
			else{
	            aux1++;
	        }
	        if(aux1 == 2){
	        	rewind(usr);
	            Usuarios user2;
	            fread(&user2, sizeof(Usuarios), 1, usr);
	            while (!feof(usr)) {
	              if(strcmp(user.user,user2.user) == 0){
	                aux = 1;
	                system("cls");
	                printf("El usuario debe ser unico\n");
	                system("pause");
	                system("cls");
	            	}
	            fread(&user2, sizeof(Usuarios), 1, usr);
	            }
	          }
	        if(aux == 0){
	        	for(int i = 0; i < strlen(user.user); i++){
	            	if(isalnum(user.user[i]) || isupper(user.user[i]) || user.user[i] == '+' || user.user[i] == '-' || user.user[i] == '/' || user.user[i] == '*' || user.user[i] == '?' || user.user[i] == '�' || user.user[i] == '!' || user.user[i] == '�'){
	            } 
				else{
	                aux = 1;
	                system("cls");
	                printf("Solo se permiten los siguientes simbolos +, -, /, *, ?, �, !, �\n");
	                system("pause");
	                system("cls");
	                break;
	            	}
	            }
	
	          }
	        }
	    }
	    }while(aux == 1);
	    
		do{
    	aux = 0;
    	system("cls");
    	printf("Registro de un nuevo usuario recepcionista\n");
		printf("=========================\n");
	    printf("La contrasenia debe tener al menos una letra mayuscula, una letra minuscula y un numero\nLa contrasenia debe tener entre 6 y 32 caracteres\nLa contrasenia solo podra tener caracteres alfanumericos\nLa contrasenia no debe tener mas de 3 caracteres numericos consecutivos\nLa contrasenia no podra tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas.");
	    printf("Ingrese una contrasenia: ");
	    _flushall();
	    gets(user.pw);
    	if(strlen(user.pw) > 32 || strlen(user.pw) < 6){
        	aux = 1;
	        system("cls");
			printf("La contrasenia debe tener entre 6 y 32 caracteres\n");
			system("pause");
			system("cls");
    	}
		else{
        int contMay = 0;
        int contMin = 0;
        int contD = 0;
        for(int i = 0; i < strlen(user.pw); i++){
        	if(isupper(user.pw[i]) && isalpha(user.pw[i])){
            	contMay++;
        	}
        	if(islower(user.pw[i]) && isalpha(user.pw[i])){
        		contMin++;
        	}
        	if(isdigit(user.pw[i])){
            	contD++;
        	}
        }
        if(contMay == 0){
        	aux = 1;
	        system("cls");
			printf("La contrasenia debe tener al menos una letra mayuscula\n");
			system("pause");
			system("cls");
        }
        if(contMin == 0){
        	aux = 1;
	        system("cls");
			printf("La contrasenia debe tener al menos una letra minuscula\n");
			system("pause");
			system("cls");
        }
        if(contD == 0){
        	aux = 1;
	        system("cls");
			printf("La contrasenia debe tener al menos un digito\n");
			system("pause");
			system("cls");
        }
      }
      	if(aux == 0){
	        int num[3];
	        int cont = 0;
	        for(int i = 0; i < strlen(user.pw); i++){
	        	if(isdigit(user.pw[i])){
	        		num[cont] = user.pw[i];
	        		cont++;
	        	}
	        }
	    	if(num[0] + 1 == num[1]){
	        	if(num[0] + 2 == num[2]){
	    			if(num[0] + 3 == num[3]){
		            	aux = 1;
				        system("cls");
						printf("La contrasenia no debe tener mas de 3 digitos consecutivos\n");
						system("pause");
						system("cls");
		            	num[3] = 0;
	            }
					else{
		              break;
		            }
	        	}
				else{
	            	break;
	        	}
	        }
			else{
	        	break;
	        }
	    	}
	    	if(aux == 0){
		    	char letra[32];
		        for(int i = 0; i < strlen(user.pw); i++){
		        	if(isalpha(letra[i])){
		            	letra[i] = user.pw[i];
		            	letra[i] = toupper(letra[i]);
		        	}
		        	if(i > 0){
		        		if (letra[i - 1] + 1 == letra[i]){//no debe ser alfabeticamente consecutiva
				            aux = 1;
				        	system("cls");
							printf("La contrasenia debe tener al menos una letra minuscula\n");
							system("pause");
							system("cls");
		              		break;
		            }
		          }
		        }
	    		for(int j = 0; j < strlen(user.pw); j++){
	        		if(ispunct(user.pw[j]) || isspace(user.pw[j])){
	            			aux = 1;
				        	system("cls");
							printf("La contrasenia no puede contener signos de puntuacion, ni espacios\n");
							system("pause");
							system("cls");
	        		}
	    		}
	    	}
    	}while(aux == 1);
	}
	system("cls");
    printf("Registro de un nuevo usuario recepcionista\n");
	printf("=========================\n");
	printf("Ingrese el apellido y nombre: ");
	_flushall();
	gets(user.apenom);
	fclose(usr);
	printf("\nDatos registrados exitosamente\n\n");
	system("pause");
	system("cls");
}