#ifndef PLANNINGSTATE_H
#define PLANNINGSTATE_H

#include <string>
#include "TaskState.h"
using namespace std;

class PlanningState : public TaskState {


public:
	void advance(ProductionTask* task);

	string getName();
};

#endif
