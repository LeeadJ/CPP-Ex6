#include "Schedule.hpp"
#include <iostream>
//Constructor:
Schedule::Schedule(League& league){
    this->_league=&league;
    this->setGamesPerRounds(league.getLeagueVec().size()/2);
    this->setNumTeams(league.getLeagueVec().size());
    this->setRounds((this->getNumTeams()-1)*2);
    for(int round = 0; round < this->getRounds(); round++){
        for(int game = 0; game < this->getGamesPerRound(); game++){
            if(round + 1 <= 19){
                int home = (round + game) % (this->getNumTeams() - 1);
                int away = (this->getNumTeams() - 1 - game + round) % (this->getNumTeams() - 1);
                if(game == 0){
                    away = this->getNumTeams() - 1;
                }
                Game *tmp = new Game(*this->_league->getLeagueVec().at(home) , *this->_league->getLeagueVec().at(away));
                this->getRoundsNumVec().push_back(*tmp);
                if(this->getRoundsNumVec().size() == this->getGamesPerRound()){
                    this->getGamesVec().push_back(this->getRoundsNumVec());
                    this->getRoundsNumVec().clear();
                }
            }
            else{
                int away = (round + game) % (this->getNumTeams() - 1);
                int home = ((unsigned int)this->getNumTeams() - 1 - game + round) % (this->getNumTeams() - 1);
                if(game == 0){
                    home = this->getNumTeams() - 1;
                }
                Game *tmp = new Game(*this->_league->getLeagueVec().at(home) , *this->_league->getLeagueVec().at(away));
                this->getRoundsNumVec().push_back(*tmp);
                if(this->getRoundsNumVec().size() == this->getGamesPerRound()){
                    this->getGamesVec().push_back(this->getRoundsNumVec());
                    this->getRoundsNumVec().clear();
                }
            }
        }
    }
}

void Schedule::start_season(){
    for(int i = 0; i < this->getRounds(); i++){
        for(int j = 0; j < this->getGamesPerRound(); j++){
            std::cout<<this->getGamesVec().at(i).at(j).getHomeTeam()->getName()<<std::endl;
            std::cout<<this->getGamesVec().at(i).at(j).getHomeTeam()->getName()<<std::endl;
            // this->getGamesVec().at(i).at(j).startGame();
        }
    }
}