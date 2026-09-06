#include "PlanningState.h"
#include "ShootingState.h"
#include "ProductionTask.h"

void PlanningState::advance(ProductionTask* task) {
	task->setState(new ShootingState());
}

string PlanningState::getName() {
	return "Planning";
}
