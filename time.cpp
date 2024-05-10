// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "time.h"
#include <string>

using namespace std;

Team::Team(string name, vector<vector<unsigned int>> goalsScored, vector<vector<unsigned int>> goalsConceded)
{
    setName(name);
    setGoalsScored(goalsScored);
    setGoalsConceded(goalsConceded);
};

void Team::setName(string newName)
{
    name = newName;
};

vector<vector<unsigned int>> Team::getGoalsScored(){
    return goalsScored;
}

vector<vector<unsigned int>> Team::getGoalsConceded()
{
    return goalsConceded;
}

void Team::setGoalsScored(vector<vector<unsigned int>> newGoalsScored)
{
    goalsScored = newGoalsScored;
}

void Team::setGoalsConceded(vector<vector<unsigned int>> newGoalsConceded)
{
    goalsConceded = newGoalsConceded;
}

string Team::getName(){
    return name;
}
