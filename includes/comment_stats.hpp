#ifndef COMMENT_STATS_HPP
#define COMMENT_STATS_HPP

#include <map>
#include <string>
#include <vector>
struct CommentStats {
  std::map<std::string, int> mention_frequencies;
  std::vector<std::string> popular_mentions;
};

#endif