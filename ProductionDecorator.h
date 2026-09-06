#ifndef PRODUCTIONDECORATOR_H
#define PRODUCTIONDECORATOR_H

#include <string>
#include "ProductionComponent.h"
using namespace std;

class ProductionDecorator : public ProductionComponent {

protected:
	ProductionComponent* wrapped;

public:
	ProductionDecorator(ProductionComponent* c);

	virtual ~ProductionDecorator();

	int getDuration();

	double getCost();

	void display(int depth);

	void advance();

	string getStatus();
};

#endif
