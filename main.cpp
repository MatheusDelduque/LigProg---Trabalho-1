// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "liga.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printAverageGoalEvolution(Team team, vector<double> listGoalEvolution, string typeGoal, string typeMovingAverage);
void printGoalPerformanceEachChampionship(vector<Team> teams, vector<vector<string>> listTeamsGoalPerformance, string typePerformance);
void printGoalPerformanceAllChampionship(vector<Team> teams, vector<vector<string>> listTeamsGoalPerformance, string typePerformance);

int main()
{
    Liga liga;

    // [Campeonato][Anos] = Gols marcados
    vector<vector<unsigned int>> goalsScoredTeamA =
        {{0, 0, 1, 20},
         {0, 0, 2, 3},
         {0, 1, 0, 3}};

    // [Campeonato][Anos] = Gols sofridos
    vector<vector<unsigned int>> goalsConcededA =
        {{0, 0, 20, 12},
         {1, 2, 3, 5},
         {0, 1, 2, 4}};

    vector<vector<unsigned int>> goalsScoredTeamB =
        {{0, 5, 0, 4},
         {1, 0, 3, 2},
         {0, 3, 0, 4}};

    vector<vector<unsigned int>> goalsConcededB =
        {{0, 2, 0, 0},
         {1, 0, 2, 2},
         {0, 0, 2, 1}};

    vector<vector<unsigned int>> goalsScoredTeamC =
        {{1, 0, 0, 10},
         {0, 0, 4, 1},
         {3, 1, 2, 5}};

    vector<vector<unsigned int>> goalsConcededC =
        {{1, 0, 0, 10},
         {0, 0, 4, 0},
         {0, 2, 0, 0}};

    // Criar o time
    Team teamA("Flamengo", goalsScoredTeamA, goalsConcededA);
    Team teamB("Vasco", goalsScoredTeamB, goalsConcededB);
    Team teamC("Botafogo", goalsScoredTeamC, goalsConcededC);

    // Adicionar o time na liga
    liga.addTime(teamA);
    liga.addTime(teamB);
    liga.addTime(teamC);

    // Pegar os times da liga
    vector<Team> teams = liga.getTeams();

    unsigned int currentYear = 0;

    int option = 0;

    do
    {
        cout << "Selecione uma opcao:" << endl;
        cout << "1 - Exibir a evolução da média dos gols realizados e sofridos" << endl;
        cout << "2 - Mostrar a evolucao de gols sofridos de um time" << endl;
        cout << "3 - Mostrar a evolucao de gols marcados e sofridos de um time" << endl;
        cout << "4 - Exibir o time com maior saldo de gols em cada campeonato" << endl;
        cout << "5 - Exibir o time que teve a maior evolução no último ano em relação aos gols efetuados e gols sofridos" << endl;
        cout << endl;
        cout << "0 - Sair" << endl;

        cout << endl;

        cin >> option;
        cout << endl;

        switch (option)
        {
        case 1:
        {
            for (unsigned int index = 0; index < teams.size(); index++)
            {
                Team team = teams[index];

                vector<double> listGoalEvolutionScoredPerYearCurrentYear = liga.averageGoalEvolutionScoredPerYear(team, currentYear);
                printAverageGoalEvolution(team, listGoalEvolutionScoredPerYearCurrentYear, "scored", "year");
                cout << endl;

                vector<double> listGoalEvolutionConcededPerYearCurrentYear = liga.averageGoalEvolutionConcededPerYear(team, currentYear);
                printAverageGoalEvolution(team, listGoalEvolutionConcededPerYearCurrentYear, "conceded", "year");
                cout << endl;

                vector<double> listGoalEvolutionScoredPerChampionshipCurrentYear = liga.averageGoalEvolutionScoredPerChampionship(team, currentYear);
                printAverageGoalEvolution(team, listGoalEvolutionScoredPerChampionshipCurrentYear, "scored", "championship");

                vector<double> listGoalEvolutionConcededPerChampionshipCurrentYear = liga.averageGoalEvolutionConcededPerChampionship(team, currentYear);
                printAverageGoalEvolution(team, listGoalEvolutionConcededPerChampionshipCurrentYear, "conceded", "championship");
                cout << endl;
            }

            break;
        }

        case 2:
        {

            vector<vector<string>> listTeamsGoalPerformanceImprovement = liga.goalPerformanceEachChampionship(teams, "improvement");
            printGoalPerformanceEachChampionship(teams, listTeamsGoalPerformanceImprovement, "improvement");
            cout << endl;

            vector<vector<string>> listTeamsGoalPerformanceWorsened = liga.goalPerformanceEachChampionship(teams, "worsened");
            printGoalPerformanceEachChampionship(teams, listTeamsGoalPerformanceWorsened, "worsened");
            cout << endl;

            vector<vector<string>> listTeamsGoalPerformanceStable = liga.goalPerformanceEachChampionship(teams, "stable");
            printGoalPerformanceEachChampionship(teams, listTeamsGoalPerformanceStable, "stable");
            cout << endl;

            break;
        }

        case 3:
        {

            vector<vector<string>> listTeamsGoalPerformanceImprovement = liga.goalPerformanceAllChampionship(teams, "improvement");
            printGoalPerformanceAllChampionship(teams, listTeamsGoalPerformanceImprovement, "improvement");
            cout << endl;

            vector<vector<string>> listTeamsGoalPerformanceWorsened = liga.goalPerformanceAllChampionship(teams, "worsened");
            printGoalPerformanceAllChampionship(teams, listTeamsGoalPerformanceWorsened, "worsened");
            cout << endl;

            vector<vector<string>> listTeamsGoalPerformanceStable = liga.goalPerformanceAllChampionship(teams, "stable");
            printGoalPerformanceAllChampionship(teams, listTeamsGoalPerformanceStable, "stable");
            cout << endl;

            break;
        }

        case 4:
        {
            liga.highestGoalDifferenceChampionship(teams);
            cout << endl;

            break;
        }

        case 5:
        {
            liga.teamGreatestEvolution(teams);
            cout << endl;

            break;
        }

        case 0:
            break;

        default:
            cout << "Opcao invalida" << endl;
        }

    } while (option != 0);

    return 0;
}

