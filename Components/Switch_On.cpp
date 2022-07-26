#include"Switch_On.h"


Switch_On::Switch_On(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_OutputPin.setStatus(HIGH);
}


void Switch_On::Operate()
{

	m_OutputPin.setStatus(HIGH);
	//Add you code here
}


// Function Draw

void Switch_On::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSwitch(m_GfxInfo, true);
}

//returns status of outputpin
int Switch_On::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Switch_On::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Switch_On::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

/* Saves the states of the component*/
void Switch_On::Save(ofstream& file) {
	file << "Switch_on " << m_Label << " " << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}

/* Returns the Add-ActionType of the component */
ActionType Switch_On::GetAddActionType() const {
	return ActionType::ADD_SwitchOn;
}

/* Deletes the component */
void Switch_On::Delete(Output* pOut) {
	selected = false;
	deleted = true;
	mOutputPin.Delete(pOut);
}


/* Restores the component after being deleted */
void Switch_On::Restore(Output* pOut) {
	deleted = false;
	mOutputPin.Restore(pOut);

}