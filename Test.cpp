#include <iostream>
#include "sources/Game.hpp"
#include "sources/Team.hpp"
#include "sources/League.hpp"
#include "sources/Schedule.hpp"
using namespace std;

TEST_CASE("Default"){
    Team::Team a{"sixers", 0.1121};
    Team b{"knicks", 0.4};
    CHECK(a.getName()=="sixers")
    CHECK(b.getName()=="knicks")
    League league{};
    CHECK(league.teams->size() == 20);
    CHECK(league.getLeagueVec().at(1)=="Celtics");
    CHECK(League.league_LWS()==0);
    Schedule schedule(league);
    CHECK(schedule.rounds == 38);
    CHECK(schedule.num_teams == 20);    
    schedule.run_the_season();
    CHECK(schedule._league.league_LWS().getLWS() != 0);
    CHECK(schedule._league.league_LLS().getLLS() != 0);
    CHECK(schedule._league.league_MostPoints().getTotalPoints() != 0);
    CHECK(schedule._league.teamWithFewestPoints().getTotalPoints() != 0);
    CHECK(schedule._league.numPosTeams() != 0);
}