#include "Team.hpp"
#include "Game.hpp"
#include "League.hpp"
#include "Schedule.hpp"
#include<iostream>
#include<vector>


using namespace std;

int main(){
    // Team a{"sixers", 0.1121};
    // Team b{"knicks", 0.4};
    // cout << a<<endl;
    // vector<Team*> vec = {&a,&b};
    // Game g{a,b};
    // cout << g <<endl;

    // // cout<<a<<endl;
    // // cout<<b<<endl;
    // // cout<<g<<endl;
    // League ll{vec};
    // cout<<ll<<endl;
    League league;
    // cout<<league<<endl;
    Schedule sc(league);
    cout<<*sc._league->getLeagueVec().at(8)<<endl;
    // cout<<sc.getGamesPerRound()<<endl;
    sc.start_season();
    return 0;
}