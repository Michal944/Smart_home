#include <iostream>
#include "sensors.h"
#include "device.h"
#include <unistd.h>

using namespace std;

class Control_system
{
		bool SEASON;
		char *choose_locacl;
		bool *pick;
	public:
//SENSORS
		Time 			  LOCAL_HOST_TIME;
	 	Termometr 		* TERMO_SENSOR_MODEL_XXX;
	 	Light_sensor 	* PHOTORESISTOR_MODEL_XXX;
	 	Anemometr 		* WIND_SENSOR_MODEL_XXX;
		Sensor_move		* MOVE_SENSOR_MODEL_XXX;
	 	Wetness_sensor  * WETNESS_SENSOR_MODEL_XXX;
//DEVICE
		Air_conditioning *	COOL_SYSTEM_MODEL_XXX=NULL;
		Warming_system *	CO_MODEL_XXX=NULL;
		Windows	*			ENGINES_WINDOWS;
		Light_inside *		SYSTEM_LIGHT_INSIDE;

	
//INTERFACE
		Control_system();
		virtual ~Control_system();
		void sensors_start();
		void device_start();
		void f_season();
};

Control_system::Control_system()
{
		TERMO_SENSOR_MODEL_XXX=new Termometr(20,12,0.2);
		PHOTORESISTOR_MODEL_XXX=new Light_sensor(50,12,0.4);
		WIND_SENSOR_MODEL_XXX=new Anemometr(5,12,0.3);
		MOVE_SENSOR_MODEL_XXX=new Sensor_move(false,12,0.5);
		WETNESS_SENSOR_MODEL_XXX=new Wetness_sensor(20,12,0.5);

		ENGINES_WINDOWS=new Windows;
		SYSTEM_LIGHT_INSIDE=new Light_inside;

}

Control_system::~Control_system()
{
		delete TERMO_SENSOR_MODEL_XXX;
		delete PHOTORESISTOR_MODEL_XXX;
		delete WIND_SENSOR_MODEL_XXX;
		delete MOVE_SENSOR_MODEL_XXX;
		delete WETNESS_SENSOR_MODEL_XXX;
	
	if(SEASON==false)
		delete COOL_SYSTEM_MODEL_XXX;
	else
		delete CO_MODEL_XXX;

		delete ENGINES_WINDOWS;
		delete SYSTEM_LIGHT_INSIDE;

}
void Control_system::f_season()
{		choose_locacl=new char[1];
		cout<<"Choose season:"<<endl<<"WINTER[y]/SUMMER[n]:  ";
		cin>>choose_locacl;
			if(choose_locacl[0]=='y'||choose_locacl[0]=='Y'){
				SEASON=true;
				CO_MODEL_XXX=new Warming_system;
				cout<<"Warming system is: ON"<<endl<<
				"Air_conditioning is: OFF"<<endl;
			}
			else{
				SEASON=false;
				COOL_SYSTEM_MODEL_XXX=new Air_conditioning;
				cout<<"Warming system is: OFF"<<endl<<
				"Air_conditioning is: ON"<<endl;
			}
		delete choose_locacl;
		sleep(5);
}

void Control_system::sensors_start()
{
//f() sensors_controller
		LOCAL_HOST_TIME.f_time();
		TERMO_SENSOR_MODEL_XXX->f();
		PHOTORESISTOR_MODEL_XXX->f();
		WIND_SENSOR_MODEL_XXX->f();
		MOVE_SENSOR_MODEL_XXX->f();
		WETNESS_SENSOR_MODEL_XXX->f();
//view() sensors_display
		LOCAL_HOST_TIME.view_time_start();
		TERMO_SENSOR_MODEL_XXX->view();
		PHOTORESISTOR_MODEL_XXX->view();
		WIND_SENSOR_MODEL_XXX->view();
		MOVE_SENSOR_MODEL_XXX->view();
		WETNESS_SENSOR_MODEL_XXX->view();
}

void Control_system::device_start()
{
	pick=new bool;
		if(TERMO_SENSOR_MODEL_XXX->TEMP>25&&
		WETNESS_SENSOR_MODEL_XXX->WETNESS<65)
			*pick=true;
		else *pick=false;
	ENGINES_WINDOWS->f_d(pick);
	
	(PHOTORESISTOR_MODEL_XXX->light_out_ret()>80)?
	SYSTEM_LIGHT_INSIDE->LIGHT_INSIDE_INTENSITY=70: 
	SYSTEM_LIGHT_INSIDE->LIGHT_INSIDE_INTENSITY=40;
	
	ENGINES_WINDOWS->view();
	SYSTEM_LIGHT_INSIDE->view();
	
	if(SEASON==false)
		{
			TERMO_SENSOR_MODEL_XXX->TEMP>28? 
			COOL_SYSTEM_MODEL_XXX->TEMP_AIR_COND=19.5:
			COOL_SYSTEM_MODEL_XXX->TEMP_AIR_COND=22.5;
			COOL_SYSTEM_MODEL_XXX->view();
		}
	else 
		{
			TERMO_SENSOR_MODEL_XXX->TEMP<5?
			CO_MODEL_XXX->TEMP_WARMING_SYS=25:
			CO_MODEL_XXX->TEMP_WARMING_SYS=21;
			CO_MODEL_XXX->view();
		}	
}



int main()
{
		Control_system SYSTEM;
		SYSTEM.f_season();
		while(true)
		{
			SYSTEM.sensors_start();
			SYSTEM.device_start();
			sleep(1);
		}

		return 0;
}








