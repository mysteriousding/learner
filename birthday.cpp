//音频
//#include <SDL.h>
//#include <SDL_mixer.h>
//#include <iostream>
//
//int main(int argc, char* args[]) {
//    // 初始化SDL音频子系统
//    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
//        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//        return 1;
//    }
//
//    // 初始化SDL_mixer
//    if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048) < 0) {
//        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
//        SDL_Quit();
//        return 1;
//    }
//
//    // 加载WAV文件
//    Mix_Chunk* chunk = Mix_LoadWAV("happy_birthday.mp3");
//    if (chunk == nullptr) {
//        std::cerr << "Failed to load WAV file! SDL_mixer Error: " << Mix_GetError() << std::endl;
//        Mix_CloseAudio();
//        SDL_Quit();
//        return 1;
//    }
//
//    // 播放音频
//    Mix_PlayChannel(-1, chunk, 0);
//
//    // 等待音频播放完成
//    while (Mix_Playing(-1)) {
//        SDL_Delay(10); // 每次等待10毫秒
//    }
//
//    // 释放音频资源
//    Mix_FreeChunk(chunk);
//
//    // 关闭音频设备和退出SDL
//    Mix_CloseAudio();
//    SDL_Quit();
//
//    return 0;
//}



////文字
//#include <SDL.h>
//#include <SDL_ttf.h>
//#include <iostream>
//#include <string>
//
//int main(int argc, char* argv[]) {
//    // 初始化SDL
//    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//        return 1;
//    }
//
//    // 创建窗口
//    SDL_Window* window = SDL_CreateWindow("SDL_ttf Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
//    if (window == nullptr) {
//        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//        SDL_Quit();
//        return 1;
//    }
//
//    // 获取窗口渲染器
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    if (renderer == nullptr) {
//        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//        SDL_DestroyWindow(window);
//        SDL_Quit();
//        return 1;
//    }
//
//    // 初始化字体库
//    if (TTF_Init() == -1) {
//        std::cerr << "TTF_Init failed: " << TTF_GetError() << std::endl;
//        SDL_DestroyRenderer(renderer);
//        SDL_DestroyWindow(window);
//        SDL_Quit();
//        return 1;
//    }
//
//    // 加载字体
//    TTF_Font* font = TTF_OpenFont("STKAITI.TTF", 24); // 使用微软雅黑字体
//    if (font == nullptr) {
//        std::cerr << "Failed to load font! TTF_Error: " << TTF_GetError() << std::endl;
//        SDL_DestroyRenderer(renderer);
//        SDL_DestroyWindow(window);
//        TTF_Quit();
//        SDL_Quit();
//        return 1;
//    }
//
//    // 设置文本颜色
//    SDL_Color textColor = { 255, 255, 255, 255 }; // 白色
//
//    // 渲染文本
//    std::string text = u8"生日快乐"; // 使用UTF-8编码的字符串
//    SDL_Surface* textSurface = TTF_RenderUTF8_Solid(font, text.c_str(), textColor);
//    if (textSurface == nullptr) {
//        std::cerr << "Unable to render text surface! TTF_Error: " << TTF_GetError() << std::endl;
//        TTF_CloseFont(font);
//        SDL_DestroyRenderer(renderer);
//        SDL_DestroyWindow(window);
//        TTF_Quit();
//        SDL_Quit();
//        return 1;
//    }
//
//    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
//    SDL_FreeSurface(textSurface);
//
//    if (texture == nullptr) {
//        std::cerr << "Unable to create texture from surface! SDL_Error: " << SDL_GetError() << std::endl;
//        TTF_CloseFont(font);
//        SDL_DestroyRenderer(renderer);
//        SDL_DestroyWindow(window);
//        TTF_Quit();
//        SDL_Quit();
//        return 1;
//    }
//
//    SDL_Rect textRect = { 100, 100, textSurface->w, textSurface->h }; // 文本位置和大小
//
//    // 主循环
//    bool quit = false;
//    SDL_Event e;
//    while (!quit) {
//        while (SDL_PollEvent(&e) != 0) {
//            if (e.type == SDL_QUIT) {
//                quit = true;
//            }
//        }
//
//        SDL_RenderClear(renderer);
//        SDL_RenderCopy(renderer, texture, NULL, &textRect);
//        SDL_RenderPresent(renderer);
//    }
//
//    // 清理资源
//    SDL_DestroyTexture(texture);
//    TTF_CloseFont(font);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    TTF_Quit();
//    SDL_Quit();
//
//    return 0;
//}


//// 设置文本颜色 --- 重点
//SDL_Color textColor = { 255, 255, 255, 255 }; // 白色
//// 渲染文本
//std::string text = u8"生日快乐"; // 使用UTF-8编码的字符串
//SDL_Surface* textSurface = TTF_RenderUTF8_Solid(font, text.c_str(), textColor);
//if (textSurface == nullptr) {
//    std::cerr << "Unable to render text surface! TTF_Error: " << TTF_GetError() << std::endl;
//    TTF_CloseFont(font);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    TTF_Quit();
//    SDL_Quit();
//    return 1;
//}



/*
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

// 烟花结构体
struct Firework {
    float x, y; // 位置
    float vx, vy; // 速度
    SDL_Color color;
    enum State { READY, LAUNCHING, EXPLODING, DISAPPEARING } state;
    int explosionTime;
    std::vector<struct Particle> particles;
};

// 粒子结构体
struct Particle {
    float x, y;
    float vx, vy;
    SDL_Color color;
    float size;
    int life;
    int initialLife;
};

// 初始化SDL和创建窗口
SDL_Window* initSDL(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return nullptr;
    }
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return nullptr;
    }
    return window;
}

// 烟花发射函数
void launchFirework(Firework & firework) {
    firework.state = Firework::LAUNCHING;
    firework.y = 600; // 假设窗口高度为600
    firework.vy = -5.0f; // 向上发射
}

// 更新烟花状态
void updateFireworks(std::vector<Firework>&fireworks) {
    for (auto& firework : fireworks) {
        switch (firework.state) {
        case Firework::LAUNCHING:
            firework.y += firework.vy;
            if (firework.y < 100) { // 假设100为爆炸高度
                firework.state = Firework::EXPLODING;
                firework.explosionTime = 0;
            }
            break;
        case Firework::EXPLODING:
            if (firework.explosionTime < 50) { // 爆炸持续时间
                firework.explosionTime++;
            }
            else {
                firework.state = Firework::DISAPPEARING;
            }
            break;
        case Firework::DISAPPEARING:
            for (auto& particle : firework.particles) {
                particle.life--;
                if (particle.life <= 0) {
                    particle.x = -100; // 移除粒子
                }
            }
            firework.particles.erase(std::remove_if(firework.particles.begin(), firework.particles.end(),
                [](const Particle& p) { return p.life <= 0; }), firework.particles.end());
            if (firework.particles.empty()) {
                firework.state = Firework::READY;
            }
            break;
        }
    }
}

// 绘制烟花和粒子
void drawFireworks(SDL_Renderer * renderer, const std::vector<Firework>&fireworks) {
    for (const auto& firework : fireworks) {
        switch (firework.state) {
        case Firework::LAUNCHING:
            SDL_SetRenderDrawColor(renderer, firework.color.r, firework.color.g, firework.color.b, 255);
            SDL_RenderDrawPoint(renderer, static_cast<int>(firework.x), static_cast<int>(firework.y));
            break;
        case Firework::EXPLODING:
        case Firework::DISAPPEARING:
            for (const auto& particle : firework.particles) {
                SDL_SetRenderDrawColor(renderer, particle.color.r, particle.color.g, particle.color.b, 255 - particle.life / (float)particle.initialLife * 255);
                SDL_Rect rect = { static_cast<int>(particle.x - particle.size / 2), static_cast<int>(particle.y - particle.size / 2), static_cast<int>(particle.size), static_cast<int>(particle.size) };
                SDL_RenderFillRect(renderer, &rect);
            }
            break;
        }
    }
}

// 初始化粒子
void initParticle(Particle & particle, const Firework & firework) {
    particle.x = firework.x;
    particle.y = firework.y;
    particle.vx = (rand() % 10) / 5.0f - 2.0f;
    particle.vy = (rand() % 10) / 5.0f - 2.0f;
    particle.color = firework.color;
    particle.size = (rand() % 5) + 1;
    particle.life = (rand() % 100) + 50;
    particle.initialLife = particle.life;
}

// 生成烟花粒子
void generateParticles(Firework & firework) {
    firework.particles.clear();
    for (int i = 0; i < 100; ++i) {
        Particle particle;
        initParticle(particle, firework);
        firework.particles.push_back(particle);
    }
}

// 主函数
int main(int argc, char* args[]) {
    const char* title = "生日祝福";
    int width = 800;
    int height = 600;
    SDL_Window* window = initSDL(title, width, height);
    if (!window) {
        return 1; // 初始化失败，退出程序
    }



    // 初始化SDL音频子系统
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // 打开音频设备
    int audioRate = 44100;       // 音频采样率
    Uint16 audioFormat = AUDIO_S16SYS; // 音频格式
    int audioChannels = 2;       // 音频通道数
    int audioBuffers = 2048;     // 音频缓冲区大小

    if (Mix_OpenAudio(audioRate, audioFormat, audioChannels, audioBuffers) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }



    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    std::vector<Firework> fireworks;
    for (int i = 0; i < 10; ++i) {
        Firework firework;
        firework.x = rand() % width;
        firework.y = height;
        firework.color = { 255, 255, 255 }; // 白色
        firework.state = Firework::READY;
        fireworks.push_back(firework);
    }

    TTF_Font* font = TTF_OpenFont("msyh.ttc", 48); // 替换为实际字体路径
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    // 设置文本颜色
    SDL_Color textColor = { 255, 255, 255, 255 }; // 白色
    // 渲染文本
    std::string text = u8"生日快乐"; // 使用UTF-8编码的字符串
    SDL_Surface* textSurface = TTF_RenderUTF8_Solid(font, text.c_str(), textColor);
    if (textSurface == nullptr) {
        std::cerr << "Unable to render text surface! TTF_Error: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    //SDL_Rect textRect = { 100, 100, textSurface->w, textSurface->h }; // 文本位置和大小
    SDL_Rect textRect = { (width - textSurface->w) / 2, 10, textSurface->w, textSurface->h };

    Mix_Chunk* sound = Mix_LoadWAV("happy_birthday.wav"); // 替换为实际音乐路径
    if (!sound) {
        std::cerr << "Failed to load sound: " << Mix_GetError() << std::endl;
        SDL_DestroyTexture(textTexture);
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    Mix_PlayChannel(-1, sound, 0);

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // 发射新的烟花
        if (rand() % 50 == 0) { // 随机发射烟花
            launchFirework(fireworks[rand() % fireworks.size()]);
            generateParticles(fireworks[rand() % fireworks.size()]);
        }

        // 更新烟花状态
        updateFireworks(fireworks);

        // 绘制烟花和粒子
        drawFireworks(renderer, fireworks);

        // 绘制文字
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        SDL_RenderPresent(renderer);

        if (!Mix_Playing(-1)) { // 如果音乐播放完毕
            Mix_PlayChannel(-1, sound, 0); // 重新播放音乐
        }

        SDL_Delay(16); // 控制帧率
    }

    // 清理资源
    Mix_FreeChunk(sound);
    TTF_CloseFont(font);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
    TTF_Quit();
    Mix_CloseAudio();

    return 0;
}
*/





#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

// 粒子结构体
struct Particle {
    float x, y;
    float vx, vy;
    SDL_Color color;
    float size;
    int life;
    int initialLife;
};

// 初始化SDL和创建窗口
SDL_Window* initSDL(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return nullptr;
    }
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return nullptr;
    }
    return window;
}

