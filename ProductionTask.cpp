#include "ProductionTask.h"
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
	cout << "Name:" << getName() << "Duration: " << this->duration << "Cost: " << this->cost << "State: " << getStatus() << endl;
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
