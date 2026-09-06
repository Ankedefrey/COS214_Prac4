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
	double cost = 0;
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
}

string ProductionGroup::getStatus() {
	int completed = 0;
    int total = 0;

    for(int i = 0; i < (int)children.size(); i++){
        string childStatus = children[i]->getStatus();
        size_t slashPos = childStatus.find('/');

        if(slashPos != string::npos){
            int childCompleted = stoi(childStatus.substr(0, slashPos));

            size_t spacePos = childStatus.find(' ', slashPos);

			int childTotal = stoi(childStatus.substr(slashPos + 1, spacePos - slashPos - 1));

			completed += childCompleted;
			total += childTotal;
        }else{
            //child is a leaf task, status = state name
            total += 1;
            if(childStatus == "Completed"){
                completed += 1;
            }
        }
    }
    return to_string(completed) + "/" + to_string(total) + " tasks completed";
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
