#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10
#define STARTROW 8
#define STARTCOL 8
#define EXITROW 1
#define EXITCOL 1

struct verhor{
    int ver;
    int hor;
};

struct element{
    int row;
    int col;
    int dir;
};

class MazeSolver{
private:
    int top;
    verhor move[4] = { // right up left down
        {0, 1}, {-1, 0}, {0, -1}, {1, 0}
    };
    int maze[10][10];
    char mark[10][10];
    element stack[100];
public:
    MazeSolver(){
        top = -1;
        for(int i = 0; i < 10; i++){
            for(int j =0; j< 10; j++){
                maze[i][j] = 0;
                mark[i][j] = '0';
            }
        }
    }
    
    void readmaze(){
        for(int i = 0; i < 10; i++){
            for(int j =0; j< 10; j++){
                cin >> maze[i][j];
            }
        }
    }

    void add(element item){
        if(top >= 100){
            cerr << "penuh ga ush nambah2 lgi" << endl;
            exit(1);
        }
        stack[++top] = item;
    }

    element popp(){
        if(top < 0){
            cerr << "empty list" << endl;
            exit(1);
        }
        return stack[top--];
    }

    bool findpath(){
        int row, col, nextcol, nextrow, dir;
        bool found = false;
        element position;
        top = 0;
        stack[0].row = 8;
        stack[0].col = 8;
        stack[0].dir = 0;
        mark[8][8] = 'S';
        mark[1][1] = 'X';

        while(top > -1 && !found){
            position = popp();
            row = position.row;
            col = position.col;
            dir = position.dir;

            while(dir < 4){
                nextrow = row + move[dir].ver;
                nextcol = col + move[dir].hor;

                if(maze[nextrow][nextcol] == 0 && mark[nextrow][nextcol] == 'X'){
                    found = true;
                    break;
                }
                if(found) break;

                if(maze[nextrow][nextcol] == 0 && mark[nextrow][nextcol] == '0'){
                    mark[nextrow][nextcol] = 'G';
                    position.row = row;
                    position.col = col;
                    position.dir = ++dir;
                    add(position);
                    dir = 0;
                    row = nextrow;
                    col = nextcol;
                } else dir++;
            }

            if(dir >= 4 && (row != 8 && col !=8)){
                mark[row][col] = 'D';
            }
        }

        return found;
    }

    void printMaze() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
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
                if (j < SIZE - 1) cout << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    MazeSolver Solver;
    Solver.readmaze();

    bool found = Solver.findpath();

    if(found){
        cout << "YES" << endl;
    } else cout << "NO" << endl;

    Solver.printMaze();
}