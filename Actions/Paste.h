#pragma once
#include "../Actions/Action.h"
#include "../ApplicationManager.h"
#include "../Components/Gate.h"
#include "../Actions\AddANDgate2.h"
#include"../Actions/AddINVgate.h"
#include "../Actions/AddBUFFgate.h"
#include "../Actions/AddNORgate2.h"
#include "../Actions/AddNORgate3.h"
#include "../Actions/AddNANDgate2.h"
#include "../Actions/AddORgate2.h"
#include "../Actions/AddXORgate2.h"
#include "../Actions/AddXORgate3.h"
#include "../Actions/AddXNORgate2.h"
#include "../Actions/AddANDgate3.h"
#include "../Actions/Add_Connection.h"
#include "../Actions/AddSwitch_On.h"
#include "../Actions/AddSwitch_Off.h"
#include "../Actions/AddLED.h"

class Paste : public Action
{
private:
	int x, y;
	Component* mComp;		// Pointer to the pasted component
	Action* mAct;			// Add component action
	ApplicationManager* pA;
	GraphicsInfo GInfo;
public:
	/* Constructor */
	Paste(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Paste();
};

