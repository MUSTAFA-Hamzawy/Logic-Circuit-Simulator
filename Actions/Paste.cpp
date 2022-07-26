#include "Paste.h"

/* Constructor */
Paste::Paste(ApplicationManager* pAppMan) : Action(pAppMan)
{
	pA = NULL;
}

/* Reads parameters required for action to execute */
void Paste::ReadActionParameters() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	mComp = pManager->GetCopiedComp();
	pOut->PrintMsg("Click on the location to copy in it");
	pOut->getWind()->WaitMouseClick(x, y);
	int Len = UI.INV_Width;
	int Wdth = UI.INV_Height;
	GInfo.x1 = x - Len / 2;
	GInfo.x2 = x + Len / 2;
	GInfo.y1 = y - Wdth / 2;
	GInfo.y2 = y + Wdth / 2;
}

/* Executes action */
void Paste::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ActionType act;
	
	//[1] If user clicks on the Toolbar
	if (pOut->isValidArea(y))
	{
		if (dynamic_cast<Buff*>(mComp))
		{
			Buff* pA = new Buff(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<AND2*>(mComp))
		{
			AND2* pA = new AND2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<AND3*>(mComp))
		{
			AND3* pA = new AND3(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<INV*>(mComp))
		{
			INV* pA = new INV(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<LED*>(mComp))
		{
			LED* pA = new LED(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<NAND2*>(mComp))
		{
			NAND2* pA = new NAND2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<NOR2*>(mComp))
		{
			NOR2* pA = new NOR2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<NOR3*>(mComp))
		{
			NOR3* pA = new NOR3(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<OR2*>(mComp))
		{
			OR2* pA = new OR2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<Switch_Off*>(mComp))
		{
			Switch_Off* pA = new Switch_Off(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<Switch_On*>(mComp))
		{
			Switch_On* pA = new Switch_On(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<XNOR2*>(mComp))
		{
			XNOR2* pA = new XNOR2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<XOR2*>(mComp))
		{
			XOR2* pA = new XOR2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
		else if (dynamic_cast<XOR3*>(mComp))
		{
			XOR3* pA = new XOR3(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);
		}
	}

}

/* Undo action */
void Paste::Undo() {
	mAct->Undo();
}

/* Redo action */
void Paste::Redo() {
	mAct->Redo();
}

/* Destructor */
Paste::~Paste() {
}