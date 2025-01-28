#include <SDL.h>
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
    const char* title = u8"新年快乐!";
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

    //老友，蛇年钟声敲响，愿你似蛇灵动聪慧，在复杂世事中找准方向。
    // 事业上稳步攀升，成为行业翘楚。
    // 生活中，幸运如蛇影随形，每天都有小确幸。
    // 无论何时，咱们情谊不变，有空多唠唠，祝你新的一年超精彩！
    SDL_Color color = { 255, 255, 255 }; // 白色
    std::string text1 = u8"2025,蛇年快乐！！！"; // 使用UTF-8编码的字符串  
    std::string text2 = u8"老友，蛇年钟声敲响，愿你似蛇灵动聪慧，在复杂世事中找准方向";
    std::string text3 = u8"事业上稳步攀升，成为行业翘楚。";
    std::string text4 = u8"生活中，幸运如蛇影随形，每天都有小确幸。";
    std::string text5 = u8"无论何时，咱们情谊不变，有空多唠唠，祝你新的一年超精彩！";
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

    Mix_Chunk* sound = Mix_LoadWAV("happy_NewYear.mp3"); // 替换为实际音乐路径
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
