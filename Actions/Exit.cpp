#include "Exit.h"

/* Constructor */
Exit::Exit(ApplicationManager* pAppMan) : Action(pAppMan) {

}

/* Reads parameters required for action to execute */
void Exit::ReadActionParameters()
{
	ifstream originalFile, backUpFile;

	originalFile.open("Data.txt");
	backUpFile.open("BackUp.txt");

	if (!originalFile.is_open() || !backUpFile.is_open()) {
		;
	}

	string s1, s2;

	while (!originalFile.eof() && !backUpFile.eof()) {
		std::getline(originalFile, s1);
		std::getline(backUpFile, s2);

		if (s1 != s2) {
			originalFile.close();
			backUpFile.close();
		}

	}
	originalFile.close();
	backUpFile.close();
}

/* Executes action */
void Exit::Execute() {
	mWrite.open("BackUp.txt");
	mWrite.clear();
	pManager->Save(mWrite);
	mWrite << "-1\n";
	mWrite.close();
}

/* Undo action */
void Exit::Undo() {
	return;
}

/* Redo action */
void Exit::Redo() {
	return;
}

/* Destructor */
Exit::~Exit() {
	mWrite.close();
}