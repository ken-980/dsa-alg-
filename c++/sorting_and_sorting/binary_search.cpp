#include <iostream>
#include <vector>
#include <algorithm>


int binarySearch(std::vector <int> array, int x){

    std::sort(array.begin(), array.end());

    int begin = 0, end = array.size() - 1;

    while(begin <= end){

        int half = (begin + end)/2;

        if(array[half] == x){
            return array[half];
        }
 
        if(array[half] > x)
            end = half - 1;
        else 
            begin = half + 1;
    } 
    return - 1;
}
