#ifndef SHOOTINGSTATE_H
#define SHOOTINGSTATE_H

#include <string>
#include "TaskState.h"
using namespace std;

class ShootingState : public TaskState {


public:
	void advance(ProductionTask* task);

	string getName();
};

#endif
