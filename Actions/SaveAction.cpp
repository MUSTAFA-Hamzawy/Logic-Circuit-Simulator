#include "SaveAction.h"

/* Constructor */
SaveAction::SaveAction(ApplicationManager* pAppMan) : Action(pAppMan) {

}

/* Reads parameters required for action to execute */
void SaveAction::ReadActionParameters() {
}

/* Executes action */
void SaveAction::Execute() {
	mWrite.open("circuits.txt");
	mWrite.clear();
	pManager->Save(mWrite);
	mWrite << "-1\n";
	pManager->GetOutput()->PrintMsg("Saved");
}

/* Undo action */
void SaveAction::Undo() {
	return;
}

/* Redo action */
void SaveAction::Redo() {
	return;
}

/* Destructor */
SaveAction::~SaveAction() {
	mWrite.close();
}