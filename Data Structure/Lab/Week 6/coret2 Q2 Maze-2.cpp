#include <iostream>
#include <vector>
#define size 10
#define start 8
#define end 1
using namespace std;

struct Offsets{
    int ver;
    int hor;
};

struct Element{
    int row;
    int col;
    int dir;
};

class Mazesolver{
private:
    Offsets Move[4]{ //right up left down
        {0,1}, {-1,0}, {0,-1}, {1,0}
    };
    int maze[size][size];
    char mark[size][size];
    vector<Element> stackk;
public:
    Mazesolver(){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                maze[i][j] = 0;
                mark[i][j] = '0';
            }
        }
    }

    void readpath(){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cin >> maze[i][j];
            }
        }
    }

    bool findpath(){
        int row, col, dir, nextrow, nextcol;
        Element position;
        bool found = false;
        mark[start][start] = 'S';
        mark[end][end] = 'X';
        position.row = start;
        position.col = start;
        position.dir = 0;
        stackk.push_back(position);

        while(!found && !stackk.empty()){
            position = stackk.back();
            stackk.pop_back();
            row = position.row;
            col = position.col;
            dir = position.dir;
            while(dir < 4 && !found){
                nextrow = row + Move[dir].ver;
                nextcol = col + Move[dir].hor;

                if(mark[nextrow][nextcol] == 'X'){
                    found = true;
                }
                
                if(found) break;
                
                if(maze[nextrow][nextcol] == 0 && mark[nextrow][nextcol] == '0' && !found){
                    mark[nextrow][nextcol] = 'G';
                    position.row = row;
                    position.col = col;
                    position.dir = ++dir;
                    stackk.push_back(position);
                    
                    row = nextrow;
                    col = nextcol;
                    dir = 0;
                } else dir++;
            }

            if(dir >= 4 && mark[row][col] != 'S'){
                mark[row][col] = 'D';
            }
        }
        return found;
    }

    void printpath(){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(maze[i][j] == 1){
                    cout << '1';
                }
                else if(mark[i][j] == 'G'){
                    cout << 'G';
                }
                else if(mark[i][j] == 'D'){
                    cout << 'D';
                }
                else if(mark[i][j] == 'X'){
                    cout << 'X';
                }
                else if(mark[i][j] == 'S'){
                    cout << 'S';
                }
                else cout << '0';
            }
            cout << endl;
        }
    }
};

int main(){
    Mazesolver solver;
    solver.readpath();
    if(solver.findpath()){
        cout << "YES" << endl;
    } else cout << "NO" << endl;

    solver.printpath();
}
