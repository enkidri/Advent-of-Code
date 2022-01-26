import numpy as np
import pprint as pp
import sys

f = open("day4.txt", "r")

def check_win(board, x, y):
    if all(board[:, y] == ['x', 'x', 'x', 'x', 'x']) or all(board[x, :] == ['x', 'x', 'x', 'x', 'x']):
        return True

    return False

def do_draws(): 
    total_wins = 0
    for draw in draws:
        for board in boards:
            x = 0
            for row in board:
                y = 0
                for nr in row:
                    if (nr == str(draw)):
                        nr = "x"
                        board[x,y] = 'x'
                        if check_win(board, x, y) and (board[0,0] != 'w'):
                            board[0,0] = 'w'
                            total_wins += 1
                            if (total_wins == total_boards):
                                last = [board, draw]
                                return last
                    y += 1
                x += 1

boards = []
board = []
row = []
draws = [99,56,7,15,81,26,75,40,87,59,62,24,58,34,78,86,44,65,18,94,20,17,98,29,57,92,14,32,46,79,85,84,35,68,55,22,41,61,90,11,69,96,23,47,43,80,72,50,97,33,53,25,28,51,49,64,12,63,21,48,27,19,67,88,66,45,3,71,16,70,76,13,60,77,73,1,8,10,52,38,36,74,83,2,37,6,31,91,89,54,42,30,5,82,9,95,93,4,0,39]
#draws = [7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1]
all_idx = []
total_boards = 0
for line in f:
    temp = line.split()

    if (temp == []):
        boards.append(np.array(board))
        board = []
        all_idx.append([])
        total_boards += 1
        continue

    board.append(temp)
boards.append(np.array(board))
total_boards += 1

fin_board, draw = do_draws()

pp.pprint(fin_board)

sum = 0
for row in fin_board:
    for ele in row:
        if ele.isnumeric():
            sum += int(ele)

print("The final answer is: ", sum*draw)