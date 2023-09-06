#pragma once
#include <string>
#include <iostream>
#include <vector>

class Menu_Interface {
public:
  typedef void (*Menu_Processing_Function_Ptr)();
  struct Menu_Item {
	int number;
	std::string value;
	Menu_Processing_Function_Ptr p_processing_function;
  };

private:
  std::vector <Menu_Item> menu_items;
  Menu_Interface(const std::vector<Menu_Item>& items) : menu_items(items) {};
}