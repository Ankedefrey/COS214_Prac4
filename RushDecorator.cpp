#include "RushDecorator.h"
#include "ProductionComponent.h"
#include <iostream>

RushDecorator::RushDecorator(ProductionComponent* c) : ProductionDecorator(c) {}

int RushDecorator::getDuration() {
	// Rushing cuts the schedule -- e.g. compress the wrapped duration by 30%.
	int base = wrapped->getDuration();
	int rushed = (base * 7) / 10;
	return rushed < 1 ? 1 : rushed;
}

double RushDecorator::getCost() {
	// Overtime/expediting surcharge on top of the wrapped cost.
	const double surcharge = 250.0;
	return wrapped->getCost() + surcharge;
}

void RushDecorator::display(int depth) {
	for (int i = 0; i < depth; ++i) {
		std::cout << "  ";
	}
	std::cout << "[Rush]" << std::endl;
	wrapped->display(depth + 1);
}
