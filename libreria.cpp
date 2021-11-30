#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "libreria.h"
#include <thread>

void text(){
	int dou = 261, re = 294, mi = 330, fa = 349, sol = 392, la = 440, si = 494, time = 370, x = 80;
	printf("Gracias por usar el programa!");
	Sleep(300);
	system("cls");
	printf("o");
	Sleep(x);
	system("cls");
	printf("do");
	Sleep(x);
	system("cls");
	printf("edo");
	Sleep(x);
	system("cls");
	printf("bedo");Sleep(x);
	system("cls");
	printf("obedo");Sleep(x);
	system("cls");
	printf("cobedo");Sleep(x);
	system("cls");
	printf("scobedo");Sleep(x);
	system("cls");
	printf("Escobedo");Sleep(x);
	system("cls");
	printf(" Escobedo");Sleep(x);
	system("cls");
	printf("n Escobedo");Sleep(x);
	system("cls");
	printf("on Escobedo");Sleep(x);
	system("cls");
	printf("con Escobedo");Sleep(x);
	system("cls");
	printf("acon Escobedo");Sleep(x);
	system("cls");
	printf("hacon Escobedo");Sleep(x);
	system("cls");
	printf("Chacon Escobedo");Sleep(x);
	system("cls");
	printf(" Chacon Escobedo");Sleep(x);
	system("cls");
	printf("o Chacon Escobedo");Sleep(x);
	system("cls");
	printf("ro Chacon Escobedo");Sleep(x);
	system("cls");
	printf("tro Chacon Escobedo");Sleep(x);
	system("cls");
	printf("stro Chacon Escobedo");Sleep(x);
	system("cls");
	printf("astro Chacon Escobedo");Sleep(x);
	system("cls");
	printf("Castro Chacon Escobedo");Sleep(x);
	system("cls");
	printf(" Castro Chacon Escobedo");Sleep(x);
	system("cls");
	printf("a Castro Chacon Escobedo");Sleep(x);
	system("cls");
	printf("la Castro Chacon Escobedo");Sleep(x);
	system("cls");
	printf("rla Castro Chacon Escobedo");Sleep(x);
	system("cls");
	printf("orla Castro Chacon Escobedo");Sleep(x);
	system("cls");
	printf("zorla Castro Chacon Escobedo");Sleep(x);
    system("cls");
	printf("azorla Castro Chacon Escobedo");Sleep(x);
	for(int i = 0; i < 24; i++){
		system("cls");
		printf("\033[1;31m");
		printf("Cazorla Castro Chacon Escobedo");Sleep(100);
		system("cls");
		printf("\033[0;34m");
		printf("Cazorla Castro Chacon Escobedo");Sleep(100);
		system("cls");
		printf("\033[0;35m");
		printf("Cazorla Castro Chacon Escobedo");Sleep(100);
	}
}

void musica(){
	int dou = 261, re = 294, mi = 330, fa = 349, sol = 392, la = 440, si = 494, time = 400, x = 80, y = 200;
	//mi fa mi re mi do 
	Beep(mi, time);
	Beep(fa, time);
	Beep(mi, time);
	Beep(re, time);
	Beep(mi, time);
	Beep(re, time);
	Beep(dou, time);
	//do si la do si si re do do
	Beep(dou, time);
	Beep(si, time);
	Beep(la, time);
	Beep(dou, time);
	Beep(si, time);
	Beep(si, time);
	Beep(re, time);
	Beep(dou, time);
	Beep(dou, time);
	//mi fa sol la sol fa re do do
	Beep(mi, time);
	Beep(fa, time); 
	Beep(sol, time); 
	Beep(la, time); 
	Beep(sol, time); 
	Beep(fa, time); 
	Beep(re, time); 
	Beep(dou, time); 
	Beep(dou, time); 
	//do si la do si si re do do
	Beep(dou, time); 
	Beep(si, time); 
	Beep(la, time); 
	Beep(dou, time); 
	Beep(si, time); 
	Beep(si, time); 
	Beep(re, time);
	Beep(dou, time);
	Beep(dou, time);
}

void chau(){
	using namespace std;
	std::thread x(musica);
  	std::thread y(text);
  	x.join();
  	y.join();
  	exit(1);
}