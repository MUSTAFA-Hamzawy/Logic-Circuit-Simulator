#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void LED::Operate()
{
	if (GetInputPinStatus(1) == HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void LED::Draw(Output* pOut, bool selected)
{
	pOut->DrawLED(m_GfxInfo, this->selected);
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

/* Saves the states of the component*/
void LED::Save(ofstream& file) {
	file << "LED " << m_Label << " " << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}


/* Returns the Add-ActionType of the component */
ActionType LED::GetAddActionType() const {
	return ActionType::ADD_LED;
}

/* Deletes the component */
void LED::Delete(Output* pOut) {
	selected = false;
	deleted = true;
	InputPin.Delete(pOut);

}

/* Restores the component after being deleted */
void LED::Restore(Output* pOut) {
	deleted = false;
	InputPin.Restore(pOut);

}
