#include "Team.hpp"
#include <cstdlib>

//Setters:
void Team::setTalentLevel(double lev){
    if(lev > 1.0 || lev < 0){
        throw std::runtime_error("Team Error: Talent Level must be a double between 0 and 1.");
    }
    this->_talent_level=lev;
    }
//Constructors
Team::Team(std::string n) : _name(n){
    this->initTalentLevel();
}

Team::Team(std::string n, double lev) : _name(n){
    this->setTalentLevel(lev);
}

//Operators:
std::ostream& operator << (std::ostream& out, const Team& team){
    out << "Team: " << team.getName() << ". Talent Level: " << team.getTalentLevel();
    return out;
}

//Functions:
void Team::initTalentLevel(){
    srand(time(0));
    double talent =((double)rand()/(double)RAND_MAX);
    this->_talent_level=talent;
}
void Team::updateLWS(){
    if(this->getCWS() > this->getLWS()){
        this->setLWS(this->getCWS());
    }
    this->setCWS(0);
}
void Team::updateLLS(){
    if(this->getCLS() > this->getLLS()){
        this->setLLS(this->getCLS());
    }
    this->setCLS(0);
}
void Team::win(){
    this->setWins(this->getWins()+1);
    this->setCWS(this->getCWS()+1);
    this->updateLLS();
}
void Team::loss(){
    this->setLoss(this->getLosses()+1);
    this->setCLS(this->getCLS()+1);
    this->updateLWS();
}