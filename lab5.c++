#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
bool containsOnlyDigits(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
int main() {
    string inputFilePath, outputFilePath;
    cout << "Enter the input file path: ";
    cin >> inputFilePath;
    cout << "Enter the output file path: ";
    cin >> outputFilePath;
    ifstream inputFile(inputFilePath);
    if (!inputFile) {
        cout << "Failed to open input file." << endl;
        return 1;
    }
    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();
    if (lines.empty()) {
        ofstream outputFile(outputFilePath);
        outputFile.close();
        cout << "The output file has been created." << endl;
        return 0;
    }
    ofstream outputFile(outputFilePath);
    if (!outputFile) {
        cout << "Failed to open output file." << endl;
        return 1;
    }
    int groupStartLine = 0;
    int groupSize = 0;
    string repeatedLine = "";
    for (int i = 0; i < lines.size(); i++) {
        if (containsOnlyDigits(lines[i])) {
            if (groupSize == 0) {
                groupStartLine = i;
                repeatedLine = lines[i];
            }
            groupSize++;
        }
        else {
            if (groupSize > 0) {
                outputFile << "The group starts with the line " << groupStartLine + 1;
                outputFile << ", number of repetitions: " << groupSize << endl;
                groupSize = 0;
            }
        }
    }
    if (groupSize > 0) {
        outputFile << "The group starts with the line " << groupStartLine + 1;
        outputFile << ", number of repetitions: " << groupSize << endl;
    }
    outputFile.close();
    cout << "The output file has been created." << endl;
    return 0;
}