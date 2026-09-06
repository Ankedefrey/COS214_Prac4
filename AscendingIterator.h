#ifndef ASCENDINGITERATOR_H
#define ASCENDINGITERATOR_H

#include <vector>
#include "ProductionIterator.h"
using namespace std;

class AscendingIterator : public ProductionIterator {

private:
	vector<ProductionComponent*> items;
	int index;

public:
	AscendingIterator(vector<ProductionComponent*> children);

	void first();

	void next();

	bool isDone();

	ProductionComponent* currentItem();
};

#endif
