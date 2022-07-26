#ifndef _PIN_H
#define _PIN_H

#include "..\Defs.h"
#include"../GUI/Output.h"
#include <vector>
class Gate;
class Connection;


class Pin
{
protected:
	STATUS m_Status;	//Status of the Pin
	int mFanout;								// Maximum number of connections that can be connected to that pin
	int mConnectionsCount;						// Actual number of connections connected to that pin
	//Gate* mGate;								// Gate at which this pin is associated
	Connection* mConnections[MAX_CONNS];	// Array of connections to be connected to that pin
public:
	Pin();
	void setStatus(STATUS r_Status);
	STATUS getStatus();
	/* Removes the given connection from the pin */
	bool RemoveConnection(Connection* pConnection);
	/* Deletes the pin which removes all connected connections from the pin */
	void Delete(Output* pOut);
	/* Restores the pin after being deleted */
	void Restore(Output* pOut);

};

#endif