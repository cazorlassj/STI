#ifndef _LIBRERIA
#define _LIBRERIA
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
	int rank;
	Usuarios User;
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

void chau();
void musica();
void text();
#include "libreria.cpp"
#endif