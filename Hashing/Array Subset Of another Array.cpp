/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#
     Logic: hashmap
     Source:gfg
*/
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_set<int> s;
    int count=0;
    for(int i=0;i<m;i++)
        s.insert(a2[i]);
    for(int i=0;i<n;i++)
    {
        if(s.find(a1[i])!=s.end())
        count++;
    }
    if(count==m)
    return "Yes";
    return "No";
}