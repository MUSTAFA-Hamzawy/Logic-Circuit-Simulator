#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include"Actions/AddINVgate.h"
#include "Actions/AddBUFFgate.h"
#include "Actions/AddNORgate2.h"
#include "Actions/AddNORgate3.h"
#include "Actions/AddNANDgate2.h"
#include "Actions/AddORgate2.h"
#include "Actions/AddXORgate2.h"
#include "Actions/AddXORgate3.h"
#include "Actions/AddXNORgate2.h"
#include "Actions/AddANDgate3.h"
#include "Actions/Add_Connection.h"
#include "Actions/AddSwitch_On.h"
#include "Actions/AddSwitch_Off.h"
#include "Actions/AddLED.h"
#include "Actions/EditAction.h"
#include "Actions/SelectAction.h"
#include "Actions/Delete.h"
#include "Actions/SimMode.h"
#include "Actions/SaveAction.h"
#include "Actions/StopSimulation.h"
#include "Actions\EditAction.h"
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Paste.h"
#include "Actions\UndoAction.h"
#include "Actions/RedoAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\Exit.h"
#include "Actions/ActionLabel.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
int ApplicationManager::getCount() const
{
	return CompCount;
}
// To makesure that the component(gate )the user clicked on is exist (this benefit for copy,cut,etc....)
bool ApplicationManager::isExist(int x, int y, int& index)
{
	GraphicsInfo gfx;
	for (int i = 0; i < CompCount; i++)
	{
		gfx = CompList[i]->getGxfInfo();
		if ((x >= gfx.x1 && x <= gfx.x2) && (y >= gfx.y1 && y <= gfx.y2))
		{
			index = i;
			return true;
		}
	}
	return false;
}
//TO Return the graphicsInfo of the component(gates&&connections)
GraphicsInfo ApplicationManager::getComponentGFX(int index)
{
	return CompList[index]->getGxfInfo();
}
//To Return the component(gate)
Component* ApplicationManager::getComponent(int index)
{
		return CompList[index];
}
//To Return the component(connection)
Connection* ApplicationManager::getConnection(int index)
{
	Connection* conn = (Connection*)CompList[index];
	return conn;
}
// To makesure that the component(connection) the user clicked on is exist (this benefit for copy,cut,etc....)
bool ApplicationManager::isExist(int x1, int y1, int x2, int y2, int& index)
{
	GraphicsInfo gfx;
	for (int i = 0; i < CompCount; i++)
	{
		Connection* target = dynamic_cast<Connection*>(CompList[i]);
		if (target)
		{
			gfx = CompList[i]->getGxfInfo();
			if (((x1 >= gfx.x1 - 10 && x1 < gfx.x1 + 10) && (y1 >= gfx.y1 - 5 && y1 <= gfx.y1 + 5))
				&& ((x2 >= gfx.x2 - 10 && x2 <= gfx.x2 + 10) && (y2 >= gfx.y2 - 3 && y2 <= gfx.y2 + 5)))
			{
				index = i;
				return true;
			}
		}
	}
	return false;
}
//Remove component (gate or connection)
void ApplicationManager::RemoveComp(int index)
{
	delete CompList[index];
	CompList[index] = CompList[CompCount - 1];
	CompList[CompCount - 1] = NULL;
	CompCount--;

}

/* Returns the number of the existing components */
/*
int ApplicationManager::GetExistingComponentsCount() const {
	int n = 0;
	for (int i = 0; i < CompCount; i++) 
	{
		if (!CompList[i]->IsDeleted()) {
			n++;
		}
	}
	return n;
}
*/
//Return the LED to use it in simulation
/*
LED* ApplicationManager::getLeds()
{
	for (int i = 0; i < CompCount; i++)
	{
		LED* test = dynamic_cast<LED*>(CompList[i]);
		if (test)
		{
			return test;
		}
	}
	return NULL;
}
*/

/* Returns the last copied/cut component */
Component* ApplicationManager::GetCopiedComp() const {
	return mCopiedComp;
}


