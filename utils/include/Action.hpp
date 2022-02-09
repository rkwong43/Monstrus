#pragma once

#include <vector>

namespace Game::Utils {
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
    enum class Side {
        ALLIES,
        ENEMIES,
        ALL
    };

    struct Action {
            Action(ActionType type, int value, Side side, std::initializer_list targets) : type(type), value(value){
                targets = vector<int>(targets);
            }
            // What type of action?
            ActionType type;
            // Value of the action done to the target(s)
            int value;
            // What target?
            Side side;
            // Target positions (if not all)
            vector<int> targets;

    };
}