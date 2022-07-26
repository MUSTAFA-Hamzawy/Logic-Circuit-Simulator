#include "UndoAction.h"

/* Constructor */
UndoAction::UndoAction(ApplicationManager* pAppMan) : Action(pAppMan) {

}

/* Reads parameters required for action to execute */
void UndoAction::ReadActionParameters() {
	return;
}

/* Executes action */
void UndoAction::Execute() {
	pManager->Undo();
	pManager->GetOutput()->ClearStatusBar();

	// To prevent adding this action to the stack again
}

/* Undo action */
void UndoAction::Undo() {
	return;
}

/* Redo action */
void UndoAction::Redo() {
	return;
}

/* Destructor */
UndoAction::~UndoAction() {

}