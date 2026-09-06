#include "ProductionDecorator.h"

#include <iostream>

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
	for (int i = 0; i < depth; ++i) {
		std::cout << "  ";
	}
	std::cout << "Name: " << getName() << " Duration: " << getDuration()
	        << " Cost: " << getCost() << " State: " << getStatus() << std::endl;
	wrapped->display(depth + 1);
}

void ProductionDecorator::advance() {
	wrapped->advance();
}

string ProductionDecorator::getStatus() {
	return wrapped->getStatus();
}
