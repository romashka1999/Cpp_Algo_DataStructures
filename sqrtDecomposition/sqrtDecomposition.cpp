/*SQRT დეკომპოზიცია მუშაობის დრო : ფესვი n 
ალგორითმი არის იმისათვის რათა ვიპოვოთ ინტერვალებზე ჯამი,მინიმუმი და მაქსიმუმი
*/
#include<bits/stdc++.h>
using namespace std; 
#define ARRMAX 50005
#define SQRTMAX 225
int arr[ARRMAX],blockMin[SQRTMAX],blockMax[SQRTMAX],blockSum[SQRTMAX],blk_sz; 

//SQRT მასივების განახლება
void update(int idx,int val){ 
    int blockNumber=idx/blk_sz; 
    
    //MIN SQRT განახლება
    blockMin[blockNumber]=min(val,blockMin[blockNumber]); 
    
    //MAX SQRT განახლება
    blockMax[blockNumber]=max(val,blockMin[blockNumber]); 
    
    //SUM SQRT განახლება
    blockSum[blockNumber]+=val-arr[idx]; 
    
    arr[idx] = val;
} 

//ფუნქცია აბრუნებს მინიმუმს მოცემული ინტერვალისათვის
int queryMin(int l,int r){ 
    int mn=1e7; 
    while (l<r and l%blk_sz!=0 and l!=0){  
        mn = min(mn,arr[l]); 
        l++; 
    } 
    while (l+blk_sz <= r){ 
        mn=min(mn,blockMin[l/blk_sz]); 
        l+=blk_sz; 
    } 
    while (l<=r){ 
        mn=min(mn,arr[l]); 
        l++; 
    } 
    return mn; 
} 

//ფუნქცია აბრუნებს მაქსიმუმს მოცემული ინტერვალისათვის
int queryMax(int l,int r){ 
    int mx=-1e7; 
    while (l<r and l%blk_sz!=0 and l!=0){  
        mx=max(mx,arr[l]); 
        l++; 
    } 
    while (l+blk_sz <= r){ 
        mx=max(mx,blockMax[l/blk_sz]); 
        l+=blk_sz; 
    } 
    while (l<=r){ 
        mx=max(mx,arr[l]); 
        l++; 
    } 
    return mx; 
}

//ფუნქცია აბრუნებს ჯამს მოცემული ინტერვალისათვის
int querySum(int l,int r){ 
    int sum = 0; 
    while (l<r and l%blk_sz!=0 and l!=0){ 
        sum += arr[l]; 
        l++; 
    } 
    while (l+blk_sz<=r){ 
        sum+=blockSum[l/blk_sz]; 
        l+=blk_sz; 
    } 
    while (l<=r){ 
        sum += arr[l]; 
        l++; 
    } 
    return sum; 
} 

int main() { 
//QUERY OF ARRAY
	int n,blk_idx;
 	cout<<"შემოიტანეთ მასივის ელემენტების რაოდენობა : ";cin>>n; cout<<endl;
 	cout<<"შემოიტანეთ მასივის ელემენტები : ";
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<endl;
	blk_sz=sqrt(n); 
/**********************************************************/
//MIN SQRT მასივის აგება
	blk_idx=-1;  
    for (int i=0;i<n;i++){ 
        if (i%blk_sz==0){  
            blk_idx++; 
            blockMin[blk_idx]=1e7;
        } 
        blockMin[blk_idx] = min(arr[i],blockMin[blk_idx]); 
    } 
/**********************************************************/
//MAX SQRT მასივის აგება
	blk_idx=-1; 
    for (int i=0;i<n;i++){ 
        if (i%blk_sz==0){  
            blk_idx++; 
            blockMax[blk_idx]=-1e7;
        } 
        blockMax[blk_idx] = max(arr[i],blockMax[blk_idx]);  
    } 
/**********************************************************/
//SUM SQRT მასივის აგება
    blk_idx = -1; 
    for (int i=0;i<n;i++){ 
        if (i%blk_sz==0){ 
            blk_idx++; 
        } 
        blockSum[blk_idx]+=arr[i]; 
    } 
/**********************************************************/
//შემოვიტანოთ კითხვები
    int lx,rx,q;
    cout<<"შემოიტანე კითხვების რაოდენობა : ";cin>>q;
    for(int i=0;i<q;i++){
    	int ans;
    	cout<<endl;
    	cout<<"შემოიტანე მარცხენა ინდექსი : ";cin>>lx; 
    	cout<<"შემოიტანე მარჯვენა ინდექსი : ";cin>>rx; 
		cout<<endl;
    	cout<<"QUERY MIN : "<<queryMin(lx-1,rx-1)<<endl;
    	cout<<"QUERY MAX : "<<queryMax(lx-1,rx-1)<<endl;
    	cout<<"QUERY SUM : "<<querySum(lx-1,rx-1)<<endl;
	}
/**********************************************************/
     return 0;
} 
