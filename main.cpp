/* 
 * File:   main.cpp
 * Author: student
 *
 * Created on January 12, 2012, 10:34 AM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <sstream>

#include <stdlib.h>



using namespace std;

/*
 * 
 */
double factorial(double n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n-1);
}

vector<int> readFile(char filename[]) //Reads a file of numbers and returns a vector
{

    int numbers[5000];
  
    ifstream File;  
    File.open(filename);
 
    int i = 0;        
    while (File >> numbers[i])    
    {               
        File >> numbers[i];                
        i++;
        
    }
      
    File.close();

    vector<int> nums (numbers, numbers + sizeof(numbers) / sizeof(int));
    
    return nums;
}


int isPrime(long n)
{  
    
    long max = sqrt(n);
    
    if (n == 2)
    {
        return 1; 
    }
             
    for (long i = 3; i <= max; i += 2)
    {  
        if (n % i == 0)
        {            
            return 0;
        }
    }
    return 1;
}

int sumOfMultiples() //Sum of multiples of 3 and 5 up to 1000
{
    int sum = 0;
    
    for (int i = 0; i < 1000; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            sum += i;
        }
    }
    return sum;
}
int finobacciSeq(int n1, int n2) //Sum of Finnobacci sequence to 4M
{
    int fino = 0;
    int finoSum = 0;
    
    while (fino < 4000000)
    {
        fino = n1+n2;
        n1 = n2;
        n2 = fino;
        
        if (fino % 2 == 0)
        {
            cout << fino << endl;
            finoSum += fino;
        }        
    }   
    return finoSum;
}

int largestPrimeFactor() //What is the largest prime factor of the number 600851475143 ?
{
    const long NUM = 600851475143;
    int largest = 0;
    
    for (long i = 1; i < sqrt(NUM); i++)
    {
        if (NUM % i == 0)
        {
            if (isPrime(i) == 1)
            {
                largest = i;
            }
        }
    }   
    return largest;
}

//Find the largest palindromic number that is the product of two three digit numbers
int palindromicNum() 
{
    int palindrome = 0;
    int product = 0;
    int a1, a2, a3, b1, b2, b3;
    
    for (int factor1 = 100; factor1 < 1000; factor1++)
    {
        for (int factor2 = 100; factor2 < 1000; factor2++)
        {
            product = factor1 * factor2;

            //First half from right to left            
            b1 = product%10; //Last digit
            b2 = (product%100) / 10; //2nd to last digit
            b3 = (product%1000) / 100; //3rd to last digit
            
            a1 = (product/1000) %10; //3rd digit in
            a2 = ((product/1000) %100) / 10; //2nd digit in
            a3 = (product/1000) /100; //First digit
                    
            if (a3 == b1 && a2 == b2 && a1 == b3)
            {
                if (palindrome < product)
                {
                    palindrome = product;
                }
            }
        }
    }
    return palindrome;
}

//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
int smallestQuotient(int q)
{
    int quotient = q;
    int count = 0;
   
    
    while(count < 2)  
    {       
        for (int n = 1; n <= 20; n++)
        {                                  
            if (quotient % n == 0)
            {
                count++;
                if (count >= 20)
                {
                    return quotient;
                }  
            }
            else
            {             
                count = 0;
                quotient+=2;
                break;
            }
        }
    }
}

//Find the difference between the sum of 
//the squares of the first one hundred natural numbers and the square of the sum.
int sumOfSquares()
{
    int sum1 = 0, sum2 = 0;
    
    for (int i = 1; i <= 100; i++)
    {
        sum1 += i;
        //cout << i*i << endl;
        sum2 += i*i;
    }
    sum1 = sum1*sum1;
    //cout << sum1 << endl << sum2 << endl;
    return (sum1 - sum2);
}

//What is the 10001st prime number?
int thousandthPrime()
{
    int count = 1;
    long n = 2;
    
    while (count < 10001)
    {
        if (n == 2)
        {
            count++;
            n++;
        }
        else
        {
            if (isPrime(n) == 1)
            {               
                count++;
                if (count == 10001)
                {
                    break;
                }               
            }
        }
        n += 2;  
    }
    return n;    
}

