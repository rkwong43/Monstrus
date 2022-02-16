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
        DEBUFF,
        // Does nothing
        NONE
    };

    // Which team? Or everyone?
    enum class Side { ALLIES, ENEMIES, ALL };

    struct Action {
        Action(ActionType type, int value, Side side, std::initializer_list<int> targetPosns) : type(type), value(value) {
            targets = std::vector<int>(targetPosns);
        }
        Action(ActionType type) : type(type) {
            if (type != ActionType::NONE) {
                throw std::runtime_error("Given non-NONE action type without parameters.");
            }
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