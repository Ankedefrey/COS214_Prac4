#include "UnionCrewDecorator.h"
#include <iostream>

UnionCrewDecorator::UnionCrewDecorator(ProductionComponent* c) : ProductionDecorator(c) {}

double UnionCrewDecorator::getCost() {
	// Certified union crew adds a fixed surcharge on top of the wrapped cost.
	const double surcharge = 500.0;
	return component->getCost() + surcharge;
}

void UnionCrewDecorator::display(int depth) {
	for (int i = 0; i < depth; ++i) {
		std::cout << "  ";
	}
	std::cout << "[Union Crew]" << std::endl;
	component->display(depth + 1);
}
