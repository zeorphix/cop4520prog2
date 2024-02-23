// Evan Tieu
// Programming Assignment 2
// Problem 1: Minotaur’s Birthday Party
// COP 4520, Spring 2024

#include <iostream>
#include <thread>
#include <random>
#include <mutex>

std::array<bool, NUM_GUESTS> allVisited;
const int NUM_GUESTS = 5;
bool cupcake = true;

mutex mtx;

int randomNumber(int min, int max)
{
    using namespace std;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distibrution<> distr(min, max);

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

    thread guests[NUM_GUESTS];

    for (int i = 0; i < NUM_GUESTS; ++i)
        guests[i] = thread(enter, i + 1);

    while 

    for (int i = 0; i < NUM_GUESTS; ++i)
        guests[i].join();
    
    cout << "All " << NUM_GUESTS << " guests have visited the labyrinth." << endl;

    return 0;
}
