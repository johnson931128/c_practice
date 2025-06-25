#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    // 1. 設定回傳陣列的大小，就是 n
    *returnSize = n;

    // 2. 配置主陣列，它可以存放 n 個字串指標 (char*)
    char** answer = (char**)malloc(n * sizeof(char*));
    if (answer == NULL) { // 記憶體配置失敗的保護
        *returnSize = 0;
        return NULL;
    }

    // 3. 遍歷從 1 到 n 的每個數字
    for (int i = 1; i <= n; i++) {
        // C 陣列索引是從 0 開始，所以數字 i 的結果放在 answer[i-1]
        int index = i - 1;

        // 4. 判斷條件，順序很重要！
        if (i % 15 == 0) {
            // "FizzBuzz" 長度為 8，加上 '\0' 需要 9 個 char 的空間
            answer[index] = (char*)malloc(9 * sizeof(char));
            strcpy(answer[index], "FizzBuzz");
        } else if (i % 3 == 0) {
            // "Fizz" 長度為 4，加上 '\0' 需要 5 個 char 的空間
            answer[index] = (char*)malloc(5 * sizeof(char));
            strcpy(answer[index], "Fizz");
        } else if (i % 5 == 0) {
            // "Buzz" 長度為 4，加上 '\0' 需要 5 個 char 的空間
            answer[index] = (char*)malloc(5 * sizeof(char));
            strcpy(answer[index], "Buzz");
        } else {
            // 處理數字轉字串的情況
            // 先用 sprintf 轉到一個足夠大的 buffer
            // 一個 32-bit int 最多 10 位數，加上負號和 '\0'，12 位元組綽綽有餘
            char buffer[12];
            sprintf(buffer, "%d", i);

            // 根據 buffer 中字串的實際長度來配置記憶體
            answer[index] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(answer[index], buffer);
        }
    }

    // 5. 回傳結果
    return answer;
}