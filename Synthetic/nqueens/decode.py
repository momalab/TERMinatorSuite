import sys
from math import sqrt, floor, log

sys.argv.pop(0)
board_size = floor(sqrt(len(sys.argv)))
args = list(map(int, sys.argv))
sol_cnt = floor(log(max(args), 2))

for sol in range(1, sol_cnt+1):
    for i in range(board_size):
        for j in range(board_size):
            if args[i*board_size + j] & (1 << sol):
                print("Q ", end="")
            else:
                print("_ ", end="")
        print()
    print()

print("{}-Queens have {} solutions".format(board_size, sol_cnt))
