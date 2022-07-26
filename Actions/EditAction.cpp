#include "../Actions/EditAction.h"
#include "..\ApplicationManager.h"
#include "../Actions/Add_Connection.h"

EditAction::EditAction(ApplicationManager* pApp) :Action(pApp)
{
	con = NULL;
	comp = NULL;
	newInputPin = NULL;
	newOutputPin = NULL;
	test = true;
}

EditAction::~EditAction(void)
{

}
int Index;   // location of component in compList
GraphicsInfo Gfx;
char check;
void EditAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("To edit connection enter w, otherwise, enter c");
	char input;
	pOut->getWind()->WaitKeyPress(input);
	
	switch (input)
	{
	case 'c':
		pOut->PrintMsg("Click on the component to edit its label");
		pIn->GetPointClicked(Cx, Cy);
		//int Index; 
		if (pManager->isExist(Cx, Cy, Index))
		{
			Gfx = pManager->getComponentGFX(Index);
			comp = pManager->getComponent(Index);
			if (!(comp->isLabeld()))
			{
				pOut->PrintMsg("Failed, It is not a labeled component to be edited");
				test = false;
			}
		}
		else
		{
			pOut->PrintMsg("Failed, It is not a component. try again accurately");
			test = false;
		}
		break;
	case 'w':
		pOut->PrintMsg("To edit label press 1, to edit pins press 2");
		//char check;
		pOut->getWind()->WaitKeyPress(check);
		switch (check)
		{
		case '1':
			pOut->PrintMsg("Click on the start of the wire");
			pIn->GetPointClicked(Gfx.x1, Gfx.y1);
			pOut->PrintMsg("Click on the end of the wire");
			pIn->GetPointClicked(Gfx.x2, Gfx.y2);
			if (pManager->isExist(Gfx.x1, Gfx.y1, Gfx.x2, Gfx.y2, Index))
			{
				if (!(pManager->getComponent(Index)->isLabeld()))
				{
					pOut->PrintMsg("Failed, It is not a labeled component to be edited");
					test = false;
				}
				else
				{
					con = (Connection*)(pManager->getComponent(Index));
					Gfx = con->getGxfInfo();
				}
			}
			else
			{
				pOut->PrintMsg("Failed, It is not a wire. try again accurately");
				test = false;
			}
			break;
		case '2':
			pOut->PrintMsg("Click on the start of the wire");
			pIn->GetPointClicked(Gfx.x1, Gfx.y1);
			pOut->PrintMsg("Click on the end of the wire");
			pIn->GetPointClicked(Gfx.x2, Gfx.y2);
			if (pManager->isExist(Gfx.x1, Gfx.y1, Gfx.x2, Gfx.y2, Index))
			{
				con = (Connection*)(pManager->getComponent(Index));
				con->Draw(pOut, true);
			}
			else
			{
				pOut->PrintMsg("Failed, It is not a wire. try again accurately");
				test = false;
			}
			break;
		default:
			pOut->PrintMsg("Invalid input, try again");
			test = false;
			break;
		}
		break;
	default:
		pOut->PrintMsg("Invalid character. try again");
		test = false;
		break;
	}

}

void EditAction::Execute()
{
	ActionType ap;
	//Get Center point of the Gate
	ReadActionParameters();
	if (test)
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		if (comp)
		{
			// remove the old text
			comp->removeLabel();
			pOut->getWind()->SetPen(WHITE, 10);
			pOut->getWind()->DrawRectangle(Gfx.x1, Gfx.y1, Gfx.x2, Gfx.y1 - 20, FILLED, 20);
			// get the new label
			string InputText = pIn->GetSrting(pOut, "Edit Here : ", Gfx.x1, Gfx.y1 - (0.5 * UI.AND2_Height + 5));
			comp->setLabel(InputText);
		}
		else if (con)
		{
			if (check == '2')
			{
				pManager->RemoveComp(Index);
				pOut->PrintMsg("Now we will set the new DstPin and the new SrcPin for this wire , press Enter to continue");
				char Input;
				pOut->getWind()->WaitKeyPress(Input);
				if (int(Input == 13))
				{
					Action* act;
					act = new Add_Connection(pManager, ap);
					act->Execute();
				}
				else
				{
					pOut->PrintMsg("Failed, You didn't press Enter");
					return;
				}
			}
			else            // edit label
			{
				// remove old label
				con->removeLabel();
				pOut->getWind()->SetPen(WHITE, 10);
				pOut->getWind()->DrawRectangle(((Gfx.x1 + Gfx.x2) / 2.0), Gfx.y1, Gfx.x2, Gfx.y1 - 20, FILLED, 20);
				// set new label
				string InputText = pIn->GetSrting(pOut, "Edit Here : ", ((Gfx.x1 + Gfx.x2) / 2.0), Gfx.y1 - (0.5 * UI.AND2_Height + 2));
				con->setLabel(InputText);
			}
			
		}
	}
	else
	{
		return;
	}
}

void EditAction::Undo()
{}

void EditAction::Redo()
{}


