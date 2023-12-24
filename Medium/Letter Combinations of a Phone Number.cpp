class Solution {
public:
     void backtrack(std::string combination, std::string nextDigits, std::unordered_map<char, std::string>& myMap, std::vector<std::string>& result) {
        if (nextDigits.empty()) {
            result.push_back(combination);
        } else {
            char digit = nextDigits[0];
            std::string letters = myMap[digit];
            for (char letter : letters) {
                backtrack(combination + letter, nextDigits.substr(1), myMap, result);
            }
        }}
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        unordered_map<char, string> map = {{'2' ,"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tvu"}, {'9',"wxyz"}};
        vector<string> out;
        

            backtrack("",digits, map, out);
            return out;
            

        }
        
    
};