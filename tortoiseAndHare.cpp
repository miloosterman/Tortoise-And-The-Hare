/************************************************************************
* Name: Exercise 8.12 (Simulation: The Tortoise and the Hare)
* File: tortoiseAndHare.cpp
* Author: Milo Osterman
* Date: 3/1/2021
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//Prototypes
void moveHare (int *);
void moveTortoise (int *);
void displayRace (int *, int *, const int);

int main(int argc, const char * argv[]) {
    //Declare variables for tortoise and hare starting place
    int tortoisePosition{1};
    int harePosition{1};
    int raceTrackLength{70}; //Set finish line to 70
    srand(static_cast<unsigned int>(time(0))); //Randomize seed using time
    
    cout << "BANG !!!!! AND THEY'RE OFF!!!!!" << endl;
    
    while (tortoisePosition < raceTrackLength && harePosition < raceTrackLength){
        moveHare(&harePosition);
        if (harePosition < 1){
            harePosition = 1;
        }
        if (harePosition > raceTrackLength){
            harePosition = raceTrackLength;
        }
        moveTortoise(&tortoisePosition);
        if (tortoisePosition < 1){
            tortoisePosition = 1;
        }
        if (tortoisePosition > raceTrackLength){
            tortoisePosition = raceTrackLength;
        }
        displayRace(&harePosition, &tortoisePosition, raceTrackLength);
    }

}

void moveHare(int *harePosition){
    int move = 0;
    int moveRoll = 1 + rand() % 11;
    
    switch (moveRoll) {
        case 1:
        case 2:
            move = 0; //Sleep
            break;
        case 3:
        case 4:
            move = 9; //Big hop
            break;
        case 5:
            move = -12; //Big slip
            break;
        case 6:
        case 7:
        case 8:
            move = 1; //Small hop
            break;
        case 9:
        case 10:
            move = -2; //Small slip
            break;
        default:
            break;
    }
    *harePosition += move;
}

void moveTortoise(int *tortoisePosition){
    int move = 0;
    int moveRoll = 1 + rand() % 11;
    
    switch (moveRoll) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            move = 3; //Fast plod
            break;
        case 6:
        case 7:
            move = -6; //Slip
        case 8:
        case 9:
        case 10:
            move = 1; //Slow plod
        default:
            break;
    }
    *tortoisePosition += move;
}

void displayRace(int *harePosition, int *tortoisePosition, int raceTrackLength){
    bool overlap = false; //Boolean to test if tortoise bites hare
    //For loop that prints either an underscore to display track, or H or T to display tortoise/hare
    for(int i = 0; i < raceTrackLength + 1; ++i){
        if (i == *harePosition && i == *tortoisePosition){ //Check for overlap
            if (i == raceTrackLength){
                cout << "\nLet's give it to the underdog, the tortoise!"; //If tie, give to tortoise
            }
            else {
                cout << "#"; //Display # to represent overlap
                overlap = true; //Set boolean to true
            }
        }
        else if (i == *harePosition){
            cout << "H"; //Display H if harePosition matches i
            if (i == raceTrackLength){
                cout << "\nHare wins. Yuck."; //If i is race track length, hare won
                }
            }
        else if (i == *tortoisePosition){
            cout << "T"; //Display T if tortoisePosition matches i
            if (i == raceTrackLength){
                cout << "\nTORTOISE WINS!!! YAY!!!"; //If i is race track length, tortoise won
                }
            }
        else {
            cout << "_"; //If i does not match tortoise or hare position, print underscore
        }
    }
    if (overlap){ //Check boolean flag and print OUCH!!! if true
        cout << "OUCH!!!";
    }
    cout << endl; //End line after for loop resolves
}

