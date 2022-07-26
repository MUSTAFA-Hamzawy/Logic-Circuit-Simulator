#include "../Actions/Delete.h"
#include "..\ApplicationManager.h"

using namespace std;

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
	deletedComp = NULL;
	deletedConn = NULL;
	test = true;
}

Delete::~Delete(void)
{

}
int index;
char input;
void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("To delete wire press w, otherwise press c");
	pOut->getWind()->WaitKeyPress(input);
	
	switch (input)
	{
	case 'c':
		pOut->PrintMsg("Click on the component to delte it");
		pIn->GetPointClicked(Cx, Cy);

		if (pManager->isExist(Cx, Cy, index))
		{
			gfx = pManager->getComponentGFX(index);
			deletedComp = pManager->getComponent(index);
		}
		else
		{
			pOut->PrintMsg("Failed, It is not a component. try again accurately");
			test = false;
		}
		break;
	case 'w':
		pOut->PrintMsg("Click on the start of the wire");
		pIn->GetPointClicked(gfx.x1, gfx.y1);
		pOut->PrintMsg("Click on the end of the wire");
		pIn->GetPointClicked(gfx.x2, gfx.y2);
		if (pManager->isExist(gfx.x1, gfx.y1, gfx.x2, gfx.y2, index))
		{
			deletedConn = pManager->getConnection(index);
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

void Delete::Execute()
{
	ReadActionParameters();
	
	if (test)
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		if (deletedComp)
		{
			Gate* deletedGate;
			deletedGate = dynamic_cast<Gate*>(deletedComp);
			if (deletedGate)
			{
				pOut->getWind()->SetPen(WHITE, 10);
				pOut->getWind()->DrawRectangle(gfx.x1 - 5, gfx.y1 - 25, gfx.x2 + 5, gfx.y2);
				deletedGate->Remove();
				pManager->RemoveComp(index);
			}
		}
		else if (deletedConn)
		{
			//deletedConn->getSourcePin()->setStatus(LOW);
			//deletedConn->getDestPin()->setStatus(LOW);
			//deletedConn->getSourcePin()->removeConnection(deletedConn);
			//deletedConn->getDestPin()->removeConnection();
			pOut->getWind()->SetPen(WHITE, 10);
			deletedConn->Draw(pOut, true);
			pManager->RemoveComp(index);
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

void Delete::Undo()
{}

void Delete::Redo()
{}