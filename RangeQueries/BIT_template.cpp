
class BIT {
    int n;
    vector<long long> v;
public:
    BIT(int sz) {
        n = sz;
        v.resize(n + 1);
    }

    //110100 stores sum from  110000 + 1 to 110100
    //k & -k is efficient way to get last set bit
    long long sum(int k) {
        //sum till index k
        long long sum = 0;
        while (k > 0) {
            sum += v[k];
            k -= k & -k;
        }

        return sum;
    }

    //110100 -> we need to add in all ranges that after removing last set bit contain this number
    //so we increase the the val of number by increasing the left bit and make current bit 0 so that
    // after removing the last bit number is smaller than current , and this way current lies
    //between a smaller and a greater number

   void add(int k , int x) {

        while (k <= n) {
            v[k] += x;
            k += k & -k;
        }
    }

};
