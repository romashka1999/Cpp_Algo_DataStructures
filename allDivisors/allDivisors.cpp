// ვიპოვოთ ყველა N - ის გამყოფი
#include <bits/stdc++.h> 
using namespace std;
// ფუნქცია ბეჭდავს გამყოფებს 
int printAllDivisors(long long n) 
{ 
    //მთვლელი
	int cnt = 0;
	
    // ციკლი გაგრძელდება N - ის ფესვამდე
    for (int i=1; i<=sqrt(n); i++) 
    { 
        //თუ N იყოფა i -  ზე
        if (n%i == 0) 
        { 
        	// თუ N - არის რომელიმე რიცხვის კვადრატი დავბეჭდოთ ერთი
            if (n/i == i)
			{
            	printf("%d ", i); 
            	cnt++;
			}
                
  			// თუარადა ორივე დავბეჭდოთ 
            else 
			{
                printf("%d %d ", i, n/i); 
                cnt += 2;
        	}
        } 
    } 

    //დავბეჭდოთ პასუხი თუ სულ რამდენი გამყოფიაქვს 
    printf("\n\n სულ არის : ");
    printf("%d ", cnt); 
    printf(" გამყოფი");
} 
  
/* main პროგრამა ფუნქციის გატესტვისთვის */
int main() 
{ 
    printf("გამყოფები 1000000000 - ის არიან : \n\n"); 
    printAllDivisors(1000000000); 
    return 0; 
} 

