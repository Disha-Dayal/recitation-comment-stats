#include "solution.hpp"

#include <cctype>
#include <iostream>
#include <string>

CommentStats GenerateCommentStats(const std::vector<std::string>& comments) {
  CommentStats stats;

  // empty
  if (comments.empty()) {
    return stats;
  }

  // what terminates
  const std::string terminators = "!?,.\'@";

  for (const auto& comment : comments) {
    const size_t clength = comment.length();
    for (size_t i = 0; i < clength; ++i) {
      if (comment[i] != '@') continue;

      // build user
      size_t j = i + 1;
      if (j >= clength) continue;
      // whitespace
      if (std::isspace(static_cast<unsigned char>(comment[j]))) continue;

      std::string username;
      while (j < clength) {
        unsigned char uc = static_cast<unsigned char>(comment[j]);
        char c = comment[j];

        if (std::isspace(uc) || terminators.find(c) != std::string::npos) {
          break;
        }

        username += static_cast<char>(std::tolower(uc));
        ++j;
      }

      if (!username.empty()) {
        std::string mention = "@" + username;
        stats.mention_frequencies[mention]++;

        // set to last character of the user
        i = j - 1;
      }
    }
  }

  // popular mentions
  for (const auto& pair : stats.mention_frequencies) {
    if (pair.second >= 2) {
      stats.popular_mentions.push_back(pair.first);
    }
  }

  return stats;
}