////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType& ActType)
{
	Action* pAct = NULL;
	//string text = " "; // to store return of getString and add it to setLabel function
	switch (ActType)
	{
		case ADD_Buff:
		pAct = new AddBUFFgate(this , ActType);
		break;
		case ADD_INV:
			pAct = new AddINVgate(this, ActType);
			break;
		case ADD_AND2:
			pAct= new AddANDgate2(this , ActType);
			break;
		case ADD_OR2:
			pAct = new AddORgate2(this, ActType);
			break;
		case ADD_NAND2:
			pAct = new AddNANDgate2(this, ActType);
			break;
		case ADD_NOR2:
			pAct = new AddNORgate2(this, ActType);
			break;
		case ADD_XOR2:
			pAct = new AddXORgate2(this, ActType);
			break;
		case ADD_XNOR2:
			pAct = new AddXNORgate2(this, ActType);
			break;
		case ADD_AND3:
			pAct = new AddANDgate3(this, ActType);
			break;
		case ADD_NOR3:
			pAct = new AddNORgate3(this, ActType);
			break;
		case ADD_XOR3:
			pAct = new AddXORgate3(this, ActType);
			break;
		case ADD_WIRE:
			pAct = new Add_Connection(this, ActType);
			break;
		case ADD_LED:
			pAct = new AddLED(this, ActType);
			break;
		case ADD_SwitchOn:
			pAct = new AddSwitch_On(this, ActType);
			break;
		case ADD_SwitchOff:
			pAct = new AddSwitch_Off(this, ActType);
			break;
		case ADD_Label:
			pAct = new ActionLabel(this);
			break;
		case ADD_Edit:
			pAct = new EditAction(this);
			break;
		case ADD_DEL:
			pAct = new Delete(this);
			break;
		case ADD_COPY:
			pAct = new Copy(this);
			break;
		case ADD_CUT:
			pAct = new Cut(this);
			break;
		case ADD_PASTE:
			pAct = new Paste(this);
			break;
		case ADD_UNDO:
			pAct = new UndoAction(this);
			break;
		case ADD_REDO:
			pAct = new RedoAction(this);
			break;
		case ADD_PLAY:
			pAct = new SimMode(this);
			break;
		case ADD_PAUSE:
			pAct = new StopSimulation(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;
		case ADD_Select:
			pAct = new SelectAction(this);
			break;
		case EXIT:
			pAct = new Exit(this);
			break;

	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}

/* Redoes the last action */
void ApplicationManager::Redo() {
	if (mRedoStack.empty()) {
		return;
	}

	Action* lastAction = mRedoStack.top();
	lastAction->Redo();

	mRedoStack.pop();
	mUndoStack.push(lastAction);
}


/* Releases all the memory used by the components */
void ApplicationManager::ReleaseMemory() {
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->Delete(OutputInterface);
		delete CompList[i];
	}

	CompCount = 0;
	mCopiedComp = NULL;
	for (int i = 0; i < MAX_CONNS; i++) CompList[i] = NULL;

	while (!mUndoStack.empty()) delete mUndoStack.top(), mUndoStack.pop();
	while (!mRedoStack.empty()) delete mRedoStack.top(), mRedoStack.pop();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Draw(OutputInterface);
	}

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}


// Saves the current circuit 
void ApplicationManager::Save(ofstream& file) {
	for (int i = 0; i < CompCount; i++) {
		if (!CompList[i]->IsDeleted()) {
			CompList[i]->Save(file);
		}
	}
}

/* Sets the last copied/cut component */
void ApplicationManager::SetCopiedComp(Component* pComp) {
	mCopiedComp = pComp;
}


/* Undoes the last action */
void ApplicationManager::Undo() {
	if (mUndoStack.empty()) {
		return;
	}

	Action* lastAction = mUndoStack.top();
	lastAction->Undo();

	mUndoStack.pop();
	mRedoStack.push(lastAction);
}


/* Loads the circuit from the file */
void ApplicationManager::Load(ifstream& file) {
	Data compData;
	string compType;
	Action* pAct;
	ActionType pp;
	while (file >> compType, compType != "-1") {
		if (file.eof()) {
			break;
		}

		if (compType == "CONNECTION") {
			file >> compData.Label;
			file >> compData.GfxInfo.x1 >> compData.GfxInfo.y1 >> compData.GfxInfo.x2 >> compData.GfxInfo.y2;
			pAct = new Add_Connection(this, pp, &compData);
		}
		else {
			file >> compData.Label;
			file >> compData.GfxInfo.x1 >> compData.GfxInfo.y1;

			if (compType == "AND")
				pAct = new AddANDgate2(this, ADD_AND2, &compData);
			else if (compType == "OR")
				pAct = new AddORgate2(this, ADD_OR2, &compData);
			else if (compType == "NOT")
				pAct = new AddINVgate(this, ADD_INV, &compData);
			else if (compType == "NAND")
				pAct = new AddNANDgate2(this, ADD_NAND2, &compData);
			else if (compType == "NOR")
				pAct = new AddNORgate2(this, ADD_NOR2, &compData);
			else if (compType == "XOR")
				pAct = new AddXORgate2(this, ADD_XOR2, &compData);
			else if (compType == "XNOR")
				pAct = new AddXNORgate2(this, ADD_XNOR2, &compData);
			else if (compType == "AND3")
				pAct = new AddANDgate3(this, ADD_AND3, &compData);
			else if (compType == "NOR3")
				pAct = new AddNORgate3(this, ADD_NOR3, &compData);
			else if (compType == "XOR3")
				pAct = new AddXORgate3(this, ADD_XOR3, &compData);
			else if (compType == "BUFFER")
				pAct = new AddBUFFgate(this, ADD_Buff, &compData);
			else if (compType == "SWITCH_ON")
				pAct = new AddSwitch_On(this, ADD_SwitchOn, &compData);
			else if (compType == "SWITCH_OFF")
				pAct = new AddSwitch_Off(this, ADD_SwitchOff, &compData);
			else if (compType == "LED")
				pAct = new AddLED(this, ADD_LED, &compData);
		}

		pAct->Execute();
		delete pAct;
	}
}