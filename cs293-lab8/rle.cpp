#include "rle.h"
#include <cmath>
#include <bitset>
#include <iostream>

// Constructor
rle::rle(int gamma): gamma(gamma){}

// Convert integer to gamma-bit binary string
string rle::f(int i)
{  
    //let the number be some abcdef...
    string encoding = "";
    int len = 0;
    int i1 = i;

    while(i1>0){
        len++;
        i1= i1/10;
    }

    if(i/(int)(pow(10,len-1)) == 1) //this means starts with a 1
    {
        bool flag = 1;
        encoding += "1";
        i = i % (int)pow(10,len-1); //we take the remaining digits
        len -= 1;
        while(len>1){
            int dig = (i/(int)pow(10,len-1));
            len -= 1;
            while(dig>0){
                if(flag)
                    encoding = encoding + "1";
                else
                    encoding = encoding + "0";
                dig = dig-1;
            }
            flag = !flag;
        }
    }else{ //this means starts with a zero
        bool flag = 0;
        encoding += "0";
        while(len>1){
            int dig = (i/(int)pow(10,len-1))%10;
            len -= 1;
            while(dig>0){
                if(flag)
                    encoding = encoding + "1";
                else
                    encoding = encoding + "0";
                dig = dig-1;
            }
            flag = !flag;
        }
    }
   
    return encoding; 

}

// Convert gamma-bit binary string to integer
int rle::g(string i)
{ 
    int result = 0;
    int len = i.length();
    int flag = (i[0] == '1')? 1 : 0;
    char prev = 'x';
    int counter = 0;
    for(int j = 0; j < len;j++){
        if(flag == 1){
            if(j == 0)
                continue;
            
            if(prev == 'x'){
                counter++;
                prev = i[j];
                continue;
            }

            if(i[j]==prev){
                counter = counter++;
                prev = i[j];
                continue;
            }
            else{
                counter = 1;
                prev = i[j];
                result = result*10+counter;
            }
        }
        else{
            if(prev == 'x'){
                counter++;
                prev = i[j];
                continue;
            }

            if(i[j]==prev){
                counter = counter++;
                prev = i[j];
                continue;
            }
            else{
                counter = 1;
                prev = i[j];
                result = result*10+counter;
            }
        }
    }
    return result;
}

// Compress the input file
string rle::compress(string input_string)
{   
    int result = 0;
    for(int i=0; i<input_string.length(); i++){
        if(input_string[i]>=100){
            result = result*1000 + (int)input_string[i];
        }else if(input_string[i]>=10){
            result = result*100 + (int)input_string[i];
        }
        else
            result = result*10 + (int)input_string[i];
    }

    //now we compress this result further into a binary string
    string final_result = f(result);
    return final_result; 
}

// Decompress the input file
string rle::decompress(string input_string)
{ 
    //given the string we convert it first into an integer
    int ascii_number = g(input_string);
    string final_result = "";
    while(ascii_number>0){
        int dig_3 = ascii_number%1000;
        int dig_2 = ascii_number%100;
        if(dig_3/100 == 1){
            final_result = char(dig_3) + final_result ;
            ascii_number = ascii_number/1000;
        }
        else{
            final_result = char(dig_2) + final_result;
            ascii_number = ascii_number/100;
        }
    }
    return final_result;
}