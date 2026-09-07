#include "ProductionComponent.h"
#include "ProductionGroup.h"
#include "ProductionTask.h"
#include "RushDecorator.h"
#include "UnionCrewDecorator.h"
#include "ApprovalRequiredDecorator.h"
#include "ProductionIterator.h"

#include <iostream>

using namespace std;

int main(){

    cout << "==TaskForge: A day on set of 12 Angry Dining Philosophers==\n"<<endl;

    // BUILDING THE HIERARCHY (COMPOSITE)
    // movie->preProd->scriptDev->script is 3 levels of nesting below main
        //with both nested groups (preProd and scriptDev) and individual leaves (script)
    ProductionGroup* movie = new ProductionGroup("12 Angry Dining Philosophers");
    ProductionGroup* preProd = new ProductionGroup("Pre-Production");
    ProductionGroup* scriptDev = new ProductionGroup("Script Development");
    ProductionGroup* shooting = new ProductionGroup("Production");
    ProductionGroup* post = new ProductionGroup("Post-Production");

    //write script - 10 hours - R5000
    ProductionTask* script = new ProductionTask("Write Script", 10, 5000);
    //shoot scene12 - 3 hours - R15000
    ProductionTask* scene12 = new ProductionTask("Shoot Scene 12", 3, 15000);
    //edit the trailer - 5 hours - R6000
    ProductionTask* edit = new ProductionTask("Edit Trailer", 5, 6000);

    scriptDev->add(script);
    preProd->add(scriptDev);
    shooting->add(scene12);
    post->add(edit);
    
    movie->add(preProd);
    movie->add(shooting);
    movie->add(post);

    cout<<"Morning call sheet (full hierarchy): "<<endl;
    movie->display(0);
    cout<<endl;

    // Lifecycle (state diagram)
    cout<<"==Scenario 1: Script development & a rush order on Scene 12=="<<endl;
    cout<<"Script status: "<<script->getStatus()<<endl;

    script->advance();//planning -> shooting
    script->advance();//shooting -> editing
    script->advance();//editing -> completed

    cout<<"Script is now: "<<script->getStatus()<<endl;

    cout<<endl;

    //Last-minute change: scene 12 becomes rushe + union + approval required
    cout << "\n==Producer: \"Scene 12 is now a rush job with union crew. Needs approval.\"==\n";
    ProductionComponent* decorated = new RushDecorator(scene12);
    decorated = new UnionCrewDecorator(decorated);
    ApprovalRequiredDecorator* gated = new ApprovalRequiredDecorator(decorated);

    //decorated object participates in normal system behaviour
    cout<<"Decorated Scene 12 cost: R"<<gated->getCost()<<endl;
    cout<<"Trying to advance before approval...\n"<<endl;
    gated->advance(); //Expect blocked output string
    gated->setApproved(true);
    cout<<"Approval granted. Advancing...\n";
    gated->advance(); //expect advancement - now allowed

    //structural change: replace the original task with the decorated version
    shooting->remove(scene12);
    shooting->add(gated);
    cout<<"\nUpdated Production unit after the change:\n";
    shooting->display(0);
    cout<<endl;
    
    //two independant traversals + snapshot policy
    cout<<"==Two independant traversals over Production=="<<endl;
    ProductionIterator* ascIt = shooting->createIterator("ascending");
    ProductionIterator* descIt = shooting->createIterator("descending");
    ascIt->first();
    descIt->first();

    //Runtime structural change while both iterators are already open
    ProductionTask* reshoot = new ProductionTask("Reshoot Scene 3", 2, 8000);
    shooting->add(reshoot);

    cout<<"Ascending (before the add): "<<endl;
    for(; !ascIt->isDone(); ascIt->next()){
        cout<<"  "<<ascIt->currentItem()->getName()<<endl;
    } //should NOT include "Reshoot Scene 3"

    cout<<"Descending (before the add): "<<endl;
    for(; !descIt->isDone(); descIt->next()){
        cout<<"  "<<descIt->currentItem()->getName()<<endl;
    } //should NOT include "Reshoot Scene 3"

    ProductionIterator* freshIt = shooting->createIterator("ascending");
	cout << "Fresh iterator, created after the add:" << endl;
	for (freshIt->first(); !freshIt->isDone(); freshIt->next()) {
		cout << "  " << freshIt->currentItem()->getName() << endl;
	} //should include "Reshoot Scene 3"

    delete ascIt;
    delete descIt;
    delete freshIt;

    cout<<"==Final structure=="<<endl;
    movie->display(0);

    delete movie;
    return 0;

}