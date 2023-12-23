#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

int main() {

    ifstream fin("C:\\Users\\ruots\\source\\repos\\project-2.1\\project-2.1\\321.txt");
    ofstream fout("C:\\Users\\ruots\\source\\repos\\project-2.1\\project-2.1\\123.txt");

    string i;

    while (getline(fin, i))
    {
        fout << stoi(i) * 10 << endl;
    }

    fin.close();
    fout.close();

    return 0;
}