#pragma once
#include <iostream>
#include "Team.hpp"
#include "Game.hpp"
#include <vector>
#include <string>
const int LEAGUE_SIZE = 20;
class Team;
class League{
    private:
        std::vector<Team*> _teams;
        std::vector<std::string> _DefaultTeams = {
           "Celtics", "76ers", "Raptors", "Nets ", "Knicks",
           "Bucks", "Bulls", "Cavaliers", "Pacers", "Pistons",
           "Heat", "Hawks", "Hornets", "Wizards", "Magic",
           "Jazz", "Nuggets", "Suns", "Lakers", "Clippers"};
    
    public:
        //Getters:
        std::vector<Team*>& getLeagueVec() {return this->_teams;}
        std::vector<std::string>& getDefaultTeams() {return this->_DefaultTeams;} 

        //Constructors
        League();
        League(const std::vector<Team*>& other_teams);
        

        //Operators:
        friend std::ostream& operator << (std::ostream& out, League& league);

        //Functions:
        Team* league_LWS() ;
        Team* league_LLS() ;
        Team* league_MostPoints () ;
        Team* teamWithFewestPoints() ;
        int numPosTeams();
        int numNegTeams();
        void bubbleSort(Team* array[], int size);


        
};