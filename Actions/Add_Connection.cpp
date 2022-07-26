#include "Add_Connection.h"
#include "..\ApplicationManager.h"
#include <string>

Add_Connection::Add_Connection(ApplicationManager* pApp, ActionType actType, Data* pLoadedData) :Action(pApp)
{
	src = NULL;
	dst = NULL;
	srcComp = NULL;
	dstComp = NULL;
	test = true;
}

Add_Connection::~Add_Connection(void)
{

}

string InputString;
void Add_Connection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Add wire : Click to source pin");

	//Wait for User Input
	pIn->GetPointClicked(x1, y1);
	int index;
	char input;

	if (pManager->isExist(x1, y1, index))
	{
		srcComp = pManager->getComponent(index);
	}
	else
	{
		pOut->PrintMsg("It is not a component. try again accurately, please");
		test = false;
	}

	pOut->PrintMsg("Enter the number of input destination pin (it can't be negative)");
	pOut->getWind()->WaitKeyPress(input);
	InputString = input;
	while (stoi(InputString) < 0 || stoi(InputString) > 3)
	{
		pOut->PrintMsg(InputString + " : is Not valid, please Enter a number between 1 and 3");
		pOut->getWind()->WaitKeyPress(input);
		InputString = input;
	}
	
	pOut->PrintMsg("OK, click on the input destination pin");
	pIn->GetPointClicked(x2, y2);
	if (pManager->isExist(x2, y2, index))
	{
		dstComp = pManager->getComponent(index);

	}
	else
	{
		pOut->PrintMsg("It is not a component. try again accurately, please");
		test = false;
	}

}

void Add_Connection::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	if (test)
	{
		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = x1;
		GInfo.x2 = x2;
		GInfo.y1 = y1;
		GInfo.y2 = y2;
		Connection* con = new Connection(GInfo);
		Gate* gate = dynamic_cast<Gate*>(srcComp);
		if (gate)
		{
			src = (gate->getOutputPin());
		}
		gate = dynamic_cast<Gate*>(dstComp);
		if (gate)
		{
			dst = (gate->getInputPin(stoi(InputString)));
		}
		con->setSourcePin(src);
		con->setDestPin(dst);
		pManager->AddComponent(con);
		con->Operate();
		gate->setInputPinStatus(stoi(InputString), con->getSourcePin()->getStatus());
		gate->Operate();
	}
	else
	{
		return;
	}
}

void Add_Connection::Undo()
{}

void Add_Connection::Redo()
{}

