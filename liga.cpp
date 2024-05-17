// Linguagem de Programacao - Trabalho 01
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "liga.h"
#include <iomanip>
#include <algorithm>

// Metodo para adicionar um time na lista de times
void Liga::addTeam(Team team)
{
    teams.push_back(team);
}

// Esta funcao adiciona um novo time a lista de times da liga.
vector<Team> Liga::getTeams()
{
    return teams;
};

// Funcao que calcula a evolucao media de gols marcados por um time em cada ano de um campeonato especifico
vector<double> Liga::averageGoalEvolutionScoredPerYear(Team team, unsigned int startingYear)
{
    // Vetor de vetores que armazena os gols marcados de cada campeonato
    vector<vector<unsigned int>> goalsScored = team.getGoalsScored();

    // Variavel para armazenar as media movel
    vector<double> listGoalEvolutionScoredPerYear;

    // Percorre cada campeonato
    for (unsigned int championship = 0; championship < goalsScored.size(); championship++)
    {
        // Variavel para armazenar a media movel
        double movingAverage = 0;

        // Percorre cada ano do campeonato
        for (unsigned int year = startingYear; year < goalsScored[championship].size() - 1 + startingYear; year++)
        {
            // Somamos os gols marcados no ano atual
            movingAverage += goalsScored[championship][year];
        }

        // Adicionamos as medias moveis para cada campeonato a uma lista
        listGoalEvolutionScoredPerYear.push_back(movingAverage / goalsScored[championship].size());
    }

    return listGoalEvolutionScoredPerYear;
}
// Esta funcao calcula a evolucao media de gols sofridos por um time em cada ano de um campeonato especifico.
vector<double> Liga::averageGoalEvolutionConcededPerYear(Team team, unsigned int startingYear)
{
    // Vetor de vetores que armazena os gols sofridos de cada campeonato
    vector<vector<unsigned int>> goalsConceded = team.getGoalsConceded();

    // Variavel para armazenar a media maxima
    vector<double> listGoalEvolutionConcededPerYear;

    // Percorre cada campeonato
    for (unsigned int championship = 0; championship < goalsConceded.size(); championship++)
    {
        // Variavel para armazenar a media móvel
        double movingAverage = 0;
        // Percorre cada ano do campeonato
        for (unsigned int year = startingYear; year < goalsConceded[championship].size() - 1 + startingYear; year++)
        {
            // Somamos os gols sofridos no ano atual
            movingAverage += goalsConceded[championship][year];
        }
        // Calcula a media movel dividindo pela quantidade de anos e adiciona ao vetor de medias
        listGoalEvolutionConcededPerYear.push_back(movingAverage / goalsConceded[championship].size());
    }

    return listGoalEvolutionConcededPerYear;
}

// Funcao que calcula a evolucao media de gols marcados por um time em todos os campeonatos
vector<double> Liga::averageGoalEvolutionScoredPerChampionship(Team team, unsigned int startingYear)
{
    // Vetor de vetores que armazena os gols marcados de cada campeonato
    vector<vector<unsigned int>> goalsScored = team.getGoalsScored();

    vector<double> listGoalEvolutionScoredPerChampionship;

    // Variavel para armazenar a media movel
    double movingAverage = 0;

    // Percorre cada campeonato
    for (unsigned int championship = 0; championship < goalsScored.size(); championship++)
    {
        // Percorre cada ano do campeonato
        for (unsigned int year = startingYear; year < goalsScored[championship].size() - 1 + startingYear; year++)
        {
            // Somamos os gols marcados no ano atual
            movingAverage += goalsScored[championship][year];
        }
    }

    // Calcula a media movel dividindo pela quantidade de anos e adiciona as medias moveis para cada campeonato a uma lista
    listGoalEvolutionScoredPerChampionship.push_back(movingAverage / goalsScored.size());
    return listGoalEvolutionScoredPerChampionship;
}

// Funcao que calcula a evolucao media de gols sofridos por um time em todos os campeonatos
vector<double> Liga::averageGoalEvolutionConcededPerChampionship(Team team, unsigned int startingYear)
{
    // Vetor de vetores que armazena os gols sofridos de cada campeonato
    vector<vector<unsigned int>> goalsConceded = team.getGoalsConceded();

    vector<double> listGoalEvolutionConcededPerChampionship;

    // Variavel para armazenar a media móvel
    double movingAverage = 0;

    // Percorre cada campeonato
    for (unsigned int championship = 0; championship < goalsConceded.size(); championship++)
    {
        // Percorre cada ano do campeonato
        for (unsigned int year = startingYear; year < goalsConceded[championship].size() - 1 + startingYear; year++)
        {
            // Somamos os gols sofridos no ano atual
            movingAverage += goalsConceded[championship][year];
        }
    }

    // Calcula a media movel dividindo pela quantidade de anos e adiciona as medias moveis para cada campeonato a uma lista
    listGoalEvolutionConcededPerChampionship.push_back(movingAverage / goalsConceded.size());
    return listGoalEvolutionConcededPerChampionship;
}

