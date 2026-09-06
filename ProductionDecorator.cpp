#include "ProductionDecorator.h"

ProductionDecorator::ProductionDecorator(ProductionComponent* c)
	: ProductionComponent(c->getName()), wrapped(c) {}

ProductionDecorator::~ProductionDecorator() {
	delete wrapped;
}

int ProductionDecorator::getDuration() {
	return wrapped->getDuration();
}

double ProductionDecorator::getCost() {
	return wrapped->getCost();
}

void ProductionDecorator::display(int depth) {
	wrapped->display(depth);
}

void ProductionDecorator::advance() {
	wrapped->advance();
}

string ProductionDecorator::getStatus() {
	return wrapped->getStatus();
}
