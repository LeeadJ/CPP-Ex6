#include "Game.hpp"
#include <random>

//Getters
Team* Game::getHomeTeam() {return this->_homeTeam;}
Team* Game::getAwayTeam() {return this->_awayTeam;}

//Setters:
Game::Game(Team& home, Team& away) : _homeTeam(&home), _awayTeam(&away){}

//Operators:
std::ostream& operator << (std::ostream& out, Game& game){
    out << "Game:\n" << "Home " << *game.getHomeTeam();
    out << "\nAway " << *game.getAwayTeam();
    return out;
}

//Functions:
void Game::updateTeamPoints(){
    //Creating a random number for the away and home points:
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> awayPoints(50,100);
    std::uniform_int_distribution<int> homePoints(55,100);
    int home_p = homePoints(rng);
    int away_p = awayPoints(rng);
    //Updating the home and away team points and stats:
    this->updateHomeTeam(home_p);
    this->updateAwayTeam(away_p);
}

//These functions update the individual team points and stats:
void Game::updateHomeTeam(int num){
    int home_talent = this->getHomeTeam()->getTalentLevel() * 10;
    this->getHomeTeam()->setPointsScored(this->getHomeTeam()->getPointsScored() + num + home_talent);
    this->getHomeTeam()->setPosPoints(this->getHomeTeam()->getPositvePoints() + this->getHomeTeam()->getPointsScored());
    this->getHomeTeam()->setNegPoints(this->getHomeTeam()->getNegativePoints() + this->getAwayTeam()->getPointsScored());
}
void Game::updateAwayTeam(int num){
    int away_talent = this->getAwayTeam()->getTalentLevel() * 10;
    this->getAwayTeam()->setPointsScored(this->getAwayTeam()->getPointsScored() + num + away_talent);
    this->getAwayTeam()->setPosPoints(this->getAwayTeam()->getPositvePoints() + this->getAwayTeam()->getPointsScored());
    this->getAwayTeam()->setNegPoints(this->getAwayTeam()->getNegativePoints() + this->getHomeTeam()->getPointsScored());
}

void Game::updateGam_WinnerLoser(){
    //Away team is the winner:
    if(this->getHomeTeam()->getPointsScored() < this->getAwayTeam()->getPointsScored()){
        this->setWinner(*this->getAwayTeam());
        this->setLoser(*this->getHomeTeam());
    }
    //Home team is the winner if they tie or have more points (Home team advantage):
    else{
        this->setWinner(*this->getHomeTeam());
        this->setLoser(*this->getAwayTeam());
    }
    //Clearing the points from the game, for future uses:
    this->getHomeTeam()->setPointsScored(0);
    this->getAwayTeam()->setPointsScored(0);
}

// void Game::startGame(){
//     this->updateTeamPoints();
//     this->up
// }
       
