#pragma once
#include <iostream>
#include "League.hpp"

unsigned int ROUNDS = 19;
unsigned int MATCHES_PER_ROUND = 10;
unsigned int TOTAL_GAMES = 380; 
class Schedule{
    public:
        League* _league;
        int _rounds;
        int _matches_per_round;
        unsigned int num_teams = 0;
        std::vector<std::vector<Game>> matches;
        std::vector<Game> round_number;

        //Constructor:
        Schedule(League& league);

        //Operators:
        friend std::ostream& operator << (std::ostream& out, Schedule& sced);

        //Functions:
        void print_matches_in_round(int round);
        void start_season();
        



};