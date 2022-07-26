#ifndef _ACTIONLABEL_H
#define _ACTIONLABEL_H

#include "action.h"
#include "../Components/Component.h"
class ActionLabel : public Action
{

private:
	int Cx, Cy;	//Two corners of the start and end of wire
	bool test;           // to validate that ReadActionParameters has no problem
	Component* comp;
public:
	ActionLabel(ApplicationManager* pApp);
	virtual ~ActionLabel(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif