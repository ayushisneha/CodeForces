#include <iostream>
#include <string>

using namespace std;

int is_vowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y': return true;
    }

    return false;
}

int main()
{
    int length;
    string text;
    cin >> length >> text;

    string final_text;
    final_text += text[0];
    for(int i = 1; i < length; i++)
    {
        if(is_vowel(text[i]) && is_vowel(final_text[final_text.size() - 1]))
        {
               continue;
        }

        final_text += text[i];
    }

    cout << final_text;
    return 0;
}
