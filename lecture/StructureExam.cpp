#include <iostream>
#include <vector>
using namespace std;

struct StanfordID {
    string name;
    string sunet;
    int idNumber;
};

// Using list initialization
StanfordID issueNewID() {
    StanfordID id = { "Jacob Roberts-Baca", "jtrb", 6504417 };
    return id;
}

int main() {
    // Initial structure
    StanfordID id = { "John", "John6054", 94126054 };

    cout << "Initial ID:" << endl;
    cout << "Name: " << id.name << endl;
    cout << "SUNet: " << id.sunet << endl;
    cout << "ID Number: " << id.idNumber << endl;

    // Issue a new ID
    StanfordID newID = issueNewID();
    cout << "\nNew ID:" << endl;
    cout << "Name: " << newID.name << endl;
    cout << "SUNet: " << newID.sunet << endl;
    cout << "ID Number: " << newID.idNumber << endl;

    // Additional IDs
    StanfordID jrb = { "Jacob Roberts-Baca", "jtrb", 6504417 };
    StanfordID fi = { "Fabio Ibanez", "fibanez", 6504418 };

    cout << "\nAdditional IDs:" << endl;
    cout << "Name: " << jrb.name << ", SUNet: " << jrb.sunet << ", ID Number: " << jrb.idNumber << endl;
    cout << "Name: " << fi.name << ", SUNet: " << fi.sunet << ", ID Number: " << fi.idNumber << endl;

    return 0;
}

