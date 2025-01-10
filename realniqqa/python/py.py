def add_commas_to_file_content(input_file, output_file):
    try:
        # Open the input file and read its content
        with open(input_file, 'r') as file:
            content = file.read()
        
        # Separate each character by a comma
        modified_content = ','.join(content)
        
        # Write the modified content to the output file
        with open(output_file, 'w') as file:
            file.write(modified_content)
        
        print(f"Contents have been modified and saved to {output_file}.")
    except FileNotFoundError:
        print(f"The file {input_file} does not exist.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Example usage
input_file = 'input.txt'  # Replace with the path to your input file
output_file = 'output.txt'  # Replace with the path to your output file
add_commas_to_file_content(input_file, output_file)
