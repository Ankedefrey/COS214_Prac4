#include "ShootingState.h"
#include "EditingState.h"
#include "ProductionTask.h"

void ShootingState::advance(ProductionTask* task) {
	task->setState(new EditingState());
}

string ShootingState::getName() {
	return "Shooting";
}
