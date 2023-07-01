#include "function.h"

int main(){
    int turn{0}, max_turns{10};
    GameState state{0, -1, 2};

    auto start = [](GameState& s)
    {
        cout << "Starting a game of chess with " <<
            s.number_of_players << " players\n";
    };

    auto take_turn = [&](GameState& s)
    {
        cout << "Turn " << turn++ << "taken by players"
             << s.current_player << "\n";
        s.current_player = (s.current_player + 1) % s.number_of_players;
        s.winning_player = s.current_player;
    };

    auto have_winner = [&](GameState& s)
    {
        return turn == max_turns;
    };

    run_game(state, start, take_turn, have_winner);
    return 0;
}