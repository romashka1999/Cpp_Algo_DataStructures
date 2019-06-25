// დავადგინოთ 1 - დან N - მდე რიცხვების ჯამი
#include <bits/stdc++.h> 
using namespace std;
// ფუნქცია ითვლის 1 - დან N -მდე რიცხვების ჯამს
int sumNumbers1ToN(long long n) 
{ 
	long long ans;
	//თუ N არის ლუწი
	if( n%2 == 0 )
	{
		ans = ((n/2 * n) + n/2);
	}
	//თუ N არის კენტი
	else
	{
		ans = ((n+1)/2 * n);
	}
	
    //დავბეჭდოთ პასუხი
    printf("\n\n პასუხი არის : ");
    printf("%d ", ans); 
} 
  
/* main პროგრამა ფუნქციის გატესტვისთვის */
int main() 
{ 
    printf("1 - დან  10 - მდე ჯამი არის : \n\n"); 
    sumNumbers1ToN(10); 
    return 0; 
} 

