// #ifndef PRODUCTIONITERATOR_H
// #define PRODUCTIONITERATOR_H

// class ProductionComponent;

// class ProductionIterator {


// public:
// 	virtual void first() = 0;

// 	virtual void next() = 0;

// 	virtual bool isDone() = 0;

// 	virtual ProductionComponent* currentItem() = 0;

// 	virtual ~ProductionIterator();
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