// 生成随机颜色
SDL_Color getRandomColor() {
    return { static_cast<unsigned char>(rand() % 256), static_cast<unsigned char>(rand() % 256), static_cast<unsigned char>(rand() % 256) };
}

// 更新粒子状态
void updateParticles(std::vector<Particle>& particles) {
    for (auto& particle : particles) {
        particle.x += particle.vx;
        particle.y += particle.vy;
        particle.life--;
        if (particle.life <= 0) {
            particle.x = -100; // 移除粒子
            particle.y = -100;
        }
    }
    particles.erase(std::remove_if(particles.begin(), particles.end(), [](const Particle& p) { return p.life <= 0; }), particles.end());
}

// 绘制粒子
void drawParticles(SDL_Renderer* renderer, const std::vector<Particle>& particles) {
    for (const auto& particle : particles) {
        SDL_SetRenderDrawColor(renderer, particle.color.r, particle.color.g, particle.color.b, 255);
        SDL_Rect rect = { static_cast<int>(particle.x - particle.size / 2), static_cast<int>(particle.y - particle.size / 2), static_cast<int>(particle.size), static_cast<int>(particle.size) };
        SDL_RenderFillRect(renderer, &rect);
    }
}

// 初始化粒子
void initParticle(Particle& particle) {
    particle.x = rand() % 800;
    particle.y = 0; // 从顶部发射
    particle.vx = (rand() % 10) / 5.0f - 2.0f; // 水平速度
    particle.vy = 2.0f + (rand() % 6) / 5.0f; // 垂直速度，确保向下流动
    particle.color = getRandomColor();
    particle.size = (rand() % 3) + 1;
    particle.life = (rand() % 100) + 50;
    particle.initialLife = particle.life;
}

