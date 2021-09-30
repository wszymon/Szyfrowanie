#include <iostream>

class Cipher {
protected:
    std::string result;
public:
    virtual void encryptIt(std::string) = 0;
};
// Caesar class
class Caesar :public Cipher {       
public:
    void encryptIt(std::string inputString) override  {
        const int inputLength = inputString.length();
        for (int i = 0; i < inputLength; i++)
            result += char(int(inputString[i] + 4 - 97) % 26 + 97);
        std::cout << result << std::endl;
    }
};
// Reversing class
class Reversing :public Cipher{
public:
    void encryptIt(std::string inputString) override {
        const int inputLength = inputString.length();
        for (int i = inputLength - 1; i >= 0; i--)
            result += inputString[i];
        std::cout << result << std::endl;
    }
};
// Exchange class
class Exchange :public Cipher {   
public:
    void encryptIt(std::string inputString) override {
        const int inputLength = inputString.length();
        for (int i = 0; i < inputLength; i++) {
            switch (inputString[i]) {
            case 'a': result += 'z'; break; case 'b': result += 'y'; break; case 'c': result += 'x'; break;
            case 'd': result += 'w'; break; case 'e': result += 'v'; break; case 'f': result += 'u'; break;
            case 'g': result += 't'; break; case 'h': result += 's'; break; case 'i': result += 'r'; break;
            case 'j': result += 'q'; break; case 'k': result += 'p'; break; case 'l': result += 'o'; break;
            case 'm': result += 'n'; break; case 'n': result += 'm'; break; case 'o': result += 'l'; break;
            case 'p': result += 'k'; break; case 'q': result += 'j'; break; case 'r': result += 'i'; break;
            case 's': result += 'h'; break; case 't': result += 'g'; break; case 'u': result += 'f'; break; 
            case 'v': result += 'e'; break; case 'w': result += 'd'; break; case 'x': result += 'c'; break;
            case 'y': result += 'b'; break; case 'z': result += 'a'; break;
            }
        }
        std::cout << result << std::endl;
    }
};
// Basic class
class Start {
private:
    Cipher* polymorphicPointer{};
    char choice = NULL;
public:
    char whichCipher() { // cipher choosing // c-ceasar, o-reversing, w-exchange
        char choice = NULL;
        std::cin >> choice;
        return std::tolower(choice);
    }
    std::string input() { // output text
        std::cout << std::endl << "Wpisz napis do zaszyfrowania: ";
        std::string inputString, lowerCased;
        std::cin >> inputString;
        const int inputLength = inputString.length();
        for (int i = 0; i < inputLength; i++)
            lowerCased += std::tolower(inputString[i]);//lowercasing whole input string
        if (true) { //checking is there any wrong character
            for (int i = 0; i < inputLength; i++) {
                if (!isalpha(lowerCased[i])) {
                    std::cout << "Nieprawidlowy tekst! Sprobuj wpisac tylko litery" << std::endl << std::endl;
                    return "0";
                }
            }
        }
        std::cout << "Twoj zaszyfrowany napis: ";
        return lowerCased;
    }
    void encrypt(Cipher* pointer, std::string s) { // setting polimorphic pointer
        pointer->encryptIt(s);
        std::cout << std::endl;
    }
    void message() {
        std::cout << R"(Wybierz rodzaj szyfru
        c - szyfr cezara
        o - odwracanie
        w - wymiana
        0 - zamknij program
    )" << std::endl;
    }
    void procedure() {
        do {
            message();
            choice = whichCipher();
            if (choice == 'c') {
                Caesar c;
                polymorphicPointer = &c;
                std::string text = input();
                if(text != "0")
                    encrypt(polymorphicPointer, text);
            }
            else if (choice == 'o') {
                Reversing o;
                polymorphicPointer = &o;
                std::string text = input();
                if (text != "0")
                    encrypt(polymorphicPointer, text);
            }
            else if (choice == 'w') {
                Exchange w;
                polymorphicPointer = &w;
                std::string text = input();
                if (text != "0")
                    encrypt(polymorphicPointer, text);
            }
            else if (choice == '0')
                std::cout << "Dowidzenia :)" << std::endl;
            else
                std::cout << "Zly wybor!" << std::endl << std::endl;
        }while (choice != '0');
    }
};
int main()
{
    Start s;
    s.procedure();
    return 0;
}
