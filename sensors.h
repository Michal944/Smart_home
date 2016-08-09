#ifndef _SENSORS_H
#define _SENSORS_H
#include <iostream>

class Time
{ 		static int TIME_START;
	public:
		static unsigned long int TIME;
		static void f_time();
		void view_time_start();
};
class Power
{
	public:
		float VOLATAGE;
		float CURRENT;
		void view_power();
	//	virtual void f_power();
		Power(float V=0, float C=0);
		virtual ~Power();		
};

class Termometr : virtual public Power 
{
		float TEMP;
	public:
		void f_temp();
		void view_temp();
		Termometr(float T=20, float Vv=0, float Cc=0);
		virtual ~Termometr();
		void f_power();
};

//class Barometr

class Light_sensor : virtual public Power 
{
		short LIGHT_INTENSITY;
	public:
		void f_light_intensity();
		void view_light();
		Light_sensor(short L=50, float Vv=0, float Cc=0);
		virtual ~Light_sensor();
};

class Anemometr : virtual public Power
{
		float  WIND_SPEED;
	public:
		void f_wind_speed();
		void view_wind();
		Anemometr(float W=5, float Vv=0, float Cc=0);
		virtual ~Anemometr();
};

class Sensor_move : virtual public Power
{
		bool MOVE;
	public:
		void f_move();
		void view_move();
		Sensor_move(bool M=false, float Vv=0, float Cc=0);
		virtual ~Sensor_move();
};

class Wetness_sensor : virtual public Power
{
		unsigned short WETNESS;
	public:
		void f_wetness();
		void view_wetness();
		Wetness_sensor(unsigned short W=20, float Vv=0, float Cc=0);
		virtual ~Wetness_sensor();
};
	
#endif
