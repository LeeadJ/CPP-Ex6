#pragma once
#include <iostream>
#include "Team.hpp"


class Game{
    private:
    Team* _homeTeam;
    Team* _awayTeam;

    public:
        //Getters
       Team* getHomeTeam() const;
       Team* getAwayTeam() const;

       //Setters:
       void setWinner(Team& winner) {winner.win();}
       void setLoser(Team& loser){loser.loss();}

        //Constructor:
       Game(Team& homeTeam, Team& awayTeam);

        //Operator:
        friend std::ostream& operator << (std::ostream& out, const Game& game);

        //Functions:
        void updateTeamPoints();
        void updateHomeTeam(int num);
        void updateAwayTeam(int num);
        void updateGam_WinnerLoser();
        void startGame();
};