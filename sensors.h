#ifndef _SENSORS_H
#define _SENSORS_H
#include <iostream>

class Interface
{	public:
		virtual	void view()=0;
		virtual void f()=0;
};

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

class Termometr : virtual public Power, virtual public Interface
{
		float TEMP;
	public:
		void f() override;
		void view() override;
		Termometr(float T=20, float Vv=0, float Cc=0);
		virtual ~Termometr();
		void f_power();
};

//class Barometr

class Light_sensor : virtual public Power, virtual public Interface 
{
		short LIGHT_INTENSITY;
	public:
		void f() override;
		void view() override;
		Light_sensor(short L=50, float Vv=0, float Cc=0);
		virtual ~Light_sensor();
};

class Anemometr : virtual public Power, virtual public Interface
{
		float  WIND_SPEED;
	public:
		void f() override;
		void view() override;
		Anemometr(float W=5, float Vv=0, float Cc=0);
		virtual ~Anemometr();
};

class Sensor_move : virtual public Power, virtual public Interface
{
		bool MOVE;
	public:
		void f() override;
		void view() override;
		Sensor_move(bool M=false, float Vv=0, float Cc=0);
		virtual ~Sensor_move();
};

class Wetness_sensor : virtual public Power, virtual public Interface
{
		unsigned short WETNESS;
	public:
		void f() override;
		void view() override;
		Wetness_sensor(unsigned short W=20, float Vv=0, float Cc=0);
		virtual ~Wetness_sensor();
};
	
#endif
