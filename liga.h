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
    double averageGoalEvolution(string nameTeam, vector<vector<unsigned int>> gols, double (*) (Team team));

private:
    vector<Team> teams;
};