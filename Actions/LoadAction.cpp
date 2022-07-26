#include "LoadAction.h"

/* Constructor */
LoadAction::LoadAction(ApplicationManager* pAppMan) : Action(pAppMan) {

}

/* Reads parameters required for action to execute */
void LoadAction::ReadActionParameters() {
	mRead.open("circuits.txt");
}

/* Executes action */
void LoadAction::Execute() {


	pManager->ReleaseMemory();
	pManager->GetOutput()->ClearDrawingArea();
	//pManager->Load(mRead);
	pManager->GetOutput()->PrintMsg("Loaded");
}


/* Undo action */
void LoadAction::Undo() {
	return;
}

/* Redo action */
void LoadAction::Redo() {
	return;
}

/* Destructor */
LoadAction::~LoadAction() {
	mRead.close();
}