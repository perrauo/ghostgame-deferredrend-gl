#include "game/game.h"
#include "game/types.h"

#include "framework/engine.h"
#include "framework/model.h"
#include "framework/entity.h"

#include <filesystem>

namespace GhostGame
{
    void Game::start(Framework::Engine& engine)
    {
        using namespace Framework;

        for (const auto& entry : std::filesystem::directory_iterator("./sponza"))
        {
            auto model = std::make_unique<Model>(entry.path().string());
            EntityId id = engine.spawnEntity();

        }

        engine.add(std::make_unique<Avatar>());
    }

    void Game::update(Framework::Engine& engine, float deltaTime)
    {
        static auto lastSpawnTime = std::chrono::high_resolution_clock::now();
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - lastSpawnTime);

        auto ghost = std::make_unique<Ghost>();
        ghost->transform.position = player->transform.position; // Assuming Avatar has a getPosition method
        engine.add(std::move(ghost));


    }

    void Game::render(Framework::Engine& engine)
    {
    }

    Game::~Game()
    {
    }
}