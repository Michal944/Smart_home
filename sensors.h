#ifndef _SENSORS_H
#define _SENSORS_H


class Power
{
	public:
		float VOLATAGE;
		float CURRENT;
		virtual void view_power();
		Power(float V, float C);
		virtual ~Power();		
};

class Termometr : virtual public Power 
{
		float TEMP;
	public:
		void f_temp();
		void view_temp();
		Termometr(float T);
		virtual ~Termometr();
};

//class Barometr

class Light_sensor : virtual public Power 
{
		short LIGHT_INTENSITY;
	public:
		void f_light_intensity();
		void view_light();
		Light_sensor(short L);
		virtual ~Light_sensor();
};

class Anemometr : virtual public Power
{
		float  WIND_SPEED;
	public:
		void f_wind_speed();
		void view_wind();
		Anemometr(float W);
		virtual ~Anemometr();
};

class Sensor_move : virtual public Power
{
		bool MOVE;
	public:
		void f_move();
		void view_move();
		Sensor_move(bool M);
		virtual ~Sensor_move();
};







#endif
