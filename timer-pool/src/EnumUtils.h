#pragma once

#include "magic_enum.hpp"
#include "magic_enum_containers.hpp"

#include "Common.h"

namespace tpp::Enum
{
    template<typename T>
    concept IsEnum = std::is_enum_v<T>;

    static constexpr std::string_view ToString(IsEnum auto enumVal) { return magic_enum::enum_name(enumVal); }
    template<IsEnum T>
    static constexpr T FromString(std::string_view enumStr) { return magic_enum::enum_cast<T>(enumStr); }

    template<IsEnum TEnum, typename TVal>
    using Array = magic_enum::containers::array<TEnum, TVal>;
    template<IsEnum T>
    using Bitset = magic_enum::containers::bitset<T>;
    template<IsEnum T>
    using Set = magic_enum::containers::set<T>;

    template<IsEnum T>
    struct Metadata
    {
        static constexpr auto Entries = magic_enum::enum_entries<T>();

        static constexpr size_t Size = magic_enum::enum_count<T>();

        template<size_t I>
        static constexpr T Value = Entries[I].first;

        template<size_t I>
        static constexpr std::string_view Name = Entries[I].second;
    };



} // namespace tpp
