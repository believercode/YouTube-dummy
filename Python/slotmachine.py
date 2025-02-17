import random

# Constants
MAX_LINES = 3
MIN_BET = 1
MAX_BET = 100
ROWS = 3
COLS = 3

symbol_count = {"A": 2, "B": 4, "C": 6, "D": 8}
symbol_value = {"A": 5, "B": 4, "C": 3, "D": 2}


def check_winner(columns, lines, bet, values):
    winning = 0
    winning_lines = []
    for line in range(lines):
        symbol = columns[0][line]
        for column in columns:
            symbol_to_check = column[line]
            if symbol != symbol_to_check:
                break
        else:
            winning += values[symbol] * bet
            winning_lines.append(line)

    return winning, winning_lines


def get_slot_machine_spin(rows, cols, symbols):
    all_symbols = []
    for symbol, symbol_count in symbols.items():
        for _ in range(symbol_count):
            all_symbols.append(symbol)

    columns = []
    for _ in range(cols):
        column = []
        current_symbols = all_symbols.copy()
        for _ in range(rows):
            value = random.choice(current_symbols)
            current_symbols.remove(value)
            column.append(value)

        columns.append(column)
    return columns


def print_slot_machine(columns):
    for row in range(len(columns[0])):
        for i, column in enumerate(columns):
            if i != len(columns) - 1:
                print(column[row], end=" | ")
            else:
                print(column[row])
        print("")


def deposit():
    while True:
        amount = input("Deposit amount: $")
        if amount.isdigit():
            amount = int(amount)
            if amount > 0:
                break
            else:
                print("Amount must be greater than 0!")
        else:
            print("Invalid input! Please enter a valid number.")
    return amount


def get_number_of_lines():
    while True:
        lines = input(f"Enter the number of lines to bet on (1-{MAX_LINES}): ")
        if lines.isdigit():
            lines = int(lines)
            if 1 <= lines <= MAX_LINES:
                break
            else:
                print(f"Number of lines must be between (1 and {MAX_LINES})!")
        else:
            print("Invalid input! Please enter a valid number.")
    return lines


def get_bet():
    while True:
        amount = input(f"Enter your bet amount on each line (minimum "
                       f"${MIN_BET} and maximum ${MAX_BET}): $")
        if amount.isdigit():
            amount = int(amount)
            if MIN_BET <= amount <= MAX_BET:
                break
            else:
                print(f"Bet amount must be between ${MIN_BET} and ${MAX_BET}!")
        else:
            print("Invalid input! Please enter a valid amount.")
    return amount


def spin(balance):
    lines = get_number_of_lines()

    while True:
        bet = get_bet()
        total_bet = lines * bet
        if total_bet > balance:
            print(f"You do not have enough balance to bet ${total_bet}.")
        else:
            break

    print(f"You have deposited ${balance}.")
    print(f"You have chosen to bet on {lines} lines.")
    print(f"Your bet amount is ${bet} on each line "
          f"and your total bet amount is ${total_bet}.")

    print("")

    slots = get_slot_machine_spin(ROWS, COLS, symbol_count)
    print_slot_machine(slots)

    winning, winning_lines = check_winner(slots, lines, bet, symbol_value)

    if winning > 0:
        print(f"Congratulations! You won ${winning}!")
        print("You won on lines:", *winning_lines)
        return winning
    else:
        print(f"Sorry, you lost ${total_bet}")
        return winning - total_bet


def main():
    balance = deposit()
    while True:
        print(f"Current balance is ${balance}.")
        answer = input("Hit enter to spin or q to quit: ")
        if answer.lower() == "q":
            break
        print("")
        balance += spin(balance)
        if balance <= 0:
            print("Sorry, you have run out of money. Game over.")
            break

    print(f"Your final balance is ${balance}.")


main()
