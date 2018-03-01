#include <stdio.h>
#include <tchar.h>
#include <cstdlib>
#include "bag.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	bag baglist;
	// Start of my additions ke
	int tempValue;
	int ErrorCatching=0;
	bool badInput;
	// End of my additions ke
	int loop = 0;
	int choice = 0;
	int removedNumber = 0; //Stores number returned by removeRandom() method


	while (loop != 1) {

		// Start of my additions ke
		if (ErrorCatching != 0)
		{
			cin.clear();
			cin.ignore(30000, '\n');
		}
		// End of my additions ke
		int num = 0;
		cout << "\n\n1. Insert\n";
		cout << "2. Remove random node\n";
		cout << "3. Display all values\n";
		cout << "4. Quit\n\n";
		cout << "Please make your choice. \n";
		cout << "Choice: ";
		cin >> choice;
		

		switch (choice) {
		case 1:
			// Start of my additions ke
			badInput = true;
			while (badInput == true)
			{

				cout << "\n\n What Value would you like to add?\n";
				cin >> tempValue;
				ErrorCatching = cin.rdstate();

				if (ErrorCatching != 0)
				{
					cout << "\nThere has been an input error\n";
					badInput = true;
					cin.clear();
					cin.ignore(30000, '\n');
				}
				else
				{
					//if (tempValue == -1)
					//{
						//badInput = false;
					//}
					//else
					//{
						badInput = false;
						num = tempValue;
						baglist.insert(num);
						cout << "\n" << "The value '" << num << "' has successfully been added to the list! \n";
					//}
				}
			}
			// End of my additions kelton

			break;
		case 2:
			//remove random node
			//cout << "\nPlease enter a number: ";
			//cin >> num;
			removedNumber = baglist.removeRandom();
			if (removedNumber == -1) // -1 means the bag is empty
			cout <<"\n\nThe list is empty. There's nothing to remove.\n\n";
			else
			{
				cout << "\n" << "The value '" << removedNumber << "' has successfully been removed from the list! \n\n";
			}
			
			break;
		case 3:
			//display all nodes
			baglist.displayBag();
			break;
		case 4:
			cout << "\nQuitting program...\n";
			//linkedList.displayL();
			loop = 1;
			break;
		default:
			cout << "That is not a choice, please try again. \n" << endl;
			// Start of Additions to fix menu error kelton
			ErrorCatching = 1;
			choice = 0;
			// End of Additions to fix menu error kelton
			break;
		}
	}
	//system("PAUSE");
	return EXIT_SUCCESS;
}
