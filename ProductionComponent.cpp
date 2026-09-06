#include "ProductionComponent.h"
using namespace std;
// abstract class 
ProductionComponent::ProductionComponent(string name) {
    this->name = name;
}

ProductionComponent::~ProductionComponent() {
}

void ProductionComponent::add(ProductionComponent* c) {
}

void ProductionComponent::remove(ProductionComponent* c) {
}

ProductionComponent* ProductionComponent::getChild(int i) {
    return nullptr;
}

string ProductionComponent::getName() {
    return this->name;
}