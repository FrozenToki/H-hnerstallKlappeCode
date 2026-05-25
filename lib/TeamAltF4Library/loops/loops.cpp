#include "loops.h"
#include "app/Application.h"


Loops::Loops (Application* a) : app(a) {
	
}

void Loops::readDistance() {
	if (millis() - time >= 10)
	{
		time = millis();

		switch (status)
		{
		case 0:
			distRight->update();
			status = 1;
			break;
		
		case 1:
			ezVL->update();
			status = 2;
			break;
		case 2:
			distBack->update();
			status = 3;
			break;
		case 3:
			ezV->update();
			status = 4;
			break;
		case 4:
			distLeft->update();
			status = 5;
			break;
		case 5:
			ezVR->update();
			status = 0;
			break;
		
		default:
			break;
		}
		//if (status == 0)
		//{
		//	distRight->update();
		//	ezVL->update();
		//	status = 1;
		//}
		//else if (status == 1) {
		//	distBack->update();
		//	ezV->update();
		//	status = 2;
		//}
		//else {
		//	distLeft->update();
		//	ezVR->update();
		//	status = 0;
		//}
	}
	
}
