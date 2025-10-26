#include <iostream>
#include <vector>
#include <string>
#define maxsize 10
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

class MazeSolver{
private:
    int top = -1;
    Offsets move[4]{ // right up left down
        {0,1},{-1,0},{0,-1},{1,0} 
    };
    int maze[maxsize][maxsize];
    char mark[maxsize][maxsize];
    vector<Element> stack;
public:
    MazeSolver(){
        top = 0;
        for(int i = 0; i < maxsize; i++){
            for(int j = 0; j < maxsize; j++){
                mark[i][j] = '0';
            }
        }
    }
    void readmaze(){
        for(int i = 0; i < maxsize; i++){
            for(int j = 0; j < maxsize; j++){
                cin >> maze[i][j];
            }
        }
    }
    
    bool findpath(){
        bool found = false;
        mark[start][start] = 'S';
        mark[end][end] = 'X';
        
        int row, col, nextrow, nextcol, dir;
        Element position;
        position.row = start;
        position.col = start;
        position.dir = 0;
        stack.push_back(position);
        
        while(!stack.empty() && !found){
            position = stack.back();
            stack.pop_back();
            row = position.row;
            col = position.col;
            dir = position.dir;
            while(dir < 4){
                nextrow = row + move[dir].ver;
                nextcol = col + move[dir].hor;
                
                if(maze[nextrow][nextcol] == 0 && mark[nextrow][nextcol] == 'X'){
                    found = true;
                }
                
                if(found) break;
                
                if(maze[nextrow][nextcol] == 0 && mark[nextrow][nextcol] == '0'){
                    mark[nextrow][nextcol] = 'G';
                    position.row = row;
                    position.col = col;
                    position.dir = ++dir;
                    stack.push_back(position);
                    row = nextrow;
                    col = nextcol;
                    dir = 0;
                } else dir++;
                
            }
            if(dir >= 4 && (row != start && col != 8)){
                mark[row][col] = 'D';
            }
        }
        
        return found;
    }
    
    void printmaze(){
        for(int i = 0; i < maxsize; i++){
            for(int j = 0; j < maxsize; j++){
                if (maze[i][j] == 1) {
                    cout << "1";
                }
                else if (mark[i][j] == 'S') {
                    cout << "S";
                }
                else if (mark[i][j] == 'X') {
                    cout << "X";
                }
                else if (mark[i][j] == 'G') {
                    cout << "G";
                }
                else if (mark[i][j] == 'D') {
                    cout << "D";
                }
                else {
                    cout << "0";
                }
                if (j < maxsize - 1) cout << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    MazeSolver solver;
    solver.readmaze();
    if(solver.findpath()){
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    
    solver.printmaze();
    
}