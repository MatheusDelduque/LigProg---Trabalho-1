// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "liga.h"

void Liga::addTime(Team team)
{
    teams.push_back(team);
}

void Liga::averageGoalEvolution(Team team, void (*function)(Team team))
{
    function(team);
};

vector<Team> Liga::getTeams()
{
    return teams;
};

void Liga::highestGoalDifferenceChampionship(vector<Team> teams)
{
    string teamHighestGoalDifference;
    int highestGoalDifference = 0;
    int goalDifference = 0;
    for (unsigned int index = 0; index < teams.size(); index++)
    {
        Team team = teams[index];

        vector<vector<unsigned int>> goalsScored = team.getGoalsScored();
        vector<vector<unsigned int>> goalsConceded = team.getGoalsConceded();

        for (unsigned int championship = 0; championship < goalsScored.size(); championship++)
        {



            for (unsigned int year = goalsScored[championship].size(); year > 0; year--)
            {
                goalDifference += goalsScored[championship][year] - goalsConceded[championship][year];
                if (goalDifference > highestGoalDifference)
                {
                    highestGoalDifference = goalDifference;
                    teamHighestGoalDifference = team.getName();
                }
            }
            cout << "O time com o maior saldo de gols no Campeonato " << championship << " eh: " << teamHighestGoalDifference << " com a diferenca de: " << highestGoalDifference << endl;
            goalDifference = 0;
            highestGoalDifference = 0;
        }
    }
}