/*
 * Esta funcao calcula a melhoria de performance de gol de cada time em cada campeonato.
 * Para isso, ela percorre cada time e, para cada campeonato, compara a media de gols marcados
 * daquele ano com a media de gols marcados do ano anterior. Se a porcentagem de aumento for maior
 * que 10%, o campeonato e o nome do time sao adicionados a uma lista de campeonatos com melhoria.
 * No final, a lista de times com melhoria e exibida.
 */
vector<vector<string>> Liga::goalPerformanceEachChampionship(vector<Team> teams, string typePerformance)
{
    // Cria uma instancia da classe Liga
    Liga liga;

    // Inicia o ano atual com 0
    unsigned int currentYear = 0;
    // Inicia o ano anterior com 1
    unsigned int lastYear = 1;

    // Cria um vetor de vetores para armazenar a lista de campeonatos com melhoria para cada time
    vector<vector<string>> listTeamsGoalPerformanceImprovement;

    // Cria um vetor de vetores para armazenar a lista de campeonatos com piora para cada time
    vector<vector<string>> listTeamsGoalPerformanceWorsened;

    // Cria um vetor de vetores para armazenar a lista de campeonatos que se mantiveram estaveis para cada time
    vector<vector<string>> listTeamsGoalPerformanceStable;

    // Percorre cada time
    for (unsigned int index = 0; index < teams.size(); index++)
    {
        // Obtém o time atual
        Team team = teams[index];

        // Calcula a evolucao media de gols marcados do ano atual
        vector<double> listGoalEvolutionScoredPerYearCurrentYear = liga.averageGoalEvolutionScoredPerYear(team, currentYear);
        // Calcula a evolucao media de gols marcados do ano anterior
        vector<double> listGoalEvolutionScoredPerYearLastYear = liga.averageGoalEvolutionScoredPerYear(team, lastYear);

        // Calcula a evolucao media de gols sofridos do ano atual
        vector<double> listGoalEvolutionConcedPerYearCurrentYear = liga.averageGoalEvolutionConcededPerYear(team, currentYear);
        // Calcula a evolucao media de gols sofridos do ano anterior
        vector<double> listGoalEvolutionConcedPerYearLastYear = liga.averageGoalEvolutionConcededPerYear(team, lastYear);

        // Cria um vetor para armazenar a lista de campeonatos com melhoria para o time atual
        vector<string> teamsChampionshipsWithImprovement;

        // Cria um vetor para armazenar a lista de campeonatos com piora para o time atual
        vector<string> teamsChampionshipsWithWorsened;

        // Cria um vetor para armazenar a lista de campeonatos que se mantiveram estaveis para o time atual
        vector<string> teamsChampionshipsWithStable;

        // Percorre cada campeonato
        for (unsigned int championship = 0; championship < listGoalEvolutionScoredPerYearCurrentYear.size(); championship++)
        {

            // Calcula a porcentagem de aumento de gols marcados no campeonato
            double percentageIncrease = ((listGoalEvolutionScoredPerYearCurrentYear[championship] / listGoalEvolutionScoredPerYearLastYear[championship])) * 100;

            // Calcula a porcentagem de diminuicao de gols sofridos no campeonato
            double percentageDecrease = ((listGoalEvolutionConcedPerYearCurrentYear[championship] / listGoalEvolutionConcedPerYearLastYear[championship])) * 100;

            // Verifica se a porcentagem de aumento foi maior que 10%
            if (percentageIncrease > 10 || percentageDecrease < 10)
            {
                // Adiciona o campeonato na lista de campeonatos com melhoria
                teamsChampionshipsWithImprovement.push_back(to_string(championship + 1));
            }
            if (percentageIncrease < 10 || percentageDecrease > 10)
            {
                // Adiciona o campeonato na lista de campeonatos com piora
                teamsChampionshipsWithWorsened.push_back(to_string(championship + 1));
            }
            if (percentageIncrease == 10 && percentageDecrease == 10)
            {
                // Adiciona o campeonato na lista de campeonatos que se mantiveram estaveis
                teamsChampionshipsWithStable.push_back(to_string(championship + 1));
            }
        }

        // Adiciona a lista de campeonatos com melhoria ao vetor de vetores
        listTeamsGoalPerformanceImprovement.push_back(teamsChampionshipsWithImprovement);

        // Adiciona a lista de campeonatos com piora ao vetor de vetores
        listTeamsGoalPerformanceWorsened.push_back(teamsChampionshipsWithWorsened);

        // Adiciona a lista de campeonatos que se mantiveram estaveis ao vetor de vetores
        listTeamsGoalPerformanceStable.push_back(teamsChampionshipsWithStable);
    }

    // Verifica o tipo de performance desejada
    if (typePerformance == "improvement")
    {
        // Retorna a lista de campeonatos com melhoria
        return listTeamsGoalPerformanceImprovement;
    }
    else if (typePerformance == "worsened")
    {
        // Retorna a lista de campeonatos com piora
        return listTeamsGoalPerformanceWorsened;
    }
    else
    {
        // Retorna a lista de campeonatos que se mantiveram estaveis
        return listTeamsGoalPerformanceStable;
    }
}

