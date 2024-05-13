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
    void averageGoalEvolution(Team team, void (*) (Team team));
    void highestGoalDifferenceChampionship(vector<Team> teams);

private:
    vector<Team> teams;
};