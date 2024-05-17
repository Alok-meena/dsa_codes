Given that integers are read from a data stream.

	data stream means data is incoming in a contiguous fashion

Your task is to find the median of the elements read so far.

Median is the middle value in an ordered integer list.
If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.

For example :
[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.


1st approach:
sort the elements and store in another vector as data is in continguous flow then return the median

vector<int> findMedian(vector<int> &arr, int n){
	vector<int>store;

	vector<int>m;

	for(int i=0;i<n;i++){
		store.push_back(arr[i]);

		sort(store.begin(),store.end());
		
		int median;
		if((i+1)%2==0){
			median=(store[i/2]+store[(i+1)/2])/2;
		}
		else{
			median=store[i/2];
		}
		m.push_back(median);
	}
	return m;

}

Time Complexity
O(N*(N*log(N))), Where N is the number of elements in the data stream.

 

The algorithm uses inbuilt sorting algorithm to sort the vector. 
So, for sorting time complexity will be N*log(N). The vector is sorted for every element of the data stream.
So, the final time complexity of the algorithm is O(N*(N*(log(N))).

Space Complexity
O(N), where N is the number of elements in the data stream.


but it will be not suitable as we have to use insertion sort because it is a running stream 

void insertionSort(vector<int>&arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
vector<int> findMedian(vector<int> &arr, int n){
	vector<int>store;

	vector<int>m;

	for(int i=0;i<n;i++){
		store.push_back(arr[i]);

		insertionSort(store,store.size());
		
		int median;
		if((i+1)%2==0){
			median=(store[i/2]+store[(i+1)/2])/2;
		}
		else{
			median=store[i/2];
		}
		m.push_back(median);
	}
	return m;

}

so this should be the required code 

time complexity: O(N^3)
space complexity: O(N)

and instead of calling insertion sort separately you can do this also
int j = 0;
		
		while(j < i){
			
			if(store[j] <= arr[i]){
				j++;	
			}
			else{
				break;
			}
			
		}
		
		// Shifting all the elements greater than the current element to the right 
		
		int k = i-1;
		
		while(k >= j){
			
			store[k+1] = store[k];
			k--;
			
		}
		
		// Inserting the current element at its sorted position
		store[j] = arr[i];

then t.c:O(N^2)
	s.c:O(N)

 

Since the algorithm stores every element of the data stream in a vector, which requires O(N) space.
#include <queue>

int signum(int a, int b){
	if(a==b){
		return 0;
	}
	else if(a>b){
		return 1;
	}
	else{
		return -1;
	}
}


void callmedian(int element,priority_queue<int> &maxi,
                        priority_queue<int,vector<int>,greater<int>>&mini,int &median){
	switch(signum(maxi.size(),mini.size())){


		case 0:if(element>median){
			           mini.push(element);
			           median=mini.top();
		            }
					else{
						maxi.push(element);
						median=maxi.top();
					}
					break;
        case 1:if(element>median){
			           mini.push(element);
					   median=(mini.top()+maxi.top())/2;
		            }
					else{
						mini.push(maxi.top());
						maxi.pop();
						maxi.push(element);
						median=(mini.top()+maxi.top())/2;
					}
					break;
		case -1:if(element>median){
			            maxi.push(mini.top());
						mini.pop();
						mini.push(element);
						median=(mini.top()+maxi.top())/2;
             		}
					 else{
						 maxi.push(element);
						 median=(mini.top()+maxi.top())/2;
					 }
					 break;
	}
}
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector<int>ans;
	priority_queue<int>maxheap;
	priority_queue<int,vector<int>,greater<int>>minheap;
	int median=0;

	for(int i=0;i<n;i++){
		callmedian(arr[i],maxheap,minheap,median);
		ans.push_back(median);
	}
	return ans;
}

t.c:O(NlogN)
s.c:O(N)


explained in detail in notebook
