// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include <vector>
#include "time.h"
#include <algorithm>

using namespace std;

class Liga
{
public:
    void addTime(Team team);
    vector<Team> getTeams();

    vector<double> averageGoalEvolutionScoredPerChampionship(Team team, unsigned int year);
    vector<double> averageGoalEvolutionScoredPerYear(Team team, unsigned int year);

    vector<double> averageGoalEvolutionConcededPerChampionship(Team team, unsigned int year);
    vector<double> averageGoalEvolutionConcededPerYear(Team team, unsigned int year);

    vector<vector<string>> goalPerformanceEachChampionship(vector<Team> teams, string typePerformance);

    vector<vector<string>> goalPerformanceAllChampionship(vector<Team> teams, string typePerformance);

    void highestGoalDifferenceChampionship(vector<Team> teams);

    void teamGreatestEvolution(vector<Team> teams);

private:
    vector<Team> teams;
};