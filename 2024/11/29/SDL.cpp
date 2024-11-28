//五子棋-----失败
//#include <SDL.h>
//#include <SDL_ttf.h>
//#include <iostream>
//#include <vector>
//#include <string>
//#include <ctime>
//
//const int square_size = 40;
//const int chess_size = square_size / 2 - 2;
//const int web_broad = 15;
//const int map_w = web_broad * square_size;
//const int map_h = web_broad * square_size;
//const int info_w = 60;
//const int button_w = 120;
//const int button_h = 45;
//const int screen_w = map_w;
//const int screen_h = map_h + info_w;
//
//enum MAP_ENUM { be_empty = 0, player1 = 1, player2 = 2, out_of_range = 3 };
//
//class Map {
//public:
//    std::vector<std::vector<int>> map;
//    std::vector<std::pair<int, int>> steps;
//    int width, height;
//
//    //Map(int w, int h) : width(w), height(h), map(w, std::vector<int>(h, 0)) {}
//
//    void get_init() {
//        for (int y = 0; y < height; ++y) {
//            for (int x = 0; x < width; ++x) {
//                map[y][x] = 0;
//            }
//        }
//        steps.clear();
//    }
//
//    void click(int x, int y, int type) {
//        if (x >= 0 && x < width && y >= 0 && y < height) {
//            map[y][x] = type;
//            steps.push_back(std::make_pair(x, y));
//        }
//    }
//
//    void drawBoard(SDL_Renderer* renderer) {
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//        for (int y = 0; y < height; ++y) {
//            for (int x = 0; x < width; ++x) {
//                SDL_Rect rect = { x * square_size + 1, y * square_size + 1, square_size - 2, square_size - 2 };
//                SDL_RenderDrawRect(renderer, &rect);
//            }
//        }
//    }
//
//    void printChessPiece(SDL_Renderer* renderer) {
//        SDL_Color white = { 255, 245, 238 };
//        SDL_Color black = { 41, 36, 33 };
//        for (auto& step : steps) {
//            int x = step.first;
//            int y = step.second;
//            int type = map[y][x];
//            SDL_SetRenderDrawColor(renderer, (type == 1) ? white.r : black.r, (type == 1) ? white.g : black.g, (type == 1) ? white.b : black.b, 255);
//            SDL_Rect circle = { (x * square_size + square_size / 2) - chess_size, (y * square_size + square_size / 2) - chess_size, chess_size * 2, chess_size * 2 };
//            SDL_RenderFillRect(renderer, &circle);
//        }
//    }
//};
//
//class Button {
//public:
//    SDL_Renderer* renderer;
//    std::string text;
//    SDL_Rect rect;
//    SDL_Color color;
//    bool enabled;
//
//    Button(SDL_Renderer* r, const std::string& t, int x, int y, int w, int h, SDL_Color c, bool e)
//        : renderer(r), text(t), rect({ x, y, w, h }), color(c), enabled(e) {}
//
//    void draw() {
//        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
//        SDL_RenderFillRect(renderer, &rect);
//        SDL_Color white = { 255, 255, 255 };
//        SDL_Surface* textSurface = TTF_RenderText_Solid(TTF_OpenFont(NULL, 24), text.c_str(), white);
//        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//        SDL_Rect textRect = { rect.x + (rect.w - textSurface->w) / 2, rect.y + (rect.h - textSurface->h) / 2, textSurface->w, textSurface->h };
//        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
//        SDL_FreeSurface(textSurface);
//        SDL_DestroyTexture(textTexture);
//    }
//};
//
//class Game {
//public:
//    SDL_Window* window;
//    SDL_Renderer* renderer;
//    Map map;
//    std::vector<Button> buttons;
//    bool isPlaying;
//
//    Game(const std::string& title) {
//        SDL_Init(SDL_INIT_VIDEO);
//        TTF_Init();
//        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_w, screen_h, SDL_WINDOW_SHOWN);
//        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//        //map = Map(web_broad, web_broad);
//        isPlaying = false;
//
//        Button startButton(renderer, "开始游戏", 20, map_h, button_w, button_h, { 255, 0, 0, 255 }, true);
//        buttons.push_back(startButton);
//    }
//
//    ~Game() {
//        SDL_DestroyRenderer(renderer);
//        SDL_DestroyWindow(window);
//        SDL_Quit();
//        TTF_Quit();
//    }
//
//    void play() {
//        SDL_Event event;
//        while (SDL_PollEvent(&event)) {
//            if (event.type == SDL_QUIT) {
//                isPlaying = false;
//            }
//            else if (event.type == SDL_MOUSEBUTTONDOWN) {
//                int x, y;
//                SDL_GetMouseState(&x, &y);
//                if (isPlaying) {
//                    int col = x / square_size;
//                    int row = y / square_size;
//                    map.click(col, row, 1); // Player 1
//                }
//            }
//        }
//
//        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//        SDL_RenderClear(renderer);
//
//        if (isPlaying) {
//            map.drawBoard(renderer);
//            map.printChessPiece(renderer);
//        }
//        else {
//            for (auto& button : buttons) {
//                button.draw();
//            }
//        }
//
//        SDL_RenderPresent(renderer);
//    }
//};
//
//int main(int argc, char* args[]) {
//    std::string title = "五子棋游戏 " + std::to_string(std::time(nullptr));
//    Game game(title);
//    while (game.isPlaying) {
//        game.play();
//    }
//    return 0;
//}




