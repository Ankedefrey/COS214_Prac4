#ifndef DESCENDINGITERATOR_H
#define DESCENDINGITERATOR_H

#include <vector>
#include "ProductionIterator.h"
using namespace std;

class DescendingIterator : public ProductionIterator {

private:
	int index;
	vector<ProductionComponent*> items;

public:
	void first();

	void next();

	bool isDone();

	ProductionComponent* currentItem();

	DescendingIterator(vector<ProductionComponent*> children);
};

#endif
