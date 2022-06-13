#pragma once
#include <string>
#include <iostream>

class Team{
    private:
        std::string _name;
        double _talent_level=0;
        int _pointsScored;
        int _wins=0;
        int _losses=0;
        int _pos_points = 0;
        int _neg_points = 0;
        int _CWS = 0;
        int _CLS = 0;
        int _LWS = 0;
        int _LLS = 0;

    public:
        //Getters:
        std::string getName() const {return this->_name;}
        double getTalentLevel() const{return this->_talent_level;}
        int getPointsScored() const{return this->_pointsScored;}
        int getWins() const{return this->_wins;}
        int getLosses() const{return this->_losses;}
        int getPositvePoints() const{return this->_pos_points;}
        int getNegativePoints() const{return this->_neg_points;}
        int getCWS() const{return this->_CWS;}
        int getCLS() const{return this->_CLS;}
        int getLWS() const{return this->_LWS;}
        int getLLS() const{return this->_LLS;}


        //Setters:
        void setPointsScored(int points){this->_pointsScored=points;}
        void setCWS(int num){this->_CWS=num;}
        void setCLS(int num){this->_CLS=num;}
        void setLWS(int num){this->_LWS=num;}
        void setLLS(int num){this->_LLS=num;}
        void setTalentLevel(double lev){this->_talent_level=lev;}
        void setWins(int num) {this->_wins=num;}
        void setLoss(int num) {this->_losses=num;}
        void setPosPoints(int num){this->_pos_points=num;}
        void setNegPoints(int num){this->_neg_points=num;}
        
        

        //Constructor:
        Team(const std::string n);
        Team(const std::string n, double lev);

        //Operators:
        friend std::ostream& operator << (std::ostream& out, const Team& team);

        //Functions:
        void updateLWS();
        void updateLLS();
        void initTalentLevel();
        void win();
        void loss();
};