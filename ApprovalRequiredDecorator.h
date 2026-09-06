#ifndef APPROVALREQUIREDDECORATOR_H
#define APPROVALREQUIREDDECORATOR_H

#include "ProductionDecorator.h"

class ApprovalRequiredDecorator : public ProductionDecorator {

private:
	bool approved;

public:
	ApprovalRequiredDecorator(ProductionComponent* c);

	void advance();

	void setApproved(bool a);
};

#endif
