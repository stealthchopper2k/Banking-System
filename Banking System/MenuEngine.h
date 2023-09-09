
#include <string>
#include <iostream>
#include <stack>
#include <vector>

struct Menu_Interface;

//typedef std::vector<Menu_Interface>(*Menu_Processing_Function_Ptr)();
using Menu_Processing_Function_Ptr = std::vector<Menu_Interface>(*)();

struct Menu_Interface {
	int number;
	std::string value;
	Menu_Processing_Function_Ptr p_processing_function;
};

class Menu_Engine {
public:
	std::stack<std::vector<Menu_Interface>> curr_menu;	// we use curr_menu as a tracking of menu state so user can go BACK

	void Init_Menu(std::vector<Menu_Interface>& menu) {
		bool flag = true;
		while (flag) {
			int sz = menu.size();

			for (size_t i = 0; i < sz; i++) {
				std::cout << menu[i].number << " " << menu[i].value << "\n";
			}

			int selection;
			std::cout << "Please make a selection: \n";
			std::cin >> selection;

			if (selection > sz || selection < 1 || std::cin.fail()) {
				std::cout << "Please Enter a Valid selection: \n";
				std::cin.clear(); // clear buffer 
				while (std::cin.get() != '\n'); // clear stream
			}
			else if (selection) {
				const Menu_Interface& selected_item = menu[static_cast<size_t>(selection) - 1];
				auto processing_function = selected_item.p_processing_function;

				if (processing_function != nullptr) {
					 
					std::vector<Menu_Interface> new_menu = processing_function();
					//curr_menu.push(&new_menu[0]);
					menu = new_menu;
				}
				else {
					// fallback
				};
				// flag = false; end when card is out, is the bool passed from an application class??
			};
		}
	};
};