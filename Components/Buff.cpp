#include "Buff.h"

Buff::Buff(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void Buff::Operate()
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
void Buff::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBuff(m_GfxInfo, this->selected);
}

//returns status of outputpin
int Buff::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Buff::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Buff::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

/* Saves the states of the component*/
void Buff::Save(ofstream& file) {
	file << "Buffer " << m_Label << " " << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}


/* Returns the Add-ActionType of the component */
ActionType Buff::GetAddActionType() const {
	return ActionType::ADD_Buff;
}
/* Deletes the component */
void Buff::Delete(Output* pOut) {
	selected = false;
	deleted = true;
	mOutputPin.Delete(pOut);
	for (int i = 0; i < mInputsCount; i++) {
		mInputPins[i].Delete(pOut);
	}
}

/* Restores the component after being deleted */
void Buff::Restore(Output* pOut) {
	deleted = false;
	mOutputPin.Restore(pOut);
	for (int i = 0; i < mInputsCount; i++) {
		mInputPins[i].Restore(pOut);
	}
}