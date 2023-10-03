#include <iostream>
#include <cstdlib>

using namespace std;

enum enQuestionsLevel {Easy, Med, Hard, QMix};

enum enOperationType {Add, Sub, Mul, Div, OMix};

struct stQuizData
{
    short NumberOfQuestions = 0;
    short NumberOfRightAnswer = 0;
    short NumberOfWrongAnswers = 0;
    string QuestionLevel = "";
    string OpType = "";
};

int ReadAnswer()
{
    int Number; 
    cin >> Number;

    return Number;
}

int RandomNumber(int From, int To)
{
    return (rand() % (To - From + 1) + From);
}

short ReadNumberOfQuestions()
{
    int Number;
    do 
    {
        cout << "How many questions do you want? ";
        cin >> Number;
    }
    while (Number < 0);

    return Number;
}

enQuestionsLevel ReadQuestionLevel()
{
    short Level;
    cout << "Enter Question Level [0] Easy, [1] Med, [2] Hard, [3] Mix: ";
    cin >> Level;

    return enQuestionsLevel(Level);
}

enOperationType ReadOperationType()
{
    short Type;
    cout << "Enter Operation Type [0] Add, [1] Sub, [2] Mul, [3] Div, [4] Mix: ";
    cin >> Type;

    return enOperationType(Type);
}

char Operation(enOperationType OperationType)
{
    char OpType[4] = {'+', '-', '*', '/'};

    if (OperationType == enOperationType::OMix)
        return OpType[RandomNumber(0, 3)];
    else
        return OpType[OperationType];
}

string GetLevel(enQuestionsLevel QuestionsLevel)
{
    string Level[4] = {"Easy", "Medium", "Hard", "Mix"};

    return Level[QuestionsLevel];
}

string GetOperation(enOperationType OperationType)
{
    string Operation[5] = {"+", "-", "*", "/", "Mix"};
    return Operation[OperationType];
}

int GenerateNumbers(enQuestionsLevel QuestionLevel)
{
    switch (QuestionLevel)
    {
        case enQuestionsLevel::Easy:
            return RandomNumber(1, 10);
        case enQuestionsLevel::Med:
            return RandomNumber(10, 100);
        case enQuestionsLevel::Hard:
            return RandomNumber(100, 1000);
        case enQuestionsLevel::QMix:
            return RandomNumber(1, 1000);
    }
} 

void GenerateQuestion(int Number1, int Number2, char OperationType)
{
    cout << Number1 << endl;
    cout << Number2;
    cout << " " << OperationType;
    cout << "\n___________________\n";
}

int CalculateResult(int Number1, int Number2, char OperationType)
{
    switch (OperationType)
    {
        case '+':
            return Number1 + Number2;
        case '-':
            return Number1 - Number2;
        case '*':
            return Number1 * Number2;
        case '/':
            return Number1 / Number2;
    }
}

void CheckAnswer(int Answer, int Result, stQuizData &QuizData)
{
    if (Answer == Result)
    {
        cout << "Right Answer.\n";
        QuizData.NumberOfRightAnswer++;
    }
        
    else 
    {
        cout << "Wrong Answer.\n";
        cout << "The right answer is: " << Result << endl;
        QuizData.NumberOfWrongAnswers++;
    }
}

string CheckPassFail(stQuizData QuizData)
{
    if (QuizData.NumberOfRightAnswer > QuizData.NumberOfWrongAnswers)
        return "Pass.";
    else 
        return "Fail.";
}

void QuizResult(stQuizData QuizData)
{
    cout << "\n\n_______________________________\n\n";
    cout << "\t Final Result is: " << CheckPassFail(QuizData) << endl;
    cout << "_______________________________\n\n";
    cout << "Number Of Questions    : " << QuizData.NumberOfQuestions <<endl;
    cout << "Question Level         : " << QuizData.QuestionLevel <<endl;
    cout << "Operation Type         : " << QuizData.OpType <<endl;
    cout << "Number Of Right Answers: " << QuizData.NumberOfRightAnswer <<endl;
    cout << "Number Of Wrong Answers: " << QuizData.NumberOfWrongAnswers <<endl;
}

void StartQuiz()
{
    char QuizAgain = 'Y';
    do 
    {
        stQuizData QuizData;

        QuizData.NumberOfQuestions = ReadNumberOfQuestions();
        enQuestionsLevel Level = ReadQuestionLevel();
        enOperationType OperationType = ReadOperationType();
        
        QuizData.QuestionLevel = GetLevel(Level);
        QuizData.OpType = GetOperation(OperationType);

        for (int i = 1; i <= QuizData.NumberOfQuestions; i++)
        {
            int Number1 = GenerateNumbers(Level);
            int Number2 = GenerateNumbers(Level);
            char OpType = Operation(OperationType);
            int Result = CalculateResult(Number1, Number2, OpType);

            cout << "\n\nQuestion [" << i << "/" << QuizData.NumberOfQuestions << "]\n\n";
            GenerateQuestion(Number1, Number2, OpType);
            int Answer = ReadAnswer();
            CheckAnswer(Answer, Result, QuizData);
        }
        
        QuizResult(QuizData);

        cout << "Do You Need to Take Quiz Again [Y/N]? ";
        cin >> QuizAgain;
    }
    while (QuizAgain == 'Y' || QuizAgain == 'y');
    

}


int main()
{
    srand(unsigned(time(NULL)));

    StartQuiz();

    return 0;
}