/**
 * 
 * 
 * Find the greatest product of 5 consecutive digits
 * 
73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450
 *  
 */

int greatestProduct()
{
    ifstream File;  
    
    int numbers[1000];
    char num;
    int i = 0;     
    
    File.open("input"); //Let's open the file and read the integers
    while (File.good())    
    {               
        File >> num;
        numbers[i] = num - '0'; //Convert char to int       
        i++;      
    }     
    File.close();
    
    int product = 0;
    
    for (int i = 0; i < 995; i++)
    {
        int prod = numbers[i]*numbers[i+1]*numbers[i+2]*numbers[i+3]*numbers[i+4]; 
        if (prod > product)
        {
            product = prod;
        }
    }
    
    return product;
   
}

int pythagoreanTrip() //returns the product of the pythag trip that has the sum of 1000
{
    int sum = 0;
    
    for (int a = 0; a < 1000; a++)
    {
        for (int b = 0; b < 1000; b++)
        {
            for (int c = 0; c < 1000; c++)
            {
                sum = a + b + c;
                
                if (sum == 1000 && a < b && b < c)
                {
                    if (a*a + b*b == c*c)
                    {
                        return a * b * c;
                    }
                }
                
            }
        }
    }
}

double sumOfPrimes() //Find the sum of all the primes below two million.
{

    
    double sum = 2;
    
    for (int i = 3; i < 2000000; i +=2)
    {
        if (isPrime(i) == 1)
        {
            //cout << i << endl;
            sum += i;
        }
    }
    return sum;
}

int gridProduct()
{
    ifstream File;
    
    int numbers[20][20];
    int n;
    int product = 1;
    int greatest = 0;

    File.open("grid"); //Let's open the file and read the integers     
    
    for (int row = 0; row < 20; row++)
    {
        for (int i = 0; i < 20; i++)      
        {    
                File >> n;          
                numbers [row][i] = n;  
               
        }      
    }
    File.close();

        for (int row = 0; row < 20; row++)
        {  
                for (int column = 0; column < 20; column++)
                {
                    product = 1; //Reset our product
                    //Right and left direction
                    if (column < 17)
                    {
                        product *= numbers[row][column];
                        product *= numbers[row][column+1];
                        product *= numbers[row][column+2];
                        product *= numbers[row][column+3];

                        if (product > greatest)
                        {
                            greatest = product;        
                        }                       
                    }            
                    product = 1; //Reset our product
                    //Up and down
                    if (row < 17)
                    {
                        product *= numbers[row][column];
                        product *= numbers[row+1][column];
                        product *= numbers[row+2][column];
                        product *= numbers[row+3][column];

                        if (product > greatest)
                        {
                            greatest = product;                    
                        }                        
                    }
                    product = 1; 
                    //Diag right
                    if (column < 17 && row < 17)
                    {
                        product *= numbers[row][column];
                        product *= numbers[row+1][column+1];
                        product *= numbers[row+2][column+2];
                        product *= numbers[row+3][column+3];
                        
                        if (product > greatest)
                        {
                            greatest = product;          
                        }
                    }
                    product = 1;
                    //Diag left
                    if (column < 17 && row > 3)
                    {
                        product *= numbers[row][column];
                        product *= numbers[row-1][column+1];
                        product *= numbers[row-2][column+2];
                        product *= numbers[row-3][column+3];
                        
                        if (product > greatest)
                        {
                            greatest = product;    
                        }                        
                    }                
                }
                              
        }
    
    return greatest;   
}
int triangularNum(int n) //The sum of n + n-1 + n-2...etc
{
    if (n <= 1)
    {
        return 1;
    }
    return n + triangularNum(n-1);
}
int numOfDivisors(long n) //Returns the number of divisors a number has
{
    int count = 0;
    long max = sqrt(n);
    
             
    for (long i = 1; i <= max; i++)
    {  
        if (n % i == 0)
        {            
            count++;
        }
    }
    return count *2;
}
int divisorsOfTriangularNumbers() //Traingular number with 500 divisors
{
    int n = 0;
    int divisors = 0;
    int tNum = 0;
    
    while (divisors < 500)
    {
        tNum = triangularNum(n);
        divisors = numOfDivisors(tNum);
    
        if (divisors >= 500)
                return tNum;
        n++;
    }
    
    
}

