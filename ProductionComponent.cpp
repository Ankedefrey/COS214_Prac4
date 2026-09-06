#include "ProductionComponent.h"
using namespace std;
// abstract class
ProductionComponent::ProductionComponent(string name) {
    this->name = name;
}

ProductionComponent::~ProductionComponent() {
}

void ProductionComponent::add(ProductionComponent*) {
}

void ProductionComponent::remove(ProductionComponent*) {
}

ProductionComponent* ProductionComponent::getChild(int) {
    return nullptr;
}

string ProductionComponent::getName() {
    return this->name;
}