// Esta funcao calcula a evolucao de cada time em relacao aos outros times em todos os campeonatos.
vector<vector<string>> Liga::goalPerformanceAllChampionship(vector<Team> teams, string typePerformance)
{
    // Cria uma instancia da classe Liga
    Liga liga;

    // Inicia o ano atual com 0
    unsigned int currentYear = 0;
    // Inicia o ano anterior com 1
    unsigned int lastYear = 1;

    // Cria um vetor de vetores para armazenar a lista de campeonatos com melhoria para cada time
    vector<vector<string>> listTeamsGoalPerformanceImprovement;

    // Cria um vetor de vetores para armazenar a lista de campeonatos com piora para cada time
    vector<vector<string>> listTeamsGoalPerformanceWorsened;

    // Cria um vetor de vetores para armazenar a lista de campeonatos que se mantiveram estaveis para cada time
    vector<vector<string>> listTeamsGoalPerformanceStable;

    // Percorre cada time
    for (unsigned int index = 0; index < teams.size(); index++)
    {
        // Obtém o time atual
        Team team = teams[index];

        // Calcula a evolucao media de gols marcados do ano atual
        vector<double> listGoalEvolutionScoredPerYearCurrentYear = liga.averageGoalEvolutionScoredPerChampionship(team, currentYear);
        // Calcula a evolucao media de gols marcados do ano anterior
        vector<double> listGoalEvolutionScoredPerYearLastYear = liga.averageGoalEvolutionScoredPerChampionship(team, lastYear);

        vector<double> listGoalEvolutionConcedPerYearCurrentYear = liga.averageGoalEvolutionConcededPerChampionship(team, currentYear);
        vector<double> listGoalEvolutionConcedPerYearLastYear = liga.averageGoalEvolutionConcededPerChampionship(team, lastYear);

        // Cria um vetor para armazenar a lista de campeonatos com melhoria para o time atual
        vector<string> teamsChampionshipsWithImprovement;

        // Cria um vetor para armazenar a lista de campeonatos com piora para o time atual
        vector<string> teamsChampionshipsWithWorsened;

        // Cria um vetor para armazenar a lista de campeonatos que se mantiveram estaveis para o time atual
        vector<string> teamsChampionshipsWithStable;

        // Percorre cada campeonato
        for (unsigned int championship = 0; championship < listGoalEvolutionScoredPerYearCurrentYear.size(); championship++)
        {

            // Calcula a porcentagem de aumento de gols marcados no campeonato
            double percentageIncrease = ((listGoalEvolutionScoredPerYearCurrentYear[championship] / listGoalEvolutionScoredPerYearLastYear[championship])) * 100;

            // Calcula a porcentagem de diminuicao de gols sofridos no campeonato
            double percentageDecrease = ((listGoalEvolutionConcedPerYearCurrentYear[championship] / listGoalEvolutionConcedPerYearLastYear[championship])) * 100;

            // Verifica se a porcentagem de aumento foi maior que 10%
            if (percentageIncrease > 10 || percentageDecrease < 10)
            {
                // Adiciona o campeonato na lista de campeonatos com melhoria
                teamsChampionshipsWithImprovement.push_back(to_string(championship + 1));
            }
            if (percentageIncrease < 10 || percentageDecrease > 10)
            {
                // Adiciona o campeonato na lista de campeonatos com piora
                teamsChampionshipsWithWorsened.push_back(to_string(championship + 1));
            }
            if (percentageIncrease == 10 && percentageDecrease == 10)
            {
                // Adiciona o campeonato na lista de campeonatos que se mantiveram estaveis
                teamsChampionshipsWithStable.push_back(to_string(championship + 1));
            }
        }

        // Adiciona a lista de campeonatos com melhoria ao vetor de vetores
        listTeamsGoalPerformanceImprovement.push_back(teamsChampionshipsWithImprovement);

        // Adiciona a lista de campeonatos com piora ao vetor de vetores
        listTeamsGoalPerformanceWorsened.push_back(teamsChampionshipsWithWorsened);

        // Adiciona a lista de campeonatos que se mantiveram estaveis ao vetor de vetores
        listTeamsGoalPerformanceStable.push_back(teamsChampionshipsWithStable);
    }

    // Retorna a lista de campeonatos com melhoria de acordo com o parametro 'typePerformance'
    if (typePerformance == "improvement")
    {
        return listTeamsGoalPerformanceImprovement;
    }
    // Retorna a lista de campeonatos com piora de acordo com o parametro 'typePerformance'
    else if (typePerformance == "worsened")
    {
        return listTeamsGoalPerformanceWorsened;
    }
    // Retorna a lista de campeonatos que se mantiveram estaveis de acordo com o parametro 'typePerformance'
    else
    {
        return listTeamsGoalPerformanceStable;
    }
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

/*
 * Esta funcao calcula a evolucao de cada time em relacao aos outros times em todos os campeonatos.
 * Para isso, ela percorre cada time e, para cada campeonato, verifica se o time teve uma melhoria, piora ou mantem-se
 * estabil em relacao aos outros times. Em cada campeonato, o time com a maior melhoria e o time com a maior piora
 * sao contados. No final, exibe o time com a melhor evolucao e o time com a pior evolucao.
 */
void Liga::teamGreatestEvolution(vector<Team> teams)
{
    // Cria uma instancia da classe Liga
    Liga liga;

    // Cria um vetor de vetores para armazenar a lista de campeonatos com melhoria para cada time
    vector<vector<string>> listTeamsGoalPerformanceImprovement = liga.goalPerformanceEachChampionship(teams, "improvement");

    // Cria um vetor de vetores para armazenar a lista de campeonatos com piora para cada time
    vector<vector<string>> listTeamsGoalPerformanceWorsened = liga.goalPerformanceEachChampionship(teams, "worsened");

    // Cria um vetor para armazenar a contagem de campeonatos com melhoria para cada time
    vector<int> counterTeamPerformanceImprovement(teams.size(), 0);

    // Cria um vetor para armazenar a contagem de campeonatos com piora para cada time
    vector<int> counterTeamPerformanceWorsened(teams.size(), 0);

    // Percorre cada campeonato
    for (unsigned int championship = 0; championship < teams[0].getGoalsScored().size(); championship++)
    {
        // Percorre cada time
        for (unsigned int index = 0; index < teams.size(); index++)
        {
            // Verifica se o time teve uma melhoria no campeonato
            if (find(listTeamsGoalPerformanceImprovement[index].begin(), listTeamsGoalPerformanceImprovement[index].end(), to_string(championship + 1)) != listTeamsGoalPerformanceImprovement[index].end())
            {
                // Se tiver, adiciona 1 ao contador de melhorias do time
                counterTeamPerformanceImprovement[index]++;
            }

            // Verifica se o time teve uma piora no campeonato
            if (find(listTeamsGoalPerformanceWorsened[index].begin(), listTeamsGoalPerformanceWorsened[index].end(), to_string(championship + 1)) != listTeamsGoalPerformanceWorsened[index].end())
            {
                // Se tiver, adiciona 1 ao contador de piores do time
                counterTeamPerformanceWorsened[index]++;
            }
        }
    }

    // Encontra o time com a maior melhoria
    int maxCounterTeamPerformanceImprovement = *max_element(counterTeamPerformanceImprovement.begin(), counterTeamPerformanceImprovement.end());

    // Encontra o time com a maior piora
    int maxCounterTeamPerformanceWorsened = *max_element(counterTeamPerformanceWorsened.begin(), counterTeamPerformanceWorsened.end());

    // Exibe o time com a melhor evolucao
    cout << "O time com a melhor evoluçao foi o " << teams[distance(counterTeamPerformanceImprovement.begin(), find(counterTeamPerformanceImprovement.begin(), counterTeamPerformanceImprovement.end(), maxCounterTeamPerformanceImprovement))].getName() << endl;

    // Exibe o time com a pior evolucao
    cout << "O time com a pior evoluçao foi o " << teams[distance(counterTeamPerformanceWorsened.begin(), find(counterTeamPerformanceWorsened.begin(), counterTeamPerformanceWorsened.end(), maxCounterTeamPerformanceWorsened))].getName() << endl;
}
