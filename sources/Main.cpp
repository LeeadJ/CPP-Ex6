#include "Team.hpp"
#include "Game.hpp"
#include "League.hpp"

using namespace std;

int main(){
    Team a{"sixers", 0.1121};
    Team b{"knicks", 0.4};
    vector<Team*> vec = {&a,&b};
    Game g{a,b};
    g.setWinner(a);
    g.setLoser(b);

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<g<<endl;
    League ll{vec};
    for(Team* team : ll.getLeagueVec()){
        cout << *team << endl;
    }
    // double talent =((double)rand()/(double)RAND_MAX);
    // cout<<talent<<endl;
    cout << ll.getLeagueVec().size()<<endl;
    return 0;
}