// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "liga.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void averageGoalEvolutionScoredPerYear(Team team);
void averageGoalEvolutionScoredPerChampionship(Team team);

void averageGoalEvolutionConcededPerYear(Team team);
void averageGoalEvolutionConcededPerChampionship(Team team);

int main()
{
    Liga liga;

    // [Campeonato][Anos] = Gols marcados
    vector<vector<unsigned int>> goalsScoredTeamA =
        {{0, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}};

    // [Campeonato][Anos] = Gols sofridos
    vector<vector<unsigned int>> goalsConcededA =
        {{0, 0, 1, 1},
         {1, 2, 3, 5},
         {0, 1, 2, 0}};

    vector<vector<unsigned int>> goalsScoredTeamB =
        {{0, 0, 0, 0},
         {1, 0, 3, 0},
         {0, 0, 0, 0}};

    vector<vector<unsigned int>> goalsConcededB =
        {{0, 2, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 2, 0}};

    vector<vector<unsigned int>> goalsScoredTeamC =
        {{0, 0, 0, 0},
         {0, 0, 0, 0},
         {3, 1, 2, 5}};

    vector<vector<unsigned int>> goalsConcededC =
        {{3, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}};

    // Criar o time
    Team teamA("Time A", goalsScoredTeamA, goalsConcededA);
    Team teamB("Time B", goalsScoredTeamB, goalsConcededB);
    Team teamC("Time C", goalsScoredTeamC, goalsConcededC);

    // Adicionar o time na liga
    liga.addTime(teamA);
    liga.addTime(teamB);
    liga.addTime(teamC);
    int option = 0;
    do
    {
        cout << "Selecione uma opcao:" << endl;
        cout << "1 - Exibir a evolução da média dos gols realizados e sofridos" << endl;
        cout << "2 - Mostrar a evolucao de gols sofridos de um time" << endl;
        cout << "3 - Mostrar a evolucao de gols marcados e sofridos de um time" << endl;
        cout << "4 - Exibir o time com maior saldo de gols em cada campeonato" << endl;
        cout << "5 - Exibir o time que teve a maior evolução no último ano em relação aos gols efetuados e gols sofridos" << endl;
        cout << "0 - Sair" << endl;

        cout << endl;

        cin >> option;
        cout << endl;

        switch (option)
        {
        case 1:
        {
            vector<Team> teams = liga.getTeams();
            for (unsigned int index = 0; index < teams.size(); index++)
            {
                Team team = teams[index];

                liga.averageGoalEvolutionScoredPerYear(team);
                cout << endl;

                liga.averageGoalEvolutionConcededPerYear(team);
                cout << endl;

                liga.averageGoalEvolutionScoredPerChampionship(team);
                liga.averageGoalEvolutionConcededPerChampionship(team);
                cout << endl;
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
            vector<Team> teams = liga.getTeams();
            liga.highestGoalDifferenceChampionship(teams);
            cout << endl;

            break;
        }

        case 5:
            break;

        case 0:
            break;

        default:
            cout << "Opcao invalida" << endl;
        }

    } while (option != 5);

    return 0;
}
