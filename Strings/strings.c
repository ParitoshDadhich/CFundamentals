#include <stdio.h>
#include <stdbool.h>

int length(char *str){
    int length = 0;
    int i;
    for(i=0; str[i] != '\0'; i++)
        length++;
    
    return length;
}

void findDublicates(char *str){
    int *arr = (int *)malloc(26*sizeof(int));
    
    for(int i=0; str[i] != '\0'; i++){
        arr[str[i] - 97]++;
    }
    
    for(int i=0; i<26; i++)
        printf("%d ", arr[i]);
    
    printf("dublicates are: \n");
    for(int i=0; i<26; i++){
        if(arr[i] > 1 ){
            printf("%c %d\n", str[i]+97, arr[i]);
        }
    }
}

void changeCase(char *str){
    for(int i=0; str[i] !='\0'; i++){
        if(str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        else if(str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
}


void reverseString(char *str){
    int i=0;
    for(i=0; str[i] !='\0'; i++){}
    i--;
    
    for(int j=0; j<i; j++, i--){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

bool isAnagram(char *s1, char *s2){
    int arr[26];
    
    for(int i=0; s1[i] != '\0'; i++){
        arr[s1[i]-'a']++;
    }
    
    for(int i=0; s2[i] != '\0'; i++){
        arr[s2[i]-'a']--;
    }
    
    for(int i=0; i<26; i++)
        if(arr[i]  != 0)
            return false;
    
    return true;
}

int main()
{
    char str[] = "ajay";
    // changeCase(str);
    // printf("%s\n", str);
    // printf("%d\n", length(str));
    // reverseString(str);
    // printf("%s\n", str);
    // findDublicates(str);
    
    char *s1 = "decimal";
    char *s2 = "medical";
    printf(" boolean %d\n", isAnagram(s1, s2));
    return 0;
}
