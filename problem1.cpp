// Evan Tieu
// Programming Assignment 2
// Problem 1: Minotaur’s Birthday Party
// COP 4520, Spring 2024

#include <array>
#include <iostream>
#include <thread>
#include <random>
#include <mutex>

const int NUM_GUESTS = 5;
int currentVisited = 0;
bool cupcake = true;

std::array<bool, NUM_GUESTS> allVisited;
std::mutex mtx;

int randomNumber(int min, int max)
{
    using namespace std;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(min, max);

    return distr(gen);
}
  
void cupcakeCheck(void)
{

}

void enter(int id)
{
    using namespace std;

    cout << "Guest " << id << " is entering the labyrinth." << endl;

    if (cupcake)
    {
        cout << "Guest " << id << " ate the cupcake." << endl;
    }
}

int main(void)
{
    using namespace std;

    cout << "Preparing " << NUM_GUESTS << " guests to visit the labyrinth..." << endl;

    while (currentVisited < NUM_GUESTS)
    {
        int rng = randomNumber(0, NUM_GUESTS);

        allVisited[rng] = true;

        cout << "The random number is " << rng << endl;
    }

    thread guests[NUM_GUESTS];

    for (int i = 0; i < NUM_GUESTS; ++i)
        guests[i] = thread(enter, i + 1);

    for (int i = 0; i < NUM_GUESTS; ++i)
        guests[i].join();
    
    cout << "All " << NUM_GUESTS << " guests have visited the labyrinth." << endl;

    return 0;
}
