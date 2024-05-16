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
    // Vetor para armazenar a diferença de gols maior em cada campeonato
    vector<string> highestGoalDifferenceList;

    // Percorre cada campeonato
    for (unsigned int championship = 0; championship < teams[0].getGoalsScored().size(); championship++)
    {
        // Inicializa a diferença de gols maior do campeonato como 0
        int highestGoalDifference = 0;
        // Guarda o indice do time com a maior diferença de gols
        int highestGoalDifferenceIndex = 0;

        // Percorre cada time
        for (unsigned int index = 0; index < teams.size(); index++)
        {
            // Pega o time atual
            Team team = teams[index];

            // Inicializa a diferença de gols do time em 0
            int goalDifference = 0;

            // Percorre cada ano do campeonato
            for (unsigned int year = 0; year < team.getGoalsScored()[championship].size(); year++)
            {
                // Soma a diferença de gols do time em um ano específico
                goalDifference += team.getGoalsScored()[championship][year] - team.getGoalsConceded()[championship][year];
            }

            // Se for o primeiro time, guarda a diferença de gols como a maior
            if (index == 0)
            {
                highestGoalDifference = goalDifference;
            }

            // Se a diferença de gols do time atual for maior que a maior encontrada
            if (goalDifference > highestGoalDifference)
            {
                // Guarda a diferença de gols do time atual como a maior encontrada
                highestGoalDifference = goalDifference;
                // Guarda o indice do time com a maior diferença de gols
                highestGoalDifferenceIndex = index;
            }
        }

        // Adiciona a diferença de gols maior do campeonato ao vetor
        highestGoalDifferenceList.push_back(to_string(highestGoalDifference));

        // Exibe o time com a maior diferença de gols no campeonato
        cout << "O " << teams[highestGoalDifferenceIndex].getName() << " no campeonato " << championship + 1 << " teve o maior saldo de gols de: " << highestGoalDifferenceList[championship] << endl;
    }
}
