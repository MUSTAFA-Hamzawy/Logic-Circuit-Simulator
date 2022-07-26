#include "../Actions/ActionLabel.h"
#include "..\ApplicationManager.h"

ActionLabel::ActionLabel(ApplicationManager* pApp) :Action(pApp)
{
	test = true;
	comp = NULL;
}

ActionLabel::~ActionLabel(void)
{

}

void ActionLabel::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("click on the item that you want to label (if wire click on its srcPin or DstPin)");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	int i;
	if (pManager->isExist(Cx, Cy, i))
	{
		comp = pManager->getComponent(i);
		if (comp->isLabeld())
		{
			pOut->PrintMsg("This component has already been labeled (we suggest to click on edit from tool bar)");
			test = false;
		}
	}
	else
	{
		pOut->PrintMsg("Failed, It is not a component. try again accurately");
		test = false;
	}
}

void ActionLabel::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	if (test)
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		GraphicsInfo gfx;
		Gate* g;
		Connection* c;
		if (comp)
		{
			g = dynamic_cast<Gate*>(comp);
			c = dynamic_cast<Connection*>(comp);
			string InputText = "empty";
			if (g)
			{
				gfx = comp->getGxfInfo();
				InputText = pIn->GetSrting(pOut, "Write Here : ", gfx.x1, gfx.y1 - (0.5 * UI.AND2_Height + 5));
			}
			else if (c)
			{
				gfx = comp->getGxfInfo();
				InputText = pIn->GetSrting(pOut, "Write Here : ", ((gfx.x1 + gfx.x2) / 2.0), gfx.y1 - (0.5 * UI.AND2_Height + 2));
			}
			comp->setLabel(InputText);
		}
	}
	else
	{
		return;
	}



}

void ActionLabel::Undo()
{}

void ActionLabel::Redo()
{}

