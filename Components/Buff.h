#ifndef _Buff_H
#define _Buff_H

/*
  Class Buff
  -----------
  represent the 1-input Buff gate
*/

#include "Gate.h"

class Buff :public Gate
{
protected:
	int mInputsCount;		// Number of input pins
	Pin* mInputPins;		// Array of input pins
	Pin mOutputPin;			// The output pin of the gate
public:
	Buff(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the Buff gate
	virtual void Draw(Output* pOut, bool selected = false);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
			/* Saves the states of the component*/
	virtual void Save(ofstream& file);
	/* Returns the Add-ActionType of the component */
	virtual ActionType GetAddActionType() const;
	/* Deletes the component */
	virtual void Delete(Output* pOut);
	/* Restores the component after being deleted */
	virtual void Restore(Output* pOut);
};

#endif