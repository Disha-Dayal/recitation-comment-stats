#include "solution.hpp"

#include <cctype>
#include <iostream>
CommentStats GenerateCommentStats(const std::vector<std::string>& comments) {
  CommentStats stats;

  // Early return if comments is empty
  if (comments.empty()) {
    return stats;
  }

  for (const auto& comment : comments) {
    for (unsigned int i = 0; i < comment.length(); ++i) {
      if (comment[i] == '@') {
        unsigned int start_pos = i + 1;
        std::string username;
        const std::string terminators = " !?,.\'@";

        for (unsigned int j = start_pos; j < comment.length(); ++j) {
          char c = comment[j];
          if (terminators.find(c)) {
            break;
          }

          username += std::tolower(c);
        }

        if (!username.empty()) {
          std::string mention = "@" + username;
          stats.mention_frequencies[mention]++;
        }
      }
    }
  }

  // Build popular_mentions from those with count > 1
  for (const auto& pair : stats.mention_frequencies) {
    if (pair.second >= 2) {
      stats.popular_mentions.push_back(pair.first);
    }
  }

  return stats;
}