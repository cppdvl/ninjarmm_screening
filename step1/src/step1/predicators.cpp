//
// Created by User on 8/27/2023.
//

#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

template <typename T>
auto IsInBounds(T value, T lower, T upper) -> bool
{
    if (lower>upper) std::swap(lower, upper);
    return (value >= lower && value <= upper);
}

auto ContainsTheString(std::vector<std::string> strings, std::function<bool(const std::string&)> predicate = [](const auto& tested){ return tested == "test"; })
{
    return std::accumulate(strings.begin(), strings.end(), 0, [&](auto prev, const auto& stringtotest){ return prev + (predicate(stringtotest) ? 1 : 0); });
}


std::ostream &operator<<(std::ostream &os, const std::vector<std::string> &strings)
{
    os << "\""; for (const auto &string : strings) os << string << ", ";
    os << (char) 0x8 << (char) 0x8 << "\"";
    return os;
}

int main ()
{
    std::cout << IsInBounds<int>(0, 1, 10) << std::endl;
    std::cout << IsInBounds<int>(1, 1, 10) << std::endl;
    std::cout << IsInBounds<int>(10, 1, 10) << std::endl;
    std::cout << IsInBounds<int>(11, 1, 10) << std::endl;
    //the same but for int32_t
    std::cout << IsInBounds<int32_t>(0, 1, 10) << std::endl;
    std::cout << IsInBounds<int32_t>(1, 1, 10) << std::endl;
    std::cout << IsInBounds<int32_t>(10, 1, 10) << std::endl;
    std::cout << IsInBounds<int32_t>(11, 1, 10) << std::endl;

    auto onetesthere = std::vector<std::string> {"one", "test", "here"};
    auto nowimhere  = std::vector<std::string> {"now", "im", "here"};
    auto thinkIllStayAroundAroundAround = std::vector<std::string> {"think", "Ill", "stay", "around", "around", "around"};

    auto hits = ContainsTheString(onetesthere);
    std::cout << onetesthere << " hits test " << hits << " time" << (hits==1 ? "":"s") << std::endl;

    auto anotherPredicate = [](const auto& tested){ return tested == "around"; };
    hits = ContainsTheString(nowimhere, anotherPredicate);
    std::cout << nowimhere << " hits around " << hits << " time" << (hits==1 ? "":"s") << std::endl;

    hits = ContainsTheString(thinkIllStayAroundAroundAround, anotherPredicate);
    std::cout << thinkIllStayAroundAroundAround << " hits around " << hits << " time" << (hits==1 ? "":"s") << std::endl;

    return 0;
}