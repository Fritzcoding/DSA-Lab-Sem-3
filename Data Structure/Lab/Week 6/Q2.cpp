#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10
#define MAX_STACK_SIZE 100
#define START_ROW 8
#define START_COL 8
#define EXIT_ROW 1
#define EXIT_COL 1

struct Offsets {
    short int vert;
    short int horiz;
};

struct Element {
    short int row;
    short int col;
    short int dir;
};

class MazeSolver {
private:
    // Move directions: Right, Up, Left, Down
    Offsets move[4] = {
        {0, 1},   // Right
        {-1, 0},  // Up
        {0, -1},  // Left
        {1, 0}    // Down
    };
    
    int maze[SIZE][SIZE];
    char mark[SIZE][SIZE];  // 'G' for good path, 'D' for dead end, 'S' for start, 'X' for exit
    Element stack[MAX_STACK_SIZE];
    int top;
    
public:
    MazeSolver() : top(-1) {
        // Initialize arrays
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                maze[i][j] = 0;
                mark[i][j] = '0';
            }
        }
    }
    
    void readMaze() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cin >> maze[i][j];
            }
        }
    }
    
    void add(Element item) {
        if (top >= MAX_STACK_SIZE - 1) {
            cerr << "Stack is full" << endl;
            exit(1);
        }
        stack[++top] = item;
    }
    
    Element deleteStack() {
        if (top < 0) {
            cerr << "Stack is empty" << endl;
            exit(1);
        }
        return stack[top--];
    }
    
    bool findPath() {
        int row, col, next_row, next_col, dir;
        bool found = false;
        Element position;
        
        // Initialize mark array
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                mark[i][j] = '0';
            }
        }
        
        // Set starting point
        mark[START_ROW][START_COL] = 'S';
        top = 0;
        stack[0].row = START_ROW;
        stack[0].col = START_COL;
        stack[0].dir = 0;
        
        while (top > -1 && !found) {
            position = deleteStack();
            row = position.row;
            col = position.col;
            dir = position.dir;
            
            while (dir < 4 && !found) {
                // Calculate next position
                next_row = row + move[dir].vert;
                next_col = col + move[dir].horiz;
                
                // Check if reached exit
                if (next_row == EXIT_ROW && next_col == EXIT_COL) {
                    found = true;
                    mark[EXIT_ROW][EXIT_COL] = 'X';
                }
                // Check if move is valid
                else if (maze[next_row][next_col] == 0 && mark[next_row][next_col] == '0') {
                    mark[next_row][next_col] = 'G';
                    position.row = row;
                    position.col = col;
                    position.dir = ++dir;
                    add(position);
                    row = next_row;
                    col = next_col;
                    dir = 0;
                }
                else {
                    ++dir;
                }
            }
            
            // If all directions blocked, mark as dead end
            if (dir >= 4 && !found) {
                if (row != START_ROW || col != START_COL) {
                    mark[row][col] = 'D';
                }
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

int main() {
    MazeSolver solver;
    
    // Read maze input
    solver.readMaze();
    
    // Find path
    bool found = solver.findPath();
    
    // Output result
    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    solver.printMaze();
    
    return 0;
}