#ifndef CONST_H
#define CONST_H
using namespace std;
#include<string>
//This header file contains some defenitions to be used all over the application
class Component;	// Forward class declaration
//All possible actions
enum ActionType
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND2,		//Add 2-input AND gate
	ADD_OR2,		//Add 2-input OR gate
	ADD_NAND2,	//Add 2-input NAND gate
	ADD_NOR2,		//Add 2-input NOR gate
	ADD_XOR2,		//Add 2-input XOR gate
	ADD_XNOR2,	//Add 2-input XNOR gate
	ADD_AND3,		//Add 3-input AND gate
	ADD_NOR3,		//Add 3-input NOR gate
	ADD_XOR3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_WIRE,		//Add Wire Connection
	ADD_SwitchOn,
	ADD_SwitchOff,
	ADD_Label,			//Add Label to a Component, a Connection
	ADD_Edit,
	ADD_DEL,
	ADD_Select,
	ADD_COPY,
	ADD_CUT,
	ADD_PASTE,
	ADD_UNDO,
	ADD_REDO,
	ADD_PLAY,
	ADD_PAUSE,
	

	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file
	COPY,
	CUT,
	PASTE,
	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};


enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_Buff,	     	//ITM 1-input Buffer gate
	ITM_INV,			//ITM 1-input Inverter gate
	ITM_AND2,		//AND gate item in menu
	ITM_OR2,		//OR gate item in menu
	ITM_NAND2,	//ITM 2-input NAND gate
	ITM_NOR2,		//ITM 2-input NOR gate
	ITM_XOR2,		//ITM 2-input XOR gate
	ITM_XNOR2,	//ITM 2-input XNOR gate
	ITM_AND3,
	ITM_NOR3,		//ITM 3-input NOR gate
	ITM_XOR3,		//ITM 3-input XOR gate
	ITM_WIRE,	 //ITM Switch
	ITM_SwitchOn,
	ITM_SwitchOff,
	ITM_LED,			//ITM LED
	ITM_Select,
	ITM_Label,
	ITM_Edit,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_DELETE,
	ITM_UNDO,
	ITM_REDO,
	ITM_PLAY,
	ITM_PAUSE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_EXIT,
	//Exit item
	//TODO: ITM more items names here

	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum

};


enum ToolBarItem {
	/*ITM_EDIT,
	ITM_DELETE,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_UNDO,
	ITM_REDO,
	ITM_PLAY,
	ITM_PAUSE,
	ITM_TRUTHTABLE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_Exit,*/

	TOOLS_COUNT,
};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5, //Default fan out of 2-input AND gate
	Buff_FANOUT = 5,			//Add 1-input Buffer gate
	INV_FANOUT = 5,			//Add 1-input Inverter gate
	OR2_FANOUT = 5,		//Add 2-input OR gate
	NAND2_FANOUT = 5,	//Add 2-input NAND gate
	NOR2_FANOUT = 5,		//Add 2-input NOR gate
	XOR2_FANOUT = 5,		//Add 2-input XOR gate
	XNOR2_FANOUT = 5,	//Add 2-input XNOR gate
	AND3_FANOUT = 5,		//Add 3-input AND gate
	NOR3_FANOUT = 5,		//Add 3-input NOR gate
	XOR3_FANOUT = 5,		//Add 3-input XOR gate
	LED_FANOUT = 5			//Add LED
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1, y1, x2, y2;
};

/* Type of what the pin is containing */
enum PinType {
	EMPTY,						// Empty pin
	GATE,						// Pin containing gate, switch or led
	HOR_CONNECTION,				// Pin containing horizontal connection
	VER_CONNECTION,				// Pin containing vertical connection
	INTERSECTING_CONNECTIONS	// Pin containing intersecting horizontal and vertical connections
};

/* Infromation of what the pin is containing */
struct PinInfo {
	PinType Type;
	Component* Comp;

	PinInfo() {
		Type = PinType::EMPTY;
		Comp = NULL;
	}
};


/* Structure holding the loaded information needed for creating new components */
struct Data {
	string Label;
	GraphicsInfo GfxInfo;
};

/* Structure holding the index of a pin, used in calculating the path of the connection */
struct Node {
	int x, y;	// The X and Y indices of the pin

	/* Zero-argument constructor */
	Node() {
		x = y = -1;		// Invalid indices as default value
	}

	/* Constructor for ease of access */
	Node(int x, int y) {
		this->x = x;
		this->y = y;
	}

	/* Equality operator for ease of access */
	bool operator==(const Node& rhs) const {
		return (x == rhs.x && y == rhs.y);
	}

	/* Non-equality operator for ease of access */
	bool operator!=(const Node& rhs) const {
		return (x != rhs.x || y != rhs.y);
	}
};
#ifndef NULL
#define NULL 0
#endif

#endif