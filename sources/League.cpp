#include "League.hpp"
#include <limits>

//Constructors
League::League(){
    this->getLeagueVec().clear();
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
std::ostream& operator << (std::ostream& out, League& league){
    int imin = std::numeric_limits<int>::min(); // minimum value
    Team* team_arr[20];
    int i=0;
    for(Team* team : league.getLeagueVec()){
        team_arr[i] = team;
        std::cout<<"";
        i++;
    }
    league.bubbleSort(team_arr, 20);
    // std::vector<Team*> standings;
    int count=1;
    out << "\t\tLeage:\n";
    for(Team* team : team_arr){
        out <<count<<") "<< team->getName()<<"\t Wins: "<<team->getWins()<<"\t Losses: "<<team->getLosses()<<"\t Total Points: "<<team->getTotalPoints()<<std::endl;
        count++;
    }
    out << "\n\t\tStats:"<<std::endl;
    out<<"League Largest Win Streak: "<<league.league_LWS()->getName()<<": "<<league.league_LWS()->getLWS()<<" Games.\n";
    out<<"League Largest Lossing Streak: "<<league.league_LLS()->getName()<<": "<<league.league_LLS()->getLLS()<<" Games.\n";
    out<<"League Teams with Positive Points: "<<league.numPosTeams()<<" Teams.\n";
    out<<"League Teams with Negative Points: "<<league.numPosTeams()<<" Teams.\n";
    out<<"League Team with Most Points: "<<league.league_MostPoints()->getName()<<": "<<league.league_MostPoints()->getTotalPoints()<<" Points.\n";
    out<<"League Team with Fewest Points: "<<league.teamWithFewestPoints()->getName()<<": "<<league.teamWithFewestPoints()->getTotalPoints()<<" Points.\n";
    return out;
}

//Functions:
void League::bubbleSort(Team* array[], int size){
    for(int i=0; i<size; ++i){
        for(int j=0; j<size-i; ++j){
            if(array[j]->getTotalPoints() > array[j+1]->getTotalPoints()){
                Team* temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

Team* League::league_LWS() {
    Team* curr;
    int max = std::numeric_limits<int>::min(); // minimum value
    for(Team* team : this->getLeagueVec()){
        if(team->getLWS() > max){
            max = team->getLWS();
            curr = team;
        }
    }
    return curr;
}
Team* League::league_LLS() {
    Team* curr;
    int min = std::numeric_limits<int>::max(); // maximum value
    for(Team* team : this->getLeagueVec()){
        if(team->getLWS() < min){
            min = team->getLWS();
            curr = team;
        }
    }
    return curr;
}
Team* League::league_MostPoints () {
    Team* curr;
    int max = std::numeric_limits<int>::min(); // minimum value
    for(Team* team : this->getLeagueVec()){
        if(team->getTotalPoints() > max){
            max = team->getLWS();
            curr = team;
        }
    }
    return curr;
}
Team* League::teamWithFewestPoints() {
    Team* curr;
    int min = std::numeric_limits<int>::max(); // maximum value
    for(Team* team : this->getLeagueVec()){
        if(team->getTotalPoints() < min){
            min = team->getLWS();
            curr = team;
        }
    }
    return curr;
}


int League::numPosTeams(){
    int ans=0;
    for(Team* team : this->getLeagueVec()){
        if(team->getTotalPoints() > 0){
            ans++;
        }
    }
    return ans;
}
int League::numNegTeams(){
    return 20-this->numPosTeams();
}