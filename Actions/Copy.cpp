#include "Copy.h"

/* Constructor */
Copy::Copy(ApplicationManager* pAppMan) : Action(pAppMan) {
	copiedComp = NULL;
	copiedConn = NULL;
	test = true;
}
int inde;
char inpu;
/* Reads parameters required for action to execute */
void Copy::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("To copied wire press m, otherwise press n");
	pOut->getWind()->WaitKeyPress(inpu);

	switch (inpu)
	{
	case 'n':
		pOut->PrintMsg("Click on the component to copy it");
		pIn->GetPointClicked(Cx, Cy);

		if (pManager->isExist(Cx, Cy, inde))
		{
			gfx = pManager->getComponentGFX(inde);
			copiedComp = pManager->getComponent(inde);
		}
		else
		{
			pOut->PrintMsg("Failed, It is not a component. try again accurately");
			test = false;
		}
		break;
	case 'm':
		pOut->PrintMsg("Click on the start of the wire");
		pIn->GetPointClicked(gfx.x1, gfx.y1);
		pOut->PrintMsg("Click on the end of the wire");
		pIn->GetPointClicked(gfx.x2, gfx.y2);
		if (pManager->isExist(gfx.x1, gfx.y1, gfx.x2, gfx.y2, inde))
		{
			copiedConn = pManager->getConnection(inde);
		}
		else
		{
			pOut->PrintMsg("Failed, It is not a Connection. try again accurately");
			test = false;
		}
		break;
	default:
		pOut->PrintMsg("Invalid character. try again");
		test = false;
		break;
	}
	//Clear Status Bar
	pOut->ClearStatusBar();
}

/* Executes action */
void Copy::Execute() {

	ReadActionParameters();

	if (test)
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		if (copiedComp)
		{
			Gate* copiedGate;
			copiedGate = dynamic_cast<Gate*>(copiedComp);
			if (copiedGate)
			{
				copiedGate->Restore(pOut);
				pManager->SetCopiedComp(copiedComp);
			}
		}
		else if (copiedConn)
		{
			pManager->SetCopiedComp(copiedConn);
		}
		else
		{
			pOut->PrintMsg("Failed, try again");
			return;
		}
	}
	else
	{
		return;
	}
}

/* Undo action */
void Copy::Undo() {
	return;
}

/* Redo action */
void Copy::Redo() {
	return;
}

/* Destructor */
Copy::~Copy() {

}