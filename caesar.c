// This program encrypts a message using Caesar's cipher
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// first, get key from command line argument
int main(int argc, string argv[])
{
    // only accept a single command-line argument (k)
    if (argc == 2)
    {
        // turn key into an integer (l)
        int l = atoi(argv[1]);
        // prompt user for plaintext
        string p = get_string("plaintext: ");
        /*--- for each character in the plaintext string,
        if alphabetic, preserve case and shift plaintext
        character by key (l) ---*/
        char d;
        char c[strlen(p) + 1];
        int ai;
        int cai;
        for (int i = 0; i < strlen(p); i++)
        {
            // if the character is not alphabetic, output the character unchanged
            // add the character to array c[i]
            if (isalpha(p[i]) == false)
            {
                d = p[i];
                c[i] = d;
            }
            // if the character is uppercase, preserve case and add character to array c[i]
            else if (isupper(p[i]))
            {
                // convert to alphabetical index
                ai = p[i] - 65;
                do
                {
                    if (ai + l < 0)
                    {
                        ai += 26;
                    }
                    if (ai + l > 25)
                    {
                        ai -= 26;
                    }
                }
                while ((ai + l) < 0 || (ai + l) > 25);
                cai = (ai + l) % 26;
                // convert back to ascii index
                cai += 65;
                d = cai;
                // push each encoded letter into the c array
                c[i] = d;
            }
            // if the character is lowercase, preserve case and add character to array c[i]
            else
            {
                // convert to alphabetical index
                ai = p[i] - 97;
                do
                {
                    if (ai + l < 0)
                    {
                        ai += 26;
                    }
                    if (ai + l > 25)
                    {
                        ai -= 26;
                    }
                }
                while ((ai + l) < 0 || (ai + l) > 25);
                cai = (ai + l) % 26;
                // convert back to ascii index
                cai += 97;
                d = cai;
                // push each encoded letter into the c array
                c[i] = d;
            }
        }
        // print ciphertext
        printf("ciphertext: %s\n", c);
        return 0;

    }
    /*--- if program is executed without any comand-line argument or more than one argument
    is entered, print error message and return from main value of 1 ---*/
    else
    {
        printf("ERROR!! You must enter a key (number). Only one key is accepted.\n");
        return 1;
    }
}