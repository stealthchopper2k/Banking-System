#pragma once
#include <string>
#include <iostream>

class Menu_Engine {
public:
  typedef void (*Menu_Processing_Function_Ptr)();
  struct Menu_Item {
	int number;
	std::string value;
	Menu_Processing_Function_Ptr p_processing_function;
  };

  void Fallback_Fn() {

  }

  void Init_Menu(Menu_Item* menu, unsigned int menu_sz) {
	bool flag = true;

	for (int i = 0; i < menu_sz; i++) {
	  std::cout << menu[i].number << " " << menu[i].value << "\n";
	}

	int selection;
	std::cout << "Please make a selection: \n";

	while (flag) {
	  std::cin >> selection;

	  if (selection > menu_sz || selection < 1 || std::cin.fail()) {
		std::cout << "Please Enter a Valid selection: \n";
		std::cin.clear(); // clear buffer 
		while (std::cin.get() != '\n'); // clear stream
	  }
	  else if (selection) {
		Menu_Processing_Function_Ptr processing_function = menu[selection - 1].p_processing_function;

		if (processing_function != nullptr) {
		  processing_function();
		}
		else {
		  Fallback_Fn();
		};
		flag = false;
	  };
	}
  };
};


void Processor_1() {
  std::cout << "Processing Option 1" << std::endl;
}

void Processor_2() {
  std::cout << "Processing Option 2" << std::endl;
}

void Processor_3() {
  std::cout << "Processing Option 3" << std::endl;
}


Menu_Engine::Menu_Item menu[] = {
	   {1, "First", &Processor_1},
	   {2, "Second", &Processor_2},
	   {3, "Three", &Processor_3}
};

unsigned int menu_sz = sizeof(menu) / sizeof(menu[0]);