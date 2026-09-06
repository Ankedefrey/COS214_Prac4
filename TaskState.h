#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string>
using namespace std;

class ProductionTask;

class TaskState {

public:
	virtual ~TaskState();

	virtual void advance(ProductionTask* task) = 0;

	virtual string getName() = 0;
};

#endif
