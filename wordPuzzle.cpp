#include <iostream>
#include <string>
#include <fstream>
#include "hashTable.h"
#include <vector>
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
hashTable stringSet(2000);

bool readInDictionary(string filename);
bool readInGrid(string filename, int &rows, int &cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
timer t;
vector<string> v;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        exit(1);
    }

    int rows, cols;

    string dictionaryFile;
    string gridFile;
    dictionaryFile = argv[1];
    gridFile = argv[2];
    t.start();

    bool result = readInDictionary(dictionaryFile);
    if (!result)
    {
        cout << "Error reading in file!" << endl;
        return 1;
    }

    bool resultG = readInGrid(gridFile, rows, cols);
    if (!resultG)
    {
        cout << "Error reading in file!" << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            for (int c = 0; c < cols; c++)
            {
                for (int l = 3; l < 23; l++)
                {
                    if (stringSet.findKey(getWordInGrid(j, c, i, l, rows, cols)) == true && getWordInGrid(j, c, i, l, rows, cols).length() == l)
                    {
                        count++;
                        if (i == 0)
                        {
                            string s = "N (" + to_string(j) + ", " + to_string(c) + "):      " + getWordInGrid(j, c, i, l, rows, cols) + "\n";
                            v.push_back(s);
                        }
                        if (i == 1)
                        {
                            string s = "NE (" + to_string(j) + ", " + to_string(c) + "):      " + getWordInGrid(j, c, i, l, rows, cols) + "\n";
                            v.push_back(s);
                        }
                        if (i == 2)
                        {
                            string s = "E (" + to_string(j) + ", " + to_string(c) + "):      " + getWordInGrid(j, c, i, l, rows, cols) + "\n";
                            v.push_back(s);
                        }
                        if (i == 3)
                        {
                            string s = "SE (" + to_string(j) + ", " + to_string(c) + "):      " + getWordInGrid(j, c, i, l, rows, cols) + "\n";
                            v.push_back(s);
                        }
                        if (i == 4)
                        {
                            string s = "S (" + to_string(j) + ", " + to_string(c) + "):      " + getWordInGrid(j, c, i, l, rows, cols) + "\n";
                            v.push_back(s);
                        }
                        if (i == 5)
                        {
                            string s = "SW (" + to_string(j) + ", " + to_string(c) + "):      " + getWordInGrid(j, c, i, l, rows, cols) + "\n";
                            v.push_back(s);
                        }
                        if (i == 6)
                        {
                            string s = "W (" + to_string(j) + ", " + to_string(c) + "):      " + getWordInGrid(j, c, i, l, rows, cols) + "\n";
                            v.push_back(s);
                        }
                        if (i == 7)
                        {
                            string s = "NW (" + to_string(j) + ", " + to_string(c) + "):      " + getWordInGrid(j, c, i, l, rows, cols) + "\n";
                            v.push_back(s);
                        }
                    }
                }
            }
        }
    }

    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    }

    for (int i = 0; i < 1000000000; i++)
    {
    }
    t.stop();

    cout << count << " words found" << endl;

    // print runtime 
    // uncomment if testing the program run time using the bash script averagetime.sh
    // double r = t.getTime();
    // int rr = int(r * 1000);
    // cout << rr << endl;
    return 0;
}

bool readInDictionary(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        return false;
    }
    string s;
    while (file.good())
    {
        file >> s;
        if (s.size() >= 3)
        {
            stringSet.insertKey(s);
        }
    }
    return true;
}

bool readInGrid(string filename, int &rows, int &cols)
{
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open())
    {
        return false;
    }

    // first comes the number of rows
    file >> rows;

    // then the columns
    file >> cols;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = data[pos++];
        }
    }
    return true;
}

string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols)
{
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear();      // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++)
    {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0)
        {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir)
        { // assumes grid[0][0] is in the upper-left
        case 0:
            r--;
            break; // north
        case 1:
            r--;
            c++;
            break; // north-east
        case 2:
            c++;
            break; // east
        case 3:
            r++;
            c++;
            break; // south-east
        case 4:
            r++;
            break; // south
        case 5:
            r++;
            c--;
            break; // south-west
        case 6:
            c--;
            break; // west
        case 7:
            r--;
            c--;
            break; // north-west
        }
    }

    return output;
}
