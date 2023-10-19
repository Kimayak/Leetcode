// At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

// Note that you do not have any change in hand at first.

// Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

 

// Example 1:

// Input: bills = [5,5,5,10,20]
// Output: true
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change, we output true.
// Example 2:

// Input: bills = [5,5,10,10,20]
// Output: false
// Explanation: 
// From the first two customers in order, we collect two $5 bills.
// For the next two customers in order, we collect a $10 bill and give back a $5 bill.
// For the last customer, we can not give the change of $15 back because we only have two $10 bills.
// Since not every customer received the correct change, the answer is false.
 

// Constraints:

// 1 <= bills.length <= 105
// bills[i] is either 5, 10, or 20.




class Solution {
public:
    // bool containsNumber(const std::vector<int>& vec, int number) {
    // for (int element : vec) {
    //     if (element == number) {
    //         return true; // The number was found in the vector
    //     }
    // }
   // return false; // The number was not found in the vector
//}
    bool lemonadeChange(vector<int>& bills) {
        int five =0, ten = 0;
        for(int bill:bills)
        {
            if(bill == 5)
                five++;
            else if (bill == 10)
            {
                if(!five)
                    return false;
                five--;
                ten++;
            }
            else
            {
                if(ten && five)
                {
                    ten--;
                    five--;
                }
                else if (five>=3)
                {
                    five=five-3;
                }
                else
                    return false;
            }
        }
        return true;
        // vector<int> inhand; 
        // bool ans = true;
        // int count5 = 0;
        // int count10 = 0; 
        // //int count; 
        // for (int bill: bills)
        // {
        //     if(bill == 5)
        //         inhand.push_back(5);
        //     else if(bill==10)
        //     {
        //         auto it = find(inhand.begin(), inhand.end(), 5);

        //         if (it != inhand.end()){ 
        //             // Erase the first occurrence of the target number
        //             inhand.push_back(10);
        //             inhand.erase(it);}
            
        //         else 
        //             return false;
        //     }
        //     else if(bill == 20)
        //     {
        //         for (auto it = inhand.begin(); it != inhand.end(); ) {
        //                 if (*it == 5) {
        //                     count5++;
        //                 } else if (*it == 10) {
        //                     count10++;
        //                 }
        //                 if ((count5 == 3) || (count5 == 1 && count10 == 1))
        //                 {   inhand.push_back(20);
        //                     if (count5 == 3) {
        //                     // Erase three occurrences of 5
        //                     it = inhand.erase(it - 2, it + 1);
                            
        //                 } else if (count5 == 1 && count10 == 1) {
        //                     // Erase one occurrence of 5 and one occurrence of 10
        //                     it = inhand.erase(it - 1, it + 1);
        //                 }
        //                 }
        //                 else
        //                     return false;

        //         }
        //     }
        // }
        // return true; 


        
    }
};