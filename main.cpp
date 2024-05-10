// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "liga.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double averageGoalEvolutionScored(Team team);
double averageGoalEvolutionConceded(Team team);

int main()
{
    Liga liga;

    vector<vector<unsigned int>> goalsScored =
        {
            {0, 2, 0, 1, 20, 0, 3}, // Primeiro Campeonato: ano 1: 0 gols marcado, ano 2: 0 gols marcado, ano 3: 0 gols marcado, ano 4: 1 gol marcado, ano 5: 0 gols marcado, ano 6: 3 gols marcados, ano 7: 0 gols marcado
            {1, 0, 3, 0, 1, 3, 2}, // Segundo Campeonato: ano 1: 1 gol marcado, ano 2: 0 gol marcado, ano 3: 3 gols marcados, ano 4: 0 gol marcado, ano 5: 1 gol marcado, ano 6: 2 gols marcados, ano 7: 0 gols marcado
            {3, 1, 2, 0, 0, 1, 4}  // Terceiro Campeonato: ano 1: 3 gols marcados, ano 2: 1 gol marcado, ano 3: 2 gols marcados, ano 4: 0 gol marcado, ano 5: 0 gol marcado, ano 6: 1 gol marcado, ano 7: 0 gols marcado
        };

    vector<vector<unsigned int>> goalsConceded =
        {
            {0, 2, 1, 0, 0, 0, 3}, // Primeiro Campeonato: ano 1: 0 gols sofrido, ano 2: 0 gols sofrido, ano 3: 1 gol sofrido, ano 4: 0 gols sofrido, ano 5: 0 gols sofrido, ano 6: 3 gols sofridos, ano 7: 0 gols sofrido
            {1, 5, 3, 10, 1, 0, 2}, // Segundo Campeonato: ano 1: 1 gol sofrido, ano 2: 0 gol sofrido, ano 3: 3 gols sofridos, ano 4: 0 gol sofrido, ano 5: 1 gol sofrido, ano 6: 2 gols sofridos, ano 7: 0 gols sofrido
            {3, 1, 2, 0, 0, 1, 0}  // Terceiro Campeonato: ano 1: 3 gols sofridos, ano 2: 1 gol sofrido, ano 3: 2 gols sofridos, ano 4: 0 gol sofrido, ano 5: 0 gol sofrido, ano 6: 1 gol sofrido, ano 7: 0 gols sofrido
        };

    // Criar o time
    Team teamA("Time A", goalsScored, goalsConceded);
    Team teamB("Time B", goalsScored, goalsConceded);
    Team teamC("Time C", goalsScored, goalsConceded);

    // Adicionar o time na liga
    liga.addTime(teamA);
    liga.addTime(teamB);
    liga.addTime(teamC);
    int option = 0;
    do
    {
        cout << "Selecione uma opcao:" << endl;
        cout << "1 - Mostrar a evolucao de gols marcados de um time" << endl;
        cout << "2 - Mostrar a evolucao de gols sofridos de um time" << endl;
        cout << "3 - Mostrar a evolucao de gols marcados e sofridos de um time" << endl;
        cout << "4 - Mostrar a evolucao de gols marcados de todos os times" << endl;
        cout << "5 - Sair" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            vector<Team> teams = liga.getTeams();
            for (unsigned int index = 0; index < teams.size(); index++)
            {
                Team team = teams[index];
                string teamName = team.getName();

                for (unsigned int championship = 0; championship < goalsScored.size(); championship++)
                {
                    double movingAverageScored = liga.averageGoalEvolution(teamName, goalsScored, averageGoalEvolutionScored);
                    cout << fixed << setprecision(1) << "A evolucao media de gols marcados do time " << teamName << " no Campeonato " << championship + 1 << " eh: " << movingAverageScored << endl;
                    cout << endl;
                }
            }

            break;
        }

        case 2:
        {
        }

        case 3:
        {
        }

        case 4:
        {
        }

        case 5:
            break;

        default:
            cout << "Opcao invalida" << endl;
        }

    } while (option != 5);

    return 0;
}

double averageGoalEvolutionScored(Team team)
{
    vector<vector<unsigned int>> goalsScored = team.getGoalsScored();

    double movingAverage = 0;
    for (unsigned int championship = 0; championship < goalsScored.size(); championship++)
    {
        for (unsigned int year = goalsScored[championship].size(); year > 0; year--)
        {
            cout << goalsScored[championship][year] << endl;
            movingAverage += goalsScored[championship][year];
        }
    }
    return movingAverage / 3;
}

double averageGoalEvolutionConceded(Team team)
{
    vector<vector<unsigned int>> goalsConceded = team.getGoalsConceded();

    double movingAverage = 0;
    for (unsigned int championship = 0; championship < goalsConceded.size(); championship++)
    {
        for (unsigned int year = goalsConceded[championship].size(); year > 0; year--)
        {
            movingAverage += goalsConceded[championship][year];
        }
    }
    return movingAverage / 3;
}