#include"Switch_Off.h"


Switch_Off::Switch_Off(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void Switch_Off::Operate()
{
	m_OutputPin.setStatus(LOW);

	//Add you code here
}


// Function Draw

void Switch_Off::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSwitch(m_GfxInfo);
}

//returns status of outputpin
int Switch_Off::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Switch_Off::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Switch_Off::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

/* Saves the states of the component*/
void Switch_Off::Save(ofstream& file) {
	file << "Switch_Off " << m_Label << " " << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}

/* Returns the Add-ActionType of the component */
ActionType Switch_Off::GetAddActionType() const {
	return ActionType::ADD_SwitchOff;
}

/* Deletes the component */
void Switch_Off::Delete(Output* pOut) {
	selected = false;
	deleted = true;
	mOutputPin.Delete(pOut);
}

/* Restores the component after being deleted */
void Switch_Off::Restore(Output* pOut) {
	deleted = false;
	mOutputPin.Restore(pOut);

}