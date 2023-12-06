#include <iostream>
#include <stack>
using namespace std;

// Span of a stock is defined as the number of consecutive days the price of stock is less than or equal to the 
// price on the current day. 
int main(){

    int stocks[] = {2,4,6,3,5,7,3,2,8,1,2,5,2,3,6};
    int len = sizeof(stocks)/sizeof(stocks[0]);
    int span[len];
    stack<pair<int,int>> s;

    for(int i = 0;i<len;i++){
        int price = stocks[i];
        if(s.empty()){
            s.push(make_pair(price, i));
            span[i] = i+1;
        }
        else{
            while(!s.empty()&&s.top().first<=price){ // THE S.EMPTY() CONDITION IS VERY IMPORTANT because otherwise we'll get a segmentation fault
                s.pop();
            }
            if(s.empty()){
                span[i] = i+1; // Since it is bigger than all those that came before it 
                s.push(make_pair(price,i));
            }
            else{
                span[i] = i - s.top().second;
                s.push(make_pair(price,i));
            }
        }
    }

    for(int i = 0;i<len;i++)
        cout<<span[i]<<" "; 
    return 0;
}

//2 4 6 3 5 7 3 2 8 1 2 5 2 3 6
//1 2 3 1 2 6 1 1 9 1 2 3 1 2 6