#include "Team.hpp"

//Getters:
std::string Team::getName() const { return this->_name;}
double Team::getTalentLevel() const {return this->_talent_level;}
int Team::getPointsScored() const {return this->_pointsScored;}

//Setters:
void Team::setPointsScored(int points) {this->_pointsScored=points;}

//Constructors
Team::Team(std::string n) : _name(n), _talent_level(-999), _pointsScored(0){}
Team::Team(std::string n, double lev) : _name(n), _talent_level(lev){}

//Operators:
std::ostream& operator << (std::ostream& out, const Team& team){
    out << "Team: " << team.getName() << ". Talent Level: " << team.getTalentLevel();
    return out;
}