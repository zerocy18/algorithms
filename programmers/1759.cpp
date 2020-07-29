#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int l, c;
vector<char> v;

char answer[16];

void input(){
    char in;
    scanf("%d %d",&l,&c);
    for(int i = 0; i < c;i++){
        scanf(" %c", &in);
        v.push_back(in);
    }
    sort(v.begin(), v.end());
}

void dfs(int cnt, int vowel, int consonant,int start){
    if(cnt == l){
        if(vowel > 0 && consonant>1){
            printf("%s\n", answer);
        }
        return ;
    }
    for(int i =start ; i < v.size(); i++){
        answer[cnt] = v[i];
        if(v[i]=='a'|| v[i]=='e'||v[i]=='i'||v[i]=='o'||v[i]=='u'){
            dfs(cnt+1,vowel+1,consonant,i+1);
        }
        else{
            dfs(cnt+1, vowel,consonant+1,i+1);
        }
    }
}

int main(){
    input();
    // for(int i = 0 ; i < v.size(); i++){
    //     printf("%c",v[i]);
    // }
    dfs(0,0,0,0);
    return 0;
}
