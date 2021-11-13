// Q2. Given a array of integers of length N and a positive integer 2<k<N-1. Find minimum operations to make the array good. (array good is when A[i]<=A[i+k], i=0,1,2,3....N-1)
// Ex. [2,4,1,3] - 2

def  MinOperations(arr,k) :  
  
    count=0  
    res =[]
    prev=0  
    for  i in range(len(arr) ) : 
        if i % k  == 0 :
            if arr[i] < prev : 
                arr[i] =  prev
                count+=1  
            prev =  arr[i]
        else : 
            if i + k <  len(arr) and  arr[i] >  arr[i + k ] : 
                arr[i] =  arr[i + k]
                count+=1 
    #print(arr)            
    return count            
arr = [8,9,8,10,9,12,13,12]           
print(MinOperations(arr,3))