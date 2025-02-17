import calendar

def print_year_calendar(year):
    cal = calendar.TextCalendar().formatyear(year)
    print(cal)

if __name__ == "__main__":
    year = 2024
    print_year_calendar(year)
