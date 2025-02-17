# print board
def print_board(board):

    print(board[0] + " | " + board[1] + " | " + board[2])
    print(board[3] + " | " + board[4] + " | " + board[5])
    print(board[6] + " | " + board[7] + " | " + board[8])
    print()


# get player input
def get_player_input(board):
    current_player = "X"

    while True:

        try:
            get_inp = int(input(f"{current_player}'s turn, choose a number between 1 and 9: "))
        except ValueError:
            print("Input cannot be string or empty!")
            print()
            continue

        if get_inp < 1 or get_inp > 9:
            print("Invalid input!")
            print()

        elif board[get_inp - 1] == "X" or board[get_inp - 1] == "O":
            print("Oops! That spot is already taken, please choose another.")
            print()

        else:
            board[get_inp - 1] = current_player
            print_board(board)

            if check_win(board):
                print(f"{current_player} wins!")
                break

            elif check_tie(board):
                print("It's a tie!")
                break

            else:
                current_player = "O" if current_player == "X" else "X"


# check possible win
def check_win(board):
    if (board[0] == board[3] == board[6] or
            board[1] == board[4] == board[7] or
            board[2] == board[5] == board[8]):
        return True

    elif (board[0] == board[1] == board[2] or
            board[3] == board[4] == board[5] or
            board[6] == board[7] == board[8]):
        return True

    elif (board[0] == board[4] == board[8] or
            board[2] == board[4] == board[6]):
        return True

    else:
        return False


# check TIE
def check_tie(board):
    if all(space in ["X", "O"] for space in board) and not check_win(board):
        return True
    return False


# play
def play():
    print_board(board)
    get_player_input(board)


# play again?
if __name__ == "__main__":
    while True:
        board = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
        
        play()
        again = input("Press any key to play again (q to quit): ")
        if again.lower() == "q":
            print("GAME OVER...")
            print("THANKS FOR PLAYING...")
            break
