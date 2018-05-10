#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <vector>
#include <string>
#include "widget.h"
#include "cell.h"

class Minesweeper : public Widget
{
public:
    //constructor
    Minesweeper();
	
    
    //destructor
    ~Minesweeper();

    //widget functions
    virtual void handleEvent(Event *e);
    virtual void display();

    //minesweeper functions
    virtual void selectPeg(int cursor);
    virtual void checkCell(int cursor);
	virtual void count();
	virtual void displayEnd();
	virtual bool win();
	virtual void makeKnown(int cursor);
	virtual void randomize();
	virtual void countLeftSide(int i, int _count);
	virtual void countRightSide(int i, int _count);
	virtual void countAll(int i, int _count);
	virtual void openSpaces(int i);
	
 
	
	
	
	
private:
    std::vector<Cell *> board;
    int cursor;  //the cell where the cursor is
    std::string message;//the message to display below the board
	int toMove;
	
};
#endif