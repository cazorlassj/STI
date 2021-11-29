#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <iostream>
#include <chrono>
#include <time.h>
#include <unistd.h>

struct Fecha{
	int dia, mes, anio;	
};

struct Usuarios{
	char user[10];
	char pw[10];
	char apenom[60];
};

struct Profesionales{
	char apenom[60];
	int idp;
	int dni;
	char tel[25];
};

struct Cliente{
	char apenom[60];
	char dom[60];
	int dni;
	char localidad[60];
	Fecha fec;
	float peso;
	char tel[25];
};

struct Turnos{
	int idp;
	Fecha fec;
	int dni;
	char detalle[380];
};


main(){
	
	system("cls");
    printf("Modulo Espacios");
    printf("=========================\n");
    printf("1.- Iniciar sesion\n");
    printf("2.- Visualizar lista de espera de turnos (informe)\n");
    printf("3.- Registrar evolucion del tratamiento\n");
    printf("4.- Cerrar la aplicación.\n\n");
    printf("Ingrese una opción: ");
    scanf("%d", &op);

}
