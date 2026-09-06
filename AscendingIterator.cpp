#include "AscendingIterator.h"

AscendingIterator::AscendingIterator(vector<ProductionComponent*> children) {
	this->items = children;
	this->index = 0;
}

void AscendingIterator::first() {
	this->index = 0;
}

void AscendingIterator::next() {
	if(!isDone()){
		index++;
	}
}

bool AscendingIterator::isDone() {
	if (index >= (int)items.size()){
		return true;
	}else{
		return false;
	}
}

ProductionComponent* AscendingIterator::currentItem() {
	if (!isDone()){
        return items[index];
    }
    return nullptr;
}
