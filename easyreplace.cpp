#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    // prompts user for blockname, be exact
    cout << "Enter new block: ";
    string input;
    cin >> input;
    ifstream inFile;
    // opens the template note_block file
    inFile.open("note_block.json");
    ofstream outFile;
    // an output file is created. this will be the 
    // file we move into PackName\assets\minecraft\models\block
    // output file is named the user input + .json extension
    outFile.open(input + ".json");
    // outputs an example of your new file to the terminal
    cout << "Your new file will look like this:" << endl;
    for (int i = 0; i < 13; ++i)
    {
    string line;
    getline(inFile, line);
    // searches through line string for note_block
    while (line.find("note_block") != string::npos)
    {
        // when found, replaces noteblock with user input string
        // replaces 10 values, 10 chars in note_block
        line.replace(line.find("note_block"), 10, input);
    }

    cout << line << endl;
    // outputs to out output file
    outFile << line << endl;

    }

    inFile.close();
    outFile.close();
    return 0;
    // future version may edit blockstates\note_block.json
}