#include "AddSwitch_On.h"
#include "..\ApplicationManager.h"

AddSwitch_On::AddSwitch_On(ApplicationManager* pApp, ActionType actType, Data* pLoadedData) :Action(pApp)
{
	test = true;
}

AddSwitch_On::~AddSwitch_On(void)
{

}

void AddSwitch_On::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Switch On: Click to add");

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

void AddSwitch_On::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	if (test)
	{
		//Calculate the rectangle Corners
		int Len = UI.Switch_Width;
		int Wdth = UI.Switch_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		Switch_On* pA = new Switch_On(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
	}
	else
	{
		return;
	}
}

void AddSwitch_On::Undo()
{}

void AddSwitch_On::Redo()
{}
