#include "Connection.h"
#include "../Components/InputPin.h"
#include "../Components/OutputPin.h"

Connection::Connection(const GraphicsInfo& r_GfxInfo) : Component(r_GfxInfo)
{
	isSimMode = false;
	m_Label = "empty";
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	
	SrcPin = pSrcPin;
	pSrcPin->ConnectTo(this);
}

OutputPin* Connection::getSourcePin()
{	
	return SrcPin;
}


void Connection::setDestPin(InputPin *pDstPin)
{	
	DstPin = pDstPin;
	pDstPin->ConnectTo(this);
	
}

InputPin* Connection::getDestPin()
{	
	return DstPin;
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus(SrcPin->getStatus());
}

void Connection::Draw(Output* pOut, bool selected)
{
	if (get_IsSimMode())
	{
		pOut->DrawConnectionInSimMode(m_GfxInfo, this->getSourcePin()->getStatus());
	}
	else
	{
		pOut->DrawConnection(m_GfxInfo, selected);
	}
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}


string Input::GetSrting(Output* pOut,string Text, double x, double y)
{
	string originalText = Text;
	string text = "";
	char testingInput;

	do {
		pOut->PrintMsg(originalText + text);
		pWind->WaitKeyPress(testingInput);

		if (int(testingInput) == 8)     // for Backspace ASCII = 8
		{
			if (text != "")           // if text wasn't empty
			{
				text.pop_back();     // pop --> built in fuction for string to delete the last char in it
			}
			else
			{
				pOut->PrintMsg("Error, you are trying to delete empty text !");  // if user trying to delete in the start
			}
		}
		else if (int(testingInput) == 27)    // for Escape ASCII = 27
		{
			text = " ";        // return empty text
			return text;
		}
		else if (int(testingInput == 13))
		{
			pWind->DrawString(x, y, text);
			return text;
		}
		else
		{
			text.push_back(testingInput);  // normal case, add this char to text
		}
	} while (int(testingInput) != 27);// continue in entering char while user didn't press Esc (ASCII 27)
	return text;
}


/* Saves the states of the component*/
void Connection::Save(ofstream& file) {
	file << "CONNECTION " << m_Label << ' ';
	file << m_GfxInfo.x1 << ' ' << m_GfxInfo.y1 << ' ' << m_GfxInfo.x2  << ' ' << m_GfxInfo.y2 << endl;
}

/* Deletes the component */
void Connection::Delete(Output* pOut) {
	selected = false;
	deleted = true;
	SrcPin->RemoveConnection(this);
	DstPin->RemoveConnection(this);
}
void Connection::set_IsSimMode(bool value)
{
	isSimMode = value;
}
bool Connection::get_IsSimMode()
{
	return isSimMode;
}

/* Restores the component after being deleted */
void Connection::Restore(Output* pOut) {
	deleted = false;
	SrcPin->ConnectTo(this);
	DstPin->ConnectTo(this);
}
