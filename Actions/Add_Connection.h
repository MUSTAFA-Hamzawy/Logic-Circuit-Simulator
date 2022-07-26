#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H

#include "action.h"
#include "../Components/Connection.h"
#include "../Components/Component.h"
#include "../Components/Gate.h"

class Add_Connection : public Action
{

private:
	//Parameters for rectangular area to be occupied by the gate
	//int Cx, Cy;	//Center point of the gate
	Component* srcComp;
	Component* dstComp;
	OutputPin* src;
	InputPin* dst;
	int x1, y1, x2, y2;	//Two corners of the start and end of wire
	bool test;           // to validate that ReadActionParameters has no problem
public:
	Add_Connection(ApplicationManager* pAppMan, ActionType actType, Data* pLoadedData = NULL);
	virtual ~Add_Connection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif