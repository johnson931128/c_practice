template <typename T>
class NumericRangeIterator {
    private:
        T current_value;
        T step_value;
    
    public:
        // build function
        explicit NumericRangeIterator(T value, T step):
            current_value(value), step_value(step) {}

        // 1. 解引用運算子：回傳當前值
        T operator*() const{
            return current_value;
        }

        // 2. 前置遞增運算子：移動到下一個值
        NumericRangeIterator& operator++() {
            current_value += step_value;
            return *this;
        }

        // 3. 不等於運算子：判斷迴圈是否結束
        // 這裡的邏輯是關鍵：只要當前值還小於「結束」迭代器的值，就繼續
        bool operator!=(const NumericRangeIterator& other) const {
            // 如果步長為正，則當前值小於結束值時繼續
            // 如果步長為負，則當前值大於結束值時繼續
        if (step_value > 0) {
            return current_value < other.current_value;
        } else {
            return current_value > other.current_value;
        }
    }
};

template <typename T>
class NumericRange{
    private:
        T start_value;
        T end_vlaue;
        T step_value;

    public:
        NumericRange(T start, T stop, T step = 1) :
            start_value(start), end_vlaue(stop), step_value(step) {}

        NumericRangeIterator<T> begin() const {
            return NumericRangeIterator<T>(start_value, step_value);
        }

        NumericRangeIterator<T> end() const {
            return NumericRangeIterator<T>(end_vlaue, step_value);
        }
};