# def longest_common_prefix(strs):
#     min_len = float('inf')
#     for s in strs:
#         if len(s) < min_len:
#             min_len = len(s)

#     i = 0
#     while i < min_len:
#         for s in strs:
#             if s[i] != strs[0][i]:
#                 return s[:i]
#         i += 1
#     return s[:i]


def longest_common_prefix(strs):
    if not strs:
        return ""

    prefix = strs[0]  # Start with the first string as the potential prefix

    for s in strs[1:]:  # Iterate through the rest of the strings
        while not s.startswith(prefix):  # Check if the string starts with the current prefix
            prefix = prefix[:-1]  # If not, shorten the prefix by one character
            if not prefix:  # If the prefix becomes empty, return an empty string
                return ""

    return prefix  # Return the final prefix


if __name__ == '__main__':
    strs1 = ["flower", "flow", "flight"]  # Output: "fl"
    strs2 = ["dog", "racecar", "car"]  # Output: ""
    strs3 = ["access", "accessories", "accessibility", "a"]  # Output: "a"
    strs4 = ["adnan"]  # Output: "adnan"
    strs5 = ['']  # Output: ""
    print("1. answer (expected: 'fl') : " + longest_common_prefix(strs1))
    print()
    print("2. answer (expected: '') : " + longest_common_prefix(strs2))
    print()
    print("3. answer (expected: 'a') : " + longest_common_prefix(strs3))
    print()
    print("4. answer (expected: 'adnan') : " + longest_common_prefix(strs4))
    print()
    print("5. answer (expected: '') : " + longest_common_prefix(strs5))
