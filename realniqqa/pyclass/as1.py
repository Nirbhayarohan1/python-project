def RI(s, n):
    if n >= 0 and n < len(s):
        return s[:n] + s[n+1:]
    else:
        return s

# Example usage
input_string = "MANGO"
n = 1
result = RI(input_string, n)
print("Result:", result)