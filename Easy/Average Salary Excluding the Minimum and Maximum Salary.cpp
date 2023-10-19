// You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

// Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input: salary = [4000,3000,1000,2000]
// Output: 2500.00000
// Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
// Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
// Example 2:

// Input: salary = [1000,2000,3000]
// Output: 2000.00000
// Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
// Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
 

// Constraints:

// 3 <= salary.length <= 100
// 1000 <= salary[i] <= 106
// All the integers of salary are unique.



class Solution {
public:
    double average(vector<int>& salary) {

    int minSalary = INT_MAX;
    int maxSalary = INT_MIN;
    int sum = 0;
    for (int sal: salary)
    {
        sum = sum+sal;
        minSalary = min(minSalary, sal);
        maxSalary = max(maxSalary, sal);
    }
    return (double)(sum-minSalary - maxSalary)/(double)(salary.size()-2);
    //GIVING ERRORS
    // auto minMax = minmax_element(salary.begin(), salary.end());
    // int sum = 0, avg = 0;
    // cout<<salary.size()<<endl;
    // salary.erase(minMax.first); 
    // salary.erase(minMax.second); 
    // cout<<salary.size()<<endl;
    // if (salary.size()<2)
    //     return salary[0];
    // cout<<salary.size();
    // for (int i = 0; i<salary.size()-1; i++)
    // {

    //     sum = sum + salary[i];

    // }

    // avg = sum/size(salary);

    // return avg;
        
    }
};