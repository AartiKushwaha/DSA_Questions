// MAximum product subarray

/*!!!!!!   IMPORTANT  !!!!!!*/


// Consider the array 1, -2, -3, 4. When we are at the second element, our runningProduct becomes -2. But at the third element it becomes 6. So, as we encounter negative numbers they change the sign of our product. Our product can become really small but then really big depending on the sign of the current number. To accomodate for this, we can have two running products: maxProd and minProd. maxProd will track the maximum product that we can achieve and will reset whenever the current number is greater, just as above. minProd, on the other hand, will track the minimum product that we can achieve and will reset whenever the current number is smaller. Finally, whenever we encounter a negative number, we will swap maxProd and minProd because if a <= b then -b <= -a. This makes sure that maxProd and minProd are still the max and min products after multiplied by a negative number.


int maxProduct(vector<int>& arr) {
    int mi = arr[0];
    int ma = arr[0];
    int pro = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i]<0) swap(ma, mi);
        ma = max(arr[i], ma*arr[i]);
        mi = min(arr[i], mi*arr[i]);
        if(ma>pro) pro = ma;
    }
    return pro;
}

//This is similar to kadane's algorithm just see for -ve nos!!!