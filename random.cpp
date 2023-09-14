#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int main() {
    std::mt19937 generator(time(0));
    std::uniform_int_distribution<> distribution(1, 10);

    int rdmNumber = distribution(generator);
    int num;
    cout << "Guess the number between 1 to 10:- ";
    cin >> num;

    if (num == rdmNumber)
    {
        cout << "Congrats! You Won The Game\n";
    }
    else
    {
        cout << "Sorry! You Lose \n";
    }

    cout << "The number is " << rdmNumber << endl;

    return 0;
}

