#include <iostream>
#include "term.h"
#include "minesweeper.h"
#include "application.h"


using namespace std;
bool rules();

int main()
{
    //make the parts
	if(rules()){
	
		Minesweeper *game = new Minesweeper();
		Application *app = new Application();


		//put them together
		app->child(game);

		//and go!
		cout << cursorOff;
		cout.flush();
		app->eventLoop();
		cout << cursorOn << normal << clearScreen << endl;

		return 0;
		}
	}
	

bool rules(){
	
	cout << clearScreen << cursorPosition(10,3);
	cout << "Hello, Welcome to MineSweeper." << endl;
	cout <<	"The rules are simple. If you click a bomb you blow up the world."<< endl;
	cout << "You're objective, do not blow up the world."<<endl;
	cout << "Click" << red << " ENTER " << normal <<  "to reveal whether you are on a bomb or not." << endl;
	cout << "If it is not a bomb, then a number will appear. That is the number of bombs touching it. BE CAREFUL."<<endl;
	cout << "The bomb can be touching from the top, bottom, left, right, or diagonally" <<endl;
	cout << "If you think you know a bomb, click" << blue << " Z " << normal << "to mark it with"<<yellow << " $. "<<normal<< endl;
	cout << "If you mark all bombs or if pick every space that is not a bomb, you win."<< endl;
	cout << "GoodLuck :)"<<endl <<endl;
	cout << "Press" << cyan << " ENTER " << normal << "to play";
	
	
	
	if(cin.get()){
		return true;
	}
}