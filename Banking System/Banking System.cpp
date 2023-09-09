#include <iostream>
#include <vector>
#include "./Menus.h"

std::vector<Menu_Interface> Withdraw() {
    std::vector<Menu_Interface> menu;

    menu.push_back({ 1, "10", nullptr });
    menu.push_back({ 2, "20", nullptr });

    return menu;
};

Menu getMenu() {
    std::vector<Menu_Interface> menu_items;

    menu_items.push_back({ 1, "View Balance", nullptr});
    menu_items.push_back({ 2, "Withdraw", &Withdraw });

    Menu menu(menu_items);

    return menu;
};


int main() {
    Menu main_menu = getMenu();
    Menu_Engine menu_engine;


    menu_engine.Init_Menu(main_menu.getMenuItems(), 2);

	std::cout << "its gonna be fine \n";
}

