class Solution
{
public:
  int minBitFlips(int A, int B)
  {
    int ans = A ^ B;
    int count = 0;
    while (ans != 0)
    {
      ans = ans & (ans - 1);
      count++;
    }
    return count;
  }
};