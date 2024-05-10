// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Team
{
public:
    Team(string name, vector<vector<unsigned int>> goalsScored, vector<vector<unsigned int>> goalsConceded);

    void setName(string);
    vector<vector<unsigned int>> getGoalsScored();
    vector<vector<unsigned int>> getGoalsConceded();
    void setGoalsScored(vector<vector<unsigned int>>);
    void setGoalsConceded(vector<vector<unsigned int>>);
    string getName();

private:
    // Nome do time
    string name;

    // Gols marcardos num campeonato e num certo ano
    vector<vector<unsigned int>> goalsScored;

    // Gols sofridos num campeonato e num certo ano
    vector<vector<unsigned int>> goalsConceded;
};