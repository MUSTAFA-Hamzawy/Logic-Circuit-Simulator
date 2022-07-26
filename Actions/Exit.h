#pragma once
#include "../Actions/Action.h"
#include "../Actions/SaveAction.h"
#include "../ApplicationManager.h"
#include <fstream>
#include<iostream>
#include<string>
using namespace std;


class Exit : public Action
{
private:
	ofstream mWrite;

public:
	/* Constructor */
	Exit(ApplicationManager* pApp);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Exit();
};

