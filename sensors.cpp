#include <iostream>
#include "sensors.h"
#include <cassert>
#include <exception>
#include <cstdlib>
#include <ctime>

using namespace std;

//Time
int Time::TIME_START=time(NULL);
unsigned long int Time::TIME=0;
void f_time()
{
		TIME=time(NULL)-TIME_START;
}
void view_time_start()
{
		cout<<"Time from start: "<<TIME<<endl;
}

//POWER
void Power::f_power()=0;
Power::Power(float V, float C)
		: VOLATAGE(V)
		, CURRENT(C)
		{}
void Power::view_power()
{
		cout<<"VOLATAGE: "<<VOLATAGE<<"V"<<endl;
		cout<<"CURRENT:  "<<CURRENT<<"A"<<endl;
}

//Termometr
srand(time(NULL));
Termometr::Termometr(float T, float Vv, float Cc) 
			: TEMP(T)	
		 	, Power(Vv, Cc)
			{}

void Termometr::f_temp()
{
		TEMP=(rand()%10)+20;
}
void Termometr::view_temp()
{
		cout<<"TEMP: "<<TEMP<<" *C"<<endl;
}

//Light_sensor 
Light_sensor::Light_sensor(short L, float Vv, float Cc) 
			: LIGHT_INTENSITY(L)
			, Power(Vv,Cc)
{}
void Light_sensor::f_light_intensity()
{		if(Time::TIME%300==0)
			LIGHT_INTENSITY+=1;
		if(LIGHT_INTENSITY==100)
			LIGHT_INTENSITY=40;
}
void Light_sensor::view_light()
{
		cout<<"LIGHT: "<<LIGHT_INTENSITY<<endl;
}

//Anemometr
Anemometr::Anemometr(float W, float Vv, float Cc)
		:	WIND_SPEED(W)
		,	Power(Vv,Cc)
{}
void Anemometr::f_wind_speed()
{
	if(TIME%5==0)
		WIND_SPEED+=0.9;
	else
		WIND_SPEED-=0.2;
}

void Anemometr::view_wind()
{
		cout<<"Wind speed: "<<WIND_SPEED<<" m/s"<<endl;
}

//Sensor_move
Sensor_move::Sensor_move(bool M, float Vv, float Cc)
		:	MOVE(M)
		,	Power(Vv,Cc)
{}

void Sensor_move::f_move()
{
	if(TIME%1200==0)
		MOVE=true;
	else
		MOVE=false;
}
void Sensor_move::view_move()
{	
	if(MOVE==true)
		cout<<"Wykryto ruch!"<<endl;
}


