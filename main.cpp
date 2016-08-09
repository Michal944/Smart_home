#include <iostream>
#include "sensors.h"
#include "device.h"

using namespace std;

class Control_system
{
	public:
//DEVICE_SENSORS
		Time 			  LOCAL_HOST_TIME;
	 	Termometr 		* TERMO_SENSOR_MODEL_XXX;
	 	Light_sensor 	* PHOTORESISTOR_MODEL_XXX;
	 	Anemometr 		* WIND_SENSOR_MODEL_XXX;
		Sensor_move		* MOVE_SENSOR_MODEL_XXX;
	 	Wetness_sensor  * WETNESS_SENSOR_MODEL_XXX;
//INTERFACE
		Control_system();
		virtual ~Control_system();
		void on_off();	
};

Control_system::Control_system()
{
		TERMO_SENSOR_MODEL_XXX=new Termometr(20,12,0.2);
		PHOTORESISTOR_MODEL_XXX=new Light_sensor(50,12,0.4);
		WIND_SENSOR_MODEL_XXX=new Anemometr(50,12,0.3);
		MOVE_SENSOR_MODEL_XXX=new Sensor_move(false,12,0.5);
		WETNESS_SENSOR_MODEL_XXX=new Wetness_sensor(20,12,0.5);
}

Control_system::~Control_system()
{
		delete TERMO_SENSOR_MODEL_XXX;
		delete PHOTORESISTOR_MODEL_XXX;
		delete WIND_SENSOR_MODEL_XXX;
		delete MOVE_SENSOR_MODEL_XXX;
		delete WETNESS_SENSOR_MODEL_XXX;
}

void Control_system::on_off()
{	while(true)
	{
		LOCAL_HOST_TIME.f_time();
		LOCAL_HOST_TIME.view_time_start();
	}
}

//typedef *TERMO_SENSOR_MODEL_XXX 	TEMP_S;
//typedef *PHOTORESISTOR_MODEL_XXX 	LIGHT_S




int main()
{
		Control_system SYSTEM;
		SYSTEM.on_off();

		return 0;
}

