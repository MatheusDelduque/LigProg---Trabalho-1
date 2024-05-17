// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "time.h"
#include <string>

using namespace std;

// Construtor da classe Team.
Team::Team(string name, vector<vector<unsigned int>> goalsScored, vector<vector<unsigned int>> goalsConceded)
{
    setName(name);
    setGoalsScored(goalsScored);
    setGoalsConceded(goalsConceded);
};

// Define o nome do time.
void Team::setName(string newName)
{
    name = newName;
};

// Retorna os gols marcados de cada campeonato.
vector<vector<unsigned int>> Team::getGoalsScored(){
    return goalsScored;
}

// Retorna os gols sofridos de cada campeonato.
vector<vector<unsigned int>> Team::getGoalsConceded()
{
    return goalsConceded;
}

// Define os gols marcados de cada campeonato.
void Team::setGoalsScored(vector<vector<unsigned int>> newGoalsScored)
{
    goalsScored = newGoalsScored;
}

// Define os gols sofridos de cada campeonato.
void Team::setGoalsConceded(vector<vector<unsigned int>> newGoalsConceded)
{
    goalsConceded = newGoalsConceded;
}

// Retorna o nome do time.
string Team::getName(){
    return name;
}
