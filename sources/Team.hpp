#pragma once
#include <string>
#include <iostream>

class Team{
    private:
        std::string _name;
        double _talent_level;

    public:
        //Getters:
        std:string getName() const;
        
        //Constructor:
        Team(const std::string n);
        Team(const std::string n, double lev);
};