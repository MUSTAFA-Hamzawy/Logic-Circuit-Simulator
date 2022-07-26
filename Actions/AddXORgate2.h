#ifndef _ADD_XOR_GATE_H
#define _ADD_XOR_GATE_H

#include "Action.h"
#include "..\Components\XOR2.h"

class AddXORgate2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	bool test;
public:
	AddXORgate2(ApplicationManager* pAppMan, ActionType actType, Data* pLoadedData = NULL);
	virtual ~AddXORgate2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
