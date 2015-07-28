#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc < 2) 
    {
        printf("ERROR: You need at least one argument.\n");
        // This is how you abort a program
        return 1;
    }

    // Loop through each arg
    int i, j;
    for(j = 1; j < argc; j++)
    {

        // Convert jth arg to lowercase 
        for(i = 0; argv[j][i] != '\0'; i++)
        {
            // Add 32 to each letter if upper case to convert into lower case
            if(argv[j][i] > 64 && argv[j][i] < 91)
            {
                argv[j][i] += 32;
            }
        }


        // Vowel check
        char letter;
        for(i = 0; argv[j][i] != '\0'; i++) 
        {
            letter = argv[j][i];
            switch(letter) 
            {
                case 'a':
                    printf("%d: 'A'\n", i);
                    break;

                case 'e':
                    printf("%d: 'E'\n", i);
                    break;

                case 'i':
                    printf("%d: 'I'\n", i);
                    break;

                case 'o':
                    printf("%d: 'O'\n", i);
                    break;

                case 'u':
                    printf("%d: 'U'\n", i);
                    break;

                case 'y':
                    if(i > 2)
                    {
                        // it's only sometimes Y
                        printf("%d: 'Y'\n", i);
                    }
                    break;

                default:
                    printf("%d: %c is not a vowel\n", i, letter);
            }
        }
    }
    return 0;
}





