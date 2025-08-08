class Solution {
  public:
    long long maxBalls(int n, int m, vector<int> a, vector<int> b) {
        int i = 0, j = 0;
        long long aSum = 0, bSum = 0, result = 0;
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                aSum += a[i++];
            } else if (a[i] > b[j]) {
                bSum += b[j++];
            } else {
                long long currSumA = 0,currSumB = 0,currVal = a[i];
                long long countA =0 ,countB=0;
                while (i < n-1 && a[i] == a[i + 1])
                {
                    countA++;
                    currSumA += a[i++];
                }
                while (j < m-1 && b[j] == b[j + 1]){
                    countB++;
                    currSumB += b[j++];
                }
                long long e1 = aSum+currSumA+currVal;
                if(countA>0) e1 = max(e1,aSum+currSumA+currSumB);
                e1 = max(e1,bSum+currSumA+currSumB+currVal);
                long long e2 = bSum+currSumB+currVal;
                if(countB>0) e2 = max(e2,bSum+currSumA+currSumB);
                e2 = max(e2,aSum+currSumA+currSumB+currVal);
                aSum = e1; bSum = e2;
                i++; j++;
            }
        }
        while (i < n) aSum += a[i++];
        while (j < m) bSum += b[j++];
        return max(aSum, bSum);
    }
};