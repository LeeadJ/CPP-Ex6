#pragma once
#include <iostream>
#include "League.hpp"

class Schedule{
    private:
        
        int _rounds;
        int _games_per_round;
        int _numberTeams = 0;
        std::vector<std::vector<Game>> _gamesVec;
        std::vector<Game> _roundNumVec;
        
        
    public:
        League* _league;
        //Getters:
        // League* getLeague(){return _league;}
        int getRounds(){return _rounds;}
        int getGamesPerRound(){return _games_per_round;}
        int getNumTeams(){return _numberTeams;}
        std::vector<std::vector<Game>> getGamesVec() {return this->_gamesVec;}
        std::vector<Game> getRoundsNumVec() {return this->_roundNumVec;}


        //Setters:
        void setLeague(League& leg) {*this->_league=leg;}
        void setGamesPerRounds(int m) {this->_games_per_round=m;}
        void setNumTeams(int num){this->_numberTeams=num;}
        void setRounds(int num){this->_rounds=num;}


        //Constructor:
        Schedule(League& league);

        //Operators:
        friend std::ostream& operator << (std::ostream& out, Schedule& sced);

        //Functions:
        // void print_matches_in_round(int round);
        void start_season();
        



};