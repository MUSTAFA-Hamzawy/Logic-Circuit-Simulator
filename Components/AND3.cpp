#include "AND3.h"

AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND3::Operate()
{
	if (GetInputPinStatus(1) == HIGH && GetInputPinStatus(2) == HIGH && GetInputPinStatus(3) == HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
	//caclulate the output status as the ANDing of the three input pins
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void AND3::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo, this->selected);
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

/* Saves the states of the component*/
void AND3::Save(ofstream& file) {
	file << "AND3 " << m_Label << " " << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}

/* Returns the Add-ActionType of the component */
ActionType AND3::GetAddActionType() const {
	return ActionType::ADD_AND3;
}
/* Deletes the component */
void AND3::Delete(Output* pOut) {
	selected = false;
	deleted = true;
	mOutputPin.Delete(pOut);
	for (int i = 0; i < mInputsCount; i++) {
		mInputPins[i].Delete(pOut);
	}
}

/* Restores the component after being deleted */
void AND3::Restore(Output* pOut) {
	deleted = false;
	mOutputPin.Restore(pOut);
	for (int i = 0; i < mInputsCount; i++) {
		mInputPins[i].Restore(pOut);
	}
}