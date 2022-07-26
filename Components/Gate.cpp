#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	m_Label = "empty";
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

void Gate::Remove()
{
	// remove conncetions of input pins
	for (int i = 0; i < m_Inputs; i++)
	{
		if (m_InputPins[i].RemoveConnection(pConn))
		{
			continue;
		}
	}
}

InputPin* Gate::getInputPin(int index)
{
	return &m_InputPins[index - 1];
}

OutputPin* Gate::getOutputPin()
{
	return &m_OutputPin;
}


