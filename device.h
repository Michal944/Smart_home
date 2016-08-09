#ifndef _DEVICE_H
#define _DEVICE_H
#include <iostream>
#include "sensors.h"


class Air_conditioning : virtual public Power 
{
		float TEMP_AIR_COND;
	public:
		Air_conditioning(float tac=19, float Vv=0, float Cc=0);
		virtual ~Air_conditioning();
		void f_air_cond(float TEMP_MANUAL);
		void view_air_cond();
};

class Warming_system : virtual public Power
{
		float TEMP_WARMING_SYS;
	public:
		Warming_system(float tws=20, float Vv=0, float Cc=0);
		virtual ~Warming_system();
		void f_temp_warming_sys(float TEMP_MANUAL);
		void view_temp_warming_sys();
};

class Windows : virtual public Power
{
		bool POSITION;
	public:
		Windows(bool p=0, float Vv=0, float Cc=0);
		~Windows();
		void f_windows(bool WINDOWS_MANUAL=false);
		void view_windows();
};

class Light_inside : virtual public Power
{
		unsigned short LIGHT_INSIDE_INTENSITY;
	public:
		Light_inside(unsigned short L_IN=0, float Vv=0, float Cc=0);
		virtual ~Light_inside();
		void f_light_inside(unsigned short LIGHT_MANUAL);
		void view_light_inside();
};
/*
class Notifications
{
		string *TEXT_MESSAGE;
	public:
		Notifications(string tx);
		virtual ~Notifications();
		void f_notifications();
		void view_message();
};

*/


	

#endif
