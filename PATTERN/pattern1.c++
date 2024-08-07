void symmetry(int n) {
    // Write your code here.
    int space=2*n-2;
    for(int i=1;i<=n;i++){
        int j=i;
        while(j){
            cout<<"*"<<" ";
            j--;
        }
        int k=space;
        while(k){
            cout<<" ";
            k--;
        }
        space-=2;
        j=i;
        while(j){
            cout<<"*"<<" ";
            j--;
        }

        cout<<endl;
    }
    space=2;
    for(int i=n-1;i>=1;i--){
        int j=i;
        while(j){
            cout<<"*"<<" ";
            j--;
        }
        int k=space;
        while(k){
            cout<<" ";
            k--;
        }
        space+=2;
        j=i;
        while(j){
            cout<<"*"<<" ";
            j--;
        }

        cout<<endl;
    }
    
}


*         *
* *     * *
* * * * * *
* *     * *
*         *
