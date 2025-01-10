import random
import string
import tkinter as tk
from tkinter import messagebox
from words import words

lives_visual_dict = {
    0: """
        ___________
       | /        | 
       |/        ( )
       |          |
       |         / \\
       |
    """,
    1: """
        ___________
       | /        | 
       |/        ( )
       |          |
       |         / 
       |
    """,
    2: """
        ___________
       | /        | 
       |/        ( )
       |          |
       |          
       |
    """,
    3: """
        ___________
       | /        | 
       |/        ( )
       |          
       |          
       |
    """,
    4: """
        ___________
       | /        | 
       |/        
       |          
       |          
       |
    """,
    5: """
        ___________
       | /        
       |/        
       |          
       |          
       |
    """,
    6: """
       |
       |
       |
       |
       |
    """,
    7: "",
}

# Sample words for the hangman game


def get_valid_word(words):
    word = random.choice(words)
    while '-' in word or ' ' in word:
        word = random.choice(words)
    return word.upper()

class HangmanGame:
    def __init__(self, root):
        self.root = root
        self.root.title("Hangman Game")
        self.word = get_valid_word(words)
        self.word_letters = set(self.word)
        self.used_letters = set()
        self.lives = 7

        # Create labels and buttons
        self.lives_label = tk.Label(self.root, text=f"Lives: {self.lives}", font=('Helvetica', 18))
        self.lives_label.pack()

        self.word_label = tk.Label(self.root, text=" ".join(['-' for _ in self.word]), font=('Helvetica', 24))
        self.word_label.pack()

        self.hangman_label = tk.Label(self.root, text=lives_visual_dict[self.lives], font=('Courier', 12), justify="left")
        self.hangman_label.pack()

        self.buttons_frame = tk.Frame(self.root)
        self.buttons_frame.pack()

        self.buttons = {}
        for letter in string.ascii_uppercase:
            button = tk.Button(self.buttons_frame, text=letter, width=4, height=2, font=('Helvetica', 14),
                               command=lambda l=letter: self.guess_letter(l))
            button.grid(row=ord(letter) // 9, column=ord(letter) % 9)  # Grid layout for letters
            self.buttons[letter] = button

    def guess_letter(self, letter):
        if letter in self.used_letters:
            messagebox.showinfo("Hangman", "You already used that letter!")
            return

        self.used_letters.add(letter)
        if letter in self.word_letters:
            self.word_letters.remove(letter)
        else:
            self.lives -= 1

        self.update_game()

    def update_game(self):
        # Update the displayed word
        word_display = [letter if letter in self.used_letters else '-' for letter in self.word]
        self.word_label.config(text=" ".join(word_display))

        # Update lives
        self.lives_label.config(text=f"Lives: {self.lives}")
        self.hangman_label.config(text=lives_visual_dict[self.lives])

        # Check if the game is over
        if self.lives == 0:
            messagebox.showinfo("Hangman", f"You died! The word was {self.word}.")
            self.root.destroy()
        elif len(self.word_letters) == 0:
            messagebox.showinfo("Hangman", f"Congratulations! You guessed the word {self.word}.")
            self.root.destroy()

if __name__ == "__main__":
    root = tk.Tk()
    game = HangmanGame(root)
    root.mainloop() 