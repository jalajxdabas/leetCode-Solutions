class Solution {
public:
    bool equalFrequency(string word){
        unordered_map<char, int> cnt;

        for(char ch : word)
        {
            cnt[ch]++;
        }

        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            if(cnt.find(ch) == cnt.end()) 
            continue;

            cnt[ch]--;

            unordered_set<int> freqSet;
            for(auto it : cnt)
            {
                if(it.second > 0)
                {
                    freqSet.insert(it.second);
                }
            }

            if(freqSet.size() == 1)
            {
                return true;
            }

            cnt[ch]++;
        }

        return false;
    }
};