#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <array>

 struct Menu_Interface {
    typedef void(Menu::*Menu_Processing_Function_Ptr)();
    int number;
    std::string value;
    Menu_Processing_Function_Ptr p_processing_function;
  };

  class Menu {
  public:
    std::array<Menu_Interface,3> menu_items;

    void Processor_1() {
      std::cout << "Processing Option 1" << std::endl;
    };

    Menu() : menu_items(initialiseMenu()) {};

    void Home() {
      std::cout << "Todo Home stuff" << std::endl;
    };

    std::array<Menu_Interface, 3> initialiseMenu() {
        Menu_Interface menu_items[3] = {
        {1, "Option 1", &Menu::Home}, // You can provide the processing function here
        {2, "Option 2", nullptr}, // You can provide the processing function here
        {3, "Option 3", nullptr}  // You can provide the processing function here
        };

        return { menu_items[0]};
    };
  };

