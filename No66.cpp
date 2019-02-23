class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int sum = 0;
        int addend = 1;
        int carry = 0;
        int i=0;
        for(i=0;i<size;i++){
            sum = digits[size-i-1]+addend+carry;
            if(digits[size-i-1]==9){
                carry = 1;
                addend = 0;
                digits[size-i-1] = sum-10;
            }
            else{
                digits[size-i-1] +=(carry+addend) ;
                return digits;
            }

        }
        digits.insert(digits.begin(),carry);
        
        return digits;
    }
};
