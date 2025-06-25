// double pointer
void reverseString(char* s, int sSize) {
    // 設定頭尾兩個指標
    int left = 0;
    int right = sSize - 1;

    // 當左指標在右指標左邊時，持續交換
    while (left < right) {
        // 1. 暫存左邊的字元
        char temp = s[left];
        
        // 2. 將右邊的字元放到左邊
        s[left] = s[right];
        
        // 3. 將暫存的字元 (原本左邊的) 放到右邊
        s[right] = temp;

        // 移動指標，向中間靠攏
        left++;
        right--;
    }
}