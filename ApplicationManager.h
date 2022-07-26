#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Components/Connection.h"
#include "Components/LED.h"
#include "Components/Gate.h"
#include"Components/Switch_On.h"
#include"Components/Switch_Off.h"
#include <stack>

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Component* mCopiedComp;       //// Pointer to the last copied/cut component
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	stack<Action*> mUndoStack;	// Stack holding the done actions
	stack<Action*> mRedoStack;	// Stack holding the un-done actions
public:


public:
	ApplicationManager(); //constructor



	//Creates an action and executes it
	void ExecuteAction(ActionType&);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	int getCount()const;
	bool isExist(int x, int y, int& index);                           // search for component
	GraphicsInfo getComponentGFX(int index);
	Component* getComponent(int index);
	Connection* getConnection(int index);
	bool isExist(int x1, int y1, int x2, int y2, int& index);         // search for connection
	void RemoveComp(int index);
	//LED* getLeds();
	~ApplicationManager();
	/* Returns the last copied/cut component */
	Component* GetCopiedComp() const;
	/* Saves the current circuit */
	void Save(ofstream& file);
	/* Sets the last copied/cut component */
	void SetCopiedComp(Component* pComp);
	/* Releases all the memory used by the components */
	void ReleaseMemory();
	/* Returns the number of the existing components */
	//int GetExistingComponentsCount() const;
	/* Undoes the last action */
	void Undo();
	/* Loads the circuit from the file */
	void Load(ifstream& file);

	/* Redoes the last action */
	void Redo();
	/* Reads the required action from the user and returns the corresponding action type */
	ActionType GetUserAction();


};

#endif