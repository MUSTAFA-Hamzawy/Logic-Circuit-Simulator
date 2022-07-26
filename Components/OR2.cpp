#include "OR2.h"

OR2::OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void OR2::Operate()
{
	if (GetInputPinStatus(1) == LOW && GetInputPinStatus(2) == LOW)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);
	//caclulate the output status as the ORing of the two input pins
	//Add you code here
}


// Function Draw
// Draws 2-input OR gate
void OR2::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR2(m_GfxInfo, this->selected);
}

//returns status of outputpin
int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

/* Saves the states of the component*/
void OR2::Save(ofstream& file) {
	file << "OR " << m_Label << " " << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}

/* Returns the Add-ActionType of the component */
ActionType OR2::GetAddActionType() const {
	return ActionType::ADD_OR2;
}

/* Deletes the component */
void OR2::Delete(Output* pOut) {
	selected = false;
	deleted = true;
	mOutputPin.Delete(pOut);
	for (int i = 0; i < mInputsCount; i++) {
		mInputPins[i].Delete(pOut);
	}

}

/* Restores the component after being deleted */
void OR2::Restore(Output* pOut) {
	deleted = false;
	mOutputPin.Restore(pOut);
	for (int i = 0; i < mInputsCount; i++) {
		mInputPins[i].Restore(pOut);
	}

}