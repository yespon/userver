#include <gtest/gtest.h>

#include <sstream>

#include <formats/yaml/exception.hpp>
#include <formats/yaml/serialize.hpp>
#include <formats/yaml/value_builder.hpp>

#include <formats/common/member_access_test.hpp>

namespace {
constexpr const char* kDoc = R"(
key1: 1
key2: val
key3:
  sub: -1
key4: [1,2,3]
key5: 10.5
key6: false
)";
}

template <>
struct MemberAccess<formats::yaml::Value> : public ::testing::Test {
  inline MemberAccess() : doc_(formats::yaml::FromString(kDoc)) {}
  formats::yaml::Value doc_;

  using ValueBuilder = formats::yaml::ValueBuilder;
  using Value = formats::yaml::Value;
  using Type = formats::yaml::Type;

  using ParseException = formats::yaml::ParseException;
  using TypeMismatchException = formats::yaml::TypeMismatchException;
  using OutOfBoundsException = formats::yaml::OutOfBoundsException;
  using MemberMissingException = formats::yaml::MemberMissingException;
};

INSTANTIATE_TYPED_TEST_CASE_P(FormatsYaml, MemberAccess, formats::yaml::Value);

struct FormatsYamlSpecificMemberAccess
    : public MemberAccess<formats::yaml::Value> {};

TEST_F(FormatsYamlSpecificMemberAccess, CheckPrimitiveTypes) {
  // Differs from JSON:

  // FIXME: yaml-cpp uses streams internally while libstdc++ happily reads
  //        negative numbers into unsigned types
  // EXPECT_FALSE(doc_["key3"]["sub"].IsUInt64());

  EXPECT_NO_THROW(doc_["key1"].As<std::string>());
  EXPECT_NO_THROW(doc_["key5"].As<std::string>());
  EXPECT_NO_THROW(doc_["key6"].As<std::string>());
}
