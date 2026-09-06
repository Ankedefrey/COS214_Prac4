#ifndef UNIONCREWDECORATOR_H
#define UNIONCREWDECORATOR_H

#include "ProductionDecorator.h"

class UnionCrewDecorator : public ProductionDecorator {


public:
	double getCost();

	void display(int depth);

	UnionCrewDecorator(ProductionComponent* c);
};

#endif
