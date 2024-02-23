// Evan Tieu
// Programming Assignment 2
// Problem 2: Minotaur’s Crystal Vase
// COP 4520, Spring 2024

#include <iostream>
#include <thread>
#include <mutex>

std::array<bool, 
const int NUM_GUESTS = 5;
bool cupcake = true;
mutex mtx;

void cupcakeCheck(bool cupcake)
{

}

void enter(int id)
{

}

int main(void)
{
    using namespace std;

    cout << "Preparing " << NUM_GUESTS << " guests to visit the labyrinth..." << endl;

    thread guests[NUM_GUESTS];

    for (int i = 0; i < NUM_GUESTS; ++i)
        guests[i] = thread(enter, i + 1);

    for (int i = 0; i < NUM_GUESTS; ++i)
        guests[i].join();
    
    cout << "All guests have visited the labyrinth." << endl;

    return 0;
}
