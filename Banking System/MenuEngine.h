
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
	std::stack<std::vector<Menu_Interface>> curr_menu;	// we use curr_menu as a tracking of menu state (History stuff)

	bool isValidSelection(char& selection, int& sz, std::stack<std::vector<Menu_Interface>>& curr_menu) {
		int selectionNum = selection - '0';
		bool isB = selection == 'b';

		if (isB && curr_menu.empty()) return false; // if b and stack is empty

		return (isB || (selectionNum >= 1 && selectionNum <= sz));
	}

	void processMenuOption(const Menu_Interface& selected_item, std::vector<Menu_Interface>& menu) {
		auto processing_function = selected_item.p_processing_function;

		if (processing_function != nullptr) {
			curr_menu.push(menu); // push existing menu to stack
			std::vector<Menu_Interface> new_menu = processing_function();
			menu = new_menu;
		}
		else {
			// fallback
		};
	}

	void Init_Menu(std::vector<Menu_Interface>& menu) {
		bool flag = true;
		while (flag) {
			int sz = menu.size();

			for (int i = 0; i < sz; i++) {
				std::cout << menu[i].number << " " << menu[i].value << "\n";
			}

			char selection;
			std::cout << "Please make a selection: \n";
			if(!curr_menu.empty()) std::cout << "Press b to go back: \n";

			std::cin >> selection;

			if (!isValidSelection(selection, sz, curr_menu)) {
				std::cout << "Please Enter a Valid selection: \n";
				std::cin.clear(); // clear buffer 
				while (std::cin.get() != '\n'); // clear stream
			} else if (selection == 'b' && !curr_menu.empty()) {
				menu = curr_menu.top();
				curr_menu.pop();
			} else {
				int selectNum = (selection - '0'); // - '0' makes it ASCII number without loss of static conversion
				const Menu_Interface& selected_item = menu[selectNum - 1];
				processMenuOption(selected_item, menu);
			};
		}
	};
};