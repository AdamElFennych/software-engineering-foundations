#include <iostream>
using namespace std;
enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, OpMix = 5 };
enum enPassOrFail{Pass = 1, Fail = 2};
struct stFinalResult
{
    short NumberOfQuestions = 0;
    enQuestionsLevel QuestionsLevel;
    enOperationType OperationType;
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;
};
struct stNumbers
{
    short Number1 = 0;
    short Number2 = 0;
    short Result = 0;
};
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message ;
        cin >> Number;          
    } while (Number < 0);      

    return Number;
}
enQuestionsLevel ReadQuestionsLevel()
{
    short QuestionsLevel = 1;
    do
    {
        QuestionsLevel = ReadPositiveNumber("Enter Questins Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?  ");

    } while (QuestionsLevel < 1 || QuestionsLevel>4);
    return (enQuestionsLevel)QuestionsLevel;
}
enOperationType ReadOperationType()
{
    short OperationType = 1;
    do
    { 
        OperationType = ReadPositiveNumber("Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?  ");
    } while (OperationType < 1 || OperationType>5);
    return (enOperationType)OperationType;
}
void NumberByLevel(enQuestionsLevel QuestionsLevel, short& Number1, short& Number2)
{
    switch (QuestionsLevel)
    {
    case enQuestionsLevel::Easy:
        Number1 = RandomNumber(1, 10);
        Number2 = RandomNumber(1,10);
        break;
    case enQuestionsLevel::Med:
        Number1 = RandomNumber(11, 50);
        Number2 = RandomNumber(11,50);
        break;
    case enQuestionsLevel::Hard:
        Number1 = RandomNumber(51, 100);
        Number2 = RandomNumber(51, 100);
        break;
    default:
        Number1 = RandomNumber(1, 100);
        Number2 = RandomNumber(1, 100);
        break;
    }
}
stNumbers PrintOperation(enQuestionsLevel QuestionsLevel, enOperationType OperationType)
{
    stNumbers Numbers;
    NumberByLevel(QuestionsLevel,Numbers.Number1,Numbers.Number2);
    switch (OperationType)
    {
    case Add:
        cout << Numbers.Number1 << endl << Numbers.Number2 << " +" << endl;
        cout << "-------------" << endl;
        Numbers.Result = Numbers.Number1 + Numbers.Number2;
        break;
    case Sub:
        cout << Numbers.Number1 << endl << Numbers.Number2 << " -" << endl;
        cout << "-------------" << endl;
        Numbers.Result = Numbers.Number1 - Numbers.Number2;
        break;
    case Mul:
        cout << Numbers.Number1 << endl << Numbers.Number2 << " *" << endl;
        cout << "-------------" << endl;
        Numbers.Result = Numbers.Number1 * Numbers.Number2;
        break;
    case Div:
        cout << Numbers.Number1 << endl << Numbers.Number2 << " /" << endl;
        cout << "-------------" << endl;
        Numbers.Result = Numbers.Number1 / Numbers.Number2;
        break;
    case OpMix:
        OperationType = enOperationType(RandomNumber(1, 4));
        return PrintOperation(QuestionsLevel, OperationType);
    }
    return Numbers;
}
stFinalResult FillFinalResult(short HowManyQuestions, enQuestionsLevel QuestionsLevel, enOperationType OperationType, short NumberOfRightAnswers, short NumberOfWrongAnswers)
{
    stFinalResult FinalResult;
    FinalResult.NumberOfQuestions = HowManyQuestions;
    FinalResult.QuestionsLevel = QuestionsLevel;
    FinalResult.OperationType = OperationType;
    FinalResult.NumberOfRightAnswers = NumberOfRightAnswers;
    FinalResult.NumberOfWrongAnswers = NumberOfWrongAnswers;
    return FinalResult;
}
void ScreanColor(enPassOrFail Result)
{
    if (Result == enPassOrFail::Pass)
    {
        system("color 2F");
    }
    else
    {
        system("color 4F");
        cout << "\a";
    }
}
void ScreanOperationResult(enPassOrFail Result, short RightAnswer)
{
    if (Result == enPassOrFail::Pass)
    {
        ScreanColor(Result);
        cout << "Right Answer :-)" << endl;
    }
    else
    {
        ScreanColor(Result);
        cout << "Wrong Answer :-(" << endl;
        cout << "The right answer is: " << RightAnswer << endl;
    }
}
stFinalResult PlayGame(short HowManyQuestions)
{
    short NumberOfRightAnswers = 0, NumberOfWrongAnswers = 0;
    enQuestionsLevel QuestionsLevel = ReadQuestionsLevel();
    enOperationType OperationType = ReadOperationType();
    
    for (int i = 1; i <= HowManyQuestions; i++)
    {
        cout << "\nQuestion [" << i << "/" << HowManyQuestions << "]\n";
        stNumbers Operation = PrintOperation(QuestionsLevel,OperationType);
        int UserAnswer = ReadPositiveNumber("");
        
        if (UserAnswer == Operation.Result)
        {
            ScreanOperationResult(enPassOrFail::Pass, Operation.Result);
            NumberOfRightAnswers++;
        }
        else
        {
            ScreanOperationResult(enPassOrFail::Fail, Operation.Result);
            NumberOfWrongAnswers++;
        }
    }
    return FillFinalResult(HowManyQuestions, QuestionsLevel, OperationType, NumberOfRightAnswers, NumberOfWrongAnswers);
}
void PrintFailOrPass(short NumberOfRightAnswers, short NumberOfWrongAnswers)
{
    if (NumberOfRightAnswers >= NumberOfWrongAnswers)
    {
        ScreanColor(enPassOrFail::Pass);
        cout << "\n---------------------------------------\n";
        cout << "      Final Results is Pass :-)";
        cout << "\n---------------------------------------\n\n";
    }
    else
    {
        ScreanColor(enPassOrFail::Fail);
        cout << "\n---------------------------------------\n";
        cout << "      Final Results is Fail :-(";
        cout << "\n---------------------------------------\n\n";
    }
}
string QuestionsLevelName(enQuestionsLevel QuestionsLevel)
{
    string Levels[4] = { "Easy", "Med", "Hard", "Mix" };
    return Levels[QuestionsLevel - 1];
}
string OperationTypeName(enOperationType OperationType)
{
    string Operatonss[5] = { "Add", "Sub", "Mul", "Div", "Mix" };
    return Operatonss[OperationType - 1];
}
void PrintFinalGameResult(stFinalResult Result)
{
    cout << "Number of Questions: " << Result.NumberOfQuestions << endl;
    cout << "Questions Level    : " << QuestionsLevelName(Result.QuestionsLevel)<<endl;
    cout << "OpType             : " << OperationTypeName(Result.OperationType)<<endl;
    cout << "Number of Right Answers: " << Result.NumberOfRightAnswers << endl;
    cout << "Number of Wrong Answers: " << Result.NumberOfWrongAnswers<<endl;
    cout << "\n---------------------------------------\n\n";
}
void ResetScreen()
{
    system("cls");
    system("color 0F");
}
void StartGame()
{   
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stFinalResult Result = PlayGame(ReadPositiveNumber("How Many Questions do you want to answer ?  "));
        PrintFailOrPass(Result.NumberOfRightAnswers, Result.NumberOfWrongAnswers);
        PrintFinalGameResult(Result);
        cout << "Do you want to play again? Y/N?";
        cin >> PlayAgain;

    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}

 