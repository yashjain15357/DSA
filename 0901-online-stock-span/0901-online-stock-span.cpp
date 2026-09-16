class StockSpanner {
public:
vector<int>vec;
    StockSpanner() {
        
    }
    
    int next(int price) {
        vec.push_back(price);
        int span = 0;
        for(int i = vec.size()-1 ; i>=0 ; i--){
            if(vec[i]>price){
                break;
            }
            span++;
        }
        return span;


        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */