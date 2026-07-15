class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        """
        Calculates the GCD of the sum of the first n odd numbers 
        and the sum of the first n even numbers.
        
        - Sum of first n odd numbers = n^2
        - Sum of first n even numbers = n * (n + 1)
        - GCD(n^2, n * (n + 1)) = n * GCD(n, n + 1) = n * 1 = n
        """
        return n