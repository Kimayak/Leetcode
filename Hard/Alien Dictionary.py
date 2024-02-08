

# There is a new alien language that uses the English alphabet. However, the order of the letters is unknown to you.

# You are given a list of strings words from the alien language's dictionary. Now it is claimed that the strings in words are 
# sorted lexicographically
#  by the rules of this new language.

# If this claim is incorrect, and the given arrangement of string in words cannot correspond to any order of letters, return "".

# Otherwise, return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there are multiple solutions, return any of them.

 

# Example 1:

# Input: words = ["wrt","wrf","er","ett","rftt"]
# Output: "wertf"
# Example 2:

# Input: words = ["z","x"]
# Output: "zx"
# Example 3:

# Input: words = ["z","x","z"]
# Output: ""
# Explanation: The order is invalid, so return "".
 

# Constraints:

# 1 <= words.length <= 100
# 1 <= words[i].length <= 100
# words[i] consists of only lowercase English letters.


class Solution:
    def alienOrder(self, words: List[str]) -> str:
        adj = defaultdict(set)

        indegree = {char: 0 for word in words for char in word}

        for i in range(len(words)-1):
            word1, word2 = words[i], words[i+1]

            min_length = min(len(word1), len(word2))

            if word1[:min_length] == word2[:min_length] and len(word1)>len(word2):
                return ""

            for j in range(min_length):
                if word1[j]!= word2[j]:
                    if word2[j] not in adj[word1[j]]:
                        adj[word1[j]].add(word2[j])
                        indegree[word2[j]] += 1
                    break
        queue = deque([c for c in indegree if indegree[c] == 0])

        order = ""
        while queue:
                c = queue.popleft()
                order+=c
                for next_c in adj[c]:
                    indegree[next_c]-=1
                    if indegree[next_c] == 0:
                         queue.append(next_c)
        return order if len(order) == len(indegree) else ""

        