// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include <vector>
#include "time.h"

using namespace std;

class Liga
{
public:
    void addTime(Team team);
    vector<Team> getTeams();
    
    void averageGoalEvolutionScoredPerChampionship(Team team);
    void averageGoalEvolutionScoredPerYear(Team team);
    void averageGoalEvolutionConcededPerChampionship(Team team);
    void averageGoalEvolutionConcededPerYear(Team team);

    void highestGoalDifferenceChampionship(vector<Team> teams);

private:
    vector<Team> teams;
};