// Esta função imprime a evolução média de gols de um time para cada campeonato ou para todos os campeonatos, dependendo do tipo de média móvel escolhido.
void printAverageGoalEvolution(Team team, vector<double> listGoalEvolution, string typeGoal, string typeMovingAverage)
{
    for (unsigned int index = 0; index < listGoalEvolution.size(); index++)
    {
        if (typeMovingAverage == "year")
        {
            if (typeGoal == "scored")
            {
                cout << fixed << setprecision(1) << "The average goal evolution of "
                     << team.getName() << " in the Championship " << index << " is: "
                     << listGoalEvolution[index] << endl;
            }
            else
            {
                cout << fixed << setprecision(1) << "The average goal evolution of "
                     << team.getName() << " in the Championship " << index << " is: "
                     << listGoalEvolution[index] << endl;
            }
        }
        else
        {
            if (typeGoal == "scored")
            {
                cout << fixed << setprecision(1) << "The average goal evolution of "
                     << team.getName() << " in all championships is: "
                     << listGoalEvolution[index] << endl;
            }
            else
            {
                cout << fixed << setprecision(1) << "The average goal evolution of "
                     << team.getName() << " in all championships is: "
                     << listGoalEvolution[index] << endl;
            }
        }
    }
}

// Esta função imprime a lista de times com melhoria, piora ou que se mantiveram estáveis em cada campeonato.
void printGoalPerformanceEachChampionship(vector<Team> teams, vector<vector<string>> listTeamsGoalPerformance, string typePerformance)
{
    // Percorre cada campeonato
    for (unsigned int championship = 0; championship < listTeamsGoalPerformance.size(); championship++)
    {
        // Exibe a lista de times com melhoria, piora ou que se mantiveram estáveis em cada campeonato
        if (typePerformance == "improvement")
        {
            cout << "Lista de times com melhoria no campeonato " << championship + 1 << ": ";
        }
        else if (typePerformance == "worsened")
        {
            cout << "Lista de times com piora no campeonato " << championship + 1 << ": ";
        }
        else
        {
            cout << "Lista de times que se mantiveram estaveis no campeonato " << championship + 1 << ": ";
        }

        // Percorre cada time
        for (unsigned int index = 0; index < listTeamsGoalPerformance.size(); index++)
        {
            // Verifica se o time atual tem melhoria no campeonato
            if (find(listTeamsGoalPerformance[index].begin(), listTeamsGoalPerformance[index].end(), to_string(championship + 1)) != listTeamsGoalPerformance[index].end())
            {
                // Exibe o nome do time
                cout << teams[index].getName() << (index == listTeamsGoalPerformance.size() - 1 ? "" : ", ");
            }
        }

        cout << endl;
    }
}

/*
Esta função imprime a lista de times com melhoria, piora ou que se mantiveram estáveis em toda a Liga.
Para isso, ela percorre cada time e verifica se o time tem melhoria, piora ou se mantém estável em todos os campeonatos.
Se o time tiver melhoria, piora ou se mantiver estável em todos os campeonatos, o nome do time é exibido na lista final.
*/
void printGoalPerformanceAllChampionship(vector<Team> teams, vector<vector<string>> listTeamsGoalPerformance, string typePerformance)
{
    if (typePerformance == "improvement")
    {
        // Exibe a lista de times com melhoria na Liga
        cout << "Lista de times com melhoria na Liga: ";
    }
    else if (typePerformance == "worsened")
    {
        // Exibe a lista de times com piora na Liga
        cout << "Lista de times com piora na Liga: ";
    }
    else
    {
        // Exibe a lista de times que se mantiveram estaveis na Liga
        cout << "Lista de times que se mantiveram estaveis na Liga: ";
    }

    for (unsigned int index = 0; index < listTeamsGoalPerformance.size(); index++)
    {
        // Verifica se o time atual tem melhoria, piora ou se mantém estável em todos os campeonatos
        if (find(listTeamsGoalPerformance[index].begin(), listTeamsGoalPerformance[index].end(), to_string(1)) != listTeamsGoalPerformance[index].end() &&
            find(listTeamsGoalPerformance[index].begin(), listTeamsGoalPerformance[index].end(), to_string(listTeamsGoalPerformance[0].size())) != listTeamsGoalPerformance[index].end())
        {
            // Exibe o nome do time
            cout << teams[index].getName() << (index == listTeamsGoalPerformance.size() - 1 ? "" : ", ");
        }
    }
    cout << endl;
}
