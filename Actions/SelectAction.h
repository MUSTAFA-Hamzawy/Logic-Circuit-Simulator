#ifndef _SELECT_ACTION_H
#define _SELECT_ACTION_H

#include "action.h"
#include "../Components/Component.h"

class SelectAction : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	Component* comp;
	bool test;
public:
	SelectAction(ApplicationManager* pApp);
	virtual ~SelectAction(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif