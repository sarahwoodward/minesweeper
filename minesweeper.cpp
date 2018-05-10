#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unistd.h>
#include "term.h"
#include "minesweeper.h" 
#include "application.h"
#include "cell.h"
#include <ctime>


using namespace std;
static string defaultMessage = "Arrows to move cursor, Z to mark known bombs";

//constructor
Minesweeper::Minesweeper() : Widget(1, 1, 53, 6)
{	
	
   //sets up the cells
	for (int y=1; y<=18; y++){
   	 	for(int x=1; x<=81; x+=4){
		board.push_back(new Cell(x,y));
		}
	}
	//random see generator
	srand (time(NULL));
	randomize();
    cursor = 0;
	board[cursor]->selected(true);
	toMove=1;

    
    
    //set up initial message
    message = defaultMessage;
}


//destructor
Minesweeper::~Minesweeper() 
{
    //delete all the pegs
    for(int i=0; i<board.size(); i++) {
        delete board[i];
    }
}


void 
Minesweeper::handleEvent(Event *e)
{
    
    if(e->type() != "keyboard") { return; }
    
    //assume the default message
    message=defaultMessage;
    
    KeyboardEvent *k = (KeyboardEvent *) e;
    
    switch(k->key()) {
        case ESC:
            //exit the application
            ((Application *) parent())->running(false);
            break;
            
        case LEFT:
            //move the cursor left
            selectPeg(cursor-1);
            break;
            
        case RIGHT:
            //move the cursor right
            selectPeg(cursor+1);
            break;
            
		case UP:
			//move the cursor up
			selectPeg(cursor-21);
		
			break;
			
		case DOWN:
			//move the cursor down
			selectPeg(cursor+21);
			
			break;
			
        case ENTER:
			//checks if open or bomb
			checkCell(cursor);
			display();
			//ends the game if you win
			if(win()){
			cout<<cursorPosition(15,20)<< "You saved the world. Congrats."<<endl;
				if(cin.get()){
				((Application *) parent())->running(false);
				}
			}
            break;
			
            
        case 'z':
			//makes labels with a $
			makeKnown(cursor);
			if(win()){
			cout<<cursorPosition(15,20)<< "You saved the world. Congrats."<<endl;
				if(cin.get()){
				((Application *) parent())->running(false);
				}
			}
            break;
    
    
	
    display();
			}
		 }

void 
Minesweeper::display()
{
   
	//draw the board
	for(int i=0; i<board.size(); i++){
		board[i]->display();
	}

	
    //display the move marker
  
       cout << cursorPosition(board[toMove]->x()+1, board[toMove]->y() + 1);

    //display the message
    cout << cursorPosition(1,30) << left << setw(width()) << message << right;
    
    //flush the buffer
    cout.flush();
}




//move the cursor to a peg
void 
Minesweeper::selectPeg(int cursor)
{
    //stand firm on invalid moves
    if(cursor < 0 or cursor >= board.size()) {
        return;
    }
    
    //first, we deselect the current peg
   board[this->cursor]->selected(false);
    
    //next, we select our peg
    this->cursor = cursor;
    board[this->cursor]->selected(true);
}


//counts the bombs
void
Minesweeper::count()
{
	
	for(int i=0; i<board.size(); i++){
	int _count=0;
		

		if(i==0 or i==21 or i==42 or i==63 or i==84 or i==105 or i==126 or i==147 or i==168 or i==189 or i==210 or i==231 or i==252 or i==273 or i==294 or i==315 or i==336 or i==357 or i==378){
		countLeftSide(i,_count);
		}
		else if(i==20 or i==41 or i==62 or i==83 or i==104 or i==125 or i==146 or i==167 or i==188 or i==209 or i==230 or i==251 or i==272 or i==293 or i==314 or i==335 or i==356 or i==377){
			countRightSide(i,_count);
		}
		else{
			countAll(i,_count);
			}
		}
	}	
	
	


//check if bomb or not
void
Minesweeper::checkCell(int piece){
	
	if(board[piece]->unchosen()){
		if(board[piece]->isBomb()==false){
				board[piece]->unchosen(false);
				if(board[piece]->getNumber()==0){
					openSpaces(piece);
				}
				
			}else{
				displayEnd();
				cout<<cursorPosition(20,25)<< "YOU LOSE!!";
				if(cin.get()){
					
					}
			}
		}
	}	

