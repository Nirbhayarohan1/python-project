def SO():
    string1 = input("Enter the first string: ")
    string2 = input("Enter the second string: ")

    concatenated_string = string1 + string2
    print("Concatenated String:", concatenated_string)

    start = int(input("Enter the start index for slicing (inclusive): "))
    end = int(input("Enter the end index for slicing (exclusive): "))
    
    if 0 <= start < len(string1) and 0 < end <= len(string1):
        sliced_string = string1[start:end]
        print(f"Sliced String from index {start} to {end}:", sliced_string)
    else:
        print("Invalid slicing indices!")

    length_of_string1 = len(string1)
    print("Length of the first string:", length_of_string1)

    upper_string = string1.upper()
    lower_string = string1.lower()
    
    print("Uppercase version of the first string:", upper_string)
    print("Lowercase version of the first string:", lower_string)

SO()
