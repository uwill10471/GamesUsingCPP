#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
void createMap(vector<vector<string>> &ticMap)
{
    int k = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ticMap[i][j] = to_string(k);
            k++;
        }
    }
}

void printMap(vector<vector<string>> ticMap)
{
    for (auto i : ticMap)
    {
        for (auto j : i)
        {
            cout << j << "    ";
        }
        cout << endl
             << "\n\n\n";
    }
}

// marking ✖️ and ⭕ position with each turn
void markPos(vector<vector<string>> &ticMap, int pos, string s)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ticMap[i][j] == to_string(pos))
            {
                ticMap[i][j] = s;
            }
        }
    } // for end;
}

// checking if game is over
bool isGameOver(vector<vector<string>> &ticMap)
{
    // all values filled
    int k = 1;
    bool isThereINT = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ticMap[i][j] == to_string(k))
            {
                isThereINT = true;
            }
            k++;
        }
    }
    if (isThereINT == false)
    {
        return true;
    }

    // Forward Diagonal check
    string s = ticMap[0][0];
    if (s == ticMap[1][1] && s == ticMap[2][2])
        return true;

    // back Diagonal check
    string s2 = ticMap[0][2];
    if (s2 == ticMap[1][1] && s2 == ticMap[2][0])
        return true;

    int row = 3;
    int col = 3;

    // row check
    string s3 = "";
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        s3 = ticMap[i][0];
        for (int j = 0; j < col; j++)
        {
            if (s3 != ticMap[i][j])
            {
                break;
            }
            else
            {
                count++;
            }
        }
        if (count == 3)
        {
            return true;
        }
        count = 0;
    } // for end

    // col check
    string s4 = "";
    int count1 = 0;
    for (int i = 0; i < row; i++)
    {
        s4 = ticMap[0][i];
        for (int j = 0; j < col; j++)
        {
            if (s4 != ticMap[j][i])
            {
                break;
            }
            else
            {
                count1++;
            }
        }
        if (count1 == 3)
        {
            return true;
        }
        count1 = 0;
    }

    return false;
}

// determining winner
string getWinner(vector<vector<string>> &ticMap)
{
    // Forward Diagonal check
    string s = ticMap[0][0];
    if (s == ticMap[1][1] && s == ticMap[2][2])
    {
        if (s == "✖️")
        {
            return u8"Player 1 😎😎";
        }
        else
        {
            return u8"Player 2 💀💀";
        }
    } // forw end

    // back Diagonal check
    s = "";
    s = ticMap[0][2];
    if (s == ticMap[1][1] && s == ticMap[2][0])
    {
        if (s == "✖️")
        {
            return u8"Player 1 😎😎";
        }
        else
        {
            return u8"Player 2 💀💀";
        }
    }

    // row check
    s = "";
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        s = ticMap[i][0];
        for (int j = 0; j < 3; j++)
        {
            if (s != ticMap[i][j])
            {
                break;
            }
            else
            {
                count++;
            }
        }
        if (count == 3)
        {
            if (s == "✖️")
            {
                return u8"Player 1 😎😎";
            }
            else
            {
                return u8"Player 2 💀💀";
            }
        }
        count = 0;
    } // for end row end

    // col check
    s = "";
    int count1 = 0;
    for (int i = 0; i < 3; i++)
    {
        s = ticMap[0][i];
        for (int j = 0; j < 3; j++)
        {
            if (s != ticMap[j][i])
            {
                break;
            }
            else
            {
                count1++;
            }
        }
        if (count1 == 3)
        {
            if (s == "✖️")
            {
                return u8"Player 1 😎😎";
            }
            else
            {
                return u8"Player 2 💀💀";
            }
        }
        count1 = 0;
    }

    return u8"IT IS A TIE 😒😒😒😒👌";
}

// starting Game function
void startGame(vector<vector<string>> &ticMap)
{
    printMap(ticMap);
    unordered_map<string, bool> vis;
    bool player1 = true;
    while (!isGameOver(ticMap))
    {
        cout << "Player 1 marked by - ✖️\n";
        cout << "\nPlayer 2 marked by - ⭕\n";
        if (player1)
        {

            cout << "\nPlayer 1 - (Enter from (1-9)Where No. visible) ";
            int pos;
            cin >> pos;
            player1 = !player1;
            if (vis[to_string(pos)] == 1)
            {
                player1 = true;
            }
            else
            {
                vis[to_string(pos)] = 1;
                markPos(ticMap, pos, "✖️");
            }

            printMap(ticMap);
        }
        else
        {
            cout << "\nPlayer 2 - (Enter from (1-9) Where No. visible) ";
            int pos;
            cin >> pos;
            player1 = !player1;
            if (vis[to_string(pos)] == 1)
            {
                player1 = false;
            }
            else
            {
                vis[to_string(pos)] = 1;
                markPos(ticMap, pos, "⭕");
            }

            printMap(ticMap);
        }
    }

    cout << u8"💐💐💐WINNER ISSSS ======💐" << getWinner(ticMap);
}

void resetGame(vector<vector<string>> &ticMap)
{
    createMap(ticMap);
}

// run as long as player wanna play
void runTillInfinite(vector<vector<string>> &ticMap)
{
    cout << "\n\n\nDo you want to continue Playing? (y/n)  ";
    char c;
    cin >> c;
    switch (c)
    {
    case 'y':
        resetGame(ticMap);
        startGame(ticMap);
        break;
    case 'n':
        cout << "\n🚫🚫!!Game is Terminated🚫🚫";
        exit(0);
    default:
        break;
    }
    return;
}
int main()
{

    vector<vector<string>> ticMap(3, vector<string>(3));
    createMap(ticMap);
    startGame(ticMap);

    while (true)
    {
        runTillInfinite(ticMap);
    }

    cout << "!!🚫🚫Game is Terminated🚫🚫";
    return 0;
}