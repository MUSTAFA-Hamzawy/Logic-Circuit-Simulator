#ifndef _EDIT_ACTION_H
#define _EDIT_ACTION_H

#include "Action.h"
#include "../Components/Connection.h"
#include "../Components/Component.h"
class EditAction : public Action
{
private:
	int Cx, Cy;	//Center point of the component to be edited
	Connection* con;
	Component* comp;
	InputPin* newInputPin;
	OutputPin* newOutputPin;
	bool test;
	GraphicsInfo newgInfo;        // for new Edited connection
public:
	EditAction(ApplicationManager* pApp);
	virtual ~EditAction(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif#pragma once
