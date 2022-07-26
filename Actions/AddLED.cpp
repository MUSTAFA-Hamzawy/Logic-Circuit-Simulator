#include "AddLED.h"
#include "..\ApplicationManager.h"

AddLED::AddLED(ApplicationManager* pApp, ActionType actType, Data* pLoadedData) :Action(pApp)
{
	test = true;
}

AddLED::~AddLED(void)
{

}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg(" LED  : Click to add the gate");

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

void AddLED::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	if (test)
	{
		//Calculate the rectangle Corners
		int Len = UI.LED_Width;
		int Wdth = UI.LED_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		LED* pA = new LED(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
	else
		return;
}

void AddLED::Undo()
{}

void AddLED::Redo()
{}