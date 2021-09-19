// brute O(nlogn)
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        sort(a, a+n);
    }
    
};

// counting sort O(n)
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int zero = 0, one = 0, two = 0;
        for(int i=0; i<n; i++) {
            if(a[i] == 0) zero++;
            else if(a[i] == 1) one++;
            else two++;
        }
        
        int i = 0;
        while(zero--)
            a[i++] = 0;
        while(one--)
            a[i++] = 1;
        while(two--)
            a[i++] = 2;
    }
    
};

// dutch national flag algorithm
// 3 pointer
// low = 0, mid = 0, high = n-1
// 0....low-1 = 0's
// high+1...n = 2's

// mid = 0; swap(a[low], a[mid]); low++, mid++
// mid = 1; mid++;
// mid = 2; swap[a[mid], a[high]]; high--;
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int zero = 0, one = 0, two = 0;
        for(int i=0; i<n; i++) {
            if(a[i] == 0) zero++;
            else if(a[i] == 1) one++;
            else two++;
        }
        
        int i = 0;
        while(zero--)
            a[i++] = 0;
        while(one--)
            a[i++] = 1;
        while(two--)
            a[i++] = 2;
    }
    
};
