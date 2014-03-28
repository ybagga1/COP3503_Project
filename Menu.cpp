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
    if (userInput.front() == '1' || 
        userInput.front() == 'C' || 
        userInput.front() == 'c') {
      cout << Entering computing mode." << endl;
      // code in the computing mode here.
    }
    else if (userInput.front() == '2' || 
             userInput.front() == 'H' || 
             userInput.front() == 'h') {
      cout << "Entering help menu." << endl;
      // code in the help menu here.
    }
    else if (userInput.front() == '3' || 
             userInput.front() == 'R' || 
             userInput.front() == 'r') {
      cout << "Entering review mode." << endl;
      // code in the review mode here.
    }
    else if (userInput.front() == '4' || 
             userInput.front() == 'Q' || 
             userInput.front() == 'q') {
      cout << "Quitting..." << end;
      menuloop = 0;
    }
    else {
      cout << "Invalid input." << endl;
    }
  }
}
