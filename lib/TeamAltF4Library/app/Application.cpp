#include "Application.h"

Application::Application() : sensorManager(this), sensorList(this), 
	outputManager(this), outputList(this), errorMessages(this), drivingControl(this),
	rotationControl(this), serialComm(this), geometry(this), loops(this),
	irSensorReader(this), menuManager(this), calibration(this) {} 

SensorList& Application::getSensorList() {
	return sensorList;
}

SensorManager& Application::getSensorManager() {
	return sensorManager;
}

OutputList& Application::getOutputList() {
	return outputList;
}

OutputManager& Application::getOutputManager() {
	return outputManager;
}

Config& Application::getConfig() {
	return config;
}

ErrorMessages& Application::getErrorMessage() {
	return errorMessages;
}

DrivingControl& Application::getDrivingControl() {
	return drivingControl;
}

RotationControl& Application::getRotationControl() {
	return rotationControl;
}

SerialValuePool &Application::getSerialValuePool() {
	return serialValuePool;
}

SerialComm &Application::getSerialComm()
{
	return serialComm;
}

Geometry& Application::getGeometry() {
	return geometry;
	
}

Loops& Application::getLoops() {
	return loops;
}

IrSensorReader& Application::getIrSensorReader() {
	return irSensorReader;
}

MenuManager& Application::getMenuManager() {
	return menuManager;
}

Calibration& Application::getCalibration() {
	return calibration;
}

