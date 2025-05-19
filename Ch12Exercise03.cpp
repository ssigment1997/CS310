#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int numCandidates;

    // Ask user for number of candidates
    cout << "Enter the number of candidates: ";
    cin >> numCandidates;

    // Dynamically allocate arrays
    string* candidates = new string[numCandidates];
    int* votes = new int[numCandidates];
    int totalVotes = 0;

    // Input: Candidate names and votes
    cout << "\nEnter each candidate's last name and number of votes:\n";
    for (int i = 0; i < numCandidates; ++i) {
        cout << "Candidate " << (i + 1) << " name: ";
        cin >> candidates[i];
        cout << "Votes received by " << candidates[i] << ": ";
        cin >> votes[i];
        totalVotes += votes[i];
    }

    // Output header
    cout << "\nElection Results:\n";
    cout << left << setw(15) << "Candidate" 
         << setw(10) << "Votes" 
         << "% of Total Votes" << endl;
    cout << "------------------------------------------\n";

    // Output each candidate's results
    for (int i = 0; i < numCandidates; ++i) {
        double percentage = (static_cast<double>(votes[i]) / totalVotes) * 100;
        cout << left << setw(15) << candidates[i]
             << setw(10) << votes[i]
             << fixed << setprecision(2) << percentage << "%" << endl;
    }

    // Determine winner
    int winnerIndex = 0;
    for (int i = 1; i < numCandidates; ++i) {
        if (votes[i] > votes[winnerIndex]) {
            winnerIndex = i;
        }
    }

    cout << "\nThe winner of the election is: " << candidates[winnerIndex] << "!\n";

    // Clean up dynamic memory
    delete[] candidates;
    delete[] votes;

    return 0;
}
