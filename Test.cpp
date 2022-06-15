#include "doctest.h"
#include <iostream>
#include "sources/Game.hpp"
#include "sources/Team.hpp"
#include "sources/League.hpp"
#include "sources/Schedule.hpp"
using namespace std;

TEST_CASE("Default Tests"){
    Team a{"sixers", 0.1121};
    Team b{"knicks", 0.4};
    CHECK(a.getName()=="sixers");
    CHECK(b.getName()=="knicks");
    League league{};
    CHECK_EQ(league.getLeagueVec().size(), 20);
    CHECK_EQ(league.getLeagueVec().at(1), "Celtics");
    CHECK_EQ(league.league_LWS(), 0);

    Schedule schedule(league);
    CHECK_EQ(schedule.getRounds(), 38);
    CHECK_EQ(schedule.getNumTeams(), 20); 

    schedule.start_season();
    CHECK_FALSE(schedule._league->league_LWS()==0);
    CHECK_FALSE(schedule._league->league_LLS()->getLLS() == 0);
    CHECK_FALSE(schedule._league->league_MostPoints()->getTotalPoints() == 0);
    CHECK_FALSE(schedule._league->teamWithFewestPoints()->getTotalPoints() == 0);
    CHECK_FALSE(schedule._league->numPosTeams() != 0);
}