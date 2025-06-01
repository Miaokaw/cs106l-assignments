#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <ranges>
#include <set>
#include <vector>

template<typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string &source) {
    /* TODO: Implement this method */
    Corpus tokens;

    auto ch = find_all(source.begin(), source.end(), [](const char c)-> bool { return std::isspace(c); });
    std::transform(
        std::next(ch.begin()), ch.end(),
        ch.begin(),
        std::inserter<Corpus>(tokens, tokens.end()),
        [&source](auto it1, auto it2) {
            return Token(source, it2, it1);
        });

    std::erase_if(tokens, [](auto &token) { return token.content == ""; });

    return tokens;
}

std::set<Misspelling> spellcheck(const Corpus &source, const Dictionary &dictionary) {
    /* TODO: Implement this method */
    namespace rv = std::ranges::views;
    namespace rng = std::ranges;
    auto view = source | rv::filter([dictionary](const Token &token) {
                    return !dictionary.contains(token.content);
                })
                | rv::transform([dictionary](const Token &token) {
                    auto filteredDictionary = dictionary | rv::filter([token](const std::string &word) {
                        return levenshtein(token.content, word) <= 1;
                    });
                    return Misspelling{
                        token, std::set<std::string>(filteredDictionary.begin(), filteredDictionary.end())
                    };
                }) | rv::filter([](const Misspelling &misspelling) {
                    ;
                    return !misspelling.suggestions.empty();
                });
    std::set<Misspelling> misspellings(view.begin(), view.end());
    return misspellings;
};
/* Helper methods */

#include "utils.cpp"
