#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum enChoice {Stone = 1, Paper = 2, Scissors = 3};

struct stGameResults
{
    short GameRounds = 0;
    short PlayerWonTimes = 0;
    short ComuterWonTimes = 0;
    short DrawTimes = 0;
};

int RandomNumber(int From, int To)
{
    return (rand() % (To - From + 1) + From);
}

short ReadRounds()
{
    short Rounds;
    do
    {
        cout << "How many round do you need 1 to 10? \n";
        cin >> Rounds;
    }
    while (Rounds < 1 || Rounds > 10);

    return Rounds;
}

enChoice ReadPlayerChoice()
{
    short PlayerChoice;

    do 
    {
        cout << "Enter Your Choice [1]: Stone, [2]: Paper, [3]: Scissors: ";
        cin >> PlayerChoice;
    }
    while (PlayerChoice < 1 || PlayerChoice > 3);

    return enChoice(PlayerChoice);   
}

enChoice ReadComputerChoice()
{
    short ComputerChoice = RandomNumber(1, 3);

    return enChoice(ComputerChoice);
}

string GetChoiceName(enChoice Choice)
{
    string arr[3] = {"Stone", "Paper", "Scissors"};
    return arr[Choice - 1];
}

string RoundWinner(enChoice PlayerChoice, enChoice ComputerChoice, stGameResults &GameResults)
{
    if (PlayerChoice == enChoice::Paper)
    {
        switch (ComputerChoice)
        {
            case enChoice::Stone:
                GameResults.PlayerWonTimes++;
                return "[Player]";
            case enChoice::Scissors:
                GameResults.ComuterWonTimes++;
                return "[Computer\a]";
            default:
                GameResults.DrawTimes++;
                return "[No Winner]";
        }
    }    
    else if (PlayerChoice == enChoice::Stone)
    {
        switch (ComputerChoice)
        {
            case enChoice::Paper:
                GameResults.ComuterWonTimes++;
                return "[Comuter\a]";
            case enChoice::Scissors:
                GameResults.PlayerWonTimes++;
                return "[Player]";
            default:
                GameResults.DrawTimes++;
                return "[No Winner]";
        }
    }
    else if (PlayerChoice == enChoice::Scissors)
    {
        switch (ComputerChoice)
        {
            case enChoice::Paper:
                GameResults.PlayerWonTimes++;
                return "[Player]";
            case enChoice::Stone:
                GameResults.ComuterWonTimes++;
                return "[Computer\a]";
            default:
                GameResults.DrawTimes++;
                return "[No Winner]";
        }
    }
}

void ShowRoundResult(enChoice PlayerChoice, enChoice ComputerChoice, string RoundWinner, short Round)
{
    string stringPlayerChoice, stringComputerChoice;

    stringPlayerChoice = GetChoiceName(PlayerChoice);
    stringComputerChoice = GetChoiceName(ComputerChoice);

    cout << "\n_______________ Round[" << Round << "] _______________\n";
    cout << "Player   Choice: " << stringPlayerChoice << endl;
    cout << "Computer Choice: " << stringComputerChoice << endl;
    cout << "Round Winner   : " << RoundWinner << endl;
    cout << "______________________________________________________\n\n";
}

void StartRound(short Round, stGameResults &GameResults)
{
    enChoice PlayerChoice, ComputerChoice;
    string Winner;

    PlayerChoice = ReadPlayerChoice();
    ComputerChoice = ReadComputerChoice();
    Winner = RoundWinner(PlayerChoice, ComputerChoice, GameResults);

    ShowRoundResult(PlayerChoice, ComputerChoice, Winner, Round);
}

string FinalWinner(stGameResults GameResult)
{
    if (GameResult.PlayerWonTimes > GameResult.ComuterWonTimes)
        return "[Player Win]";
    else if (GameResult.PlayerWonTimes < GameResult.ComuterWonTimes)
        return "[Computer Win\a]";
    else 
        return "[No Winner]";
}

void GameOver()
{
    cout << "\n\n_______________________________________________________________\n\n";
    cout << "\t\t+ + + G a m e   O v e r + + +";
    cout << "\n\n_______________________________________________________________\n\n";  
}

void ShowGameResult(stGameResults GameResult)
{
    cout << "________________________ [Game Result] ________________________\n\n";
    cout << "Game Rounds       : " << GameResult.GameRounds << endl;
    cout << "Player Won Times  : " << GameResult.PlayerWonTimes << endl;
    cout << "Computer Won Times: " << GameResult.ComuterWonTimes << endl;
    cout << "Draw Times        : " << GameResult.DrawTimes << endl;
    cout << "Final Winner      : " << FinalWinner(GameResult) << endl;
    cout << "\n\n_______________________________________________________________\n\n";  
}

void StartGame()
{
    char PlayAgain;
    do
    {
        stGameResults GameResults;
        GameResults.GameRounds = ReadRounds();
        cout << endl;

        for (short Round = 1; Round <= GameResults.GameRounds; Round++)
        {
            cout << "Round [" << Round << "] begins: \n\n";
            StartRound(Round, GameResults);
        }

        GameOver();
        ShowGameResult(GameResults);

        cout << "Do You Need to Play Again [Y/N]: ";
        cin >> PlayAgain;
    } 
    while (PlayAgain != 'N');
}


int main()
{
    srand(unsigned(time(NULL)));

    StartGame();

    return 0;
}