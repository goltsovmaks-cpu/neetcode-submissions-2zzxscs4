class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result;
        result.reserve(nums.size() * 2);
        result.assign(nums.begin(),nums.end());

        result.insert(
            result.end(),
            std::make_move_iterator(nums.begin()),
            std::make_move_iterator(nums.end())
        );
        return result;
    }
};