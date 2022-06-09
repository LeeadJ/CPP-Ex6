#include "League.hpp"


//Constructors
League::League(){
    this->_teams.clear();
    for(std::string name : this->getDefaultTeams()){
        double talent =((double)rand()/(double)RAND_MAX);
        Team* curr = new Team{name, talent};
        this->_teams.push_back(curr);
    }
}
League::League(const std::vector<Team*>& other_teams){
    if(other_teams.size() > LEAGUE_SIZE){
        throw std::runtime_error("League Error: Too many teams to add. (size limit 20)");
    }
    this->_teams.clear();
    for(Team* team : other_teams){
        this->_teams.push_back(team);
    }
    while(this->_teams.size() < LEAGUE_SIZE){
        for(std::string name : this->getDefaultTeams()){
            bool in = false;
            for(Team* team : this->_teams){
                if(name == team->getName()){
                    in = true;
                    break;
                }
            }
            if(in == false){
                double talent =((double)rand()/(double)RAND_MAX);
                Team* curr = new Team{name, talent};
                this->_teams.push_back(curr);
            }
            if(this->_teams.size() == 20){
                break;
            }
        }
    }
}


//Operators:
std::ostream& operator << (std::ostream& out, const Team& team);