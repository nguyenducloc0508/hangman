#include <iostream>
using namespace std;

const string figure[8] = {
    " ------------- \n"
    " | \n"
    " | \n"
    " | \n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " |           |\n"
    " | \n"
    " | \n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " |           |\n"
    " |           O\n"
    " | \n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " |           |\n"
    " |           O\n"
    " |           |\n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " |           |\n"
    " |           O\n"
    " |          /|\n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " |           |\n"
    " |           O\n"
    " |          /|\\\n"
    " | \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " |           |\n"
    " |           O\n"
    " |          /|\\\n"
    " |          /\n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " |           |\n"
    " |           O\n"
    " |          /|\\\n"
    " |          / \\\n"
    " | \n"
    " ----- \n"
};

string chooseSecretWord() {
    return "secret";
}

string initGuessWord(string secretWord) {
    int len = secretWord.length();
    string returnWord = "";
    for (int i = 0; i < len; i++) {
        returnWord += "_";
    }
    return returnWord;
}

void showNumberOfCharacters(string secretWord) {
    cout << "The secret word has " << secretWord.length() << " characters.\n";
}

void renderGame(string guessWord, int badGuessCount) {
    cout << "The guess word is " << guessWord << "\nYou have " << 7 - badGuessCount << " remaining guesses.\n";
}

char readGuess() {
    cout << "Enter your guess: ";
    char guess;
    cin >> guess;
    return guess;
}

bool contains(string secretWord, char guess) {
    for (char character : secretWord) {
        if (character == guess) return true;
    }
    return false;
}

string update(string guessWord, string secretWord, char guess) {
    string returnWord = guessWord;
    for (int i = 0; i < secretWord.length(); i++) {
        if (guess == secretWord[i]) {
            returnWord[i] = guess;
        }
    }
    return returnWord;
}

void wrongAnswer() {
    cout << "Your guess is not correct.\n";
}

void showHangMan(int badGuessCount) {
    cout << figure[badGuessCount] << "\n";
}

void winGame(string secretWord) {
    cout << "The secret word is " << secretWord << "\nCongratulations, you win!\n";
}

void loseGame(string secretWord) {
    cout << "You lose. The correct word is " << secretWord << ". Let's try again later!\n";
}

int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    bool running = true;
    int badGuessCount = 0;
    string secretWord = chooseSecretWord();
    string guessWord = initGuessWord(secretWord);
    showNumberOfCharacters(secretWord);
    showHangMan(badGuessCount);
    while(running) {
        renderGame(guessWord, badGuessCount);
        char guess = readGuess();
        if (contains(secretWord, guess)) {
            guessWord = update(guessWord, secretWord, guess);
        } else {
            wrongAnswer();
            badGuessCount++;
        }
        showHangMan(badGuessCount);
        if (guessWord == secretWord) {
            winGame(secretWord);
            running = false;
        } else if (badGuessCount == 7) {
            loseGame(secretWord);
            running = false;
        }
    }
}
