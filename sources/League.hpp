#pragma once
#include <iostream>
#include "Team.hpp"
#include <vector>
#include <string>
const int LEAGUE_SIZE = 20;
class Team;
class League{
    
    private:
        std::vector<Team*> _teams;
        std::vector<std::string> _DefaultTeams = {
           "Cowboys", "Eagles", "Commanders", "Giants","Packers", "Vikings", "Bears", "Lions",
           "Buccaneeres", "Saints", "Falcons", "Panthers",
           "Rams", "Cardinals", "49ers", "Seahawks",
            "Biils", "Patriots", "Dolphins", "Jets"};
    
    public:
        //Getters:
        std::vector<Team*>& getLeagueVec() {return this->_teams;}
        std::vector<std::string>& getDefaultTeams() {return this->_DefaultTeams;} 

        //Constructors
        League();
        League(const std::vector<Team*>& other_teams);
        

        //Operators:
        friend std::ostream& operator << (std::ostream& out, const Team& team);
};