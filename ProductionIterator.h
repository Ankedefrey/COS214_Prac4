#ifndef PRODUCTIONITERATOR_H
#define PRODUCTIONITERATOR_H

class ProductionComponent;

class ProductionIterator {


public:
	virtual void first() = 0;

	virtual void next() = 0;

	virtual bool isDone() = 0;

	virtual ProductionComponent* currentItem() = 0;

	virtual ~ProductionIterator();
};

#endif
