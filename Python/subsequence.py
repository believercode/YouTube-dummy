class isSubsequence:
    def __init__(self, s: str, t: str) -> None:
        self.s = s
        self.t = t

    def isSubsequence(self) -> bool:
        S = len(self.s)
        T = len(self.t)
        if s == "":
            return True
        if S > T:
            return False
        i = 0
        for j in range(T):
            if self.s[i] == self.t[j]:
                if i == S - 1:
                    return True
                i += 1
        return False


if __name__ == "__main__":
    s = "agc"
    t = "ahbgdc"
    obj = isSubsequence(s, t)
    print(obj.isSubsequence())
