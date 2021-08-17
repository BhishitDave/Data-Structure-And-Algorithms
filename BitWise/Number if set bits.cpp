/*
     Complexity: Time=>O(logn)   , Space=>O(1)
     Link : https://practice.geeksforgeeks.org/problems/set-bits0143/1#
     Logic: 3 approaches
     Source: gfg
*/
//***********************************
{
    unsigned int count = 0;
    while (n != 0)
    {
        if (n % 2 != 0)
            count++;
        n = n / 2;
    }
    return count;
}
//***********************************
unsigned int countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

//***********************************
int table[256];

// recursive function to count set bits
void initialize()
{

    // To initially generate the table algorithmically:
    table[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        table[i] = (i & 1) + table[i / 2];
    }
}

int countSetBits(int n)
{
    return table[n & 0xff] +
           table[(n >> 8) & 0xff] +
           table[(n >> 16) & 0xff] +
           table[n >> 24];
}