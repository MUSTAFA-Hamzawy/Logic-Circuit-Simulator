#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "Pin.h"
#include"../GUI/Output.h"


class Component; //Forward class declaration
class Connection;

class InputPin : public Pin	//inherited from class Pin
{
	Component* pComp; //Component at which this pin is associated
	Connection* conn;
public:
	InputPin();
	void setComponent(Component* pCmp);	//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin
	bool ConnectTo(Connection* c);
	void removeConnection();
};

#endif