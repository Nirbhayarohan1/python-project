def fibonacci_sequence(terms):
    if terms <= 0:
        return "Number of terms must be positive."
    sequence = []
    a, b = 0, 1
    for _ in range(terms):
        sequence.append(a)
        a, b = b, a + b
    return sequence

try:
    num_terms = int(input("Enter the number of terms for the Fibonacci sequence: "))
    if num_terms <= 0:
        print("Please enter a positive integer.")
    else:
        print(f"Fibonacci sequence up to {num_terms} terms: {fibonacci_sequence(num_terms)}")
except ValueError:
    print("Invalid input! Please enter a positive integer.")
32