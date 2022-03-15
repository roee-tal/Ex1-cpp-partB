	
#include "mat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int main() {
    
    int pick = 0;
    while(pick != -1)
    {
        cout << "Hi! please press 1 to create a carpet, something else to exit" <<endl;
        cin >> pick;
        if(pick == 1)
        {
            int row, col;
            char sign1,sign2;
            cout << "Please enter column number" << endl;
            cin >> col;
            cout << "Now please enter row number" << endl;
            cin >> row;
            cout << "Now please enter the first sign of the carpet" << endl;
            cin >> sign1;
            cout << "Enter the second sign of the carpet" << endl;
            cin >> sign2;
            try {
            cout << ariel::mat(col, row, sign1, sign2) << endl;
            }
            catch (exception& ex) {
                cout << "   caught exception: " << ex.what() << endl; 
            }
        }      
    }
	cout << "Wer'e done!" << endl;
}