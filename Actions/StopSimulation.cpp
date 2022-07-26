#include "../Actions/StopSimulation.h"
#include "..\ApplicationManager.h"

StopSimulation::StopSimulation(ApplicationManager* pApp) :Action(pApp)
{
}

StopSimulation::~StopSimulation(void)
{

}

void StopSimulation::ReadActionParameters()
{
	return;

}

void StopSimulation::Execute()
{
	for (int i = 0; i < pManager->getCount(); i++)
	{
		Component* comp = pManager->getComponent(i);
		Connection* conn = dynamic_cast<Connection*>(comp);
		if (conn)
		{
			conn->set_IsSimMode(false);
		}
	}

	for (int i = 0; i < pManager->getCount(); i++)
	{
		ledsOfCircuit = dynamic_cast<LED*>(pManager->getComponent(i));
		if (ledsOfCircuit)
		{
			(ledsOfCircuit)->setSelected(false);
		}
	}
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("Simulation is stopped");
}

void StopSimulation::Undo()
{}

void StopSimulation::Redo()
{}

