
#include "BST_Tester.h"
#include "Experiment.h"
using namespace std;

int main() {
	BST_Tester bstt;
	bstt.runTests();	

	string user_input = "";
	while( user_input != "q" ){
		cout << "\nEnter the .txt file you would like to read from (EX: randomInts01.txt):" << endl;
		cin >> user_input;
		Experiment ex(user_input);
		cout << "The height of the resulting BST is " << ex.getHeight() << endl;
		cout << "There were " << ex.getNumDuplicates() << " duplicate numbers." << endl;
		cout << "Would you like to read from another file? If so, enter 'yes' (if not, enter q to quit)." << endl;
		cin >> user_input;
	}

}
