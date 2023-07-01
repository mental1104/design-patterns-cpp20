#include "Events.h"

int main(){
    Game game;
    Player player{ "Sam", game };
    Coach coach{ game };
    player.score();
    player.score();
    player.score(); // ignored by coach
}