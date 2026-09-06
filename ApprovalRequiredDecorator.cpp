#include "ApprovalRequiredDecorator.h"
#include <iostream>

ApprovalRequiredDecorator::ApprovalRequiredDecorator(ProductionComponent* c)
	: ProductionDecorator(c), approved(false) {}

void ApprovalRequiredDecorator::advance() {
	if (!approved) {
		std::cout << "Blocked: approval required before this task can advance." << std::endl;
		return;
	}
	component->advance();
}

void ApprovalRequiredDecorator::setApproved(bool a) {
	this->approved = a;
}
