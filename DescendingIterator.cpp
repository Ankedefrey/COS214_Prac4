#include "DescendingIterator.h"

DescendingIterator::DescendingIterator(vector<ProductionComponent*> children){
    items = children;
    index = items.size() - 1;
}
void DescendingIterator::first() {
	index = items.size() - 1;
}

void DescendingIterator::next() {
	if (!isDone()){
        index--;
    }
}

bool DescendingIterator::isDone() {
	return index < 0;
}

ProductionComponent* DescendingIterator::currentItem() {
	if (!isDone()){
        return items[index];
    }
    return nullptr;
}

