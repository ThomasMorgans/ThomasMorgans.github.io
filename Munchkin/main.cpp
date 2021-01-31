#include "game.hpp"
#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>

// Intialise game variables
bool game_running = true;
bool setup = true;
bool valid_race = false;
std::string player_name;
std::string race;
int inventory_size = 0;

int main()
{ 
// Setup player character
    while (setup)
    {
        std::cout << "You there, what is your name?\n";
        std::cin >> player_name;
        while (!valid_race)
        {
            std::cout << "\nAnd what are you exactly? Human, Elf, Dwarf or Halfling?\n";
            std::cout << "Humans are handy all round, elves regenerate health, dwarves have good stats and halflings are exceptional at finding extra loot.\n";
            std::cout << "(Include the capital letter at the start of your chosen race i.e. Human.)\n";
            std::cin >> race;
            if (race == "Human" || race == "Elf" || race == "Dwarf" || race == "Halfling")
            {
                valid_race = true;
            }
            else
            {
                valid_race = false;
            }
            
        }
        std::cout << "Welcome " << player_name << " to my basement. I have brought you here so that you can clear out my dungeons of dragons\n";
        std::cout << "(how original) and other such nuisances. These are appropriately labelled ! on your map, and you will not be allowed\n";
        std::cout << "to leave until all the little pests have been vanquished. Some of these creatures might be hard for a beginner such as\n";
        std::cout << "yourself to handle, so I would advise finding some tools to help you. On the map ?s represent potential loot, but \n";
        std::cout << "beware, some of these may hide a nasty surprise.\n";
        system("pause");
        setup = false;
    }
    
// Intialise game objects
    game player = character_creator(player_name, race);
    int start_health = player.get_health();

    game tibbles("Mr Tibbles", "A cute and cuddly pet who wants nothing more than an adoring owner.", "", {}, 5, 3, 2);
    game clifford("Clifford the Big Red Dog", "Not sure his bark is worse than his bite...", "", {}, 30, 8, 4);
    game ex("Your ex", "How has the most bloodthirsty creature of all time wound up down here. This could get ugly.", "", {}, 12, 5, 4);
    game goblin("Goblin git", "A rude and solitary goblin, commonly known to science as a git.", "", {}, 15, 4, 4);
    game teenage_turtle("Teenage Mutant Ninja Turtle", "Cowabunga!", "", {}, 12, 9, 6);
    game rat("Escaped lab rat", "Its HUGE! You wonder what they are feeding these things.", "", {}, 4, 3, 2);
    game dragon("Dragon", "Well obviously there was gonna be a dragon.", "", {}, 40, 20, 20);
    std::vector<game> monsters = {tibbles, ex, goblin};
    std::vector<game> boss = {rat, teenage_turtle, clifford, dragon};
       
    game stick("Pointy stick of death", "Does what it says on the tin.", "", {}, 0, 3, 0);
    game club("Club of strategy", "Large wooden club to bash someone over the head with.", "", {}, 0, 5, 0);
    game calpol("Calpol", "Ahhhh, that's the good stuff.", "", {}, start_health, 0, 0);
    game plaster("Sticky plaster", "Just whack a plaster over it.", "", {}, start_health, 0, 0);
    game shield("Tom Hardy shield", "He's pretty hard.", "", {}, 0, 0, 10);
    game staff("Wooden staff of napalm", "You really shouldn't mix wood and fire.", "", {}, 0, 10, 0);
    game hat("Pointy elf hat", "To accomodate the pointy ears.", "", {}, 0, 0, 2);
    std::vector<game> items = {stick, club, calpol, plaster, shield};

// Run game    
    while (game_running == true)
    { 

        system("cls");

// Print out map
        for (int i = 0; i < 15; i++)
        {
            std::cout << map[i] << "\n";
        }
        for (int i = 0; i < 1; i++)
        {
            std::cout << "Race: " << player.get_race() << " ";
            std::cout << " Health: " << player.get_health() << " ";
            std::cout << " Attack: " << player.get_attack() << " ";
            std::cout << " Defence: " << player.get_defence() << "\n";
            std::cout << "Inventory: \n";
            for (int j = 0; j < player.get_inventory().size(); j++)
            {
                std::cout << player.get_inventory()[j].get_name() << "\n";
            }
        }

// Combat and loot
        if (map[y][x] == '+')
        {
            game enemy = monsters[(rand() % monsters.size())];
            std::cout << enemy.get_name() << ": " << enemy.get_description() << "\n";
            while (player.get_health() > 0 && enemy.get_health() > 0)
            {
                std::cout << "Your turn to attack\n";
                system("pause");
                int damage = combat(player, enemy);
                enemy.change_health(enemy.get_health() - damage);
                std::cout << player.get_name() << " dealt " << damage << " damage\n";
                std::cout << enemy.get_name() << ": " << enemy.get_health() << "\n";
                damage = combat(enemy, player);
                player.change_health(player.get_health() - damage);
                std::cout << enemy.get_name() << " dealt " << damage << " damage\n";
                std::cout << player.get_name() << ": " << player.get_health() << "\n";
            }
            map[y][x] = 'P';
            if (player.get_health() > 0)
            {
                std::cout << "Well done, you defeated " << enemy.get_name() << ".\n";
                std::cout << "You may now loot the room.\n"; 
                game item = loot(items);
                if (item.get_health() > 0)
                {
                    player.change_health(start_health);
                }
                else if (item.get_health() == 0 && inventory_size < 6)
                {
                    player.new_items(item);
                    inventory_size ++;
                    player.change_attack(item.get_attack());
                    player.change_defence(item.get_defence());
                }
                for (int i = 0; i < player.get_inventory().size(); i++)
                {
                    if (item.get_attack() > player.get_inventory()[i].get_attack() > 0 && inventory_size == 6)
                    {
                        player.get_inventory()[i] = item;
                        player.change_attack(item.get_attack());
                    }
                    else if (item.get_defence() > player.get_inventory()[i].get_defence() > 0 && inventory_size == 6)
                    {
                        player.get_inventory()[i] = item;
                        player.change_defence(item.get_defence());
                    }
                }
            }  
            else if (player.get_health() <= 0)
            {
                std::cout << "You have been defeated. Rather embarassing if you ask me.\n";
            }
// Halfling ability
            if (player.get_race() == "Halfling")
            {
                game item_2 = loot(items);
                if (item_2.get_health() > 0)
                {
                    player.change_health(start_health);
                }
                else if (item_2.get_health() == 0 && inventory_size < 6)
                {
                    player.new_items(item_2);
                    inventory_size ++;
                    player.change_attack(item_2.get_attack());
                    player.change_defence(item_2.get_defence());
                }
                for (int i = 0; i < player.get_inventory().size(); i++)
                {
                    if (item_2.get_attack() > player.get_inventory()[i].get_attack() > 0 && inventory_size == 6)
                    {
                        player.get_inventory()[i] = item_2;
                        player.change_attack(item_2.get_attack());
                    }
                    else if (item_2.get_defence() > player.get_inventory()[i].get_defence() > 0 && inventory_size == 6)
                    {
                        player.get_inventory()[i] = item_2;
                        player.change_defence(item_2.get_defence());
                    }
                }
            }  
        }
// Boss fights "!"
        else if (map[y][x] == '*')
        {
            game enemy = boss[0];
            std::cout << enemy.get_name() << ": " << enemy.get_description() << "\n";
            while (player.get_health() > 0 && enemy.get_health() > 0)
            {
                std::cout << "Your turn to attack\n";
                system("pause");
                int damage = combat(player, enemy);
                enemy.change_health(enemy.get_health() - damage);
                std::cout << player.get_name() << " dealt " << damage << " damage\n";
                std::cout << enemy.get_name() << ": " << enemy.get_health() << "\n";
                damage = combat(enemy, player);
                player.change_health(player.get_health() - damage);
                std::cout << enemy.get_name() << " dealt " << damage << " damage\n";
                std::cout << player.get_name() << ": " << player.get_health() << "\n";
            }
            map[y][x] = 'P';
            if (player.get_health() > 0)
            {
                std::cout << "Well done, you defeated " << enemy.get_name() << ".\n";
                boss.erase(boss.begin());
            }
            else if (player.get_health() <= 0)
            {
                std::cout << "You have been defeated. Rather embarassing if you ask me.\n";
            }
        }

// Elf ability
        if (player.get_race() == "Elf" && player.get_health() > 0)
        {
            player.change_health(start_health); 
        }

        system("pause>nul");

// Player movement
        if (GetAsyncKeyState(VK_DOWN))
        {
            player.move(1, 0);
        } 
        else if (GetAsyncKeyState(VK_UP))
        {
            player.move(-1, 0);
        } 
        else if (GetAsyncKeyState(VK_LEFT))
        {
            player.move(0, -1);
        } 
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            player.move(0, 1);
        }

// Check if the game has been completed
        int count = 0;
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (map[i][j] == '!')
                {
                    count ++;
                }
            }
        }
        if (count == 0)
        {
            std::cout << "Congratulations, you have won!";
            system("pause");
            game_running = false;
        } 
        else if (player.get_health() <= 0)
        {
            game_running = false;
        }
        else
        {
            game_running = true;
        }
        
    }
}

