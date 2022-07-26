#include "SimMode.h"
#include "..\ApplicationManager.h"

SimMode::SimMode(ApplicationManager* pApp) :Action(pApp)
{

}

SimMode::~SimMode(void)
{

}

void SimMode::ReadActionParameters()
{
	return;
}

void SimMode::Execute()
{

	for (int i = 0; i < pManager->getCount(); i++)
	{
		Component* comp = pManager->getComponent(i);
		Connection* conn = dynamic_cast<Connection*>(comp);
		if (conn)
		{
			conn->set_IsSimMode(true);
		}
		comp->Operate();
	}

	for (int i = 0; i < pManager->getCount(); i++)
	{
		ledsOfCircuit = dynamic_cast<LED*>(pManager->getComponent(i));
		if (ledsOfCircuit)
		{
			if (ledsOfCircuit->GetInputPinStatus(1) == HIGH)
			{
				(ledsOfCircuit)->setSelected(true);
			}
		}
	}
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("Simulation mode");


}

void SimMode::Undo()
{}

void SimMode::Redo()
{}



