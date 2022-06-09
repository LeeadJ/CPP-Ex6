#include "Team.hpp"

Team::getName() const { return this->_name;}

Team::Team(std::string n) : _name(n);
Team::Team(std::stringn, double lev) : _name(n), _talent_level(lev);