#include <iostream>

using std::cout;
using std::endl;

class Game
{
public:
    explicit Game(int number_of_players)
        : number_of_players{number_of_players} {}

    void run()
    {
        start();
        while(!have_winner())
            take_turn();
        cout << "Player " << get_winner() << " wins.\n";
    }
protected:
    virtual void start() = 0;
    virtual bool have_winner() = 0;
    virtual void take_turn() = 0;
    virtual int get_winner() = 0;
    int current_player{0};
    int number_of_players;
};

class Chess : public Game
{
public:
    explicit Chess() : Game{2} {}
protected:
    void start() override {}
    bool have_winner() override { return turns == max_turns; }
    void take_turn() override
    {
        turns++;
        current_player = (current_player+1) % number_of_players;
    }
    int get_winner() override { return current_player; }
private:
    int turns{0};
    int max_turns{10};
};