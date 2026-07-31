class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        vector<int> freq(26, 0);
        for (char& ch : tasks) freq[ch - 'A']++;
        priority_queue<int> maxHeap;
        for (int& it : freq)
            if (it) maxHeap.push(it);
        int time = 0;
        while (!maxHeap.empty()) {
            vector<int> temp;
            for (int i = 0; i <= n; i++) {
                if (!maxHeap.empty()) {
                    int chFreq = maxHeap.top();
                    maxHeap.pop();
                    chFreq--;
                    temp.push_back(chFreq);
                }
            }
            for (int& it : temp)
                if (it > 0) maxHeap.push(it);
            maxHeap.empty() ? time += temp.size() : time += n + 1;
        }
        return time;
    }
};
