class FreqStack {
private:
    int maxFreq; // maximum frequency among all elements
    unordered_map<int,int> freq; // stores frequency of each element : [el , freq]
    unordered_map<int, stack<int> > freqStack; // stores stack of elements for each frequency [1,maxFreq] : [freq, stack]
public:
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int val) {
        freq[val]++; // insert the element with its freq count
        maxFreq= max(maxFreq, freq[val]); // update maxFreq 
        freqStack[freq[val]].push(val); // store value in its current frequency stack
    }
    
    int pop() {
        int mostFreqEl = freqStack[maxFreq].top(); // take the most frequent element
        freqStack[maxFreq].pop(); // remove the most frequent element
        freq[mostFreqEl]--; // reduce the frequency of most frequent element
        if( freqStack[maxFreq].size() == 0) maxFreq--; // if there are no elements with current maxFreq, reduce it
        return mostFreqEl; // return the MOST FREQUENT ELEMENT.
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */