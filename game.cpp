#include "game.hpp"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <vector>

// Define start position and map variables
int x = 1;
int y = 1;

char map[15][46] = {
    "#############################################",
    "#P    !      ?#             ?#   ?#         #",
    "#     #       #    ###########   ?#?    ?#  #",
    "#   ? #       !              # ###########  #",
    "####################         #    !         #",
    "#            !               #    #         #",
    "#?  ?#       # ?            ?#    #######!###",
    "######       #################    #?       ?#",
    "#            #?              #    ##!########",
    "#?  ?#       #               !    #?     ? ?#",
    "######       !               #    ###### ####",
    "#?  ?#       #       ######  #    #         #",
    "#    ####### #       #       #    #         #",
    "#?           #   ?   #?  ?   #    #        !!",
    "#############################################",
};

// Define constructors and destructors
game::game(std::string new_name, std::string new_description, std::string new_race, std::vector<game> new_items, int new_health, int new_attack, int new_defence)
{
    name = new_name;
    description = new_description;
    race = new_race;
    health = new_health;
    attack = new_attack;
    defence = new_defence;
}

game::~game()
{
}

// Define functions
void game::change_health(int new_health)
{
    health = new_health;
}

void game::change_attack(int attack_bonus)
{
    attack = attack + attack_bonus;
}

void game::change_defence(int defence_bonus)
{
    defence = defence + defence_bonus;
}

void game::new_items(game new_item)
{
    inventory.push_back(new_item);
}

// Define player movement by assigning characters to map coordinates
void game::move(int vertical, int horizontal)
{
    int y2 = y + vertical;
    int x2 = x + horizontal;
    if (map[y][x2] == ' ')
    {
        map[y][x] = ' ';
        x = x2;
        map[y][x] = 'P';
    } 
    else if (map[y][x2] == '?')
    {
        map[y][x] = ' ';
        x = x2;
        map[y][x] = '+';
    }
    else if (map[y][x2] == '!')
    {
        map[y][x] = ' ';
        x = x2;
        map[y][x] = '*';
    }
    if (map[y2][x] == ' ')
    {
        map[y][x] = ' ';
        y = y2;
        map[y][x] = 'P';
    }
    else if (map[y2][x] == '?')
    {
        map[y][x] = ' ';
        y = y2;
        map[y][x] = '+';
    }
    else if (map[y2][x] == '!')
    {
        map[y][x] = ' ';
        y = y2;
        map[y][x] = '*';
    }
}

// Returns damage dealt each turn
int combat(game player, game enemy)
{
    int damage = player.attack + (rand() % 6) - enemy.defence;
    if (damage < 0)
    {
        damage = 0;
    }
    return damage;
}

// Returns random item from items list
game loot(std::vector<game> items)
{
    game item = items[(rand() % items.size())];
    std::cout << item.name << ": " << item.description << "\n";
    std::cout << item.health << "  " << item.attack << "  " << item.defence << "\n";
    return item;
}

// Assigns attribute values dependent on race chosen
game character_creator(std::string player_name, std::string race)
{
    if (race == "Human")
    {
        game player(player_name, "player", race, {}, 22, 5, 6);
        return player;    
    }
    if (race == "Elf")
    {
        game player(player_name, "player", race, {}, 20, 5, 6);
        return player;    
    }
    else if (race == "Dwarf")
    {
        game player(player_name, "player", race, {}, 20, 5, 8);
        return player;    
    }
    else if (race == "Halfling")
    {
        game player(player_name, "player", race, {}, 18, 5, 5);
        return player;
    }
}