string addLines(string line1, string line2) //Adds numbers in the format of strings
{
    
    int sum[100][52];
       
    for (int j = 0; j < 99; j++)
    {

        
    //string line1 = lines[j];
    //string line2 = lines[j+1];
    
    
    
    int digit1 = 0, digit2 = 0;
    
    for (int i = 0; i < 52; i++)
    {
        sum[j][i] = 0;
    }

    
    for (int i = line1.size()+1; i >= 1; i--)
    {
        
        digit1 = line1[i-1] - '0';
        digit2 = line2[i-1] - '0';
  
        if ((sum[j][i]+digit1+digit2) > 9)
        {
            sum[j][i] = (digit1+digit2+sum[j][i]) % 10;
            sum[j][i-1] += 1;        
        }
        else
        {
             sum[j][i] += digit1 + digit2;
        }
       
    }
    
    
    }
    
    
    for (int line = 0; line < 99; line++)
    {
        cout << "Sum of line " << line << ": ";
        
        for (int digit = 0; digit < 51; digit++)
        {
            cout << sum[line][digit];
        }
        cout << endl;
    }
    /*
    sum = addLines(line1,line2);
    cout << sum << endl;
    */
    
    /*
    for (int i = 0; i < lines.size()-1; i++)
    {
        string line1 = lines[i];
        string line2 = lines[i+1];
        
        
        sum = addlines(line1,line2);
        
        cout << sum << endl;
        
    }
    */
}
int sumofNumbers() //This is huge, returns the sum of 100 50 digit numbers
{
        ifstream File("input.txt");
    vector<string> lines;
    string line;

    
    while (File.good()) //General file i/o bullshit
    {
        getline(File, line);
        lines.push_back(line);
        /*
        if (i >= 50)
        {
            i = 0;
            digitsTwo = digitsOne;
            line++;
            if (line % 2 == 0)
            {
                
            }
            
        }
        File >> n;
        digitsOne[i] = n - '0';
        cout << digitsOne[i];
        i++;
         *
         */
       
    
    }
    
    int nums[100][50]; //Here's the good stuff
    int sum[52]; //We have two carry over places just in case the number gets big
    
    for (int i = 0; i < 52; i++)
    {
        sum[i] = 0; //Set our incremental sums to zero so crazy shit doesn't happen
    }

    for (int j = 0; j < 100; j++)
    {

        string line1 = lines[j]; //Grab a line from the array
        int digit1 = 0; //Temp digit

        for (int i = 0; i < 50; i++)
        {
        
                digit1 = line1[i] - '0'; //Convert the char from the string to an int
                nums[j][i]= digit1; //Store it in our 2d array, rows = lines, collums = indexes
       
        }
        
    }
    
    for (int line = 0; line < 100; line++) //Here we go: the addition
    {
        
        for (int digit = 51; digit >= 0; digit--) // 51 because thats how long our sum array is
                                                        //and we have work backwards 
                                                         //Least significant to most significant digit
        {
            //int digit1 = sum[digit];
            int digit2 = nums[line][digit-2]; //The digit we are adding to our sum 
                                              //comes from an array two elements smaller
            
            if (digit-2 < 0) //so we don't go out of bounds
            {
                digit2 = 0;
            }
            
        if ((sum[digit]+digit2) > 9) //If we have to carry over
        {
                          
            sum[digit] += digit2; //Add the digit
            sum[digit] %= 10; //Then do the modulus
            sum[digit-1] += 1; //And DONT FORGET TO CARRY THE ONE       
            //cout << "Digit: " << digit << "   " << digit1 << " + " << digit2 << " = " << sum[digit] << endl;
        }
        else
        {          
             sum[digit] += digit2; //If there is no carry over, pretty straightforward
             //cout << "Digit: " << digit << "   " << digit1 << " + " << digit2 << " = " << sum[digit] << endl;
        }               
        }         
    }
    return 1; //Return 1, because why not?
}

