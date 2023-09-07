#pragma once
#include <string>
#include <iostream>
#include <vector>

  class Menu_Interface {
  public:
    typedef void(*Menu_Processing_Function_Ptr);
    struct Menu_Item {
      int number;
      std::string value;
      Menu_Processing_Function_Ptr p_processing_function;
    };

    virtual std::vector<Menu_Item> GetMenu() = 0;
  };

  class Menu : public Menu_Interface {
  public:
    std::vector<Menu_Item> menu_items;

    void Processor_1() {
      std::cout << "Processing Option 1" << std::endl;
    };
    void Processor_2() {
      std::cout << "Processing Option 1" << std::endl;
    };

    Menu() : menu_items(initialiseMenu()) {};

    void Home() {
      std::cout << "Todo Home stuff" << std::endl;
    };

    std::vector<Menu_Item> initialiseMenu() {
      std::vector<Menu_Item> items;

      auto homeFunction = [this]() { Home(); }; // Binds the home function to a valid pointer

      items.push_back({ 1, "View Balance", &homeFunction });
      items.push_back({ 2, "Deposit", nullptr });
      items.push_back({ 3, "Withdraw", nullptr });
      return items;
    }
  };