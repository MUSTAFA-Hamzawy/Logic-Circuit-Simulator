#include "RedoAction.h"

/* Constructor */
RedoAction::RedoAction(ApplicationManager* pAppMan) : Action(pAppMan) {

}

/* Reads parameters required for action to execute */
void RedoAction::ReadActionParameters() {
	return;
}

/* Executes action */
void RedoAction::Execute() {
	pManager->Redo();
	pManager->GetOutput()->ClearStatusBar();

	// To prevent adding this action to the stack again
}

/* Undo action */
void RedoAction::Undo() {
	return;
}

/* Redo action */
void RedoAction::Redo() {
	return;
}

/* Destructor */
RedoAction::~RedoAction() {

}