int sequence(unsigned long long i,unsigned long long c) //Somehow using unsigned long long
                                                        //makes a big integer
                                                        //Anyway we have a recursive method
                                                         //AKA Collatz Problem
{
  
    
    if (i <= 1)
    {
        //cout << i << " ";
        return c+1; //When i == 1 return our count
    }
    
    if (i %2 == 0)
    {
        //cout << i << " ";
       return sequence(i/2, c+1); //Even divide by two incremnt our count
    }
    else
    {
        //cout << i << " ";
        return sequence((3*i) +1, c+1); //Odd do some stuff
    }
    
    
}

double gridPaths(double n)
{
    
    //a square grid takes 2*n times to traverse
    //Eg take n to equal 2 so in a 2x2 we can go rrdd, rdrd, ddrr, drdr. 4 moves to traverse
    //Now how many different strings can we make?
    //binomial (2n)
    //         ( n)
    
    return factorial(2*n) /(factorial(n) * factorial(n));
    
    
}

//What is the sum of the digits of the number 2^1000?
double sumOfDigits()
{
    ifstream file;
    
    double n = exp2(1000); //So we just stored n in a file, read it as chars and
                            //converted those chars to ints and summed them
    
    int numLength = 303;
    char in[numLength];
    int sum = 0;
    
    file.open("bigNum");
    file.getline(in,numLength);
    
    for (int i = 0; i < numLength; i++)
    { 
        if (i == numLength-1) //Probably as bad as a try - catch, but it works.
        {
            break;
        }
        sum += in[i] - '0';

    }
    cout << sum;
}

