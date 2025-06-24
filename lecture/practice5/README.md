# 應用題：合併與過濾播放清單
## 情境：
你正在為一個音樂播放軟體開發新功能。你需要合併兩個朋友的播放清單 (playlist_A 和 playlist_B)，並產生一個新的、不包含重複歌曲的「派對播放清單」。此外，為了派對氣氛，任何長度少於 30 秒的歌曲都要被過濾掉。
## 任務：
你需要寫一個函數 create_party_playlist，它接收三個參數：
playlist_A (一個 std::vector<Song>)。
playlist_B (一個 std::vector<Song>)。
最短歌曲長度 min_duration (一個 int)。
這個函數需要回傳一個新的 std::set<Song> 作為最終的派對播放清單。set 會自動幫我們處理重複的歌曲，並且保持排序。
這個函數需要回傳一個新的 std::set<Song> 作為最終的派對播放清單。set 會自動幫我們處理重複的歌曲，並且保持排序。
資料結構 Song:
為了讓問題更具體，我們先定義 Song 結構。為了讓 Song 能被放進 std::set，它必須是可比較的，所以我們要為它重載 < 運算子。