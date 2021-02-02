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
        std::cout << "Welcome " << player_name << " to my dungeon. I have brought you here so that you can clear out my dungeons of dragons\n";
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

    game tibbles("Mr Tibbles the cat", "A cute and cuddly pet who wants nothing more than an adoring owner.", "pet", {}, 8, 4, 3);
    game clifford("Clifford the Big Red Dog", "Not sure his bark is worse than his bite...", "pet", {}, 18, 10, 7);
    game ex("Your ex", "How has the most bloodthirsty creature of all time wound up down here. This could get ugly.", "", {}, 16, 6, 5);
    game goblin("Goblin git", "A rude and solitary goblin, commonly known to science as a git.", "", {}, 15, 6, 5);
    game teenage_turtle("Teenage Mutant Ninja Turtle", "Cowabunga!", "", {}, 9, 9, 12);
    game rat("Escaped lab rat", "It's HUGE! You wonder what they are feeding these things.", "pet", {}, 6, 4, 2);
    game dragon("Dragon", "Well obviously there was gonna be a dragon.", "", {}, 35, 20, 18);
    game spider("Incy-wincy spider", "This thing is so small, you wonder why people are so afraid of them.", "pet", {}, 4, 1, 1);
    game giant_spider("Giant Spider", "AHHHH IT'S HUGE SOMEBODY KILL IT!!!", "", {}, 6, 12, 4);
    game bfg("Big Frosty Giant", "God he's mean.", "", {}, 40, 15, 15);
    game troll("Troll", "They have a cave troll!", "", {}, 35, 14, 15);
    game vampire("Vampire", "Is that Robert Pattinson?", "undead", {}, 28, 16, 9);
    game ghost("Ghost", "Spooky... Who you gonna call?", "undead", {}, 12, 6, 1);
    game skeleton("Skeleton", "This guy won't put up much of a fight, he doesn't have the guts.", "undead", {}, 12, 6, 6);
    game werewolf("Werewolf", "What big eyes, ears and teeth he has. Who could possibly mistake this for their grandma.", "", {}, 25, 15, 10);
    game baby_dragon("Baby dragon", "It would be cute if it didn't look so hungry.", "", {}, 12, 5, 5);
    game knight("The Black Knight", "Tis but a scratch. This guy doesn't know when he is beat.", "", {}, 22, 10, 16);
    game unicorn("Unicorn", "A rare and beautiful creature. Its horn is extremely valuable to boot.", "", {}, 25, 8, 3);
    game witch("Sandwitch", "After mixing various potions and herbs, from her cauldron she pulls out... a meatball marina.", "", {}, 15, 12, 3);
    game leprechaun("Leprechaun", "Mischievious little thing, always seems to be in the money.", "", {}, 12, 5, 6);
    game zombie("Teenage zombie", "An adolescent who died and came back as a zombie without anybody noticing, so similar are their habits.", "undead", {}, 16, 5, 2);

    std::vector<game> monsters = {rat, rat, spider, tibbles, ex, goblin, goblin, teenage_turtle, ghost, ghost, skeleton, baby_dragon, unicorn,
    witch, leprechaun, zombie, zombie};
    std::vector<game> boss = {spider, giant_spider, clifford, knight, vampire, werewolf, troll, bfg, dragon};
       
    game stick("Pointy stick of death", "Does what it says on the tin.", "", {}, 0, 2, 0);
    game club("Club of strategy", "Large wooden club to bash someone over the head with.", "", {}, 0, 3, 0);
    game staff("Wooden staff of napalm", "You really shouldn't mix wood and fire.", "", {}, 0, 8, 0);
    game book("Wholey book", "Religious text, some gaping holes in it.", "", {}, 0, 1, 0);
    game sword("Sword in the stone", "Sword of legends. Sadly its got a stone attatched to it.", "", {}, 0, 5, 0);
    game hammer("Big hammer", "Stop. Hammer time!", "", {}, 0, 4, 0);
    game axe("Dwarven battle axe", "Useful for parting heads from bodies and... actually thats mostly it", "", {}, 0, 6, 0);
    game knife("Old knife", "Apparently was once used to kill a king. But thats an old knives tale.", "", {}, 0, 4, 0);
    game boxing("Boxing gloves", "Fly like a butterfly, sting like a bee.", "", {}, 0, 3, 0);
    game autobiography("Wayne Rooney's autobiography", "To read this aloud is to strike fear into the heart of any intelligent being.", "", {}, 0, 1, 0);
    game calpol("Calpol", "Ahhhh, that's the good stuff.", "", {}, start_health, 0, 0);
    game plaster("Sticky plaster", "Lost a limb? Just whack a plaster over it.", "", {}, start_health, 0, 0);
    game cough("Cough syrup", "Yuck!", "", {}, start_health, 0, 0);
    game elixir("Magic elixir", "Magical healing properties. Not as nice as Calpol.", "", {}, start_health, 0, 0);
    game helmet("Tom Hardy helmet", "Made from the hardiest material in the universe, beloved actor Tom Hardy.", "", {}, 0, 0, 4);
    game hat("Hat of intellectual superiority", "This makes you look really smart.", "", {}, 0, 0, 2);
    game boots("High heels", "A must for any halfling trying to get served.", "", {}, 0, 0, 2);
    game cape("Cool cape", "Doesn't offer much protection, but damn do you look cool.", "", {}, 0, 0, 1);
    game garlic("Garlic", "Maybe it will keep vampires away?", "", {}, 0, 0, 1);
    game codpiece("Codpiece", "Never leave the house without one.", "", {}, 0, 0, 2);
    game jacket("High-vis jacket", "Gets you in anywhere.", "", {}, 0, 0, 1);
    game chainmail("Chainmail of cheerios", "Surprisingly effective, that is if you succeed in not eating it.", "", {}, 0, 0, 3);
    game chest("Toned chestplate", "Who says you have to work out to look good?", "", {}, 0, 0, 6);
    game trousers("Yoga pants", "You don't feel this free when you're naked.", "", {}, 0, 0, 2);
    game shield("Shield of abuse", "Mean spirited shield that defends you from physical attack whilst calling you names.", "", {}, 0, 0, 5);
    game belt("Belt of chit-chatty", "Magical and sentient belt that won't shut up.", "", {}, 0, 0, 1);
    game mask("Donald Trump mask", "Deflects all criticism, fake news, criminal prosecutions and general sense.", "", {}, 0, 0, 1);

    std::vector<game> items = {stick, club, staff, book, autobiography, boxing, sword, hammer, axe, knife, calpol, plaster, cough, elixir, helmet,
    hat, boots, cape, garlic, jacket, codpiece, mask, belt, shield, trousers, chest, chainmail, calpol, plaster, cough, elixir,};

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
            std::cout << "Inventory spaces left: " << 10 - player.get_inventory().size() << "\n";
        }

        // Combat 
        if (map[y][x] == '+')
        {
            game enemy = monsters[(rand() % monsters.size())];
            std::cout << enemy.get_name() << ": " << enemy.get_description() << "\n";
            if (enemy.get_race() == "undead")
            {
                for (int i = 0; i < player.get_inventory().size(); i++)
                {
                    if (player.get_inventory()[i].get_name() == "Wholey book")
                    {
                        std::cout << "The undead flee from you Wholey book, before you bore them with a sermon.\n";
                        enemy.change_health(0);
                    }
                }
            }
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
            // If player is alive loot
            if (player.get_health() > 0 && enemy.get_race() != "pet")
            {
                std::cout << "Well done, you defeated " << enemy.get_name() << ".\n";
                std::cout << "You may now loot the room.\n"; 
                game item = loot(items);
                if (item.get_health() > 0)
                {
                    player.change_health(start_health);
                }
                else if (item.get_health() == 0 && player.get_inventory().size() < 10)
                {
                    player.new_items(item);
                    player.change_attack(item.get_attack());
                    player.change_defence(item.get_defence());
                }
                // When inventory size is full swap for best configuration of items
                else if (player.get_inventory().size() == 10)
                {
                    for (int i = 0; i < player.get_inventory().size(); i++)
                    {
                        if (item.get_attack() > player.get_inventory()[i].get_attack() > 0)
                        {
                            player.change_attack(item.get_attack() - player.get_inventory()[i].get_attack());
                            player.get_inventory()[i] = item;
                            std::cout << player.get_inventory()[i].get_name();
                        }
                        else if (item.get_defence() > player.get_inventory()[i].get_defence() > 0)
                        {
                            player.change_defence(item.get_defence() - player.get_inventory()[i].get_defence());
                            player.get_inventory()[i] = item;
                            std::cout << player.get_inventory()[i].get_name();
                        }
                    }
                }
                //Check there are no duplicates of items
                for (int i = 0; i < player.get_inventory().size() - 1; i++)
                {
                    if (player.get_inventory()[i].get_name() == player.get_inventory()[player.get_inventory().size() - 1].get_name())
                    {
                        std::cout << "You can't have two!";
                        player.change_attack(0 - player.get_inventory()[player.get_inventory().size() - 1].get_attack());
                        player.change_defence(0 - player.get_inventory()[player.get_inventory().size() - 1].get_defence());
                        player.inventory.pop_back();
                    }
                }  
                // Halfling ability
                if (player.get_race() == "Halfling")
                {
                    game item_2 = loot(items);
                    if (item_2.get_health() > 0)
                    {
                        player.change_health(start_health);
                    }
                    else if (item_2.get_health() == 0 && player.get_inventory().size() < 10)
                    {
                        player.new_items(item_2);
                        player.change_attack(item_2.get_attack());
                        player.change_defence(item_2.get_defence());
                    }
                    if (player.get_inventory().size() == 10)
                    {
                        for (int i = 0; i < player.get_inventory().size() - 1; i++)
                        {
                            if (item_2.get_attack() > player.get_inventory()[i].get_attack() > 0)
                            {
                                player.change_attack(item_2.get_attack() - player.get_inventory()[i].get_attack());
                                player.get_inventory()[i] = item_2;
                            }
                            else if (item_2.get_defence() > player.get_inventory()[i].get_defence() > 0)
                            {
                                player.change_defence(item_2.get_defence() - player.get_inventory()[i].get_defence());
                                player.get_inventory()[i] = item_2;
                            }
                        }
                    }
                }
                for (int i = 0; i < player.get_inventory().size() - 1; i++)
                {
                    if (player.get_inventory()[i].get_name() == player.get_inventory()[player.get_inventory().size() - 1].get_name())
                    {
                        std::cout << "You can't have two!";
                        player.change_attack(0 - player.get_inventory()[player.get_inventory().size() - 1].get_attack());
                        player.change_defence(0 - player.get_inventory()[player.get_inventory().size() - 1].get_defence());
                        player.inventory.pop_back();
                    }
                }  
            }  
            else if (player.get_health() <= 0)
            {
                std::cout << "You have been defeated. Rather embarassing if you ask me.\n";
            }
        }

        // Boss fights "!"
        else if (map[y][x] == '*')
        {
            game enemy = boss[0];
            std::cout << enemy.get_name() << ": " << enemy.get_description() << "\n";
            if (enemy.get_name() == "Vampire")
            {
                for (int i = 0; i < player.get_inventory().size(); i++)
                {
                    if (player.get_inventory()[i].get_name() == "Garlic")
                    {
                        std::cout << "The Vampire flees from your garlic. That or he has seen his NECKs victim...\n";
                        enemy.change_health(0);
                    }
                }
            }
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
            for (int j = 0; j < 46; j++)
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

