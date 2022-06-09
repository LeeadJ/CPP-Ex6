#pragma once
#include <iostream>
#include "Team.hpp"

class Game{
    private:
    Team* _homeTeam;
    Team* _awayTeam;
    Team* _winner;
    Team* _loser;

    public:
        //Getters
       Team* getHomeTeam() const;
       Team* getAwayTeam() const;
    //    int* getScore() const;
       Team* getWinner() const;
       Team* getLoser() const;

       //Setters:
       void setWinner(Team& winner);
       void setLoser(Team& loser);

        //Constructor:
       Game(Team& homeTeam, Team& awayTeam);

        //Operator:
        friend std::ostream& operator << (std::ostream& out, const Game& game);
       
};