#ifndef _DELETE_H
#define _DELETE_H

#include "Action.h"
#include "../Components/Component.h"
#include "../Components/Connection.h"
#include "../Components/Gate.h"

class Delete : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* deletedComp;
	Connection* deletedConn;
	GraphicsInfo gfx;
	bool test;                      // validate for ReadActionParameters
public:
	Delete(ApplicationManager* pApp);
	virtual ~Delete(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
