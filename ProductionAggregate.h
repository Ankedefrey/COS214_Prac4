#ifndef PRODUCTIONAGGREGATE_H
#define PRODUCTIONAGGREGATE_H

#include <string>
using namespace std;

class ProductionIterator;

class ProductionAggregate {


public:
	virtual ~ProductionAggregate();

	virtual ProductionIterator* createIterator(string order) = 0;
};

#endif
