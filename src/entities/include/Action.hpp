#pragma once

#include <vector>

namespace Game::Entities {
    // What type of action is this?
    enum class ActionType {
        // Decreases HP of specified targets
        ATTACK,
        // Increases HP of specified targets
        DEFEND,
        // Increases Atk of specified targets
        BUFF,
        // Decreases Atk of specified targets
        DEBUFF
    };

    // Which team? Or everyone?
    enum class Side { ALLIES, ENEMIES, ALL };

    struct Action {
        Action(ActionType type, int value, Side side, std::initializer_list<int> targetPosns) : type(type), value(value) {
            targets = std::vector<int>(targetPosns);
        }
        // What type of action?
        ActionType type;
        // Value of the action done to the target(s)
        int value;
        // What target?
        Side side;
        // Target positions (if not all)
        std::vector<int> targets;
    };
}