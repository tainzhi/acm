#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::string in_string;
    while (getline(cin, in_string))
    {
        //input noting
        if (in_string.length() == 0)
        {
            cout<<"error"<<endl;
            continue;
        }
        int count_blank = 0, count_character = 0, begin_new_string_id = 0;
        bool pre_has_character = true;
        for (int i=0; i != in_string.length(); i++)
        {
            if (in_string[i] == ' ')
            {
                if (pre_has_character)
                {
                    count_blank++;
                    in_string[begin_new_string_id++] = ' ';
                    pre_has_character = false;
                }
            }
            else
            {
                count_character++;
                pre_has_character = true;
                in_string[begin_new_string_id++] = in_string[i];
            }
        }
        //input 1 character, no blank
        if (count_character == 1 && count_blank == 0)
        {
            cout<<"error 2"<<endl;
            continue;
        }
        /*
        for (int i=0; i<begin_new_string_id - 1; i++)
            cout<<in_string[i];
        cout<<in_string[begin_new_string_id - 1]<<"---"<<endl;
        cout<<"8****************"<<count_blank<<"----"<<count_character<<endl;
        cout<<in_string<<"****"<<begin_new_string_id<<endl;
        */
        int last_new_string_point, last_old_string_point = begin_new_string_id - 1;
        int character_number = count_blank * 3 + count_character;
        if (character_number > in_string.length())
        {
            std::string temp_string(character_number - in_string.length(), ' ');
            in_string += temp_string;
            last_new_string_point = character_number - 1;
        }
        while (last_old_string_point >= 0)
        {
            if (in_string[last_old_string_point] == ' ')
            {
                in_string[last_new_string_point--]='0';
                in_string[last_new_string_point--]='2';
                in_string[last_new_string_point--]='%';
            }
            else
                in_string[last_new_string_point--] = in_string[last_old_string_point];
            last_old_string_point--;
        }
        for (int i=0; i< character_number-1; i++)
            cout<<in_string[i];
        cout<<in_string[character_number-1]<<endl;
    }
    return 0;
}
