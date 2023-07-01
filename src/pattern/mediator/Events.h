#include <boost/signals2.hpp>
#include <string>
#include <iostream>

using std::cout;
using std::string;
using boost::signals2::signal;

struct EventData
{
    virtual ~EventData() = default;
    virtual void print() const = 0;
};

struct PlayerScoredData : EventData
{
    string player_name;
    int goals_scored_so_far;

    PlayerScoredData(const string& player_name,
        const int goals_scored_so_far)
        : player_name(player_name),
          goals_scored_so_far(goals_scored_so_far) {}
    
    void print() const override
    {
        cout << player_name << "has scored! (their "
             << goals_scored_so_far << " goal)" << "\n";
    }
};

struct Game
{
    signal<void(EventData*)> events; // observer
};

struct Player
{
    string name;
    int goals_scored = 0;
    Game& game;

    Player(const string& name, Game& game)
        : name(name), game(game) {}

    void score()
    {
        goals_scored++;
        PlayerScoredData ps{name, goals_scored};
        game.events(&ps);
    }
};

struct Coach
{
    Game& game;
    explicit Coach(Game& game) : game(game)
    {
        // celebrate if player has cored < 3 goals
        game.events.connect([](EventData* e){
            PlayerScoredData* ps = dynamic_cast<PlayerScoredData*>(e);
            if(ps && ps->goals_scored_so_far < 3){
                cout << "coach says: well done, " << ps->player_name << "\n";
            }
        });
    }
};