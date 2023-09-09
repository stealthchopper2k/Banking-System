
#include <string>
#include <iostream>
#include <stack>
#include <vector>

struct Menu_Interface;

typedef std::vector<Menu_Interface>(*Menu_Processing_Function_Ptr)();

struct Menu_Interface {
	int number;
	std::string value;
	Menu_Processing_Function_Ptr p_processing_function;
};

class Menu_Engine {
public:
	// we use curr_menu as a tracking of menu state so user can go BACK
	std::stack<std::vector<Menu_Interface>> curr_menu;

	void Init_Menu(Menu_Interface* menu, unsigned int menu_sz) {
		bool flag = true;

		while (flag) {
			for (int i = 0; i < menu_sz; i++) {
				std::cout << menu[i].number << " " << menu[i].value << "\n";
			}

			int selection;
			std::cout << "Please make a selection: \n";
			std::cin >> selection;

			if (selection > menu_sz || selection < 1 || std::cin.fail()) {
				std::cout << "Please Enter a Valid selection: \n";
				std::cin.clear(); // clear buffer 
				while (std::cin.get() != '\n'); // clear stream
			}
			else if (selection) {
				auto processing_function = menu[selection - 1].p_processing_function;
				if (processing_function != nullptr) {
					std::cout << "running";
					std::vector<Menu_Interface> new_menu = processing_function();

					std::cout << new_menu[0].number << new_menu[0].value << "x";

					//curr_menu.push(&new_menu[0]);
					menu = &new_menu[0];
				}
				else {
					// fallback
				};
				// flag = false; end when card is out, is the bool passed from an application class??
			};
		}
	};
};