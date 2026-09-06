#include "ProductionTask.h"
#include "PlanningState.h"

ProductionTask::ProductionTask(string name, int duration, double cost) {
	
	//for state
	currentState = new PlanningState();

}

int ProductionTask::getDuration() {
	return this->duration;
}

double ProductionTask::getCost() {
	return this->cost;
}

void ProductionTask::display(int depth) {
	// TODO - implement ProductionTask::display
	throw "Not yet implemented";
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
