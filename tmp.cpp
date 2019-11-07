#include<iostream>
#include<string>
using namespace std;

string pre_str, in_str, post_str;

void print_post(int s1, int e1, int s2, int e2)
{
    int root_idx = s2;
    while (pre_str[s1] != in_str[root_idx]) root_idx++;
    if (root_idx != s2) {
        print_post(s1+1, s1+root_idx-s2, s2, root_idx-1);
    }
    if (root_idx != e2) {
        print_post(s1+root_idx-s2+1, e1, root_idx+1, e2);
    }
    printf("%c", in_str[root_idx]);
}

int main()
{
    while (cin >> pre_str >> in_str) {
        print_post(0, pre_str.size()-1, 0, in_str.size()-1);
        printf("\n");
    }
    return 0;
}