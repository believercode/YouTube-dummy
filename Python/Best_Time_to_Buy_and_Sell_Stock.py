def maxProfit(prices):
    max_profit = 0
    min_price = float('inf')

    for price in prices:
        if price < min_price:
            min_price = price

        profit = price - min_price

        if profit > max_profit:
            max_profit = profit

    return max_profit


if __name__ == '__main__':
    prices = [7, 1, 5, 3, 6, 4]  # output: 5  buy = 1, sell = 6
    prices1 = [7, 6, 4, 3, 1]  # Output: 0    none
    prices2 = [7, 6, 4, 3, 1, 2]  # Output: 1 buy = 1, sell = 2
    prices3 = [2, 4, 1]  # Output: 2          buy = 2, sell = 4
    prices4 = [1, 2]  # Output: 1             buy = 1, sell = 2

    print("first:", maxProfit(prices))
    print("second:", maxProfit(prices1))
    print("third:", maxProfit(prices2))
    print("fourth:", maxProfit(prices3))
    print("fifth:", maxProfit(prices4))
