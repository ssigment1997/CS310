#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int NUM_CANDIDATES = 5;
    string candidates[NUM_CANDIDATES];
    int votes[NUM_CANDIDATES];
    int totalVotes = 0;

    // Input candidate names and their votes
    cout << "Enter the last names and the number of votes for each candidate:\n";
    for (int i = 0; i < NUM_CANDIDATES; ++i) {
        cout << "Candidate " << (i + 1) << " name: ";
        cin >> candidates[i];
        cout << "Number of votes for " << candidates[i] << ": ";
        cin >> votes[i];
        totalVotes += votes[i];
    }

    // Output header
    cout << "\nElection Results:\n";
    cout << left << setw(15) << "Candidate" << setw(10) << "Votes" << "% of Total Votes" << endl;
    cout << "--------------------------------------------------\n";

    // Output candidate results
    for (int i = 0; i < NUM_CANDIDATES; ++i) {
        double percentage = (static_cast<double>(votes[i]) / totalVotes) * 100;
        cout << left << setw(15) << candidates[i] 
             << setw(10) << votes[i] 
             << fixed << setprecision(2) << percentage << "%" << endl;
    }

    // Find the winner
    int maxVotes = votes[0];
    int winnerIndex = 0;
    for (int i = 1; i < NUM_CANDIDATES; ++i) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    cout << "\nThe winner of the election is " << candidates[winnerIndex] << "!\n";

    return 0;
}