// 生成粒子
void generateParticles(std::vector<Particle>& particles) {
    for (int i = 0; i < 3; ++i) { // 每次生成10个粒子
        Particle particle;
        initParticle(particle);
        particles.push_back(particle);
    }
}

// 主函数
int main(int argc, char* args[]) 
{
    const char* title = "生日祝福";
    int width = 800;
    int height = 600;
    SDL_Window* window = initSDL(title, width, height);
    if (!window) {
        return 1; // 初始化失败，退出程序
    }

    // 隐藏控制台窗口
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);


    // 初始化SDL音频子系统
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // 打开音频设备
    int audioRate = 44100;       // 音频采样率
    Uint16 audioFormat = AUDIO_S16SYS; // 音频格式
    int audioChannels = 2;       // 音频通道数
    int audioBuffers = 2048;     // 音频缓冲区大小

    if (Mix_OpenAudio(audioRate, audioFormat, audioChannels, audioBuffers) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    std::vector<Particle> particles;
    generateParticles(particles); // 初始生成粒子

    TTF_Font* font1 = TTF_OpenFont("STKAITI.TTF", 48); // 替换为实际字体路径
    if (!font1) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    TTF_Font* font2 = TTF_OpenFont("STKAITI.TTF", 24); // 替换为实际字体路径
    if (!font2) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Color color = { 255, 255, 255 }; // 白色
    std::string text1 = u8"生日快乐，奂雅欣！"; // 使用UTF-8编码的字符串
    //std::string text2 = u8"恭喜你步入 18 岁的青春殿堂。这是全新的起点，愿你的未来充满阳光，每一步都走得坚定有力，所有期待皆能如愿，所行皆坦途，生日快乐，青春正好！"; // 使用UTF-8编码的字符串
    std::string text2 = u8"恭喜你步入 18 岁的青春殿堂。";
    std::string text3 = u8"这是全新的起点，愿你的未来充满阳光，每一步都走得坚定有力，";
    std::string text4 = u8"所有期待皆能如愿，所行皆坦途，";
    std::string text5 = u8"生日快乐，青春正好！";
    SDL_Surface* textSurface1 = TTF_RenderUTF8_Solid(font1, text1.c_str(), color);
    SDL_Surface* textSurface2 = TTF_RenderUTF8_Solid(font2, text2.c_str(), color);
    SDL_Surface* textSurface3 = TTF_RenderUTF8_Solid(font2, text3.c_str(), color);
    SDL_Surface* textSurface4 = TTF_RenderUTF8_Solid(font2, text4.c_str(), color);
    SDL_Surface* textSurface5 = TTF_RenderUTF8_Solid(font2, text5.c_str(), color);
    if (textSurface1 == nullptr || textSurface2 == nullptr || textSurface3 == nullptr || textSurface4 == nullptr || textSurface5 == nullptr) {
        std::cerr << "Unable to render text surface! TTF_Error: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font1);
        TTF_CloseFont(font2);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Texture* textTexture1 = SDL_CreateTextureFromSurface(renderer, textSurface1);
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(renderer, textSurface2);
    SDL_Texture* textTexture3 = SDL_CreateTextureFromSurface(renderer, textSurface3);
    SDL_Texture* textTexture4 = SDL_CreateTextureFromSurface(renderer, textSurface4);
    SDL_Texture* textTexture5 = SDL_CreateTextureFromSurface(renderer, textSurface5);
    if (!textTexture1 || !textTexture2 || !textTexture3 || !textTexture4 || !textTexture5) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        SDL_DestroyTexture(textTexture1);
        SDL_DestroyTexture(textTexture2);
        SDL_DestroyTexture(textTexture3);
        SDL_DestroyTexture(textTexture4);
        SDL_DestroyTexture(textTexture5);

        SDL_FreeSurface(textSurface1);
        SDL_FreeSurface(textSurface2);
        SDL_FreeSurface(textSurface3);
        SDL_FreeSurface(textSurface4);
        SDL_FreeSurface(textSurface5);

        TTF_CloseFont(font1);
        TTF_CloseFont(font2);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_Rect textRect1 = { (width - textSurface1->w) / 2, 10, textSurface1->w, textSurface1->h };//？？？
    SDL_Rect textRect2 = { (width - textSurface2->w) / 2, 200, textSurface2->w, textSurface2->h };
    SDL_Rect textRect3 = { (width - textSurface3->w) / 2, 300, textSurface3->w, textSurface3->h };
    SDL_Rect textRect4 = { (width - textSurface4->w) / 2, 400, textSurface4->w, textSurface4->h };
    SDL_Rect textRect5 = { (width - textSurface5->w) / 2, 500, textSurface5->w, textSurface5->h };

    Mix_Chunk* sound = Mix_LoadWAV("happy_birthday.wav"); // 替换为实际音乐路径
    if (!sound) {
        std::cerr << "Failed to load sound: " << Mix_GetError() << std::endl;
        SDL_DestroyTexture(textTexture1);
        SDL_DestroyTexture(textTexture2);
        SDL_DestroyTexture(textTexture3);
        SDL_DestroyTexture(textTexture4);
        SDL_DestroyTexture(textTexture5);

        SDL_FreeSurface(textSurface1);
        SDL_FreeSurface(textSurface2);
        SDL_FreeSurface(textSurface3);
        SDL_FreeSurface(textSurface4);
        SDL_FreeSurface(textSurface5);

        TTF_CloseFont(font1);
        TTF_CloseFont(font2);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    Mix_PlayChannel(-1, sound, 0);

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // 每帧生成新的粒子
        generateParticles(particles);

        // 更新粒子状态
        updateParticles(particles);

        // 绘制粒子
        drawParticles(renderer, particles);

        // 绘制文字
        SDL_RenderCopy(renderer, textTexture1, NULL, &textRect1);
        SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
        SDL_RenderCopy(renderer, textTexture3, NULL, &textRect3);
        SDL_RenderCopy(renderer, textTexture4, NULL, &textRect4);
        SDL_RenderCopy(renderer, textTexture5, NULL, &textRect5);

        SDL_RenderPresent(renderer);

        if (!Mix_Playing(-1)) { // 如果音乐播放完毕
            Mix_PlayChannel(-1, sound, 0); // 重新播放音乐
        }

        SDL_Delay(16); // 控制帧率
    }

    // 清理资源
    Mix_FreeChunk(sound);
    TTF_CloseFont(font1); 
    TTF_CloseFont(font2); 
    SDL_DestroyTexture(textTexture1);
    SDL_DestroyTexture(textTexture2);
    SDL_DestroyTexture(textTexture3);
    SDL_DestroyTexture(textTexture4);
    SDL_DestroyTexture(textTexture5);

    SDL_FreeSurface(textSurface1);
    SDL_FreeSurface(textSurface2);
    SDL_FreeSurface(textSurface3);
    SDL_FreeSurface(textSurface4);
    SDL_FreeSurface(textSurface5);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
    TTF_Quit();
    Mix_CloseAudio();

    return 0;
}