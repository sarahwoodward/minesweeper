#include <iostream>
#include "cell.h"
#include "term.h"
#include "termmanip.h"

using namespace std;

//constructors
Cell::Cell() : Cell(0, 0)
{
    //this constructor's work is done by the other version
}


Cell::Cell(int _x, int _y) : Widget(_x, _y, 3, 1)
{
    _color = DEFAULT;
    _present = false;
    _selected = false;
}


//widget functions
void 
Cell::handleEvent(Event *e)
{
    //the peg does not respond to events
}


void 
Cell::display()
{
    //set the cursor position and draw the beginning of the hole
    cout << cursorPosition(x(), y());
    cout << ' ';

    //set the color of the peg
  

    //if it is selected, display in reverse video
    if(selected()) {
        cout << reverseVideo;
    }
	
    //draw the peg itself
   	if(known()){
		cout<<yellow<<'$';
	}
	else if(unchosen()){
		
			cout << '+';
		}
	
	
	else if(unchosen()==false and isBomb()==false){
		cout<<green<<_number;
	}

    //finish out the hole in normal color
    cout << normal << ' ';

    cout.flush();  //all done!
}


//handle peg color
void 
Cell::color(CellColor _color)
{
    this->_color = _color;
    display();
}


CellColor 
Cell::color()
{
    return this->_color;
}


//present is true if there is a peg in this hole
void 
Cell::present(bool _present)
{
    this->_present = _present;
    display();
}


bool 
Cell::present()
{
    return this->_present;
}


//pegs can also be selected, this causes them to 
//display in reverse video
void 
Cell::selected(bool _selected)
{
    this->_selected = _selected;
    display();
}


bool 
Cell::selected()
{
    return this->_selected;
}

void
Cell::isBomb(bool bomb){
	this->bomb = bomb;
}
void
Cell::unchosen(bool _unchosen){
 	this->_unchosen = _unchosen;
}
bool
Cell::isBomb(){
	return this->bomb = bomb;
}
bool
Cell::unchosen(){
 	return this->_unchosen = _unchosen;
}

int
Cell::getNumber(){
	return _number;
}
void
Cell::setNumber(int n){
	_number = n;
}
void
Cell::end(){
 cout << cursorPosition(x(), y());
    cout << '(';

    //set the color of the peg
  

   if(isBomb()){
   cout<<red<<'@';
   }else{
   cout<< ' ';
   }
    //finish out the hole in normal color
    cout << normal << ')';

    cout.flush();  
}
void
Cell::known(bool _known){
 	this->_known = _known;
}
bool
Cell::known(){
 	return this->_known= _known;
}