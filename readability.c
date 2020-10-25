#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>

int countLetters(string text);
int countWords(string text);
int countSentences(string text);
float average(int letters_sentences, int words);
int ColemanLiau(float L, float S);
void grade(int index);

// Main
int main(void)
{
    int letters, words, sentences, index;
    float L, S;

    // Ask user for text
    string text = get_string("Text: ");

    letters = countLetters(text);   // Count letters
    words = countWords(text);   // Count words
    sentences = countSentences(text);   // Count sentences
    L = average(letters, words);    // The average number of letters per 100 words in the text
    S = average(sentences, words);  // the average number of sentences per 100 words in the text
    index = ColemanLiau(L, S);      // Coleman-Liau algorithm
    grade(index);   // Print the grade
}

// Count letters function
int countLetters(string text)
{
    int lengthText = strlen(text), letters = 0;

    for (int i = 0; i < lengthText; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

// Count words function
int countWords(string text)
{
    int lengthText = strlen(text), words = 1;

    for (int i = 0; i < lengthText; i++)
    {
        if (isspace(text[i]))
        {
            words += 1;
        }
    }
    return words;
}

// Count sentences funcion
int countSentences(string text)
{
    int lengthText = strlen(text), sentences = 0;

    for (int i = 0; i < lengthText; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences += 1;
        }
    }
    return sentences;
}

// Average number of letters/sentences per 100 words function
float average(int letters_sentences, int words)
{
    float ls;

    ls = ((float) letters_sentences * 100) / (float) words;

    return ls;
}

// Coleman-Liau algorithm function
int ColemanLiau(float L, float S)
{
    int index;

    index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}

// Print grades function
void grade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
