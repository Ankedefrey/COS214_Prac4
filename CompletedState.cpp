#include "CompletedState.h"
#include "ProductionTask.h"

#include <iostream>

void CompletedState::advance(ProductionTask* task) {
	std::cout<<task->getName()<<" is already completed."<<std::endl;
}

string CompletedState::getName() {
	return "Completed";
}
