#include "AddXORgate3.h"
#include "..\ApplicationManager.h"

AddXORgate3::AddXORgate3(ApplicationManager* pApp, ActionType actType, Data* pLoadedData) :Action(pApp)
{
	test = true;
}

AddXORgate3::~AddXORgate3(void)
{

}

void AddXORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

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

void AddXORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	if (test)
	{
		//Calculate the rectangle Corners
		int Len = UI.XOR3_Width;
		int Wdth = UI.XOR3_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		XOR3* pA = new XOR3(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
	else
	{
		return;
	}
}

void AddXORgate3::Undo()
{}

void AddXORgate3::Redo()
{}