//displays if you win
void
Minesweeper::displayEnd(){
	for(int i=0; i<board.size(); i++){
		board[i]->end();
	}
}
//checks if you win
bool
Minesweeper::win(){
	for(int i=0; i<board.size(); i++){
		if (board[i]->isBomb()==false and board[i]->known()==true){
			return false;
		}
		if(board[i]->isBomb()==true and board[i]->known()==false){
			return false;	
		}
		if(board[i]->known()==false and board[i]->isBomb()==true){
		return false;
		}
	}
	return true;
}
//makes known if clicked
void
Minesweeper::makeKnown(int cursor){
	if(board[cursor]->known()==false){
			board[cursor]->known(true);
				}
			else if(board[cursor]->known()==true){
				board[cursor]->known(false);
			}
}

void
Minesweeper::randomize(){

for(int i=0; i<board.size(); i++){
		int v;
		v = rand() % 4;
		cout<<cursorPosition(15,30)<<v;
			board[i]->unchosen(true);
				if(v>0){
				board[i]->isBomb(false);
				}
				if(v==0){
				board[i]->isBomb(true);
			}
	}
	count();
}

void
Minesweeper::countLeftSide(int i, int _count){
			if(i<357){
				if(board[i+21]->isBomb()){
					_count+=1;
					}

			}
			if(i>=21){
				if(board[i-21]->isBomb()){
					_count+=1;
				}
			}
			if(i<377){
				if(board[i+1]->isBomb()){
					_count +=1;
					}
				}
			if(i>=20){
				if(board[i-20]->isBomb()){
					_count+=1;
				}
			}
			

			if(i<356){
				if(board[i+22]->isBomb()){
					_count+=1;
				}
	}
	board[i]->setNumber(_count);
}

void
Minesweeper::countRightSide(int i, int _count){
		if(i>=21){
				if(board[i-21]->isBomb()){
					_count+=1;
				}
			}
			
			if(i>=22){
				if(board[i-22]->isBomb()){
					_count+=1;
				}
		if(i<358){
			if(board[i+20]->isBomb()){
					_count+=1;
					}
				}
			}
			if(i<357){
				if(board[i+21]->isBomb()){
					_count+=1;
					}

			}
			if(i!=0){
				if(board[i-1]->isBomb()){
					_count+=1;
				}
			}
	board[i]->setNumber(_count);			
}

void
Minesweeper::countAll(int i, int _count){
	if(i>=21){
				if(board[i-21]->isBomb()){
					_count+=1;
				}
			}
			if(i>=20){
				if(board[i-20]->isBomb()){
					_count+=1;
				}
			}
			if(i>=22){
				if(board[i-22]->isBomb()){
					_count+=1;
				}

			}		
			if(i!=0){
				if(board[i-1]->isBomb()){
					_count+=1;
				}
			}
			if(i<357){
				if(board[i+21]->isBomb()){
					_count+=1;
					}

			}
			if(i<377){
				if(board[i+1]->isBomb()){
					_count +=1;
					}
				}

			
			if(i<358){
				if(board[i+20]->isBomb()){
					_count+=1;
				}
			}

			if(i<356){
				if(board[i+22]->isBomb()){
					_count+=1;
				} 
			}
			board[i]->setNumber(_count);
		}
void
Minesweeper::openSpaces(int i){
			if(i==0 or i==21 or i==42 or i==63 or i==84 or i==105 or i==126 or i==147 or i==168 or i==189 or i==210 or i==231 or i==252 or i==273 or i==294 or i==315 or i==336 or i==357 or i==378){
				if(i<357){
					board[i+21]->unchosen(false);
					}
				if(i>=21){
					board[i-21]->unchosen(false);
					}
				if(i<377){
					board[i+1]->unchosen(false);
					}
				if(i>=20){
					board[i-20]->unchosen(false);
					}
				if(i<356){
					board[i+22]->unchosen(false);
					}
			}
			else if(i==20 or i==41 or i==62 or i==83 or i==104 or i==125 or i==146 or i==167 or i==188 or i==209 or i==230 or i==251 or i==272 or i==293 or i==314 or i==335 or i==356 or i==377){
						if(i>=21){
							board[i-21]->unchosen(false);
						}

						if(i>=22){
							board[i-22]->unchosen(false);
							}
						if(i<358){
							board[i+20]->unchosen(false);
							
						}
						if(i<357){
							board[i+21]->unchosen(false);

						}
						if(i!=0){
							board[i-1]->unchosen(false);
						}
					
			}else{
						if(i>=21){
							board[i-21]->unchosen(false);
						}
						if(i>=20){
							board[i-20]->unchosen(false);
						}
						if(i>=22){
							board[i-22]->unchosen(false);

						}		
						if(i!=0){
							board[i-1]->unchosen(false);
						}
						if(i<357){
							board[i+21]->unchosen(false);
						}
						if(i<377){
							board[i+1]->unchosen(false);
							}
						if(i<358){
							board[i+20]->unchosen(false);
						}
						if(i<356){
							board[i+22]->unchosen(false);
						}

				}
}
