#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); //random generator

    int scoreA = 0; 
    int scoreB = 0;
    string again = "yes";
    const int MAX = 100;
    string array[MAX];
    int i = 0;

    // Read file
    ifstream file("list.txt");
    if(!file.is_open())
    { 
        cout << "Error opening file!";
        return 1;
    }

    string value;
    while (getline(file, value, ';') && i < MAX) {
        if (!value.empty()) {
            array[i] = value;
            i++;
        }
    }
    file.close();

    bool play = true;
    while(play && again == "yes")
    {
        int answer;
        cout << "\nWhose turn is it? (1 = Team A, 2 = Team B): ";
        cin >> answer;

        if(answer != 1 && answer != 2){
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        if(i > 0) {
            int randomIndex = rand() % i;
            string choice = array[randomIndex];
            cout << "🎯 Random pick: " << choice << endl;

            int& currentScore = (answer == 1) ? scoreA : scoreB;
            int& otherScore = (answer == 1) ? scoreB : scoreA;

            if(choice == "50000(dance)")
                currentScore += 50000;
            else if(choice == "100")
                currentScore += 100;
            else if(choice == "1000")
                currentScore += 1000;
            else if(choice == "5000")
                currentScore += 5000;
            else if(choice == "500")
                currentScore += 500;
            else if(choice == "10000")
                currentScore += 10000;
            else if(choice == "20000")
                currentScore += 20000;
            else if(choice == "My Team +/-")
                currentScore = abs(currentScore);
            else if(choice == "Other team +/-")
                otherScore *= -1;
            else if(choice == "Change") {
                int temp = currentScore;
                currentScore = otherScore;
                otherScore = temp;
            }

            cout << "\nCurrent scores:\n";
            cout << "Team A: " << scoreA << endl;
            cout << "Team B: " << scoreB << endl;

            cout << "\nSpin again? (yes/no): ";
            cin >> again;
        } else {
            cout << "Array is empty.\n";
            break;
        }
    }

    cout << "\n🏁 Final scores:\n";
    cout << "Team A: " << scoreA << endl;
    cout << "Team B: " << scoreB << endl;

    return 0;
}
