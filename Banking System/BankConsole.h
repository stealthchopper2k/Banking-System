#include <string>
#include <iostream>

class BankConsole {
public:
  void Menu() {
	std::cout << "Banking Application \n";
	bool flag = true;
	int choice;

	std::cout << "1. Withdraw \n";
	std::cout << "2. Deposit \n";
	std::cout << "3. See Balance \n";
	std::cout << "Enter to Select Your Choice \n";

	std::cin >> choice;

	switch (choice) {
	case 1:
	  std::cout << "You have selected Withdraw";
	  break;
	case 2:
	  std::cout << "You have selected Deposit";
	  break;
	case 3:
	  std::cout << "You have selected Balance";
	  break;
	default:
	  std::cout << "Please Select a Valid Choice";
	};
  };
};