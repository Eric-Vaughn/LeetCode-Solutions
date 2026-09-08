class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        longest = 0

        charSet = set()

        # O(n)
        for right in range(len(s)):
            while s[right] in charSet:
                charSet.remove(s[left])
                left += 1

            slideWinSize = (right - left) + 1
            longest = max(longest, slideWinSize)
            charSet.add(s[right])

        return longest