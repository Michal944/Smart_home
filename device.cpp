#include <iostream>
#include "device.h"

using namespace std;


//Air_conditioning
Air_conditioning::Air_conditioning(float tac)
		: TEMP_AIR_COND(tac)
{}
Air_conditioning::~Air_conditioning(){}
/*void Air_conditioning::f_air_cond(const float TEMP_MANUAL)
{		if(TEMP_MANUAL<=30&&TEMP_MANUAL>=10)
				TEMP_AIR_COND=TEMP_MANUAL;
}
*/
void Air_conditioning::view()
{
		cout<<"Temp air conditinoing: "<<TEMP_AIR_COND<<"*C"<<endl;
}

//Warming_system
Warming_system::Warming_system(float tws)
		: TEMP_WARMING_SYS(tws)
{}
Warming_system::~Warming_system(){}
/*void Warming_system::f_temp_warming_sys(const float TEMP_MANUAL)
{	if(TEMP_MANUAL>=40&&TEMP_MANUAL<=80)
		TEMP_WARMING_SYS=TEMP_MANUAL;
};
*/
void Warming_system::view(){cout<<"Warmin system temp: "<<
	TEMP_WARMING_SYS<<"*C"<<endl;
}

//Windows
Windows::Windows(bool p, float Vv, float Cc)
		: POSITION(p)
		, Power(Vv,Cc)
{}
Windows::~Windows(){}
void Windows::f_d(const bool *onoff){POSITION=*onoff;}
void Windows::view()
{	
	if(POSITION==true)
		cout<<"Windows is: OPEN"<<endl;
	else
		cout<<"Windows is: CLOSE"<<endl;
}
//Light_inside
Light_inside::Light_inside(unsigned short L_IN, float Vv, float Cc)
		: LIGHT_INSIDE_INTENSITY(L_IN)
		, Power(Vv, Cc)
{}
Light_inside::~Light_inside(){}
void Light_inside::f_light_inside(const unsigned short LIGHT_MANUAL)
{	if(LIGHT_MANUAL<=100&&LIGHT_MANUAL>=0)
		LIGHT_INSIDE_INTENSITY=LIGHT_MANUAL;
}

void Light_inside::view()
{
		cout<<"Light intensity: "<<LIGHT_INSIDE_INTENSITY<<"%"<<endl;
}











