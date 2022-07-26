#include "Cut.h"

/* Constructor */
Cut::Cut(ApplicationManager* pAppMan) : Action(pAppMan) {
	deleteAct = new Delete(pManager);
}
int ind;
char inp;
/* Reads parameters required for action to execute */
void Cut::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("To cut wire press z, otherwise press x");
	pOut->getWind()->WaitKeyPress(inp);

	switch (inp)
	{
	case 'x':
		pOut->PrintMsg("Click on the component to cut it");
		pIn->GetPointClicked(Cx, Cy);

		if (pManager->isExist(Cx, Cy, ind))
		{
			gfx = pManager->getComponentGFX(ind);
			cutiedComp = pManager->getComponent(ind);
			deleteAct = new Delete(pManager);
		}
		else
		{
			pOut->PrintMsg("Failed, It is not a component. try again accurately");
			test = false;
		}
		break;
	case 'z':
		pOut->PrintMsg("Click on the start of the wire");
		pIn->GetPointClicked(gfx.x1, gfx.y1);
		pOut->PrintMsg("Click on the end of the wire");
		pIn->GetPointClicked(gfx.x2, gfx.y2);
		if (pManager->isExist(gfx.x1, gfx.y1, gfx.x2, gfx.y2, ind))
		{
			cutiedConn = pManager->getConnection(ind);
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
void Cut::Execute() {

	ReadActionParameters();

	if (test)
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		if (cutiedComp)
		{
			Gate* cutiedGate;
			cutiedGate = dynamic_cast<Gate*>(cutiedComp);
			if (cutiedGate)
			{
				cutiedGate->Restore(pOut);
				pManager->SetCopiedComp(cutiedComp);
				pOut->getWind()->DrawRectangle(gfx.x1 - 5, gfx.y1 - 25, gfx.x2 + 5, gfx.y2);
				cutiedGate->Remove();
				pManager->RemoveComp(ind);
			}
		}
		else if (cutiedConn)
		{
			pManager->SetCopiedComp(cutiedConn);
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
void Cut::Undo() {
	deleteAct->Undo();
}

/* Redo action */
void Cut::Redo() {
	deleteAct->Redo();
}

/* Destructor */
Cut::~Cut() {
	delete deleteAct;
}