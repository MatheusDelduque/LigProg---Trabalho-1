// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "liga.h"


void Liga::addTime(Team team)
{
    teams.push_back(team);
}


double Liga::averageGoalEvolution(string teamName, vector<vector<unsigned int>> gols, double (*function) (Team team))
{
    for (unsigned int index = 0; index < teams.size(); index++)
    {
        Team team = teams[index];

        if (team.getName().compare(teamName))
        {
            double movingAverage = function(team);
            return movingAverage;
        }
    }
    return 0;
};

vector<Team> Liga::getTeams(){
    return teams;
};