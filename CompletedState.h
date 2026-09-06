#ifndef COMPLETEDSTATE_H
#define COMPLETEDSTATE_H

#include <string>
#include "TaskState.h"
using namespace std;

class CompletedState : public TaskState {


public:
	void advance(ProductionTask* task);

	string getName();
};

#endif
