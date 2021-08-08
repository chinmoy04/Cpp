#include<iostream>

using namespace std;

void reverse(char* start, char* end)
{
    char temp;
    while(start<end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseWords(char* iStr)
{
    char* wordBegin = NULL;
    char* tmp = iStr;

    while(*tmp)
    {
        if(wordBegin == NULL && *tmp != ' ')
        {
            wordBegin = tmp;
        }
        if(wordBegin && (*(tmp+1) == ' ' || *(tmp+1) == '\0'))
        {
            reverse(wordBegin, tmp);
            wordBegin = NULL;
        }
        tmp++;
    }
    reverse(iStr, tmp-1);
}


int main()
{
  char s[] = "i like this program very much";
  char *temp = s;
  cout << s << endl;
  reverseWords(s);
  cout << s << endl;
  printf("%s", s);
  getchar();
  return 0;
}
