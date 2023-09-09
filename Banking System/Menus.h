#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include "./MenuEngine.h"

class Menu {
private:
    std::vector<Menu_Interface> menu_items;

public:
    Menu(std::vector<Menu_Interface> menu) : menu_items(menu) {
        std::cout << "Initialised bank_menu with menu \n";
    };

    Menu(Menu&& menu) noexcept : menu_items(menu.menu_items) {
        menu_items = std::move(menu.menu_items);
        std::cout << "move" << std::endl;
        Print_Contents();
    };

    Menu_Interface* getMenuItems() {
        return &menu_items[0];
    }

    void Print_Contents() {
        for (const auto& item : menu_items) {
            std::cout << item.number << " " << item.value << " ";
        }
    }
};