#include <iostream>
#include <stdexcept>
#include "Operations.h"
#include "Shunting.h"
#include "Number.h"

using namespace std;
int main() {
  int menuLoop = 1;
  string userInput;
  while (menuLoop == 1) {
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Expression Calculator Project" << endl;
    cout << "By: Yayati Bagga, Nick Diez, Kayleigh Dvorak, Mathew Giaramite, Freddy Jimenez" << endl;
    cout << endl;
    cout << "Main Menu:" << endl;
    cout << "1. Compute New Expression" << endl;
    cout << "2. Help" << endl;
    cout << "3. Review" << endl;
    cout << "4. Quit" << endl;
    cout << endl;
    cout << "Enter an option from the menu:" << endl;
    cin >> userInput;
    if (userInput.at(0) == '1' || 
        userInput.at(0) == 'C' || 
        userInput.at(0) == 'c') {
      cout << "Entering computing mode." << endl;
      // code in the computing mode here.
    }
    else if (userInput.at(0) == '2' || 
             userInput.at(0) == 'H' || 
             userInput.at(0) == 'h') {
		cout << "Entering help menu..." << endl;
		cout << string(5, '\n');
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "Compute: Allows the user to enter an expression for computation." << endl;
		cout << "Help: Brings the user to the help menu." << endl;
		cout << "Review: Allows the user to enter the program's review mode in order" << endl;
		cout << "to review past entries and/or request a decimal answer form." << endl;
		cout << "Quit: Closes the program." << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		cout << string(5, '\n');
    }
    else if (userInput.at(0) == '3' || 
             userInput.at(0) == 'R' || 
             userInput.at(0) == 'r') {
      cout << "Entering review mode." << endl;
      // code in the review mode here.
    }
    else if (userInput.at(0) == '4' || 
             userInput.at(0) == 'Q' || 
             userInput.at(0) == 'q') {
      cout << "Quitting..." << endl;
      menuLoop = 0;
    }
    else {
      cout << "Invalid input." << endl;
    }
  }
}
