
// Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

// Machine 1 (sender) has the function:

// string encode(vector<string> strs) {
//   // ... your code
//   return encoded_string;
// }
// Machine 2 (receiver) has the function:
// vector<string> decode(string s) {
//   //... your code
//   return strs;
// }
// So Machine 1 does:

// string encoded_string = encode(strs);
// and Machine 2 does:

// vector<string> strs2 = decode(encoded_string);
// strs2 in Machine 2 should be the same as strs in Machine 1.

// Implement the encode and decode methods.

// You are not allowed to solve the problem using any serialize methods (such as eval).

 

// Example 1:

// Input: dummy_input = ["Hello","World"]
// Output: ["Hello","World"]
// Explanation:
// Machine 1:
// Codec encoder = new Codec();
// String msg = encoder.encode(strs);
// Machine 1 ---msg---> Machine 2

// Machine 2:
// Codec decoder = new Codec();
// String[] strs = decoder.decode(msg);
// Example 2:

// Input: dummy_input = [""]
// Output: [""]
 

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] contains any possible characters out of 256 valid ASCII characters.
 

// Follow up: Could you write a generalized algorithm to work on any possible set of characters?

#include <string>
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string combined; 
        for(string str: strs)
        {
            combined+= to_string(str.size())+"#"+str;
        }
    //     double pi = 3.14159265359;
    //    // vect
    //     for(string str: strs)
    //     {
    //         combined+= str;
    //         combined+=L"\u03C0";
    //     }
    //     for (char c : combinedString) {
    //     int asciiValue = static_cast<int>(c);
    //     // std::cout << "Character: " << c << " | ASCII Value: " << asciiValue << std::endl;
    // }


    return combined; 

        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> output;

        int start = 0;
        //int end = s.find("#")
        while (start<s.size())
        {
            int pos = s.find_first_of('#', start);
            int len = stoi(s.substr(start, pos- start));
            start = pos+1;
            output.push_back(s.substr(start, len));
            start+=len;
        }
        return output;

        // vector<string> output;
        // string temp;
       
        // double pi = 3.14159265359;
        // char s1= to_string(pi);
        // for(char c : s)
        // {
        //     if(c==L"\u03C0")
        //     {
        //         output.push_back(temp);
        //         temp = "";
        //         continue;
        //     }
        //     temp+=c;
           
        // }
        // return output;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));