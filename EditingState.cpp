#include "EditingState.h"
#include "CompletedState.h"
#include "ProductionTask.h"

void EditingState::advance(ProductionTask* task) {
	task->setState(new CompletedState());
}

string EditingState::getName() {
	return "Editing";
}