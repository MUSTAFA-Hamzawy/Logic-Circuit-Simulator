#include "SelectAction.h"
#include "../ApplicationManager.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
	comp = NULL;
	test = true;
}

SelectAction::~SelectAction(void)
{

}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("click on the component to select/Unselect");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	int I;
	if (pManager->isExist(Cx, Cy, I))
	{
		comp = pManager->getComponent(I);
	}
	else
	{
		test = false;
		pOut->PrintMsg("Failed, It is not a component. try again accurately");
	}

}

void SelectAction::Execute()
{
	ReadActionParameters();
	if (test)
	{
		if (comp->isSelected())
		{
			comp->setSelected(false);
		}
		else
		{
			comp->setSelected(true);
		}
	}
	else
	{
		return;
	}
}

void SelectAction::Undo()
{}

void SelectAction::Redo()
{}

