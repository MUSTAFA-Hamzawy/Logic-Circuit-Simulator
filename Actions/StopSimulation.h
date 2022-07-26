#ifndef _STOPSIMULATION_H
#define _STOPSIMULATION_H

#include "action.h"
#include "../Components/LED.h"

class StopSimulation : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	LED* ledsOfCircuit;
public:
	StopSimulation(ApplicationManager* pApp);
	virtual ~StopSimulation(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif