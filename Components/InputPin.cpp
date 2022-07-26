#include "InputPin.h"

InputPin::InputPin()
{
	conn = NULL;
}

void InputPin::setComponent(Component* pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::removeConnection()
{
	if (conn == NULL)
	{
		return;
	}
	delete conn;
}

bool InputPin::ConnectTo(Connection* c)
{
	conn = c;
	return true;
}
