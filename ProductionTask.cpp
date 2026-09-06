#include "ProductionTask.h"
#include <string>
#include <iostream>
using namespace std;

ProductionTask::ProductionTask(string name, int duration, double cost):ProductionComponent(name) {
	this->cost = cost;
	this->duration =duration;
	this->currentState = nullptr;
}
ProductionTask::~ProductionTask(){
	delete currentState;
}
int ProductionTask::getDuration() {
	return this->duration;
}

double ProductionTask::getCost() {
	return this->cost;
}

void ProductionTask::display(int depth) {
	cout << "Name:" << getName() << "Duration: " << this->duration << "Cost: " << this->cost << "State: " << getStatus() << endl;
}

void ProductionTask::advance() {
	// TODO - implement ProductionTask::advance
	throw "Not yet implemented";
}

string ProductionTask::getStatus() {
	// TODO - implement ProductionTask::getStatus
	throw "Not yet implemented";
}

void ProductionTask::setState(TaskState* s) {
	// TODO - implement ProductionTask::setState
	throw "Not yet implemented";
}
