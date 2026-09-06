// #ifndef PRODUCTIONCOMPONENT_H
// #define PRODUCTIONCOMPONENT_H

// #include <string>
// using namespace std;

// class ProductionComponent {

// protected:
// 	string name;

// public:
// 	ProductionComponent(string name);

// 	virtual ~ProductionComponent();

// 	virtual void add(ProductionComponent* c);

// 	virtual void remove(ProductionComponent* c);

// 	virtual ProductionComponent* getChild(int i);

// 	virtual int getDuration() = 0;

// 	virtual double getCost() = 0;

// 	virtual void display(int depth) = 0;

// 	virtual void advance() = 0;

// 	virtual string getStatus() = 0;

// 	string getName();
// };

// #endif
#ifndef PRODUCTION_COMPONENT_H
#define PRODUCTION_COMPONENT_H

#include <string>

class ProductionComponent
{
protected:
    std::string name;

public:
    explicit ProductionComponent(std::string name);
    virtual ~ProductionComponent();

    
    virtual void add(ProductionComponent* component);
    virtual void remove(ProductionComponent* component);
    virtual ProductionComponent* getChild(int index);

    virtual int getDuration() = 0;
    virtual double getCost() = 0;
    virtual void display(int depth) = 0;
    virtual void advance() = 0;
    virtual std::string getStatus() = 0;

    std::string getName();
};

#endif