//小球来回撞-----成功
//#include <SDL.h>
//#include <cmath>
//#include <iostream>
//
//// 将角度转换为弧度
//float degreesToRadians(float degrees) {
//    return degrees * 3.14159265f / 180.0f;
//}
//
//// Bresenham圆算法
//void drawCircle(SDL_Renderer* renderer, int x0, int y0, int radius, SDL_Color color) {
//    int x = 0;
//    int y = radius;
//    int d = 3 - (radius << 1);
//
//    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
//
//    while (x <= y) {
//        SDL_RenderDrawPoint(renderer, x0 + x, y0 + y);
//        SDL_RenderDrawPoint(renderer, x0 - x, y0 + y);
//        SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);
//        SDL_RenderDrawPoint(renderer, x0 - x, y0 - y);
//        SDL_RenderDrawPoint(renderer, x0 + y, y0 + x);
//        SDL_RenderDrawPoint(renderer, x0 - y, y0 + x);
//        SDL_RenderDrawPoint(renderer, x0 + y, y0 - x);
//        SDL_RenderDrawPoint(renderer, x0 - y, y0 - x);
//
//        if (d < 0) {
//            d += (4 * x) + 6;
//        }
//        else {
//            d += (4 * (x - y)) + 10;
//            y--;
//        }
//        x++;
//    }
//}
//
//int main(int argc, char* args[]) {
//    SDL_Init(SDL_INIT_VIDEO);
//    SDL_Window* window = SDL_CreateWindow("Moving Circle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//
//    SDL_Color black = { 0, 0, 0, 255 }; // 黑色
//    int circleRadius = 50;
//    int circleX = 400; // 初始x位置
//    int circleY = 300; // 初始y位置
//    int moveStep = 10; // 每次移动的像素数
//
//    bool quit = false;
//    SDL_Event e;
//
//    while (!quit) {
//        while (SDL_PollEvent(&e) != 0) {
//            if (e.type == SDL_QUIT) {
//                quit = true;
//            }
//        }
//
//        // 清空屏幕
//        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//        SDL_RenderClear(renderer);
//
//        // 更新圆的位置
//        circleX -= moveStep;
//        if (circleX + circleRadius < 100 || circleX - circleRadius > 700) {
//            moveStep = -moveStep; // 反转移动方向
//        }
//
//        // 绘制黑色圆
//        drawCircle(renderer, circleX, circleY, circleRadius, black);
//
//        // 更新屏幕
//        SDL_RenderPresent(renderer);
//
//        // 延迟，控制移动速度
//        SDL_Delay(16); // 约60帧每秒
//    }
//
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}




