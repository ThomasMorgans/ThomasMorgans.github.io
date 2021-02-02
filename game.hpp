#include <iostream>
#include <vector>

// Create game class 
class game
{
public:
    // Declare class variables
    std::string name;
    std::string description;
    std::string race;
    std::vector<game> inventory;
    int health;
    int attack;
    int defence;

    // Declare class constructors and destructors
    game(std::string new_name, std::string new_description, std::string new_race, std::vector<game> new_items, int new_health, int new_attack, int new_defence);
    ~game();

    // Declare class functions
    void move(int vertical, int horizontal);
    std::string get_name();
    std::string get_description();
    std::string get_race();
    std::vector<game> get_inventory();
    int get_health();
    int get_attack();
    int get_defence();
    void change_health(int new_health);
    void change_attack(int attack_bonus);
    void change_defence(int defence_bonus);
    void new_items(game new_item);
};

// Declare functions
int combat(game player, game enemy);
game loot(std::vector<game>);
game character_creator(std::string player_name, std::string race);

// Declare position variables
extern char map[15][46];
extern int x;
extern int y;


