#pragma once


namespace Utils::Actions {
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
    class Action {
        public:
            Action() {
                // TODO: Figure out what parameters need to be added
            }

        private:
            // What type of action?
            ActionType type;
            // To whom?
            
            // What values (damage, healing, etc)?
            

    };
}