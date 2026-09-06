#ifndef EDITINGSTATE_H
#define EDITINGSTATE_H

#include <string>
#include "TaskState.h"
using namespace std;

class EditingState : public TaskState {


public:
	void advance(ProductionTask* task);

	string getName();
};

#endif
