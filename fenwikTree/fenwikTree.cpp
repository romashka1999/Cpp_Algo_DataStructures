/*ფენვიკის ხე მუშაობის დრო : Log(n)
ალგორითმი გამოიყენება ინტერვალზე ჯამის საპოვნელად*/
#include <bits/stdc++.h> 
using namespace std; 

//ფუნქცია დააბრუნებს ჯამს პირველი ინდექსიდან(დასაწყისიდან) მითითებულ ინდექსამდე 
//პარამეტრად იღებს ფენვიკის ხეს და ინდექსს 
int getSum(int BITree[],int index){ 
    int sum=0;  
    index=index+1; 
    while (index>0){ 
        sum+=BITree[index]; 
        index-=index&(-index); 
    } 
    return sum; 
} 

//განვაახლოთ ფენვიკის ხეში ელემენტი პარამეტრად იღებს ფენვიკის ხეს , სიგრძეს ,ინდექსს და მნიშვნელობას
void updateBIT(int BITree[],int n,int index,int val){ 
    index=index+1; 
    while (index<=n){ 
    	BITree[index]+=val; 
    	index+=index&(-index); 
    } 
} 

//ავაგოთ ფენვიკის ხე პარამეტრად იღებს : მასივს და მასივის სიგრძეს
int *constructBITree(int arr[],int n){ 
    int *BITree=new int[n+1]; 
    for (int i=1; i<=n; i++) BITree[i] = 0; 
    for (int i=0; i<n; i++) updateBIT(BITree,n,i,arr[i]); 
    return BITree; 
} 

int main(){ 

	int n,idx,updIdx,newVal;
	cout<<"შემოიტანეთ მასივის ელემენტების რაოდენობა : ";cin>>n;
	int array[n+1];
	cout<<endl<<"შემოიტანეთ მასივის ელემენტები : ";
    for(int i=0;i<n;i++) cin>>array[i];
    cout<<endl<<"შემოიტანეთ ინდექსი რომელ ინდექსამდეც გაინტერესებთ ჯამი პირველი ინდექსიდან (დასაწყისიდან) : ";cin>>idx;

    int *BITree = constructBITree(array, n); 
    cout<<endl<<"ელემენტების ჯამი პირველი ინდექსიდან - "<<idx<<" ინდექსამდე არის  :"<< getSum(BITree,idx-1); 
  	cout<<endl;
  	cout<<"შემოიტანეთ ინდექსი სადაც გინდათ ელემენტის ცვლილება : ";cin>>updIdx;
  	cout<<"შემოიტანეთ ახალი ელემენტის მნიშვნელობა: ";cin>>newVal;
    //განვაახლოთ ფენვიკის ხეში მონაცემი
    updateBIT(BITree/*ხე*/, n/*მასივის სიგრძე*/, updIdx/*ინდექსი*/, newVal/*მნიშვნელობა*/); 
  
    return 0; 
} 
