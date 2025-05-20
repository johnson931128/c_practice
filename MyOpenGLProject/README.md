# OpenGL C++ 專案設置與除錯指南

本文件將統整在 Windows（MinGW + VSCode + CMake）環境下從安裝到執行、常見錯誤與除錯的完整步驟。

---

## 1. 前置需求

* Windows 作業系統
* MinGW-w64（安裝並加入 PATH）
* VSCode
* CMake 3.10+
* Git Bash / PowerShell / cmd

---

## 2. 建立專案結構

```text
MyOpenGLProject/
├── src/
│   └── main.cpp
├── external/
│   ├── glad/
│   │   ├── include/
│   │   │   ├── glad/
│   │   │   └── KHR/
│   │   └── src/
│   │       └── glad.c
│   └── glfw/
│       ├── include/
│       │   └── GLFW/
│       └── lib/
│           ├── libglfw3.a        # 或 libglfw3dll.a + libglfw3.dll
├── CMakeLists.txt
└── build/
```

> **提示**：可在 File Explorer 手動建立，或在 PowerShell 下：
>
> ```powershell
> New-Item -ItemType Directory -Path .\MyOpenGLProject\src, \
>   .\MyOpenGLProject\external\glad\include, \
>   .\MyOpenGLProject\external\glad\src, \
>   .\MyOpenGLProject\external\glfw\include, \
>   .\MyOpenGLProject\external\glfw\lib, \
>   .\MyOpenGLProject\build
> ```

---

## 3. 下載並放置函式庫

### 3.1 GLFW (MinGW-w64)

1. 官網：[https://www.glfw.org/download.html](https://www.glfw.org/download.html)
2. 選「Windows pre-compiled binaries (MinGW-w64)」下載 ZIP。
3. 解壓後：

   * `include/GLFW` 全夾複製到 `external/glfw/include/`。
   * `lib-mingw-w64/libglfw3.a` 放到 `external/glfw/lib/`。
   * （若無 `libglfw3.a`，可改用 `libglfw3dll.a` + `libglfw3.dll`）

### 3.2 GLAD

1. 線上產生器：[https://glad.dav1d.de/](https://glad.dav1d.de/)
2. 設定：

   * **Language**：C/C++
   * **Specification**：OpenGL (gl)
   * **Version**：4.6
   * **Profile**：Core
   * **Extensions**：留空（或日後依需求再加）
3. 點 `Generate`，下載 ZIP。
4. 解壓後：

   * `include/glad` & `include/KHR` 複製到 `external/glad/include/`。
   * `src/glad.c` 複製到 `external/glad/src/`。

---

## 4. 撰寫程式碼與 CMake

### 4.1 `src/main.cpp`

```cpp
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    if (!glfwInit()) return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
    if (!window) { glfwTerminate(); return -1; }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
```

### 4.2 `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyOpenGLProject)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${PROJECT_SOURCE_DIR}/external/glad/include
    ${PROJECT_SOURCE_DIR}/external/glfw/include
)

add_library(glad STATIC
    ${PROJECT_SOURCE_DIR}/external/glad/src/glad.c
)

add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES
    IMPORTED_LOCATION
      ${PROJECT_SOURCE_DIR}/external/glfw/lib/libglfw3.a
)

add_executable(main
    src/main.cpp
)

target_link_libraries(main
    glad
    glfw
    opengl32
    gdi32
)
```

---

## 5. 編譯與執行

```powershell
cd MyOpenGLProject\build
cmake -G "MinGW Makefiles" ..
mingw32-make
.\main.exe
```

> **注意**：若使用 `libglfw3dll.a`，請手動複製 `libglfw3.dll` 到 `build/`。

---

## 6. 常見錯誤與除錯

| 錯誤訊息                                            | 原因                          | 解法                                                                    |
| ----------------------------------------------- | --------------------------- | --------------------------------------------------------------------- |
| `fatal error C1083: 無法開啟檔案 'KHR/khrplatform.h'` | 忘了複製 `KHR` 資料夾              | 將 `include/KHR` 一同放入 `external/glad/include/KHR/`                     |
| `No rule to make target 'libglfw3.a'`           | 下載到的為 DLL 版 (libglfw3dll.a) | 1. 重新下載靜態版 (libglfw3.a)，或<br>2. 改用 `libglfw3dll.a` 並搭配 `libglfw3.dll` |
| 執行時找不到 DLL (`xxx.dll not found`)                | 沒把 `.dll` 放在可執行檔同目錄         | 將 `libglfw3.dll` 複製到 `build/`                                         |

---

## 7. 延伸與最佳實踐

* 建議未來改用 CMake FetchContent、自動下載並編譯 GLAD/GLFW。
* 增加 `KHR_debug` extension，開啟 `glDebugMessageCallback`。
* 引入 ImGui 做 UI。
* 練習 Shader、Model 載入、3D 物件渲染。
