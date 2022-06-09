#include "Game.hpp"

//Getters
Team* Game::getHomeTeam() const {return this->_homeTeam;}
Team* Game::getAwayTeam() const {return this->_awayTeam;}
// int* Game::getScore() const {return this->_score;}
Team* Game::getWinner() const {return this->_winner;}
Team* Game::getLoser() const {return this->_loser;}

//Setters:
void Game::setWinner(Team& winner){this->_winner=&winner;}
void Game::setLoser(Team& loser){this->_loser=&loser;}
Game::Game(Team& home, Team& away) : _homeTeam(&home), _awayTeam(&away), _winner(NULL), _loser(NULL){}

//Operators:
std::ostream& operator << (std::ostream& out, const Game& game){
    // std::string ans = "Game:\n";
    // ans += "Home Team: " + game.getHomeTeam();
    out << "Game:\n" << "Home " << *game.getHomeTeam();
    out << "\nAway " << *game.getAwayTeam();
    out << "\nWinner: " << game.getWinner()->getName() << "\t Loser: " << game.getLoser()->getName();
    return out;
}
       
