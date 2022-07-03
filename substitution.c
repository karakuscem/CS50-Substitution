#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


string key;
int check_alpha(string);
int check_unique(string);
string convert_text(string);
int convert_upper(string);

int main(int argc, string argv[])
{
    key = argv[1];
    if (argc == 1)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    else if (check_alpha(key) != 26)
    {
        printf("Key must contain alphabetic characters.");
        return 1;
    }
    else if(check_unique(key) > 0)
    {
        printf("Key must contain unique characters.");
        return 1;
    }
    else
    {
        convert_upper(key);
        string plaintext = get_string("Plain text: ");
        printf("ciphertext: %s\n", convert_text(plaintext));
        return 0;
    }
}


int check_alpha(string argv)
{
    int check_alpha = 0;
    for (int i = 0; i < strlen(argv); i++)
    {
        if (isalpha(argv[i]))
        {
            check_alpha++;
        }
    }
    return check_alpha;
}


int check_unique(string keyu)
{
    int check_unique = 0;
    for (int i = 0; i < strlen(keyu); i++)
    {
        for (int j = i + 1; j < strlen(keyu); j++)
        {
            if (toupper(keyu[i]) == toupper(keyu[j]))
            {
                check_unique++;
                return check_unique;
            }
        }
    }
    return 0;
}

int convert_upper(string ctu)
{
    int i = 0;
    while (i < strlen(ctu))
    {
        i++;
        key[i] = toupper(ctu[i]);
    }
    return 0;
}

string convert_text(string conv)
{
    string ciphertext = conv;
    for (int i = 0; i < strlen(conv); i++)
    {
        if (!isalpha(conv[i]))
        {
            ciphertext[i] = conv[i];
        }
        else if (isupper(conv[i]))
        {
            ciphertext[i] = key[(conv[i]) - 65];
        }
        else if (islower(conv[i]))
        {
            ciphertext[i] = key[(conv[i]) - 97];
            ciphertext[i] = tolower(ciphertext[i]);
        }
    }
    return ciphertext;
}