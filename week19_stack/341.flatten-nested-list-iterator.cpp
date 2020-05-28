/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        const int len = nestedList.size();
        for (int i = len - 1; i >= 0; --i) {
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        update();
        int v = st.top().getInteger();
        st.pop();
        return v;
    }

    void update() {
        // 注意条件
        while (!st.empty() && !st.top().isInteger()) {
            NestedInteger x = std::move(st.top()); st.pop();
            auto &nestedList = x.getList();
            const int len = nestedList.size();
            for (int i = len - 1; i >= 0; --i) {
                st.emplace(nestedList[i]);
            }
        }
    }
    
    bool hasNext() {
        update();
        return !st.empty();
    }
private:
    stack<NestedInteger> st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
