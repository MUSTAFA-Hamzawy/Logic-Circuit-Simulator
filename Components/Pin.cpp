#include "Pin.h"
#include "..\Components\Gate.h"
#include "..\Components\Connection.h"
Pin::Pin()
{
	m_Status = LOW;	//Default Status is LOW
}

void Pin::setStatus(STATUS r_Status)
{
	m_Status = r_Status;
}

STATUS Pin::getStatus()
{
	return m_Status;
}

/* Removes the given connection from the pin */
/* Removes the given connection from the pin */
bool Pin::RemoveConnection(Connection* pConnection) 
{
	int idx = -1;

	// Searching for the given connection
	for (int i = 0; i < mConnectionsCount; i++) {
		if (mConnections[i] == pConnection) {
			idx = i;
			break;
		}
	}

	if (idx == -1) return false;	// The given connection was not found

	// Removing the given connection from the pin
	mConnectionsCount--;

	for (int i = idx; i < mConnectionsCount; i++) {
		mConnections[i] = mConnections[i + 1];
	}

	mConnections[mConnectionsCount] = NULL;

	return true;
}

/* Deletes the pin which removes all connected connections from the pin */
void Pin::Delete(Output* pOut) {

	for (int i = mConnectionsCount - 1; i >= 0; i--) {
		mConnections[i]->Delete(pOut);
	}
}

/* Restores the pin after being deleted */
void Pin::Restore(Output* pOut) {
	for (int i = mConnectionsCount - 1; i >= 0; i--) {
		mConnections[i]->Restore(pOut);
	}
}

