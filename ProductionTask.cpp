#include "ProductionTask.h"
#include "PlanningState.h"
#include <string>
#include <iostream>


ProductionTask::ProductionTask(string name, int duration, double cost) : ProductionComponent(name){
	this->cost = cost;
	this->duration = duration;
	this->currentState = new PlanningState();
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
	for (int i = 0; i < depth; i++) {
		cout << "  ";
	}
	cout << "Name: " << getName() << " Duration: " << getDuration() << " Cost: " << getCost() << " State: " << getStatus() << endl;
}

void ProductionTask::advance() {
	currentState->advance(this);
}

string ProductionTask::getStatus() {
	return currentState->getName();
}

void ProductionTask::setState(TaskState* s) {
	//free old state before overwriting the ptr
	delete currentState;
	currentState = s;
}