//空心爱心-----成功
//// 爱心的参数方程
//#include <SDL.h>
//#include <cmath>
//#include <iostream>
//
//const int windowWidth = 800;
//const int windowHeight = 600;
//
//// 爱心的参数方程
//float x(float t) {
//    return 16 * std::sin(t) * std::sin(t) * std::sin(t);
//}
//
//float y(float t) {
//    return 13 * std::cos(t) - 5 * std::cos(2 * t) - 2 * std::cos(3 * t) - std::cos(4 * t);
//}
//
//int main(int argc, char* args[]) {
//    SDL_Window* window = nullptr;
//    SDL_Renderer* renderer = nullptr;
//
//    // 初始化SDL
//    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//        return 1;
//    }
//
//    // 创建窗口
//    window = SDL_CreateWindow("Heart Shape", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
//    if (!window) {
//        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//        SDL_Quit();
//        return 1;
//    }
//
//    // 创建渲染器
//    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    if (!renderer) {
//        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//        SDL_DestroyWindow(window);
//        SDL_Quit();
//        return 1;
//    }
//
//    // 设置背景色为白色
//    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//    SDL_RenderClear(renderer);
//
//    // 设置绘制颜色为红色
//    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//
//    // 绘制爱心
//    for (float t = 0; t < 2 * M_PI; t += 0.01) {
//        float x1 = x(t);
//        float y1 = y(t);
//        float x2 = x(t + 0.01);
//        float y2 = y(t + 0.01);
//
//        // 将极坐标转换为窗口坐标
//        int px1 = static_cast<int>(windowWidth / 2 + x1 * 10);
//        int py1 = static_cast<int>(windowHeight / 2 - y1 * 10);
//        int px2 = static_cast<int>(windowWidth / 2 + x2 * 10);
//        int py2 = static_cast<int>(windowHeight / 2 - y2 * 10);
//
//        SDL_RenderDrawLine(renderer, px1, py1, px2, py2);
//    }
//
//    // 更新屏幕
//    SDL_RenderPresent(renderer);
//    SDL_Delay(5000); // 显示5秒
//
//    // 清理
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}



//倒置空心爱心
//#include <SDL.h>
//#include <cmath>
//#include <iostream>
//
//const int windowWidth = 800;
//const int windowHeight = 600;
// 
//float heartX(float t) {
//    return 16 * std::sin(t) * std::sin(t) * std::sin(t);
//}
//
//float heartY(float t) {
//    return 13 * std::cos(t) - 5 * std::cos(2 * t) - 2 * std::cos(3 * t) - std::cos(4 * t);
//}
//
//// 爱心的边界函数
//float heartBoundaryX(float t) {
//    return windowWidth / 2 + heartX(t) * 10;
//}
//
//// 检查点是否在爱心内部
//bool isInsideHeart(float x, float y) {
//    float t = std::atan2(y - windowHeight / 2, x - windowWidth / 2);
//    if (t < 0) t += 2 * M_PI;
//    t -= M_PI / 2;
//    if (t < 0) t += 2 * M_PI;
//    float yt = heartY(t);
//    return std::abs(y - windowHeight / 2 - yt * 10) < heartX(t) * 10;
//}
//
//int main(int argc, char* args[]) {
//    SDL_Window* window = nullptr;
//    SDL_Renderer* renderer = nullptr;
//
//    // 初始化SDL
//    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//        return 1;
//    }
//
//    // 创建窗口
//    window = SDL_CreateWindow("Heart Shape", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
//    if (!window) {
//        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//        SDL_Quit();
//        return 1;
//    }
//
//    // 创建渲染器
//    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    if (!renderer) {
//        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//        SDL_DestroyWindow(window);
//        SDL_Quit();
//        return 1;
//    }
//
//    // 设置背景色为白色
//    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//    SDL_RenderClear(renderer);
//
//    // 设置绘制颜色为红色
//    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//
//    // 填充爱心
//    for (int y = 0; y < windowHeight; ++y) {
//        float minY = 100000.f, maxY = -100000.f;
//        for (float t = 0; t < 2 * M_PI; t += 0.01) {
//            float yAtT = heartY(t) * 10;
//            if (yAtT < minY) minY = yAtT;
//            if (yAtT > maxY) maxY = yAtT;
//        }
//        for (float t = 0; t < 2 * M_PI; t += 0.01) {
//            float yAtT1 = heartY(t) * 10;
//            float yAtT2 = heartY(t + 0.01) * 10;
//            if ((y - windowWidth / 2) >= std::min(yAtT1, yAtT2) && (y - windowWidth / 2) <= std::max(yAtT1, yAtT2)) {
//                int leftX = static_cast<int>((windowWidth / 2) + (heartX(t) * 10));
//                int rightX = static_cast<int>((windowWidth / 2) + (heartX(t + 0.01) * 10));
//                for (int x = leftX; x <= rightX; ++x) {
//                    SDL_RenderDrawPoint(renderer, x, y);
//                }
//            }
//        }
//    }
//
//    // 更新屏幕
//    SDL_RenderPresent(renderer);
//    SDL_Delay(5000); // 显示5秒
//
//    // 清理
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}
