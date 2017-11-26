import sys
from Queue import Queue

test_maze_1 = [['0','0','P','inf'],
               ['0','P','inf','0'],
               ['P','0','0','inf'],
               ['0','0','P','0']]

test_maze_2 = [['0','0','S','inf'],
               ['inf','inf','0','0'],
               ['inf','0','0','inf'],
               ['D','0','inf','0']]

def modMaze(maze):
    rows = len(maze)       # Num. of rows
    cols = len(maze[0])    # Num. of cols
    q, i = [], 0
    for i in range(rows):
        j = 0
        for j in range(cols):
            if maze[i][j] is 'P':
                q.append((i,j,0))

    for i,j,k in q:
        mazeval = k
        for r,c in ((i+1,j), (i-1,j), (i,j+1), (i,j-1)):
            flag = False
            if 0 <= r < rows and 0 <= c < cols and maze[r][c] is not 'P' and maze[r][c] is not 'inf':
                if maze[r][c] is '0':
                    maze[r][c] = mazeval + 1
                    flag = True
                else:
                    val = min(maze[r][c], mazeval+1)
                    if maze[r][c] != val:
                        maze[r][c] = min(maze[r][c], mazeval+1)
                        flag = True
                if flag is True:
                    q.append((r,c,maze[r][c]))
    return maze

def findPath(test_maze_2):
    return cond, pathlen

mod_maze = modMaze(test_maze_1)
for rows in mod_maze:
    print rows

cond, pathlen = findPath(test_maze_2)
print cond, pathlen