void letterSum()
{
        /* THIS IS COMMENTED OUT BECAUSE IT DOESN'T WORK

    string digits[10] = {"","one","two","three","four","five","six","seven","eight","nine"}; 
    string teens[10] = {"","eleven","twelve","thirteen","fourteen","fifteen","sixteen",
                        "seventeen","eighteen","nineteen"};
    string tens[10] = {"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    string hundred = "hundred";
    string And = "and";
    string thousand = "thousand";
    
    int sumOfLetters = 0;
    int oSum = 0;
   // cout << digits[0].length() << endl;
    
    for (int i = 1; i <= 1000; i++)
    {
        if (i < 10)
        {
            cout << digits[i];
            sumOfLetters += digits[i].length();
        }
        else if (i < 20)
        {
            if (i == 10)
            {
                cout << tens[i/10];
                sumOfLetters += tens[i/10].length();
            }
            else
            {   
                cout << teens[i%10];
                sumOfLetters += teens[i%10].length();
            }
        }
        else if (i < 100)
        {
            cout << tens[i/10];
            cout << " " << digits[i%10];
            sumOfLetters += digits[i%10].length();
            sumOfLetters += tens[i/10].length();
        }
        else if (i < 1000)
        {
            
            if ((i % 100 < 20) && (i % 100 > 10))
            {
             
                sumOfLetters += And.length();
                sumOfLetters += teens[i%10].length();
                cout << digits[i/100] << " " << hundred;
                cout << " " << And << " " << teens[i%10]; 
                
            }
            else
            {
                if (i % 100 == 0)
                {
                        cout << digits[i/100] << " " << hundred;
                        sumOfLetters += digits[i/100].length();
                        
                }
                else
                {
                        sumOfLetters += tens[(i%100)/10].length();
                        sumOfLetters += digits[i%10].length();
                        cout << digits[i/100] << " " << hundred;
                        cout << " " << And << " " << tens[(i%100)/10] << " " << digits[i%10]; 
                }
            }
            
            sumOfLetters += hundred.length();
            
        }
        else if (i == 1000)
        {
            cout << digits[i/1000] << " " << thousand;
            sumOfLetters += digits[i/1000].length();
            sumOfLetters += thousand.length();
        }
        cout << endl;
    }
    cout << endl << sumOfLetters;
                        
    */
      
    
    int sumOfLetters = 0; //Initiate sum to zero
    int oSum = 0;
    int lettersOfThousand = 8; //8 letters in thousand
    int lettersOfAnd = 3; //Three letters in and
    int lettersOfHundred = 7;  //Seven letters in hundred
    int lettersOfDigit[10] = {0,3,3,5,4,4,3,5,5,4}; //Array of the letters of ten 
    int lettersOfTens[10] = {0,3,6,6,5,5,5,7,6,6};
    int lettersOfTeens[10] = {0,6,6,8,8,7,7,9,8,8};
    
    for (int i = 1; i <= 1000; i++)
    {
        if (i < 10)
        {
            sumOfLetters += lettersOfDigit[i];
        }
        if (i > 9 && i < 20)
        {
            if (i == 10)
            {
                sumOfLetters += lettersOfTens[i/10];
            }
            sumOfLetters += lettersOfTeens[i%10];
        }
        if ((i > 19) && (i < 100))
        {
            sumOfLetters += lettersOfTens[i/10];
            sumOfLetters += lettersOfDigit[i%10];
            
        }
        if (i > 99 && i < 1000)
        {
            if ((i%100 > 10) && (i%100 < 20))
            {
                sumOfLetters += lettersOfTeens[i%10];
            }
            else
            {
                sumOfLetters += lettersOfTens[(i%100)/10];
                sumOfLetters += lettersOfDigit[i%10];
            }

            if ( i %100 == 0)
            {
                sumOfLetters -= lettersOfAnd;
            }
            sumOfLetters += lettersOfAnd;
            sumOfLetters += lettersOfHundred;
            sumOfLetters += lettersOfDigit[i/100];
            //cout << i << endl << sumOfLetters - oSum << endl << sumOfLetters << endl << " " << endl;
        }
        oSum = sumOfLetters;
        
        if (i == 1000)
        {
            sumOfLetters += lettersOfThousand;
            sumOfLetters += lettersOfDigit[i/1000];
            
        }
        
    }
    cout << sumOfLetters;
}

int main()
{
    /*
     * Problem's given triangle:
     * 75
     * 95 64
     * 17 47 82
     * 18 35 87 10
     * 20 04 82 47 65
     * 19 01 23 75 03 34
     * 88 02 77 73 07 63 67
     * 99 65 04 28 06 16 70 92
     * 41 41 26 56 83 40 80 70 33
     * 41 48 72 33 47 32 37 16 94 29
     * 53 71 44 65 25 43 91 52 97 51 14
     * 70 11 33 28 77 73 17 78 39 68 17 57
     * 91 71 52 38 17 14 91 43 58 50 27 29 48
     * 63 66 04 68 89 53 67 30 73 16 69 87 40 31
     * 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
     */
    
    /*
     * Going to try this one first
     * 3
     * 7 4
     * 2 4 6
     * 8 5 9 3
     */
    int size = 4;
    int triangle[size][size];
    
    for (int row = 0; row < size; row++)
    {
        if (row == 0)
        {
            triangle[row][0] = 3;
            triangle[row][1] = 0;
            triangle[row][2] = 0;
            triangle[row][3] = 0;
        }
        else if (row == 1)
        {
            triangle[row][0] = 7;
            triangle[row][1] = 4;
            triangle[row][2] = 0;
            triangle[row][3] = 0;
        }
        else if (row == 2)
        {
            triangle[row][0] = 2;
            triangle[row][1] = 4;
            triangle[row][2] = 6;
            triangle[row][3] = 0;
        }
        else if (row == 3)
        {
            triangle[row][0] = 8
            triangle[row][1] = 5;
            triangle[row][2] = 9;
            triangle[row][3] = 3;
        }
    }
    
    int digits[size];
    int num = 0;
    
    
}

