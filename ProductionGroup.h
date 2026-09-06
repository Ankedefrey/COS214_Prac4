#ifndef PRODUCTIONGROUP_H
#define PRODUCTIONGROUP_H

#include <string>
#include <vector>
#include "ProductionComponent.h"
#include "ProductionAggregate.h"
using namespace std;

class ProductionIterator;

class ProductionGroup : public ProductionComponent, public ProductionAggregate {

private:
	vector<ProductionComponent*> children;

public:
	ProductionGroup(string name);

	virtual ~ProductionGroup();

	void add(ProductionComponent* c);

	void remove(ProductionComponent* c);

	ProductionComponent* getChild(int i);

	int getDuration();

	double getCost();

	void display(int depth);

	void advance();

	string getStatus();

	ProductionIterator* createIterator(string order);
};

#endif
