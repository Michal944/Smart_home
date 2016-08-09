#include <iostream>
#include "device.h"

using namespace std;

//Air_conditioning
Air_conditioning::Air_conditioning(float tac, float Vv, float Cc)
		: TEMP_AIR_COND(tac)
		, Power(Vv,Cc)
{}
Air_conditioning::~Air_conditioning(){}
void Air_conditioning::f_air_cond(float TEMP_MANUAL)
{		if(TEMP_MANUAL<=30&&TEMP_MANUAL>=10)
				TEMP_AIR_COND=TEMP_MANUAL;
}
void Air_conditioning::view_air_cond()
{
		cout<<"Temp air conditinoing: "<<TEMP_AIR_COND<<"*C"<<endl;
}

//Warming_system
Warming_system::Warming_system(float tws, float Vv, float Cc)
		: TEMP_WARMING_SYS(tws)
		, Power(Vv,Cc)
{}
Warming_system::~Warming_system(){}
void Warming_system::f_temp_warming_sys(float TEMP_MANUAL)
{	if(TEMP_MANUAL>=40&&TEMP_MANUAL<=80)
		TEMP_WARMING_SYS=TEMP_MANUAL;
};

//Windows
Windows::Windows(bool p, float Vv, float Cc)
		: POSITION(p)
		, Power(Vv,Cc)
{}
Windows::~Windows(){}
void Windows::f_windows(bool WINDOWS_MANUAL)
{	
		POSITION=WINDOWS_MANUAL;
}
void Windows::view_windows()
{	
	if(POSITION==true)
		cout<<"Windows is: OPEN"<<endl;
	else
		cout<<"Windows is: CLOSE"<<endl;
}
Light_inside::Light_inside(unsigned short L_IN, float Vv, float Cc)
		: LIGHT_INSIDE_INTENSITY(L_IN)
		, Power(Vv, Cc)
{}
Light_inside::~Light_inside(){}
void Light_inside::f_light_inside(unsigned short LIGHT_MANUAL)
{	if(LIGHT_MANUAL<=100&&LIGHT_MANUAL>=0)
		LIGHT_INSIDE_INTENSITY=LIGHT_MANUAL;
}

void Light_inside::view_light_inside()
{
		cout<<"Light intensity: "<<LIGHT_INSIDE_INTENSITY<<"%"<<endl;
}











