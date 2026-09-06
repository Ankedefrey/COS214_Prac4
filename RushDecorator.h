#ifndef RUSHDECORATOR_H
#define RUSHDECORATOR_H

#include "ProductionDecorator.h"

class RushDecorator : public ProductionDecorator {


public:
	int getDuration();

	double getCost();

	void display(int depth);

	RushDecorator(ProductionComponent* c);
};

#endif
