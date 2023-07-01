#include <iostream>
using std::cout;

struct GameState
{
    int current_player, winning_player;
    int number_of_players;
};

template<typename FnStartAction,
         typename FnTakeTurnAction,
         typename FnHaveWinnerAction>
void run_game(GameState initial_state,
              FnStartAction start_action,
              FnTakeTurnAction take_turn_action,
              FnHaveWinnerAction have_winner_action)
{
    GameState state = initial_state;
    start_action(state);
    while(!have_winner_action(state))
    {
        take_turn_action(state);
    }
    cout << "Player " << state.winning_player << " win.\n";
};



