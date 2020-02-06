#include <cstdio>
#include <cstring>

using namespace stdl

const int maxn = 5678;
char s1[maxn], s2[maxn], minSub[maxn];

char min(char ch1, char ch2) { return ch1 < ch2 ? ch1 : ch2; }
char swap(char &ch1, char &ch2) { char t = ch1; ch1 = ch2; ch2 = t; }

bool checkMin()

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s %s", s1, s2);
        int l1 = strlen(s1);
        minsub[l1] = 'Z' + 1;
        for(int i = l1 - 1; ~i; --i) {
            minSub[i] = min(s1[i], minsub[i + 1]);
        }
        int k = 0;
        for(k = 0; k < l1; ++k)
            if(s1[k] != minSub[k])
                break;
        if(k != l1 && s1[k] != minSub[k]) {
            int j = k;
            for(int i = k + 1; i < l1; ++i) {
                if(s1[i] < s1[j]) {
                    j = i;
                }
            }
            swap(s1[j], s1[k]);
        }
        if(checkMin()) {
            printf("%s\n", s1);
        } else {
            printf("---\n");
        }
    }
    return 0;
}
