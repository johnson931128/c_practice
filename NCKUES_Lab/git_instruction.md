好的，這是一份為您精心整理的 Git 使用重點 README 文件。它從核心概念講起，涵蓋了日常工作流程、進階技巧與最佳實踐，適合從新手到進階使用者參考。

您可以直接複製以下所有內容，貼到一個名為 `README.md` 的檔案中。

---

# Git 終極指南：從入門到精通 (README)

歡迎來到 Git 的世界！這份文件旨在成為您的隨身速查手冊，無論您是剛接觸 Git 的新手，還是希望鞏固知識的開發者，都能在這裡找到答案。

Git 不僅僅是「上傳/下載檔案」的工具，它是一個強大的 **分散式版本控制系統**。想像它是一個擁有無限「還原點」的遊戲存檔系統，不僅能備份，還能讓你和隊友在不同的「遊戲進度」（分支）上探索，最後再完美地合併成果。

---

## 目錄

1.  [核心概念：Git 的三大區域](#1-核心概念git-的三大區域)
2.  [首次設定：報上你的大名](#2-首次設定報上你的大名)
3.  [專案生命週期：從無到有](#3-專案生命週期從無到有)
4.  [日常工作流程：最重要的循環](#4-日常工作流程最重要的循環)
5.  [遠端協作：與 GitHub 同步](#5-遠端協作與-github-同步)
6.  [時光機：查看與撤銷](#6-時光機查看與撤銷)
7.  [分支魔法：平行宇宙開發](#7-分支魔法平行宇宙開發)
8.  [實用技巧與最佳實踐](#8-實用技巧與最佳實踐)

---

## 1. 核心概念：Git 的三大區域

理解這三個區域是精通 Git 的基石。

> **比喻：線上購物**
> *   **工作區 (Working Directory)**：你的書桌/專案資料夾。你在這裡實際修改、新增、刪除檔案。就像你把想買的商品放在桌上一樣。
> *   **暫存區 (Staging Area / Index)**：你的購物車。你把桌上確定要結帳的商品（修改過的檔案）放進購物車。這是一個讓你再次確認的緩衝區。
> *   **本地倉庫 (Local Repository)**：你的儲藏室。你對購物車裡的商品結帳（Commit），它們就會被打上一個時間戳和標籤，存放到你的個人儲藏室裡，形成一個不可變更的版本紀錄。

![Git Three Areas](https://git-scm.com/images/about/areas.png)

---

## 2. 首次設定：報上你的大名

在你第一次使用 Git 時，務必設定你的姓名和 Email，這會被記錄在每一次的 `commit` 中。

```bash
# 設定你的使用者名稱
git config --global user.name "Your Name"

# 設定你的 Email
git config --global user.email "youremail@example.com"
```

---

## 3. 專案生命週期：從無到有

有兩種方式可以開始一個 Git 專案：

#### A. 在現有資料夾中初始化

如果你已經有一個專案資料夾，但還沒用 Git 管理。

```bash
# 進入你的專案資料夾
cd my-project

# 初始化 Git 倉庫，會建立一個隱藏的 .git 資料夾
git init
```

#### B. 從遠端倉庫複製 (Clone)

這是最常見的方式，從 GitHub 或其他地方下載一個現有的專案。

```bash
# 複製遠端專案到你的電腦上
git clone https://github.com/user/repository.git
```

---

## 4. 日常工作流程：最重要的循環

這是你每天都會用到的指令循環。

#### ① `git status` - 檢查狀態

隨時使用此指令，查看目前工作區和暫存區的狀態。Git 會清楚地告訴你哪些檔案被修改了、哪些還在暫存區。

```bash
# 查看當前倉庫狀態
git status
```

#### ② `git add` - 加入購物車 (暫存)

將工作區的修改加入到暫存區，準備 "結帳"。

```bash
# 將特定檔案加入暫存區
git add <file_name>

# 將所有已修改和新增的檔案加入暫存區 (最常用)
git add .
```

#### ③ `git commit` - 建立版本 (結帳)

將暫存區的所有內容建立成一個新的版本快照，存放到本地倉庫。

```bash
# 提交並附上簡潔有意義的訊息
git commit -m "feat: 新增使用者登入功能"
#
# 好的 Commit Message 慣例：
# feat: (feature) 新功能
# fix: (bug fix) 修正錯誤
# docs: (documentation) 修改文件
# style: (styling) 格式變更，不影響程式邏輯
# refactor: (refactoring) 重構程式碼
# chore: (chore) 其他雜項，如建構流程變更
```

---

## 5. 遠端協作：與 GitHub 同步

你的本地倉庫需要和遠端倉庫（例如 GitHub）溝通，才能備份和協作。

#### `git push` - 推送至遠端

將你本地的 `commit` 紀錄上傳到遠端倉庫。

```bash
# 將 main 分支推送到名為 origin 的遠端倉庫
git push origin main
```

#### `git pull` - 從遠端拉取並合併

從遠端倉庫下載最新的版本，並自動與你的本地分支合併。**在開始新工作或推送前，養成先 `pull` 的好習慣！**

```bash
# 從 origin 遠端倉庫拉取 main 分支的最新變更
git pull origin main
```

---

## 6. 時光機：查看與撤銷

Git 最強大的地方在於版本控制，你可以隨意穿梭和修改歷史。

#### 查看歷史

```bash
# 查看詳細的 commit 歷史
git log

# 查看精簡版的 commit 歷史（一行顯示）
git log --oneline

# 查看圖形化的分支歷史
git log --graph --oneline --decorate --all

# 查看某個 commit 的具體修改內容
git show <commit_hash>
```

#### 撤銷修改

**場景 1：修改了檔案，但還沒 `add`，想放棄修改**
```bash
# 放棄對特定檔案的修改
git restore <file_name>
```

**場景 2：已經 `add` 到暫存區，想取消暫存**
```bash
# 將檔案從暫存區移回工作區
git restore --staged <file_name>
```

**場景 3：剛剛的 `commit` 訊息寫錯了，或漏掉檔案**
```bash
# 重新 commit，可以修改訊息或加入新檔案
git add . # 如果有漏掉的檔案
git commit --amend
```

**場景 4：想撤銷某個已經 `push` 的 `commit` (安全作法)**
> ⚠️ **不要用 `reset` 去修改已經推送到遠端的歷史！**
> `revert` 會建立一個「反向」的新 commit 來抵銷舊的 commit，安全且保留歷史。

```bash
# 建立一個新的 commit，其內容與指定的 commit 相反
git revert <commit_hash>
```

---

## 7. 分支魔法：平行宇宙開發

分支是 Git 的殺手級功能。它讓你可以在不影響主線 (通常是 `main`) 的情況下，開闢一個新的空間來開發新功能或修復 Bug。

```bash
# 查看所有本地分支
git branch

# 建立一個名為 "feature/new-login" 的新分支
git branch feature/new-login

# 切換到指定分支 (新版指令，推薦使用)
git switch feature/new-login
# (舊版指令：git checkout feature/new-login)

# 建立並直接切換到新分支 (常用)
git switch -c feature/new-login
# (舊版指令：git checkout -b feature/new-login)

# 將 feature/new-login 分支的修改合併回 main 分支
# 1. 首先切換回 main 分支
git switch main
# 2. 拉取最新程式碼，確保 main 是最新的
git pull origin main
# 3. 執行合併
git merge feature/new-login

# 合併完成後，可以刪除不再需要的分支
git branch -d feature/new-login
```

#### 解決衝突 (Merge Conflict)

當你和別人修改了同一個檔案的同一行時，`git merge` 或 `git pull` 就會發生衝突。
1.  打開有衝突的檔案，Git 會用 `<<<<<<<`, `=======`, `>>>>>>>` 標示出衝突區塊。
2.  手動編輯檔案，決定要保留哪一部分的程式碼，並刪除 Git 標示符號。
3.  儲存檔案後，執行 `git add .` 將解決後的檔案加入暫存。
4.  最後執行 `git commit` 完成合併。

---

## 8. 實用技巧與最佳實踐

*   **`.gitignore` 文件**：在專案根目錄建立此檔案，列出你不想被 Git 追蹤的檔案或資料夾（如 `node_modules`, `*.log`, `config.ini` 等）。
*   **Commit Often, Perfect Later**：頻繁地 commit，每次只包含一個小而完整的功能或修正。
*   **Write Good Commit Messages**：清晰的 commit 訊息是最好的文件。
*   **Pull Before You Push**：在推送你的變更前，總是先拉取遠端的最新版本，以減少衝突。
*   **Use Branches for Everything**：不要直接在 `main` 分支上開發。任何新功能、修復都應該在獨立的分支上進行。