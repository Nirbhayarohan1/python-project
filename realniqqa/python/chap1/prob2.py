import os

def print_directory_contents(directory):
    try:
        # List the contents of the directory
        entries = os.listdir(directory)
        
        # Print each entry
        for entry in entries:
            print(entry)
    except FileNotFoundError:
        print(f"The directory '{directory}' does not exist.")
    except PermissionError:
        print(f"Permission denied to access the directory '{directory}'.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Specify the directory you want to list
directory_path = '.'  # Current directory

print_directory_contents(directory_path)
