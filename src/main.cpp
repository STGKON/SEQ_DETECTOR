#include <iostream>
#include <string>
using namespace std;

int main() {
    string seq;

    // INITIALIZING VARIABLES 
    bool validSeq;  
    bool hasStart; 
    bool stopAtEnd;
    bool stopBeforeEnd;
    bool correctSize;
    int n;

    while (cin >> seq) {

        // Initializing variables for each new sequence
        validSeq = true;
        hasStart = false;
        stopAtEnd = false;
        stopBeforeEnd = false;
        n = seq.length();
        correctSize = (n % 3 == 0);

        /* STEP 1. CHECK FOR ACCEPTABLE CHARACTERS (only A,T,G,C)*/
        for (size_t i = 0; i < seq.length(); ++i) {
            char c = seq[i];
            if (c != 'A' && c != 'T' && c != 'G' && c != 'C') {
                validSeq = false;
            }
        }

        /*  STEP 2. CONSEQUENCE CHECK */
        if (validSeq && correctSize) {
            for (int i = 0; i <= n - 3; i++) {

                // CHECK FOR START CODON
                if (seq.substr(i, 3) == "ATG") {
                    hasStart = true;

                    // CONTROL FOR TRIADS
                    for (int j = i + 3; j <= n - 3; j += 3) {
                        string codon = seq.substr(j, 3);

                        if (codon == "TAA" || codon == "TAG" || codon == "TGA") {
                            if (j == n - 3)
                                stopAtEnd = true;
                            else
                                stopBeforeEnd = true;
                        }
                    }
                }
            }
        }

        /* STEP 3. OPTIONS AND FINAL OUTPUT */
        if (!validSeq) {
            cout << "INVALID SEQ" << endl;
        }
        else if (!correctSize) {
            cout << "WRONG SIZE ODF SEQ" << endl;
        }
        else if (hasStart && stopAtEnd && !stopBeforeEnd) {
            cout << "THERE IS A CORRECT SEQ" << endl;
        }
        else if (stopBeforeEnd) {
            cout << "ERROR REFERRED TO STOP CODON" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
