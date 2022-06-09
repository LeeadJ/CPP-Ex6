#pragma once
#include <string>
#include <iostream>

class Team{
    private:
        std::string _name;
        double _talent_level;
        int _pointsScored;

    public:
        //Getters:
        std::string getName() const;
        double getTalentLevel() const;
        int getPointsScored() const;

        //Setters:
        void setPointsScored(int points);
        
        //Constructor:
        Team(const std::string n);
        Team(const std::string n, double lev);

        //Operators:
        friend std::ostream& operator << (std::ostream& out, const Team& team);
};