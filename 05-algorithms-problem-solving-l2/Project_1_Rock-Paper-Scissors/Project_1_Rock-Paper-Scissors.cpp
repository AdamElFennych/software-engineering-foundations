#include <iostream>
using namespace std;

enum enChoses
{
    Stone = 1, Paper = 2, Scissors = 3
};
enum enWiner
{
    user = 1, Computer = 2, NoWiner = 3
};
enChoses IntToEnum(int chose)
{
    return enChoses(chose);
}
int GetRandomNUmber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}
int HowManyRounds1To10()
{
    int Rounds = 0;
    do
    {
        cout << "How Many Rounds 1 to 10 ?" << endl;
        cin >> Rounds;
    } while (Rounds > 10 || Rounds < 1);
    return Rounds;
}
int UserChoice()
{
    int Chose;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?";
        cin >> Chose;
    } while (Chose > 3 || Chose < 1);

    return Chose;
}
int ComputerChoice()
{
    return GetRandomNUmber(1, 3);
}
string TranslateChoice(enChoses Choses)
{
    switch (Choses)
    {
    case enChoses::Paper:
        return "Paper";
    case enChoses::Scissors:
        return "Scissors";
    case enChoses::Stone:
        return "Stone";
    }
}
string TranslateWiner(enWiner Winer)
{
    switch (Winer)
    {
    case enWiner::Computer:
        return "[Computer]";
    case enWiner::user:
        return "[Player1]";
    case enWiner::NoWiner:
        return "[NoWiner]";
    }
}
enWiner HowIsTheWiner(enChoses User, enChoses computer)
{
    if (User == enChoses::Paper)
    {
        switch (computer)
        {
        case enChoses::Paper:
            return enWiner::NoWiner;
        case enChoses::Scissors:
            return enWiner::Computer;
        case enChoses::Stone:
            return enWiner::user;
        }
    }
    else if (User == enChoses::Scissors)
    {
        switch (computer)
        {
        case enChoses::Paper:
            return enWiner::user;
        case enChoses::Scissors:
            return enWiner::NoWiner;
        case enChoses::Stone:
            return enWiner::Computer;
        }
    }
    else if (User == enChoses::Stone)
    {
        switch (computer)
        {
        case enChoses::Paper:
            return enWiner::Computer;
        case enChoses::Scissors:
            return enWiner::user;
        case enChoses::Stone:
            return enWiner::NoWiner;
        }
    }
}
void RoundResult(enChoses user, enChoses computer, int Round, enWiner Winer)
{
    cout << "___________________" << Round << "___________________\n\n";
    cout << "Player1  Choice: " << TranslateChoice(user) << endl;
    cout << "Computer Choice: " << TranslateChoice(computer) << endl;
    cout << "Round Winner   : " << TranslateWiner(Winer) << endl;
    cout << "_______________________________________\n";

}
void GameOver(int ComputerWinTimes, int UserWinTimes, int DrawTimes, int Rounds)
{
    cout << "\n\t\t--------------------------------------------------------\n";
    cout << "\n\t\t\t\t+++ G a m e  O v e r +++\n";
    cout << "\n\t\t--------------------------------------------------------\n";
    cout << "\n\t\t___________________ [Game Results ] ____________________\n";
    cout << "\t\tGame Rounds        : " << Rounds << endl;
    cout << "\t\tPlayer1 won times  : " << UserWinTimes << endl;
    cout << "\t\tComputer won times : " << ComputerWinTimes << endl;
    cout << "\t\tDraw times         : " << DrawTimes << endl;
    if (UserWinTimes < ComputerWinTimes)
    {
        cout << "\t\tFinal winner       : Coumputer" << endl;
    }
    else if (UserWinTimes > ComputerWinTimes)
    {
        cout << "\t\tFinal winner       : Player1" << endl;
    }
    else
    {
        cout << "\t\tFinal winner       : Draw" << endl;
    }
    cout << "\t\t________________________________________________________\n";
}
void IfSom1Win(enWiner Winer, int& ComputerWinTimes, int& UserWinTimes, int& DrawTimes)
{
    if (Winer == enWiner::Computer)
    {
        ++ComputerWinTimes;
        cout << "\a";
        system("color 4F");
    }
    else if (Winer == enWiner::user)
    {
        ++UserWinTimes;
        system("color 2F");
    }
    else
    {
        ++DrawTimes;
        system("color 6F");
    }
}
void theGame()
{
    int ComputerWinTimes = 0, UserWinTimes = 0, DrawTimes = 0;
    int Rounds = HowManyRounds1To10();
    for (int i = 1; i <= Rounds; i++)
    {
        cout << "\nRound [" << i << "] begins:\n";
        enChoses user = IntToEnum(UserChoice());
        enChoses computer = IntToEnum(ComputerChoice());
        enWiner Winer = HowIsTheWiner(user, computer);
        RoundResult(user, computer, i, Winer);
        IfSom1Win(Winer, ComputerWinTimes, UserWinTimes, DrawTimes);
    }
    GameOver(ComputerWinTimes, UserWinTimes, DrawTimes, Rounds);

}
void StartGame()
{
    char Countunu = 'Y';
    do
    {
        system("cls");
        system("color 07");

        theGame();
        cout << "\n\t\tDo you want to play agin? Y/N?";
        cin >> Countunu;

    } while (Countunu == 'Y' || Countunu == 'y');
}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}
