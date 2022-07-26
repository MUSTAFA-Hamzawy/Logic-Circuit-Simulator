#include "AddANDgate3.h"
#include "..\ApplicationManager.h"

AddANDgate3::AddANDgate3(ApplicationManager* pApp, ActionType actType, Data* pLoadedData) :Action(pApp)
{
	test = true;
}

AddANDgate3::~AddANDgate3(void)
{

}

void AddANDgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input AND Gate: Click to add the gate");

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

void AddANDgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	if (test)
	{
		//Calculate the rectangle Corners
		int Len = UI.AND3_Width;
		int Wdth = UI.AND3_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		AND3* pA = new AND3(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
	else
	{
		return;;
	}
}

void AddANDgate3::Undo()
{}

void AddANDgate3::Redo()
{}

