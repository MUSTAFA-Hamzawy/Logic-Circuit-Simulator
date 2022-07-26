#ifndef _SIM_MODE_H
#define _SIM_MODE_H
#include "Action.h"
#include "../Components/LED.h"
#include "../GUI/Output.h"
#include "..\Actions\Action.h"
#include "../GUI/UI_Info.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Components\Switch_Off.h"
#include "..\Components\Switch_On.h"
#include "..\Components\Connection.h"
#include <string>
class SimMode : public Action
{
private:

	LED* ledsOfCircuit;
	bool Stop;
public:
	SimMode(ApplicationManager* pApp);
	virtual ~SimMode(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif
