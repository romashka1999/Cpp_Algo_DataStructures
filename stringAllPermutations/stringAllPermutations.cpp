/* პროგრამა აბრუნებს ყველა პერმუტაციას(შესაძლო ვარიანტს წყობისას) სტრინგისას */
#include<bits/stdc++.h>
using namespace std;
  
/* ფუნქცია არის იმისათვის რომ გავუცვალოთ ადგილები ორ მიმთითებელს */
void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
/* ფუნქცია ბეჭდავს სტრიქონის ყველა პერმუტაციას
   სამ პარამეტრს იღებს: 
   1. სტრიქონს
   2. სტრიქონის დასაწყის ინდექსს 
   3. სტრიქონის ბოლო ინდექსს. */
void permute(char *a, int l, int r) 
{ 
   int i; 
   if (l == r) 
     printf("%s\n", a); 
   else
   { 
       for (i = l; i <= r; i++) 
       { 
          swap((a+l), (a+i)); 
          permute(a, l+1, r); 
          swap((a+l), (a+i)); 
       } 
   } 
} 
  
/* main პროგრამა ფუნქციის გატესტვისთვის */
int main() 
{ 
    char str[] = "ABC"; 
    int n = strlen(str); 
    permute(str, 0, n-1); 
    return 0; 
} 
