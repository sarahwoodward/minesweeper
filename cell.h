#ifndef CELL_H
#define CELL_H
#include "widget.h"

enum CellColor { DEFAULT, RED, BLUE, GREEN, YELLOW };

class Cell : public Widget
{
public:
    //constructors
    Cell();
    Cell(int _x, int _y);

    //widget functions
    virtual void handleEvent(Event *e);
    virtual void display();

    //handle peg color
    virtual void color(CellColor _color);
    virtual CellColor color();

    //present is true if there is a peg in this hole
    virtual void present(bool _present);
    virtual bool present();

    //pegs can also be selected, this causes them to 
    //display in reverse video
    virtual void selected(bool _selected);
    virtual bool selected();
	virtual void unchosen(bool _unchosen);
	virtual void isBomb(bool bomb);
	virtual bool unchosen();
	virtual bool isBomb();
	virtual int getNumber();
	virtual void setNumber(int n);
	virtual void end();
	virtual void known(bool _known);
	virtual bool known();

private:
    CellColor _color;  //the peg's color
    bool _present;    //whether it is filled or not
    bool _selected; //whether or not it is selected
	bool bomb;
	bool _unchosen;
	int _number;
	bool _known;
	
	
};

#endif
