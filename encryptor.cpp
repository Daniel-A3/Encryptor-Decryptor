#include <iostream>
#include <string>
#include <stdlib.h>

int main()
{

    std::string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890'@#~;:.,></?\"!£$\\|`¬[]{ }"};
    std::string key     {"ZYXWVUTSRQPONMLKJIHGFEDCBAxznlwebgjhqdyvtkfuompciasr¬`|\\$£!\"?/<>,.:;~#@0987654321[] {}"};

    bool done{false};

    while (!done)
    {
        std::string message{};
        std::string encryptedMessage{};
        std::string decryptedMessage{};
        char eOrD;

        std::cout << "\nDo you want to encrypt or decrypt?(E/D) - 'Q' to exit : ";
        std::cin >> eOrD;

        if (toupper(eOrD) == 'Q') {
            break;
        }

        std::cout << "\nEnter your message for encryption/decryption : ";
        std::cin.ignore();
        std::getline(std::cin, message);

        if (toupper(eOrD) == 'E')
        {
            for (char c : message)
            {
                size_t position = alphabet.find(c);
                if (position != std::string::npos)
                {
                    char newChar {key.at(position)};
                    encryptedMessage += newChar; 
                } else {
                    encryptedMessage += c;
                }
            }
            std::cout << "[-]Analyzing message...\n"
                         "[-]Encrypting/Decrypting message...\n"
                         "[-]Result : " << encryptedMessage;

        } else if (toupper(eOrD) == 'D') 
        {
            for (char c : message)
            {
                size_t position = key.find(c);
                if (position != std::string::npos)
                {
                    char newChar {alphabet.at(position)};
                    decryptedMessage += newChar; 
                } else {
                    decryptedMessage += c;
                }
            }
            std::cout << "[-]Analyzing message...\n"
                        "[-]Encrypting/Decrypting message...\n"
                        "[-]Result : " << decryptedMessage;
        } else
        {
            std::cout << "\nPlease enter a valid option";
        }
    }

    return 0;
}