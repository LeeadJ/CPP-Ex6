#pragma once
#include <iostream>
#include "Team.hpp"


class Game{
    private:
    Team* _homeTeam;
    Team* _awayTeam;

    public:
        //Getters
       Team* getHomeTeam();
       Team* getAwayTeam();

       //Setters:
       void setWinner(Team& winner);
       void setLoser(Team& loser);

        //Constructor:
       Game(Team& homeTeam, Team& awayTeam);

        //Operator:
        friend std::ostream& operator << (std::ostream& out, const Game& game);

        //Functions:
        void updateTeamPoints();
        void updateHomeTeam(int num);
        void updateAwayTeam(int num);
        void updateGam_WinnerLoser();
        // void startGame();
};