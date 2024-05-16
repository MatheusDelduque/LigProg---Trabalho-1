// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "liga.h"
#include <iomanip>

void Liga::addTime(Team team)
{
    teams.push_back(team);
}

vector<Team> Liga::getTeams()
{
    return teams;
};

// Funcao que calcula a evolucao media de gols marcados por um time em cada ano de um campeonato especifico
void Liga::averageGoalEvolutionScoredPerYear(Team team)
{
    // Vetor de vetores que armazena os gols marcados de cada campeonato
    vector<vector<unsigned int>> goalsScored = team.getGoalsScored();

    // Variavel para armazenar a media móvel
    double movingAverage = 0;

    // Para cada campeonato
    for (unsigned int championship = 0; championship < goalsScored.size(); championship++)
    {
        // Para cada ano do campeonato
        for (unsigned int year = 0; year < goalsScored[championship].size() - 1; year++)
        {
            // Somamos os gols marcados no ano atual
            movingAverage += goalsScored[championship][year];
        }

        // Imprimimos a media móvel do campeonato atual
        cout << fixed << setprecision(1) << "A evolucao media de gols marcados do "
             << team.getName() << " no Campeonato " << championship << " eh: "
             << movingAverage / goalsScored[championship].size() << endl;
    }
}

// Funcao que calcula a evolucao media de gols marcados por um time em todos os campeonatos
void Liga::averageGoalEvolutionScoredPerChampionship(Team team)
{
    // Vetor de vetores que armazena os gols marcados de cada campeonato
    vector<vector<unsigned int>> goalsScored = team.getGoalsScored();

    // Variavel para armazenar a media móvel
    double movingAverage = 0;

    // Para cada campeonato
    for (unsigned int championship = 0; championship < goalsScored.size(); championship++)
    {
        // Para cada ano do campeonato
        for (unsigned int year = 0; year < goalsScored[championship].size() - 1; year++)
        {
            // Somamos os gols marcados no ano atual
            movingAverage += goalsScored[championship][year];
        }
    }

    // Imprimimos a media móvel de todos os campeonatos
    cout << fixed << setprecision(1) << "A evolucao media de gols marcados do "
         << team.getName() << " em todos os campeonatos eh: "
         << movingAverage / goalsScored.size() << endl;
}

// Funcao que calcula a evolucao media de gols sofridos por um time em cada ano de um campeonato especifico
void Liga::averageGoalEvolutionConcededPerYear(Team team)
{
    // Vetor de vetores que armazena os gols sofridos de cada campeonato
    vector<vector<unsigned int>> goalsConceded = team.getGoalsConceded();

    // Variavel para armazenar a media móvel
    double movingAverage = 0;

    // Para cada campeonato
    for (unsigned int championship = 0; championship < goalsConceded.size(); championship++)
    {
        // Para cada ano do campeonato
        for (unsigned int year = 0; year < goalsConceded[championship].size() - 1; year++)
        {
            // Somamos os gols sofridos no ano atual
            movingAverage += goalsConceded[championship][year];
        }

        // Imprimimos a media móvel do campeonato atual
        cout << fixed << setprecision(1) << "A evolucao media de gols sofridos do "
             << team.getName() << " no Campeonato " << championship << " eh: "
             << movingAverage / goalsConceded[championship].size() << endl;
    }
}

// Funcao que calcula a evolucao media de gols sofridos por um time em todos os campeonatos
void Liga::averageGoalEvolutionConcededPerChampionship(Team team)
{
    // Vetor de vetores que armazena os gols sofridos de cada campeonato
    vector<vector<unsigned int>> goalsConceded = team.getGoalsConceded();

    // Variavel para armazenar a media móvel
    double movingAverage = 0;

    // Para cada campeonato
    for (unsigned int championship = 0; championship < goalsConceded.size(); championship++)
    {
        // Para cada ano do campeonato
        for (unsigned int year = 0; year < goalsConceded[championship].size() - 1; year++)
        {
            // Somamos os gols sofridos no ano atual
            movingAverage += goalsConceded[championship][year];
        }
    }

    // Imprimimos a media móvel de todos os campeonatos
    cout << fixed << setprecision(1) << "A evolucao media de gols sofridos do "
         << team.getName() << " em todos os campeonatos eh: "
         << movingAverage / goalsConceded.size() << endl;
}

// Funcao que calcula o time com a maior diferença de gols entre todos os campeonatos
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
