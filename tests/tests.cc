#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include <algorithm>
#include <vector>

#include "catch.hpp"
#include "solution.hpp"

//////////////////////////////////////////////////////////////////////////
// Test Cases
//////////////////////////////////////////////////////////////////////////

TEST_CASE("Prompt Example", "[prompt_ex]") {
  std::vector<std::string> comments = {
      "Great job @Ashley11 and @TheRealNithin on the presentation!",
      "What do you think about @_Mei_'s new post? It seems to rival "
      "@Victor22's content",
      "I haven't seen that here before, you should tell @ashley11 ",
      "@Victor22 have you seen the new @CatsFurever video? I think you would "
      "really like it!",
      "@TheRealNithin @Victor22, you should collaborate more often!"};
  CommentStats expected = {{{"@_mei_", 1},
                            {"@ashley11", 2},
                            {"@catsfurever", 1},
                            {"@therealnithin", 2},
                            {"@victor22", 3}},
                           {"@ashley11", "@therealnithin", "@victor22"}};
  CommentStats actual = GenerateCommentStats(comments);
  std::sort(actual.popular_mentions.begin(), actual.popular_mentions.end());
  REQUIRE(actual.mention_frequencies == expected.mention_frequencies);
  REQUIRE(actual.popular_mentions == expected.popular_mentions);
}