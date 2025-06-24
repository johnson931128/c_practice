#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

struct Song {
    std::string title;
    std::string artist;
    int duration_seconds;

    // TODO : define < that Song can be put in set
    // String has < operator, which is arrange by alphabet
    bool operator<(const Song& other) const{
        if (artist != other.artist){
            return artist < other.artist;
        }
        return title < other.title;
    }
};

std::set<Song> create_party_playlist(
    const std::vector<Song>& playlist_A,
    const std::vector<Song>& playlist_B,
    int min_duration
){
    std::set<Song> party_playlist;
    //TODO: function operate
    /*
    one way is for+if, but more 「STL」way is std::copy_if
    std::copy_if(來源的開始, 來源的結束, 目標的開始, 條件)
    1 來源的開始迭代器 (playlist_A.begin())
    2 來源的結束迭代器 (playlist_A.end())
    3 目標的插入迭代器 (這是一個新概念！)
    4 一個回傳 bool 的條件判斷式 (predicate)，通常是一個 Lambda 函數。
    std::inserter(container, iterator) 會創建一個在 iterator 位置插入元素的迭代器。
    */
    std::copy_if(
        playlist_A.begin(),
        playlist_A.end(),
        std::inserter(party_playlist, party_playlist.end()),
        [min_duration](const Song& s){
            return s.duration_seconds >= min_duration;
        }
    );

    // TODO: 步驟 2 - 將 playlist_B 中長度足夠的歌曲也合併進來
    /*
    std::set 的一個關鍵特性是它自動處理重複。
    當我們試圖 insert一個已經存在的元素時，
    set 會直接忽略它，不會產生任何錯誤或重複。
    這讓我們的合併工作變得異常簡單。
    */

    std::copy_if(
        playlist_B.begin(),
        playlist_B.end(),
        std::inserter(party_playlist, party_playlist.end()),
        [min_duration](const Song& s) {
            return s.duration_seconds >= min_duration;
        } 
    );

    return party_playlist;
}

int main() {
    std::vector<Song> playlist_A = {
        {"Bohemian Rhapsody", "Queen", 355},
        {"Intro", "The xx", 25}, // 太短
        {"Stairway to Heaven", "Led Zeppelin", 482},
        {"Hotel California", "Eagles", 390}
    };

    std::vector<Song> playlist_B = {
        {"Hotel California", "Eagles", 390}, // 重複歌曲
        {"Smells Like Teen Spirit", "Nirvana", 301},
        {"Short Skit", "Some Artist", 15}, // 太短
        {"Hey Jude", "The Beatles", 431}
    };

    int min_duration = 30;
    std::set<Song> final_playlist = create_party_playlist(playlist_A, playlist_B, min_duration);

    std::cout << "--- Party Playlist ---\n";
    for (const auto& song : final_playlist) {
        std::cout << song.artist << " - " << song.title << " (" << song.duration_seconds << "s)\n";
    }

    return 0;
}
