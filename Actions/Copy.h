#pragma once
#include "../Actions/Action.h"
#include "../ApplicationManager.h"
#include "../Components/Component.h"
#include "../Components/Connection.h"

class Copy : public Action
{
private:
		//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* copiedComp;
	Connection* copiedConn;
	GraphicsInfo gfx;
	bool test;                      // validate for ReadActionParameters

public:
	/* Constructor */
	Copy(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Copy();
};