#pragma once

#include <memory>

template <typename DecoratorStage>
class DecoratingStageFactory final {
public:
    template <
            typename T, typename ...Args,
            std::enable_if_t<
                    std::is_same<typename DecoratorStage::Argument, typename T::Argument>::value
                    && std::is_same<typename DecoratorStage::Result, typename T::Result>::value, int
            >* = nullptr
    >
    std::unique_ptr<DecoratorStage> create(Args && ... args) const {
        return std::make_unique<DecoratorStage>(std::make_unique<T>(std::forward<Args>(args)...));
    }

    template <
            typename T, typename ...Args,
            std::enable_if_t<
                    !(std::is_same<typename DecoratorStage::Argument, typename T::Argument>::value
                      && std::is_same<typename DecoratorStage::Result, typename T::Result>::value), int
            >* = nullptr
    >
    std::unique_ptr<T> create(Args && ... args) const {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
};


