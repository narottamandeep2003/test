#include <iostream>
#include <set>
#include <vector>
using namespace std;
class State
{
public:
    int posX, posy;
    string status;
    State(int posX, int posy)
    {
        this->posX = posX;
        this->posy = posy;
    }
    void setStatus(string status)
    {
        this->status = status;
    }
};
bool check(int curx, int cury, char dir, int homeX, int homeY)
{
    if (dir == 's' && homeX == curx && homeY > cury)
    {
        return true;
    }
    if (dir == 'e' && homeX > curx && homeY == cury)
    {
        return true;
    }
    if (dir == 's' && homeX == curx && homeY < cury)
    {
        return true;
    }
    if (dir == 'e' && homeX < curx && homeY == cury)
    {
        return true;
    }
    return false;
}
void solve(int curx, int cury, char dir, int homeX, int homeY, vector<vector<State>> &ans, vector<State> path, set<pair<int, int>> soldiers)
{
    // cout << curx << " " << cury << endl;
    if (curx == homeX && cury == homeY && path.size() > 1)
    {
        cout << "path" << endl;
        for (auto j : path)
        {
            cout << j.posX << " " << j.posy << " " << j.status << endl;
        }
        ans.push_back(path);

        return;
    }

    vector<pair<int, int>> temp;

    for (auto it : soldiers)
    {
        if (dir == 's')
        {
            if (it.first == curx && it.second > cury)
            {
                if (it.first == homeX && it.second == homeY)
                {
                    solve(it.first, it.second, 's', homeX, homeY, ans, path, soldiers);
                    return;
                }
                State newstate(it.first, it.second);
                newstate.setStatus("kill");
                path.push_back(newstate);
                soldiers.erase(it);
                solve(it.first, it.second, 'e', homeX, homeY, ans, path, soldiers);

                path.pop_back();
                soldiers.insert(it);

                State newstate1(it.first, it.second);
                newstate1.setStatus("jump");
                path.push_back(newstate1);
                solve(it.first, it.second+1, 's', homeX, homeY, ans, path, soldiers);
                path.pop_back();
                
            }
        }
        if (dir == 'e')
        {
            if (it.first > curx && it.second == cury)
            {
                if (it.first == homeX && it.second == homeY)
                {
                    solve(it.first, it.second, 'e', homeX, homeY, ans, path, soldiers);
                    return;
                }
                State newstate(it.first, it.second);
                newstate.setStatus("kill");
                path.push_back(newstate);
                soldiers.erase(it);
                solve(it.first, it.second, 'n', homeX, homeY, ans, path, soldiers);

                path.pop_back();
                soldiers.insert(it);

                State newstate1(it.first, it.second);
                newstate1.setStatus("jump");
                path.push_back(newstate1);
                solve(it.first+1, it.second, 'e', homeX, homeY, ans, path, soldiers);
                path.pop_back();
                
            }
        }
        if (dir == 'n')
        {
            if (it.first == curx && it.second < cury)
            {
                if (it.first == homeX && it.second == homeY)
                {
                    solve(it.first, it.second-1, 'n', homeX, homeY, ans, path, soldiers);
                    return;
                }
                State newstate(it.first, it.second);
                newstate.setStatus("kill");
                path.push_back(newstate);
                soldiers.erase(it);
                solve(it.first, it.second, 'w', homeX, homeY, ans, path, soldiers);

                path.pop_back();
                soldiers.insert(it);

                State newstate1(it.first-1, it.second);
                newstate1.setStatus("jump");
                path.push_back(newstate1);
                solve(it.first, it.second, 'n', homeX, homeY, ans, path, soldiers);
                path.pop_back();
                
            }
        }
        if (dir == 'w')
        {
            if (it.first < curx && it.second == cury)
            {
                if (it.first == homeX && it.second == homeY)
                {
                    solve(it.first, it.second, 'w', homeX, homeY, ans, path, soldiers);
                    return;
                }
                State newstate(it.first, it.second);
                newstate.setStatus("kill");
                path.push_back(newstate);
                soldiers.erase(it);
                solve(it.first, it.second, 's', homeX, homeY, ans, path, soldiers);

                path.pop_back();
                soldiers.insert(it);

                State newstate1(it.first, it.second);
                newstate1.setStatus("jump");
                path.push_back(newstate1);
                solve(it.first, it.second, 'w', homeX, homeY, ans, path, soldiers);
                path.pop_back();
              
            }
        }
    }
   
}
int main()
{

    int noOfSoldiers;
    cout << "find_my_home_castle - soldiers ";
    cin >> noOfSoldiers;

    set<pair<int, int>> soldiers;

    for (int i = 1; i <= noOfSoldiers; i++)
    {
        int x, y;
        cout << "Enter coordinates for soldier " << i << " ";
        cin >> x >> y;
        soldiers.insert({x, y});
    }

    int castleX, castleY;
    cout << "Enter the coordinates for your special castle: ";
    cin >> castleX >> castleY;
    soldiers.insert({castleX, castleY});
    char dir = 's';
    vector<vector<State>> ans;
    vector<State> path;
    State s(castleX, castleY);
    s.setStatus("start");
    path.push_back(s);
    solve(castleX, castleY, dir, castleX, castleY, ans, path, soldiers);
    cout<<ans.size();
    return 0;
}
