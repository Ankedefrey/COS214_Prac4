// #ifndef PRODUCTIONTASK_H
// #define PRODUCTIONTASK_H

// #include <string>
// #include "ProductionComponent.h"
// using namespace std;

// class TaskState;

// class ProductionTask : public ProductionComponent {

// private:
// 	int duration;
// 	double cost;
// 	TaskState* currentState;

// public:
// 	ProductionTask(string name, int duration, double cost);

// 	virtual ~ProductionTask();

// 	int getDuration();

// 	double getCost();

// 	void display(int depth);

// 	void advance();

// 	string getStatus();

// 	void setState(TaskState* s);
// };

// #endif
#ifndef PRODUCTIONTASK_H
#define PRODUCTIONTASK_H

#include "ProductionComponent.h"
#include <string>

class TaskState;

class ProductionTask : public ProductionComponent
{
private:
    int duration;
    double cost;
    TaskState* currentState;

public:
    ProductionTask(std::string name, int duration, double cost);
    virtual ~ProductionTask();

    double getCost();
    int getDuration();

    void display(int depth);
    void advance();

    std::string getStatus();
    void setState(TaskState* state);
};

#endif
