#include "AddORgate2.h"
#include "..\ApplicationManager.h"

AddORgate2::AddORgate2(ApplicationManager* pApp, ActionType actType, Data* pLoadedData) :Action(pApp)
{
	test = true;
}

AddORgate2::~AddORgate2(void)
{

}

void AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

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

void AddORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	if (test)
	{
		//Calculate the rectangle Corners
		int Len = UI.OR2_Width;
		int Wdth = UI.OR2_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		OR2* pA = new OR2(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
	else
	{
		return;
	}
}

void AddORgate2::Undo()
{}

void AddORgate2::Redo()
{}
