#ifndef _DEVICE_H
#define _DEVICE_H
#include <iostream>
#include "sensors.h"

class Abstract
{	//public:
		virtual void view()=0;
};

class Air_conditioning : virtual public Abstract 
{
	public:
		float TEMP_AIR_COND;
		Air_conditioning(float tac=19);
		virtual ~Air_conditioning();
		void view() override;
};

class Warming_system : virtual public Abstract
{
	public:
		float TEMP_WARMING_SYS;
		Warming_system(float tws=20);
		virtual ~Warming_system();
		void view() override;
};

class Windows : virtual public Power, virtual public Abstract
{
		bool POSITION;
	public:
		Windows(bool p=0, float Vv=0, float Cc=0);
		virtual ~Windows();
		void f_d(const bool onoff);
		void view() override;
};

class Light_inside : virtual public Power, virtual public Abstract
{
	public:
		unsigned short LIGHT_INSIDE_INTENSITY;
		Light_inside(unsigned short L_IN=0, float Vv=0, float Cc=0);
		virtual ~Light_inside();
		void f_light_inside(const unsigned short LIGHT_MANUAL);
		void view() override;
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
