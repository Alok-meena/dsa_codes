#circular tour question.....
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.


or 

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique


#include <bits/stdc++.h> 

int firstCircularTour(vector<int>& petrol, vector<int>& distance, int N)

{

    long deficit=0;
    long balance=0;
    long start=0;
       
       for(int i=0;i<N;i++){
           balance+=petrol[i]-distance[i];
           if(balance<0){
               deficit+=balance;
               start=i+1;
               balance=0;
           }
       }
       
       if((deficit+balance)>=0){
           return start;
       }
       return -1;

}
