#include "leetcode.hpp"

/*
 * You are playing the following Bulls and Cows game with 
 * your friend: You write a 4-digit secret number and ask 
 * your friend to guess it, each time your friend guesses a 
 * number, you give a hint, the hint tells your friend how 
 * many digits are in the correct positions (called "bulls") 
 * and how many digits are in the wrong positions (called "cows"), 
 * your friend will use those hints to find out the secret number.
 * 
 * For example:
 * 
 * Secret number:  1807
 * Friend's guess: 7810
 * Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 * According to Wikipedia: "Bulls and Cows (also known as Cows 
 * and Bulls or Pigs and Bulls or Bulls and Cleots) is an old 
 * code-breaking mind or paper and pencil game for two or more players, 
 * predating the similar commercially marketed board game Mastermind. 
 * The numerical version of the game is usually played with 4 digits, 
 * but can also be played with 3 or any other number of digits."
 * 
 * Write a function to return a hint according to the secret number 
 * and friend's guess, use A to indicate the bulls and B to indicate 
 * the cows, in the above example, your function should return 1A3B.
 * 
 * You may assume that the secret number and your friend's guess only 
 * contain digits, and their lengths are always equal.
 */

string getHint(string secret, string guess) {
    int cows = 0, bulls = 0;
    unordered_map<char,int> correctChar;
    
    for(int i = 0; i < secret.size(); ++i) {
        if( secret[i] == guess[i] )
            ++bulls;
       else
            ++correctChar[secret[i]];
    }
    
    for(int i = 0; i < secret.size(); ++i) {
        if( secret[i] != guess[i] && correctChar.find(guess[i]) != correctChar.end() && correctChar[guess[i]] != 0 ) {
            ++cows;
            --correctChar[guess[i]];
        }
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
}
