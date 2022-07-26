#ifndef _ADD_Switch_On_H
#define _ADD_Switch_On_H

#include"../Actions/Action.h"
#include"../Components/Switch_On.h"

class AddSwitch_On : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	bool test;
public:
	AddSwitch_On(ApplicationManager* pAppMan, ActionType actType, Data* pLoadedData = NULL);
	virtual ~AddSwitch_On(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
