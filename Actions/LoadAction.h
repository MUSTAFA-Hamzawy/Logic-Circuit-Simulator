#include "../ApplicationManager.h"
#include <fstream>

class LoadAction : public Action
{
private:
	ifstream mRead;

public:
	/* Constructor */
	LoadAction(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~LoadAction();
};
