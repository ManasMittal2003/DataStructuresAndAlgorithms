//counting maximum number of nodes on i th level in binary tree
class Solution {
  public:
    int countNodes(int i) {
        return pow(2,i-1);
    }
};
