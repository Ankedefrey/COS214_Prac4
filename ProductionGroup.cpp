#include "ProductionGroup.h"
#include "AscendingIterator.h"
#include "DescendingIterator.h"
#include "ProductionIterator.h"
#include <iostream>
using namespace std;

ProductionGroup::ProductionGroup(string name):ProductionComponent(name){
	
}

ProductionGroup::~ProductionGroup() {
	for (int i = 0; i < children.size(); i++){
        delete children[i];
    }
    children.clear();
}

void ProductionGroup::add(ProductionComponent* c) {
	children.push_back(c);
}

void ProductionGroup::remove(ProductionComponent* c) {
	for (int i = 0; i < children.size(); i++){
        if (children[i] == c){
            children.erase(children.begin() + i);
            return;
        }
    }
}

ProductionComponent* ProductionGroup::getChild(int i) {
	if (i >= 0 && i < children.size()){
        return children[i];
    }
    return nullptr;
}

int ProductionGroup::getDuration() {
	int duration = 0;
	for (int i=0; i<children.size(); i++){
		duration += children[i]->getDuration();
	}
	return duration;
}

double ProductionGroup::getCost() {
	int cost = 0;
	for (int i=0; i<children.size(); i++){
		cost += children[i]->getCost();
	}
	return cost;
}

void ProductionGroup::display(int depth) {
	cout << "Name: " << getName()<<" Duration: " << getDuration()<<" Cost: " << getCost() << " State: " <<getStatus()<< endl;
    for (int i=0; i<children.size(); i++){
        children[i]->display(depth + 1);
    }
}

void ProductionGroup::advance() {
	// TODO - implement ProductionGroup::advance
	throw "Not yet implemented";
}

string ProductionGroup::getStatus() {
	// TODO - implement ProductionGroup::getStatus
	throw "Not yet implemented";
}

ProductionIterator* ProductionGroup::createIterator(string order) {
	if (order == "ascending"){
        return new AscendingIterator(children);//just wait on these error im working on it
    }
    if (order == "descending"){
        return new DescendingIterator(children);//just wait on these error im working on it
    }
    return nullptr;
}
