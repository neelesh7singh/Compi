// question link -> https://leetcode.com/problems/concatenated-words/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    struct Trie
    {
        bool end;
        vector<Trie *> child;

        Trie() : end(false), child(26, NULL) {}

        void insert(string s)
        {
            Trie *curr = this;
            for (auto x : s)
            {
                if (curr->child[x - 'a'] == NULL)
                    curr->child[x - 'a'] = new Trie;

                curr = curr->child[x - 'a'];
            }
            curr->end = true;
        }

        bool search(string s)
        {
            Trie *curr = this;
            for (auto x : s)
            {
                if (curr->child[x - 'a'] == NULL)
                    return false;
                curr = curr->child[x - 'a'];
            }
            return curr->end;
        }
    };
    Trie root;
    unordered_map<string, bool> um;

    bool check(string s, int count)
    {
        if (root.search(s) && count > 1)
            return um[s] = true;

        string curr;
        for (int i = 0; i < s.length(); i++)
        {
            curr.push_back(s[i]);
            if (root.search(curr) && check(s.substr(i + 1), count + 1))
                return um[s] = true;
        }
        return um[s] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        for (auto word : words)
            if (word != "")
                root.insert(word);

        vector<string> ans;
        for (auto word : words)
            if (check(word, 1))
                ans.push_back(word);

        return ans;
    }
};