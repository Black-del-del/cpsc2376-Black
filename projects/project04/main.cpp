#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"

const int CELL_SIZE = 100;
const int SCREEN_WIDTH = Game::COLS * CELL_SIZE;
const int SCREEN_HEIGHT = Game::ROWS * CELL_SIZE;

void renderGame(SDL_Renderer* renderer, const Game& game, TTF_Font* font) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue background
    SDL_RenderClear(renderer);

    // Draw grid and pieces
    for (int r = 0; r < Game::ROWS; ++r) {
        for (int c = 0; c < Game::COLS; ++c) {
            SDL_Rect cell = {c * CELL_SIZE, r * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            Cell value = game.getCell(r, c);

            if (value == EMPTY)
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else if (value == PLAYER_1)
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            else
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

            SDL_RenderFillRect(renderer, &cell);
        }
    }

    // Display win/draw message
    Status st = game.status();
    if (st != ONGOING) {
        std::string msg;
        if (st == PLAYER_1_WINS) msg = "Player 1 Wins!";
        else if (st == PLAYER_2_WINS) msg = "Player 2 Wins!";
        else msg = "It's a Draw!";

        SDL_Color white = {255, 255, 255};
        SDL_Surface* textSurf = TTF_RenderText_Blended(font, msg.c_str(), white);
        SDL_Texture* textTex = SDL_CreateTextureFromSurface(renderer, textSurf);
        int tw, th;
        SDL_QueryTexture(textTex, nullptr, nullptr, &tw, &th);
        SDL_Rect dst = {(SCREEN_WIDTH - tw) / 2, (SCREEN_HEIGHT - th) / 2, tw, th};
        SDL_RenderCopy(renderer, textTex, nullptr, &dst);
        SDL_FreeSurface(textSurf);
        SDL_DestroyTexture(textTex);
    }

    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow("Connect 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font* font = TTF_OpenFont("assets/OpenSans-Regular.ttf", 48);
    if (!font) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
        return 1;
    }

    Game game;
    bool quit = false;

    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE) quit = true;
                if (e.key.keysym.sym == SDLK_r) game = Game();
            } else if (e.type == SDL_MOUSEBUTTONDOWN && game.status() == ONGOING) {
                int col = e.button.x / CELL_SIZE;
                game.play(col);
            }
        }
        renderGame(renderer, game, font);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
