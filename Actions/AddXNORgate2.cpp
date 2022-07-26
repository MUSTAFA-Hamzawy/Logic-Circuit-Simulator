#include "AddXNORgate2.h"
#include "..\ApplicationManager.h"

AddXNORgate2::AddXNORgate2(ApplicationManager* pApp, ActionType actType, Data* pLoadedData) :Action(pApp)
{
	test = true;
}

AddXNORgate2::~AddXNORgate2(void)
{

}

void AddXNORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XNOR Gate: Click to add the gate");

	//Wait for User Input
	int i;
	pIn->GetPointClicked(Cx, Cy);
	if (pOut->isValidArea(Cy) && !(pManager->isExist(Cx, Cy, i)))
	{
		test = true;
	}
	else
	{
		pOut->PrintMsg("Invalid position to draw, try again");
		test = false;
	}

}

void AddXNORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	if (test)
	{
		//Calculate the rectangle Corners
		int Len = UI.XNOR2_Width;
		int Wdth = UI.XNOR2_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		XNOR2* pA = new XNOR2(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
	else
	{
		return;
	}
}

void AddXNORgate2::Undo()
{}

void AddXNORgate2::Redo()
{}

