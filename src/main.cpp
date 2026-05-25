#include <Arduino.h>
#include "app/Application.h"    
#include "Config/Config.h"
#include "MovingAverage/MovingAverage.h"




Application* app;

ButtonCross* buttonC;
Ssd1306* display;

Motor* motor;






void startSerialConnection(bool fastBaudRate, bool waitForConnection) {
	if(fastBaudRate) {
		Serial.begin(115200);
	} else {
		Serial.begin(9600);
	}
	if(waitForConnection){
		#if defined(USBCON) || defined(TEENSYDUINO)
		while (!Serial);
		#endif
	}
	delay(2000);
	Serial.println("Connection established");
}

void modeOne() {
	buttonC->update();
	display->print(buttonC->rawData(),0,buttonC->getPressedBtn());
}

float speed = 10;

void modeTwo() {
	display->print("MotorTest","Speed: " + String(speed/10,1) , "<--    -->");

	buttonC->update();
	if (buttonC->pressed(1)) {
		motor->turnOn(speed / 10);
	}
	else if (buttonC->pressed(3)) {
		motor->turnOn(-(speed / 10));
	}
	else if (buttonC->pressed(2)) {
		while(buttonC->pressed(2)) {
			buttonC->update();
		}
		delay(50);
		while(!(buttonC->pressed(2))) {
			buttonC->update();
			display->print("setSpeed", "","Speed: " + String(speed/10,1));

			if (buttonC->pressed(1)) {
				while(buttonC->pressed(1)) {
					buttonC->update();
				}
				if (speed != 0) {
					speed--;
				}
				
			}
			else if (buttonC->pressed(3)) {
				while(buttonC->pressed(3)) {
					buttonC->update();
				}
				if (speed != 10) {
					speed++;
				}
			}

		}
		while(buttonC->pressed(2)) {
			buttonC->update();
		}

		
	}
	else {
		motor->turnOff();
	}
}


void setup() {

	

	

	
	// startSerialConnection(false,false);

	
	app = new Application(); // JETZT erst initialisieren
    Serial.println("App erstellt");
	

	buttonC = app->getSensorManager().getButtonCrossByName(Config::BUTTON_CROSS_NAME);
	display = app->getOutputManager().getSsd1306ByName(Config::DISPLAY_NAME);
	motor = app->getOutputManager().getMotorByName(Config::MOTOR_BA_NAME);
	
	
	app->getMenuManager().addMenuItem("testButtonC", modeOne);
	app->getMenuManager().addMenuItem("Test Motor", modeTwo);


}



float i = 0;
void loop() {	 
	app->getMenuManager().loop();

}

