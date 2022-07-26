#ifndef _ADD_Switch_Off_H
#define _ADD_Switch_Off_H


#include"../Actions/Action.h"
#include"../Components/Switch_Off.h"

class AddSwitch_Off : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	bool test;
public:
	AddSwitch_Off(ApplicationManager* pAppMan, ActionType actType, Data* pLoadedData = NULL);
	virtual ~AddSwitch_Off(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif