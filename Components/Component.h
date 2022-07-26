#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include<fstream>

//Base class for classes Gate, Switch, and LED.
class Component
{
private:

protected:
	string m_Label;
	bool selected;
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool deleted;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut, bool selected = false) = 0;	//for each component to Draw itself
	
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
		// Saves the states of the component 
	virtual void Save(ofstream& file) = 0;
	// Returns whether the component is deleted or not 
	bool IsDeleted() const;
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
	virtual GraphicsInfo getGxfInfo();
	virtual void setSelected(bool sel);
	virtual bool isSelected();
	void removeGraphics();
	/* Returns the Add-ActionType of the component */
	//virtual ActionType GetAddActionType() const = 0;
	/* Deletes the component */
	virtual void Delete(Output* pOut) = 0;
	/* Restores the component after being deleted */
	virtual void Restore(Output* pOut) = 0;
	void setLabel(string l);
	bool isLabeld();           // check that this component has a label
	void removeLabel();
};

#endif
