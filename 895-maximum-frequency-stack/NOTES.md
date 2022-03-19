```
Create an unordered map of integers (freq_mp) to store the frequency of each element.
Create an unordered map of the stack (freq_stack_mp) to store the elements of the same frequency in the same stack. This is for tackling the "frequency tie" condition.
Create a variable to keep a note of the current maximum frequency (max_frequency).
FreqStack:
Just initialize max_frequency to 0.
​
FreqStack() {
// initially maximum frequency is 0
max_frequency=0;
}
push:
​
Increase freq_mp[x] by 1.
Update max_frequency, if needed.
Push the current element to its frequency stack (freq_stack_mp[freq_mp[x]]).
void push(int x) {
// increase the freq of x in frequency map
++freq_mp[x];
​
// update max_frequency
if(max_frequency<freq_mp[x]) max_frequency = freq_mp[x];
​
// push x to its freq stack
freq_stack_mp[freq_mp[x]].push(x);
}
pop:
​
Get the top element (curr_top) from the stack of maximum frequency (freq_stack_mp[max_frequency]).
Remove that top element from the above stack and also decrease its frequency in freq_mp.
If the above stack becomes empty, then delete that stack from freq_stack_mp along with decreasing the maximum frequency (max_frequency) by 1.
Return curr_top.
int pop() {
// get the top element from the stack of maximum frequency
// here stack is used for taking care of the "frequency tie" condition
int curr_top = freq_stack_mp[max_frequency].top();
​
// update both the maps
freq_stack_mp[max_frequency].pop();
--freq_mp[curr_top];
​
// if the stack of maximum element becomes empty, then delete it from "freq_stack_mp" along with decreasing "max_frequency"
if(freq_stack_mp[max_frequency].empty()) {
freq_stack_mp.erase(max_frequency);
--max_frequency;
}
​
// return the current top element
return curr_top;
}
```